package com.github.kilel.net.chat;

import java.io.Closeable;
import java.io.IOException;
import java.net.InetSocketAddress;
import java.text.MessageFormat;

import com.github.kilel.net.chat.message.Message;
import com.github.kilel.net.chat.message.MessageTransferer;
import com.github.kilel.net.chat.message.MessageType;

public class Client implements Closeable {

    private InetSocketAddress server;
    private MessageTransferer transferer;

    private String userId;

    private static void print(String source) {
        System.out.println(source);
    }

    public Client(String address, int port) {
        this.server = new InetSocketAddress(address, port);
    }

    public boolean connect(String login) throws IOException {
        this.userId = login;
        print(MessageFormat.format("Connecting to server [{0}] as [{1}]", server, login));

        transferer = new MessageTransferer(server);
        transferer.send(MessageType.CONN, userId, userId);

        // false, if server is closed, or login is incorrect
        try {
            Message response = transferer.waitForMessage();
            return new Boolean(response.getPayload());
        } catch (IOException e) {
            print("Error connecting to server");
            return false;
        }

    }

    public boolean send(String payload) throws IOException {
        transferer.send(MessageType.MSSG, userId, payload);
        return transferer.isClosed();
    }

    public Message waitForMessage() throws IOException {
        return transferer.waitForMessage();
    }

    @Override
    public void close() throws IOException {
        transferer.close();
    }
}
