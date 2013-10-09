package com.github.kilel.heartbeat;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.text.MessageFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class HeartBeat implements Runnable {
	private static final int BCAST_DELAY = 500;
	private static final int SCAN_DELAY = 100;
	private static final int WRITE_LIVE_DELAY = 2000;

	private int port;
	private String mcAddress;
	// private MulticastSocket socket;
	private DatagramSocket socket;
	private Map<String, Date> lastAccessDate;

	private Thread bcastThread;
	private Thread readingThread;
	private Thread writingLiveThread;

	{
		bcastThread = new Thread(new Runnable() {
			@Override
			public void run() {
				while (true) {
					try {
						bcastData("alive");
					} catch (IOException e) {
						e.printStackTrace();
					}
					try {
						Thread.sleep(BCAST_DELAY);
					} catch (InterruptedException e) {
						print("Closing broadcast thread");
						return;
					}
				}
			}
		});

		readingThread = new Thread(new Runnable() {
			@Override
			public void run() {
				while (true) {
					try {
						getMessage();
					} catch (IOException e) {
					}
					try {
						Thread.sleep(SCAN_DELAY);
					} catch (InterruptedException e) {
						print("Closing reading thread");
						return;
					}
				}
			}
		});

		writingLiveThread = new Thread(new Runnable() {
			@Override
			public void run() {
				while (true) {
					printAlive();
					try {
						Thread.sleep(WRITE_LIVE_DELAY);
					} catch (InterruptedException e) {
						print("Closing write-live thread");
						return;
					}
				}
			}
		});
	}

	private static void print(String s) {
		System.out.println(s);
	}

	public HeartBeat(String address, int port) {
		this.port = port;
		this.mcAddress = address;
		lastAccessDate = new HashMap<String, Date>();
	}

	public static void main(String[] args) throws IOException {
		assert (args.length > 1);

		String bcastAddr = args[0];
		int bcastPort = new Integer(args[1]);
		HeartBeat heartBeat = new HeartBeat(bcastAddr, bcastPort);
		Thread main = new Thread(heartBeat);
		main.start();

		int readed = System.in.read();
		while (readed != 10) {
			readed = System.in.read();
		}
		heartBeat.close();
		main.interrupt();
	}

	@Override
	public void run() {
		try {
			socket = new DatagramSocket(port);
			socket.setBroadcast(true);
			socket.setSoTimeout(100);

			bcastThread.start();
			readingThread.start();
			writingLiveThread.start();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void bcastData(String value) throws IOException {
		byte[] data = value.getBytes("UTF-8");
		DatagramPacket packet = new DatagramPacket(data, data.length);
		packet.setAddress(InetAddress.getByName(mcAddress));
		packet.setPort(port);
		synchronized (this) {
			socket.send(packet);
		}
	}

	private void getMessage() throws IOException {
		byte[] data = new byte[256];
		DatagramPacket packet = new DatagramPacket(data, data.length);
		synchronized (this) {
			socket.receive(packet);
		}
		InetSocketAddress address = (InetSocketAddress) packet
				.getSocketAddress();
		String status = new String(packet.getData(), "UTF-8").substring(0,
				packet.getLength());

		print(MessageFormat.format("Recieved answer from {0} -- Status: {1}",
				address, status));
		if (status.equalsIgnoreCase("alive")) {
			lastAccessDate.put(address.getAddress().getHostAddress(),
					new Date());
		} else {
			lastAccessDate.put(address.getAddress().getHostAddress(), new Date(
					0));
		}
	}

	private void printAlive() {
		Date curr = new Date();
		StringBuilder builder = new StringBuilder();
		builder.append("Alive:\n");
		for (String key : lastAccessDate.keySet()) {
			Date temp = lastAccessDate.get(key);
			if (temp.getTime() + 5000 > curr.getTime()) {
				builder.append("\t");
				builder.append(key);
				builder.append("\n");
			}
		}
		print(builder.toString());
	}

	public void close() throws IOException {
		print("Closing HeartBeat");
		readingThread.interrupt();
		writingLiveThread.interrupt();
		bcastThread.interrupt();

		bcastData("dead");

		socket.disconnect();
		socket.close();
	}

}
