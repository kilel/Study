package com.github.kilel.net.mail.impl;

import java.io.Closeable;
import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.Socket;

public class SocketWorker implements Closeable {
    private static final int SOCKET_TIMEOUT = 1000;
    private Socket socket;

    public static void print(String source) {
        System.out.println(source);
    }

    public SocketWorker(InetSocketAddress address) throws IOException {
        socket = new Socket();
        socket.setSoTimeout(SOCKET_TIMEOUT);
        socket.connect(address, SOCKET_TIMEOUT);
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

    public String getResponse() throws IOException {
        return getResponse(-1);
    }

    public String getResponse(int length) throws IOException {

        boolean isUnregulated = length < 0;
        final int buffLen = 4000;
        byte[] buffer = new byte[buffLen];
        int readed = 0;

        StringBuilder builder = new StringBuilder();
        socket.setSoLinger(false, 0);
        while ((readed = socket.getInputStream().read(buffer, 0, buffLen)) > 0) {
            builder.append(new String(buffer, 0, readed, "UTF-8"));
            length -= readed;
            if ((!isUnregulated && length <= 0) || (isUnregulated && readed < buffLen)) {
                print("Response readed");
                break;
            }
        }
        return builder.toString();
    }

    @Override
    public void close() throws IOException {
        socket.close();
    }

}
