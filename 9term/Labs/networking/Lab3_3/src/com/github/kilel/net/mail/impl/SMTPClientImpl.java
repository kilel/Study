package com.github.kilel.net.mail.impl;

import java.io.IOException;
import java.net.InetSocketAddress;

import sun.misc.BASE64Encoder;

import com.github.kilel.net.mail.SMTPClient;

public class SMTPClientImpl implements SMTPClient {
    private static final int DEFAULT_PORT = 25;

    final private String server;
    final private int port;

    private SocketWorker worker;

    public static void print(String source) {
        System.out.println(source);
    }

    public SMTPClientImpl(String server, int port) {
        this.server = server;
        this.port = port;
    }

    public SMTPClientImpl(String server) {
        this(server, DEFAULT_PORT);
    }

    @Override
    public void connect() throws IOException {
        print("Connecting to SMTP server...");

        worker = new SocketWorker(new InetSocketAddress(server, port));
        String response = worker.getResponse();
        print(response);

        response = worker.sendData("EHLO ru");
        print(response);

    }

    @Override
    public boolean login(String username, String password) {
        BASE64Encoder encoder = new BASE64Encoder();
        final String authStepOk = "334";
        final String relogin = "503";
        final String authFullyOk = "235";

        String response = send("AUTH LOGIN");
        if (response.substring(0, 3).equals(relogin)) {
            // if already authenticated
            return true;
        } else if (!response.substring(0, 3).equals(authStepOk)) {
            return false;
        }

        response = send(encoder.encode(username.getBytes()));
        if (!response.substring(0, 3).equals(authStepOk)) {
            return false;
        }

        response = send(encoder.encode(password.getBytes()));
        if (!response.substring(0, 3).equals(authFullyOk)) {
            // on unsuccessful authentication
            return false;
        }

        return true;
    }

    @Override
    public boolean sendMessage(String from, String to, String subject, String data) {
        final String acceptedCode = "250";
        String response = send("MAIL FROM: <" + from + ">");
        if (!response.substring(0, 3).equals(acceptedCode)) {
            return false;
        }
        response = send("RCPT TO: <" + to + ">");
        if (!response.substring(0, 3).equals(acceptedCode)) {
            return false;
        }
        response = send("DATA");
        if (!response.substring(0, 3).equals("354")) {
            return false;
        }

        String headers = "From: " + from + "\nTo: " + to + "\nSubject: " + subject + "\n\n";

        response = send(headers + data + "\n\n.");
        if (!response.substring(0, 3).equals(acceptedCode)) {
            return false;
        }

        return true;

    }

    public String send(String data) {
        String response = worker.sendData(data);
        print(response);
        return response;
    }

    @Override
    public void close() throws IOException {
        String response = worker.sendData("QUIT");
        print(response);
    }

}
