package com.github.kilel.net.chat;

import java.io.Closeable;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;

import com.github.kilel.net.chat.message.MessageTransferer;

public class Server implements Runnable, Closeable {

    private ServerSocket server;
    private Map<MessageTransferer, String> clients;

    private static void print(String source) {
        System.out.println(source);
    }

    public Server(int port) throws IOException {
        print("Starting server...");
        this.server = new ServerSocket(port);
        clients = new HashMap<>();
    }

    @Override
    public void run() {
        print("Server is online");
        while (true) {
            try {
                Socket target = server.accept();
                print("Accepted connection from: " + target.getInetAddress());
                Thread handler = new Thread(new ConnectionHandler(target, clients));
                handler.start();
            } catch (IOException e) {
                print("Server is offline");
                return;
            }

        }
    }

    @Override
    public void close() throws IOException {
        server.close();
    }
}
