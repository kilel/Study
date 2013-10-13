package com.github.kilel.porttransfer;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;
import java.util.Set;

public class Configuration {
    private Map<Integer, InetSocketAddress> portToAddress;
    private File configFile;
    private final static String CONFIG_NAME = "PT.cfg";
    private static final String CONFIG_DIVIDOR = ",";

    public Configuration() throws IOException {
        portToAddress = new HashMap<Integer, InetSocketAddress>();
        configFile = new File(CONFIG_NAME);
        if (!configFile.exists()) {
            configFile.createNewFile();
        }
    }

    public void initialize() throws IOException {
        if (!configFile.exists()) {
            configFile.createNewFile();
        }
    }

    public void updateConfig() throws IOException {
        initialize();
        Map<Integer, InetSocketAddress> tempConfig = new HashMap<Integer, InetSocketAddress>();
        FileInputStream in = new FileInputStream(configFile);
        Properties prop = new Properties();
        prop.load(in);
        in.close();

        for (Object key : prop.keySet()) {
            try {
                Integer port = new Integer(key.toString());
                String[] val = prop.get(key).toString().split(CONFIG_DIVIDOR);
                if (val.length < 2) {
                    throw new IOException("Invalid config line" + prop.get(key));
                }
                InetAddress address = InetAddress.getByName(val[0]);
                int toPort = new Integer(val[1]);

                tempConfig.put(port, new InetSocketAddress(address, toPort));
            } catch (Exception e) {
                // e.printStackTrace();
            }
        }
        Map<Integer, InetSocketAddress> temp = portToAddress;
        portToAddress = tempConfig;
        temp.clear();
        System.gc();
    }

    public Set<Integer> getAcceptedPorts() {
        return portToAddress.keySet();
    }

    public InetSocketAddress getTranslation(int port) {
        if (portToAddress.containsKey(port)) {
            return portToAddress.get(port);
        } else {
            return null;
        }
    }

}
