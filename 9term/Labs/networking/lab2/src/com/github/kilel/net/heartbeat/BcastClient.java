package com.github.kilel.net.heartbeat;

import static com.github.kilel.net.heartbeat.HeartBeat.print;

import java.io.Closeable;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;

public class BcastClient implements Runnable, Closeable {
    private static final int BCAST_DELAY = 1000;

    private DatagramSocket socket;
    private InetSocketAddress bcastAddress;

    private boolean isRunning = false;

    public BcastClient(DatagramSocket socket, InetSocketAddress address) {
        this.socket = socket;
        this.bcastAddress = address;
    }

    @Override
    public void run() {
        isRunning = true;
        while (true) {
            try {
                if (isRunning) {
                    sendData("alive");
                } else {
                    close();
                    return;
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                Thread.sleep(BCAST_DELAY);
            } catch (InterruptedException e) {
                isRunning = false;
            }
        }
    }

    private void sendData(String value) throws IOException {
        print("Broadcasting data:" + value);
        byte[] data = value.getBytes("UTF-8");
        DatagramPacket packet = new DatagramPacket(data, data.length);
        packet.setSocketAddress(bcastAddress);
        synchronized (socket) {
            socket.send(packet);
        }
    }

    @Override
    public void close() throws IOException {
        print("Closing client thread");
        sendData("dead");
    }

}
