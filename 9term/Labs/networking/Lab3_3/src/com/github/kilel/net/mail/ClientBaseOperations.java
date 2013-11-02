package com.github.kilel.net.mail;

import java.io.Closeable;
import java.io.IOException;

public interface ClientBaseOperations extends Closeable {

    void connect() throws IOException;

    boolean login(String username, String password);

}
