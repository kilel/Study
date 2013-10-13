package com.github.kilel.filesender;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

public class ConnectionHandler implements Runnable {

    private Socket client;

    public ConnectionHandler(Socket client) {
        this.client = client;
    }

    private void print(String s) {
        System.out.println(client.getInetAddress() + ": " + s);
    }

    @Override
    public void run() {
        final int bufferLen = 1024;
        byte[] buffer = new byte[1024];

        try {
            InputStream in = client.getInputStream();

            // read file name
            in.read(buffer, 0, bufferLen);
            String filename = "UNKNOWN";
            for (int i = 0; i < bufferLen; ++i) {
                if (buffer[i] == 0) {
                    filename = new String(buffer, 0, i, "UTF-8");
                    break;
                }
            }
            print("Recieved file: [" + filename + "] from " + client.getInetAddress());
            // Check, if file Exists
            File file = new File(filename);
            if (file.exists()) {
                print("File with this name exists...");
                for (int i = 0; i < 9999; ++i) {
                    file = new File(filename + " (copy " + i + ")");
                    if (!file.exists()) {
                        break;
                    }
                }
            }
            file.createNewFile();
            print("Writing to file " + file.getAbsolutePath());
            // write to file
            FileOutputStream out = new FileOutputStream(file);

            int readed = 0;
            while ((readed = in.read(buffer, 0, bufferLen)) >= 0) {
                out.write(buffer, 0, readed);
            }
            out.close();
            print("Successfully writed");

        } catch (IOException e) {
            System.out.println("Can't get file from " + client.getInetAddress());
            e.printStackTrace();
        }

    }
}
