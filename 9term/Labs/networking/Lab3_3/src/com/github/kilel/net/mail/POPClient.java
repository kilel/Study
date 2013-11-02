package com.github.kilel.net.mail;

import java.io.IOException;

public interface POPClient extends ClientBaseOperations {

    String[] getMessages();

    void deleteMessage(int index);

    void save();

    void refresh() throws IOException;

}
