package com.github.kilel.filesender;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;

public class Client implements Runnable {

    private File file;
    private String filename;
    private InetAddress server;

    public Client(File file, InetAddress server) {
        this.server = server;
        this.file = file;
        if (!file.exists()) {
            System.out.println("File is not exists can't send");
            throw new RuntimeException();
        }
        String[] pathToFile = file.getPath().split(File.pathSeparator);
        filename = pathToFile[pathToFile.length - 1];
    }

    @Override
    public void run() {
        System.out.println("Sendind file [" + filename + "] to " + server);

        try {
            Socket socket = new Socket(server, Server.PORT);

            final int bufferLen = 1024;
            byte[] buffer = new byte[1024];

            OutputStream out = socket.getOutputStream();
            FileInputStream in = new FileInputStream(file);

            // send file name
            byte[] nameBuffer = filename.getBytes("UTF-8");
            for (int i = 0; i < bufferLen; ++i) {
                if (i < nameBuffer.length) {
                    buffer[i] = nameBuffer[i];
                } else {
                    buffer[i] = 0;
                }
            }

            out.write(buffer, 0, bufferLen);

            // send file data
            int readed = 0;
            while ((readed = in.read(buffer, 0, bufferLen)) >= 0) {
                out.write(buffer, 0, readed);
            }

            in.close();
            System.out.println("Successfully sended");
            socket.close();
        } catch (IOException e) {
            System.out.println("Can't send message");
            e.printStackTrace();
        }
    }
}
