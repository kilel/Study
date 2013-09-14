package com.github.kilel.ipseeker;

import java.io.IOException;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.InterfaceAddress;
import java.net.NetworkInterface;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;

public class IpSeeker {
	private static final int PING_TIMEOUT = 50;
	private static final int PING_TRIES = 1;
	
	private static void print (String s) {
		System.out.println(s);
	}
	
	public static void main(String[] args) throws IOException {
		Enumeration<NetworkInterface> interfaces = NetworkInterface.getNetworkInterfaces();
		while ( interfaces.hasMoreElements()) {
			NetworkInterface netInterface = interfaces.nextElement();
			if ( !netInterface.isUp() || netInterface.isLoopback() || netInterface.isVirtual()){
				continue;
			}
			print("Name : " + netInterface.getName());
			print("DisplayName : " + netInterface.getDisplayName());
			print("Host addresses : " + netInterface.getInterfaceAddresses());
			printAccessibleHosts(netInterface);
			print("_______________");
			//print(netInterface);
		}
	}
	
	private static void printAccessibleHosts(NetworkInterface netInt) throws IOException {
		for(InterfaceAddress intAddress : netInt.getInterfaceAddresses()) {
			InetAddress address = intAddress.getAddress();
			if(!Inet4Address.class.isInstance(address)) {
				continue;
			}
			print("search by IPv4 address" + intAddress);
			findAccessibleAddresses(intAddress, netInt);
		}
	}
	
	private static void findAccessibleAddresses(InterfaceAddress base, NetworkInterface netInt) throws UnknownHostException, IOException {
		byte[] addr = base.getAddress().getAddress();
		int masklen = base.getNetworkPrefixLength();
		for(int i = masklen; i < addr.length * 8; ++i){
			setBit(i, addr, 0);
		}
		List<InetAddress> addresses = new ArrayList<>();
		while(inc(addr, masklen)) {
			InetAddress address = InetAddress.getByAddress(addr);
			String s = "Checking address: " + address + "...";
			if(address.isReachable(netInt, PING_TRIES, PING_TIMEOUT)) {
				s += "Reachable!";
				addresses.add(address);
			}
			print(s);
		}
		
		print("Reached addresses: " + addresses);
		for(InetAddress address : addresses) {
			print("Address: " + address);
			//print("Host name: " + address.getHostName());
			// TODO use arp or arp-scan
			//nmblookup -A
			//nbtstat -a (win)
			//print("Hardware address: " + NetworkInterface.getByInetAddress(address).getHardwareAddress());
		}
	}
	private static boolean inc(byte[] addr, int masklen) {
		for(int i = masklen; i < addr.length * 8; ++i) {
			if(getBit(i, addr) == 0) {
				setBit(i, addr, 1);
				return true;
			} else {
				setBit(i, addr, 0);
			}
		}
		return false;
	}
	
	private static int getBit(int i, byte[] arr) {
		int j = i/8;
		int mod = i % 8;
		return  (arr[j] & 1 << mod);
	}
	
	private static void setBit(int i, byte[] arr, int val) {
		int j = i/8;
		int mod = i % 8;
		int currVal = arr[j];
		int value = val & 1;
		if(value == 1){
			value = currVal | 1 << mod;
		} else {
			value = currVal & ( 1 << mod ^ 0xFF);
		}
		arr[j] = (byte) value;
	}
	
}
