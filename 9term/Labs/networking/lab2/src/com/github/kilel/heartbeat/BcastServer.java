package com.github.kilel.heartbeat;

import static com.github.kilel.heartbeat.HeartBeat.print;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;
import java.text.MessageFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class BcastServer implements Runnable {
    private static final int SCAN_DELAY = 100;

    private DatagramSocket socket;
    private Map<String, Date> lastAccessDate;
    private Thread writingLiveThread;

    public BcastServer(DatagramSocket socket) {
        this.socket = socket;
        lastAccessDate = new HashMap<String, Date>();
        writingLiveThread = new Thread(new LiveClientsWriter(lastAccessDate));
    }

    @Override
    public void run() {
        writingLiveThread.start();
        while (true) {
            try {
                getMessage();
            } catch (IOException e) {
            }
            try {
                Thread.sleep(SCAN_DELAY);
            } catch (InterruptedException e) {
                print("Closing server thread");
                writingLiveThread.interrupt();
                return;
            }
        }
    }

    private void getMessage() throws IOException {
        byte[] data = new byte[256];
        DatagramPacket packet = new DatagramPacket(data, data.length);
        synchronized (socket) {
            socket.receive(packet);
        }
        InetSocketAddress address = (InetSocketAddress) packet.getSocketAddress();
        String status = new String(packet.getData(), "UTF-8").substring(0, packet.getLength());

        print(MessageFormat.format("Recieved answer from {0} -- Status: {1}", address, status));
        if (status.equalsIgnoreCase("alive")) {
            lastAccessDate.put(address.getAddress().getHostAddress(), new Date());
        } else if (status.equalsIgnoreCase("dead")) {
            lastAccessDate.put(address.getAddress().getHostAddress(), new Date(0));
        }
    }

}
