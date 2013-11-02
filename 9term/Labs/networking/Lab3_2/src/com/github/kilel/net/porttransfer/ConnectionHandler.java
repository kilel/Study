package com.github.kilel.net.porttransfer;

import static com.github.kilel.net.porttransfer.PortTransfer.print;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.Socket;

public class ConnectionHandler implements Runnable {
    private Socket inputSocket;
    private Socket outputSocket;
    private InetSocketAddress target;
    private static final int BUFFER_LENGTH = 4196;

    private Thread readThread, writeThread;

    public ConnectionHandler(Socket inputSocket, InetSocketAddress out) throws IOException {
        this.inputSocket = inputSocket;
        target = out;
    }

    @Override
    public void run() {
        print("Handled connection: " + inputSocket + " to " + outputSocket);

        try {
            print("Opening target socket: " + target);
            outputSocket = new Socket(target.getAddress(), target.getPort());
            readThread.start();
            writeThread.start();
            synchronized (readThread) {
                readThread.wait();
                synchronized (writeThread) {
                    writeThread.wait();
                    inputSocket.close();
                    outputSocket.close();
                }
            }
        } catch (IOException e1) {
            print("Can't open socket: " + target);
            e1.printStackTrace();
            return;
        } catch (InterruptedException e) {
            print("Error closing sockets in interconnection: " + inputSocket + " => " + outputSocket);
        }
        print("Closed connection: " + inputSocket + " to " + outputSocket);
    }

    private void transfer(Socket input, Socket output) {
        try {
            print("Started transfer from " + input + " to " + output);
            InputStream in = input.getInputStream();
            OutputStream out = output.getOutputStream();

            byte[] buffer = new byte[BUFFER_LENGTH];
            int readed = 0;

            while ((readed = in.read(buffer, 0, BUFFER_LENGTH)) >= 0) {
                print("Writing " + readed + " bytes from " + input + " to " + output);
                out.write(buffer, 0, readed);
            }
            print("Closed transfer from " + input + " to " + output);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    {
        readThread = new Thread(new Runnable() {
            @Override
            public void run() {
                transfer(inputSocket, outputSocket);
                synchronized (readThread) {
                    readThread.notifyAll();
                }
            }
        });

        writeThread = new Thread(new Runnable() {
            @Override
            public void run() {
                transfer(outputSocket, inputSocket);
                synchronized (writeThread) {
                    writeThread.notifyAll();
                }
            }
        });
    }

}
