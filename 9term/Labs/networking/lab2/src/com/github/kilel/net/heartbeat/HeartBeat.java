package com.github.kilel.net.heartbeat;

import java.io.IOException;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;

public class HeartBeat implements Runnable {

    private InetSocketAddress bcastAddress;

    private DatagramSocket socket;

    private Thread clientThread;
    private Thread serverThread;

    public static void print(String s) {
        System.out.println(s);
    }

    public HeartBeat(String address, int port) {
        bcastAddress = new InetSocketAddress(address, port);
    }

    public static void main(String[] args) throws IOException {
        assert (args.length > 1);

        String bcastAddr = args[0];
        int bcastPort = new Integer(args[1]);
        HeartBeat heartBeat = new HeartBeat(bcastAddr, bcastPort);
        Thread main = new Thread(heartBeat);
        main.start();

        while (System.in.read() != 10) {
            ;
        }

        heartBeat.close();
        main.interrupt();
    }

    @Override
    public void run() {
        try {
            socket = new DatagramSocket(bcastAddress.getPort());
            socket.setBroadcast(true);
            socket.setSoTimeout(100);

            clientThread = new Thread(new BcastClient(socket, bcastAddress));
            serverThread = new Thread(new BcastServer(socket));

            clientThread.start();
            serverThread.start();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void close() throws IOException {
        print("Closing HeartBeat");
        clientThread.interrupt();
        serverThread.interrupt();
    }

}
