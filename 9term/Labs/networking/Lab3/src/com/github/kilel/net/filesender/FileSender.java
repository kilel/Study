package com.github.kilel.net.filesender;

import java.io.File;
import java.io.IOException;
import java.net.InetAddress;

public class FileSender {

    public static void main(String[] args) throws IOException {
        Runnable toRun;
        if (args.length > 0) {
            if (args[0].equals("client") && args.length > 2) {
                toRun = new Client(new File(args[2]), InetAddress.getByName(args[1]));

            } else if (args[0].equals("server")) {
                toRun = new Server();
            } else {
                System.out.println("Invalid parameters");
                return;
            }
            toRun.run();
        } else {
            System.out.println("Run parameters:\n\tserver to start as server;\n\t"
                    + "client address fileName (to send file to server)");
            return;
        }

    }

}
