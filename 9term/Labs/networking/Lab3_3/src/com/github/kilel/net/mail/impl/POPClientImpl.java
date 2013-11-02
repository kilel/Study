package com.github.kilel.net.mail.impl;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import com.github.kilel.net.mail.POPClient;

public class POPClientImpl implements POPClient {
    private static final int DEFAULT_PORT = 110;

    final private String server;
    final private int port;

    private boolean isAPOPLoginAccepted = false;
    private String salt = "";

    private String login;
    private String password;

    private SocketWorker worker;

    public static void print(String source) {
        System.out.println(source);
    }

    public POPClientImpl(String server, int port) {
        this.server = server;
        this.port = port;
    }

    public POPClientImpl(String server) {
        this(server, DEFAULT_PORT);
    }

    @Override
    public void connect() throws IOException {
        print("Connecting to POP server...");

        worker = new SocketWorker(new InetSocketAddress(server, port));

        String response = worker.getResponse();
        print(response);

        String[] resList = response.split(" ");
        if (resList.length == 5) {
            isAPOPLoginAccepted = true;
            salt = resList[4].trim();
            print("Secured login is acceptable with salt = " + salt);
        }
    }

    @Override
    public boolean login(String username, String password) {
        this.login = username;
        this.password = password;

        if (isAPOPLoginAccepted) {
            return loginSecured(username, password);
        } else {
            return loginSimple(username, password);
        }
    }

    private boolean loginSimple(String username, String password) {
        boolean loginResult = true;
        String response = send("USER " + username.trim());
        loginResult = loginResult && isSuccessfull(response);
        if (loginResult) {
            response = send("PASS " + password.trim());
            loginResult = loginResult && isSuccessfull(response);
        }
        return loginResult;
    }

    private boolean loginSecured(String username, String password) {
        try {
            MessageDigest md5 = MessageDigest.getInstance("MD5");
            byte[] hash = md5.digest((salt + password).getBytes());

            StringBuilder builder = new StringBuilder(2 * hash.length);
            for (byte b : hash) {
                builder.append(String.format("%02x", b & 0xff));
            }
            String digest = builder.toString();

            String comand = "APOP " + username.trim() + " " + digest;

            if (!isSuccessfull(send(comand))) {
                return loginSimple(username, password);
            }
            return true;
        } catch (NoSuchAlgorithmException e) {
            return false;
        }
    }

    private boolean isSuccessfull(String response) {
        if (response.charAt(0) != '+') {
            return false;
        }
        return true;
    }

    @Override
    public String[] getMessages() {
        String response = send("STAT");
        int numMessages = 0;
        if (isSuccessfull(response)) {
            numMessages = new Integer(response.split(" ")[1]);
        }

        String[] result = new String[numMessages];
        for (int i = 0; i < numMessages; ++i) {
            String messageLength = send("LIST " + (i + 1)).trim().split(" ")[2];
            //+OK len octets = len.len() + 12
            int length = new Integer(messageLength) + messageLength.length() + 12;
            result[i] = worker.sendData("RETR " + (i + 1), length);
        }
        return result;
    }

    @Override
    public void deleteMessage(int number) {
        send("DELE " + (number + 1));
    }

    @Override
    public void close() throws IOException {
        send("RSET");
        send("QUIT");
        worker.close();
    }

    private String send(String data) {
        String response = worker.sendData(data);
        print(response);
        return response;
    }

    @Override
    public void save() {
        send("QUIT");
        try {
            refresh();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void refresh() throws IOException {
        close();
        connect();
        login(login, password);
    }

}
