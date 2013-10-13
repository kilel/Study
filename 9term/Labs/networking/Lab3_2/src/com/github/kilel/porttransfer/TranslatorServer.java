package com.github.kilel.porttransfer;

import static com.github.kilel.porttransfer.PortTransfer.print;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class TranslatorServer implements Runnable {
    private ServerSocket server;
    private boolean isRunning = false;
    private boolean isRunningInternal = false;
    private Thread serverThread;
    private InetSocketAddress target;
    private int port;

    public TranslatorServer(int port, InetSocketAddress toWho) throws IOException {
        this.port = port;
        this.target = toWho;
    }

    boolean isRunning() {
        return isRunning;
    }

    public void start() {
        if (!isRunning) {
            isRunning = true;
            if (!isRunningInternal) {
                serverThread = new Thread(this);
                serverThread.start();
                print("Started serving port: " + port + " => " + target);
            }
        }
    }

    public void stop() {
        if (isRunning) {
            isRunning = false;
            if (!server.isClosed()) {
                try {
                    server.close();
                } catch (IOException e) {
                }
            }
            if (isRunningInternal) {
                serverThread.interrupt();
                print("Unregistering rule from port: " + port);
            }
        }
    }

    public void deregister(InetSocketAddress newTarget) {
        if (!newTarget.getHostString().equals(target.getHostString()) || target.isUnresolved()
                || newTarget.getPort() != target.getPort()) {

            stop();
            synchronized (target) {
                try {
                    target.wait(); // block while server is not closed really.
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                target = newTarget;
            }

        }

    }

    @Override
    public void run() {
        try {
            server = new ServerSocket(port);
        } catch (IOException e1) {
            e1.printStackTrace();
            isRunning = false;
            return;
        }
        isRunningInternal = true;

        while (true) {
            if (!serverThread.isInterrupted()) {
                try {
                    if (!server.isClosed()) {
                        Socket inSocket = server.accept();
                        ConnectionHandler handler = new ConnectionHandler(inSocket, target);
                        Thread connection = new Thread(handler);
                        connection.run();
                    }
                } catch (IOException e) {
                    print("Interrupted connection: " + port + " => " + target);
                }
            }
            if (!isRunning) {
                isRunningInternal = false;
                synchronized (target) { // notify, that closed
                    target.notifyAll();
                }
                return;
            }
        }

    }
}
