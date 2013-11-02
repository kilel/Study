package com.github.kilel.net.mail;

public interface SMTPClient extends ClientBaseOperations {

    boolean sendMessage(String from, String to, String subject, String data);
}
