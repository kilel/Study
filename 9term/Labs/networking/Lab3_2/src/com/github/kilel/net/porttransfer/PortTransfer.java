package com.github.kilel.net.porttransfer;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.util.HashMap;
import java.util.Map;

public class PortTransfer implements Runnable {
    private Map<Integer, TranslatorServer> servers;
    private Configuration config;

    public static void print(String s) {
        System.out.println(s);
    }

    public PortTransfer() throws IOException {
        servers = new HashMap<Integer, TranslatorServer>();
        config = new Configuration();
    }

    public static void main(String[] args) throws IOException {
        print("Starting port forwarding server");
        PortTransfer core = new PortTransfer();
        Thread coreThread = new Thread(core);
        coreThread.run();

        while (System.in.read() != 10) {
            System.out.println("Press enter to exit");
        }
        print("Closing port forwarding server");
    }

    public void updateServers() {
        for (int port : servers.keySet()) {
            if (!config.getAcceptedPorts().contains(port)) {
                config.getAcceptedPorts().remove(port);
                servers.get(port).stop();
            }
        }
        for (int port : config.getAcceptedPorts()) {
            if (!servers.containsKey(port)) {
                try {
                    InetSocketAddress toWho = config.getTranslation(port);
                    TranslatorServer server = new TranslatorServer(port, toWho);
                    servers.put(port, server);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (servers.containsKey(port)) {
                servers.get(port).deregister(config.getTranslation(port));
                servers.get(port).start();
            }
        }
    }

    @Override
    public void run() {

        while (true) {
            try {
                config.updateConfig();
                updateServers();
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                return;
            }
        }

    }
}
