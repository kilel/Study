package com.github.kilel.mail;

import java.io.Closeable;
import java.io.IOException;

public interface POPClient extends Closeable {

    void connect() throws IOException;

    boolean login(String username, String password);

    String[] getMessages();

    void deleteMessage(int index);

    void save();

    void refresh() throws IOException;

}
