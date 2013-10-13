package com.github.kilel.mail.impl;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import com.github.kilel.mail.POPClient;

public class POPClientImpl implements POPClient {
    private static final int DEFAULT_PORT = 110;
    private static final int SOCKET_TIMEOUT = 1000;

    final private String server;
    final private int port;

    private boolean isAPOPLoginAccepted = false;
    private String salt = "";

    private String login;
    private String password;

    private Socket socket;

    public static void print(String source) {
        System.out.println(source);
    }

    public POPClientImpl(String server) {
        this.server = server;
        port = DEFAULT_PORT;
    }

    public POPClientImpl(String server, int port) {
        this.server = server;
        this.port = port;
    }

    public void connect() throws IOException {
        print("Connecting to server...");
        socket = new Socket();
        socket.setSoTimeout(SOCKET_TIMEOUT);
        socket.connect(new InetSocketAddress(server, port), SOCKET_TIMEOUT);

        String response = getResponse();
        print(response);

        String[] resList = response.split(" ");
        if (resList.length == 5) {
            isAPOPLoginAccepted = true;
            salt = resList[4].trim();
            print("Secured login is acceptable with salt = " + salt);
        }
    }

    public void refresh() throws IOException {
        close();
        connect();
        login(login, password);
    }

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
        String response = sendData("USER " + username.trim());
        loginResult = loginResult && isSuccessfull(response);
        if (loginResult) {
            response = sendData("PASS " + password.trim());
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
            print(comand);

            if (!isSuccessfull(sendData(comand))) {
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

    public String[] getMessages() {
        String response = sendData("STAT");
        int numMessages = 0;
        if (isSuccessfull(response)) {
            numMessages = new Integer(response.split(" ")[1]);
        }

        String[] result = new String[numMessages];
        for (int i = 0; i < numMessages; ++i) {
            int length = new Integer(sendData("LIST " + (i + 1)).trim().split(" ")[2]);
            result[i] = sendData("RETR " + (i + 1), length);
        }
        return result;
    }

    public void deleteMessage(int number) {
        sendData("DELE " + (number + 1));
    }

    public String sendData(String comand) {
        return sendData(comand, -1);
    }

    public String sendData(String comand, int length) {
        String response = "";
        comand = comand.trim() + "\n";
        byte[] buffer = comand.getBytes();
        final int buffLen = buffer.length;

        try {
            print("Sending request of class " + comand.substring(0, 4));
            socket.getOutputStream().write(buffer, 0, buffLen);
            response = getResponse(length);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return response;
    }

    @Override
    public void close() throws IOException {
        sendData("RSET");
        sendData("QUIT");
        socket.close();
    }

    public void save() {
        sendData("QUIT");
        try {
            refresh();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String getResponse() throws IOException {
        return getResponse(-1);
    }

    public String getResponse(int length) throws IOException {

        boolean isUnregulated = length < 0;
        final int buffLen = 1024;
        byte[] buffer = new byte[buffLen];
        int readed = 0;

        StringBuilder builder = new StringBuilder();

        while ((readed = socket.getInputStream().read(buffer, 0, buffLen)) >= 0) {
            builder.append(new String(buffer, 0, readed));
            length -= readed;
            if (length <= 0 || (isUnregulated && readed < buffLen)) {
                String isOk = isSuccessfull(builder.toString()) ? "successfull" : "failure";
                print("Response read: " + isOk);
                break;
            }
        }

        return builder.toString();
    }
}
