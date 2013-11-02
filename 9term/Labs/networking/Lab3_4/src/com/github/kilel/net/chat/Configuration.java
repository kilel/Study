package com.github.kilel.net.chat;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Properties;

public class Configuration {
    private static final String CONFIG_PATH = "chat.cfg";

    private Properties properties;

    private String server;
    private int port;

    public Configuration() throws IOException {
        File config = new File(CONFIG_PATH);
        if (!config.exists()) {
            try {
                config.createNewFile();
                FileWriter writer = new FileWriter(config);
                writer.append("port=12723\n");
                writer.append("server=localhost\n");
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        properties = new Properties();
        properties.load(new FileInputStream(config));
        server = properties.getProperty("server");
        port = new Integer(properties.getProperty("port"));
    }

    public String getServer() {
        return server;
    }

    public int getPort() {
        return port;
    }

}
