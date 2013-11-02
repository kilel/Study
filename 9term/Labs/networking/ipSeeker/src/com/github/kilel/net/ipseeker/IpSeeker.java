package com.github.kilel.net.ipseeker;

import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.InterfaceAddress;
import java.net.NetworkInterface;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;

public class IpSeeker {

	private static void print(String s) {
		System.out.println(s);
	}

	public static void main(String[] args) throws Exception {
		Enumeration<NetworkInterface> interfaces = NetworkInterface
				.getNetworkInterfaces();
		while (interfaces.hasMoreElements()) {
			NetworkInterface netInterface = interfaces.nextElement();
			if (!netInterface.isUp() || netInterface.isLoopback()
					|| netInterface.isVirtual()) {
				continue;
			}
			print("Name : " + netInterface.getName());
			print("DisplayName : " + netInterface.getDisplayName());
			print("Host addresses : " + netInterface.getInterfaceAddresses());
			printAccessibleHosts(netInterface);
			print("_______________");
			// print(netInterface);
		}
	}

	private static void printAccessibleHosts(NetworkInterface netInt)
			throws Exception {
		for (InterfaceAddress intAddress : netInt.getInterfaceAddresses()) {
			InetAddress address = intAddress.getAddress();
			if (!Inet4Address.class.isInstance(address)) {
				continue;
			}
			print("search by IPv4 address" + intAddress);
			findAccessibleAddresses(intAddress);
		}
	}

	private static void findAccessibleAddresses(
			InterfaceAddress interfaceAddress) throws Exception {
		NetAddress base = new NetAddress(interfaceAddress.getAddress()
				.getAddress(), interfaceAddress.getNetworkPrefixLength()).getBase();

		List<NetAddress> addresses = new ArrayList<>();
		while (base.hasNext()) {
			base.next();
			String addressSearchResult = "Checking address: " + base + "...";
			if (base.isReachable()) {
				addressSearchResult += "Reachable!";
				addresses.add(base.clone());
			}
			print(addressSearchResult);
		}

		print("Reached addresses: " + addresses);
		for (NetAddress addr : addresses) {
			print("Address: " + addr);
			print(addr.getInfo());
		}
	}

}
