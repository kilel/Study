package com.github.kilel.net.ipseeker;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.text.MessageFormat;
import java.util.Scanner;

public class NetAddress {
	private static final int PING_TIMEOUT = 10;

	private byte[] address;
	private int mask;
	private static final int addrLen = 4 * 8;

	public NetAddress(byte[] addr, int mask) {
		this.address = addr;
		this.mask = mask;
	}

	public boolean isReachable() throws Exception {
		InetAddress inetAddress = InetAddress.getByAddress(address);
		return inetAddress.isReachable(PING_TIMEOUT);
	}

	public String getInfo() {
		StringBuilder builder = new StringBuilder();
		builder.append(getNameInfo());
		builder.append(getMacInfo());
		return builder.toString();
	}

	public NetAddress next() {
		if (hasNext()) {
			inc();
		}
		return this;
	}

	public boolean hasNext() {
		for (int i = mask; i < addrLen; ++i) {
			if (getBit(i) == 0) {
				return true;
			}
		}
		return false;
	}

	public NetAddress getBase() {
		NetAddress base = new NetAddress(address.clone(), mask);
		for (int i = mask; i < addrLen; ++i) {
			base.setBit(i, 0);
		}
		return base;
	}

	public byte[] getAddr() {
		return address;
	}

	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		boolean first = true;
		for (byte val : address) {
			if (!first) {
				builder.append(".");
			}
			builder.append(val >= 0 ? val : (val & 0x7F) + 128);
			first = false;
		}
		return builder.toString();
	}

	@Override
	protected NetAddress clone() throws CloneNotSupportedException {
		return new NetAddress(address.clone(), mask);
	}

	private void inc() {
		for (int i = addrLen - 1; i >= mask; --i) {
			if (getBit(i) == 0) {
				setBit(i, 1);
				return;
			} else {
				setBit(i, 0);
			}
		}
	}

	private int getBit(int i) {
		int element = i / 8;
		int bit = 7 - i % 8;
		return (address[element] & 1 << bit);
	}

	private void setBit(int i, int valToSet) {
		int element = i / 8;
		int bit = 7 - i % 8;
		int currVal = address[element];
		if (valToSet == 0) {
			valToSet = currVal & ((1 << bit) ^ 0xFF);
		} else {
			valToSet = currVal | 1 << bit;
		}
		address[element] = (byte) valToSet;
	}

	private String getNameInfo() {
		StringBuilder builder = new StringBuilder();
		builder.append("Searching for name info...\n");
		try {
			InetAddress inetAddress = InetAddress.getByAddress(address);
			builder.append(getInfoForCommand("nbtstat -a "
					+ inetAddress.getHostAddress()));
		} catch (UnknownHostException e) {
			builder.append("Address is unreachable\n");
		}
		return builder.toString();
	}

	private String getMacInfo() {
		StringBuilder builder = new StringBuilder();
		builder.append("Searching for MAC address...\n");
		try {
			InetAddress inetAddress = InetAddress.getByAddress(address);
			builder.append(getInfoForCommand(MessageFormat.format("arp -a {0}",
					inetAddress.getHostAddress())));
		} catch (UnknownHostException e) {
			builder.append("Address is unreachable\n");
		}
		return builder.toString();
	}

	private String getInfoForCommand(String command) {
		Runtime runtime = Runtime.getRuntime();
		StringBuilder builder = new StringBuilder();

		try {
			Process proc;
			proc = runtime.exec(command);
			int retVal = proc.waitFor();
			if (retVal == 0) {
				Scanner scanner = new Scanner(proc.getInputStream());
				while (scanner.hasNextLine()) {
					builder.append(scanner.nextLine());
				}
				builder.append("\n");
				scanner.close();
			}
		} catch (Exception e) {
			builder.append("Error!\n");
		}
		return builder.toString();
	}
}
