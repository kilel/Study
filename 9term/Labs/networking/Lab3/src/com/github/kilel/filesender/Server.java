package com.github.kilel.filesender;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server implements Runnable {
    public static final int PORT = 21578;
    private ServerSocket server;

    public Server() throws IOException {
        System.out.println("Server started");
        server = new ServerSocket(PORT);
    }

    @Override
    public void run() {
        Socket socket;
        while (true) {
            try {
                socket = server.accept();
                Thread handler = new Thread(new ConnectionHandler(socket));
                handler.start();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}
