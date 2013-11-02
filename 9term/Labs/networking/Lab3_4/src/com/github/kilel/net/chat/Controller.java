package com.github.kilel.net.chat;

import java.awt.EventQueue;
import java.io.IOException;

import com.github.kilel.net.chat.gui.Chat;

public class Controller {

    private Configuration configuration;

    private static void print(String source) {
        System.out.println(source);
    }

    private static void printHelp() {
        print("Parameters:\n\t" + "Start as server: server\n\t" + "Connect to server: client login\n");
    }

    public static void main(String[] args) {
        Controller controller;
        try {
            controller = new Controller();
        } catch (IOException e1) {
            e1.printStackTrace();
            print("Can't read configuration");
            return;
        }

        if (args.length > 0) {
            if (args[0].equals("help")) {
                printHelp();
            } else if (args[0].equals("client") && args.length > 1) {
                try {
                    controller.startClient(args[1].trim());
                } catch (IOException e) {
                    print("Can't connect to server");
                    return;
                }
            } else if (args[0].equals("server")) {
                try {
                    controller.startServer();
                } catch (IOException e) {
                    print("Can't start server");
                    return;
                }
            }
        } else {
            printHelp();
        }

    }

    public Controller() throws IOException {
        configuration = new Configuration();
    }

    public void startServer() throws IOException {
        Server server = new Server(configuration.getPort());
        server.run();
        server.close();
    }

    public void startClient(String login) throws IOException {
        final Client client = new Client(configuration.getServer(), configuration.getPort());
        if (!client.connect(login)) {
            print("Login is registered, try other");
            client.close();
            return;
        }

        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    Chat window = new Chat(client);
                    window.open();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }
}
