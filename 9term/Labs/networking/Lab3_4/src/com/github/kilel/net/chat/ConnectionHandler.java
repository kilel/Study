package com.github.kilel.net.chat;

import java.io.IOException;
import java.net.Socket;
import java.text.MessageFormat;
import java.util.Map;

import com.github.kilel.net.chat.message.Message;
import com.github.kilel.net.chat.message.MessageTransferer;
import com.github.kilel.net.chat.message.MessageType;

public class ConnectionHandler implements Runnable {
    private MessageTransferer transferer;
    private Map<MessageTransferer, String> clients;

    private String userId;

    public ConnectionHandler(Socket socket, Map<MessageTransferer, String> clients) {
        transferer = new MessageTransferer(socket);
        this.clients = clients;
    }

    private void print(String s) {
        System.out.println(s);
    }

    @Override
    public void run() {
        boolean first = true;
        Message message;
        while (true) {
            // wait for data
            if ((message = tryRead()) == null) {
                // if can't read, then close client
                try { // close silently
                    if (!first) {
                        clients.remove(transferer);
                        sendAll(MessageType.DCNN, userId);
                    }
                    transferer.close();
                } catch (IOException e1) {
                    ;
                }
                return;
            } else {
                if (first) {
                    first = false;
                    // save login
                    userId = message.getUserId().trim();
                    
                    //search for duplicating login
                    if(clients.values().contains(userId)) {
                        trySend(transferer, MessageType.CONN, "false");
                        return;
                    } else {
                        trySend(transferer, MessageType.CONN, "true");
                    }
                    //say him about other users
                    for(String user : clients.values()) {
                        trySend(transferer, MessageType.CONN, user);
                    }
                    // add client to map
                    clients.put(transferer, message.getPayload().trim());
                    print(MessageFormat.format("Connetted to chat as [{0}]", userId));
                }
                // say other clients, that you are online,
                // or resend message
                sendAll(message.getType(), message.getPayload());
            }

        }
        // if socket is closed, then send disconnect to all other.

    }

    private void sendAll(MessageType type, String payload) {
        for (MessageTransferer client : clients.keySet()) {
            trySend(client, type, payload);
        }
    }

    private void trySend(MessageTransferer transfer, MessageType type, String payload) {
        print(userId + " is sending message to " + clients.get(transfer) + " type = " + type);
        try {
            transfer.send(type, userId, payload);
        } catch (IOException e) {
            print(MessageFormat.format("Can't send message to {0}", clients.get(transfer)));
        }
    }

    private Message tryRead() {
        Message message = null;
        try {
            message = transferer.waitForMessage();
            print("Server readed message: " + message);
        } catch (IOException e) {
            print(MessageFormat.format("Can't read data from[{0}]. Will closed now.", clients.get(transferer)));
        }
        return message;
    }
}
