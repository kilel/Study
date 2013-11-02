package com.github.kilel.net.mail.impl;

import java.io.IOException;

import com.github.kilel.net.mail.MailClient;
import com.github.kilel.net.mail.POPClient;
import com.github.kilel.net.mail.SMTPClient;

public class MailClientImpl implements MailClient {

    private POPClient popClient;
    private SMTPClient smtpClient;

    public MailClientImpl(POPClient popClient, SMTPClient smtpClient) {
        this.popClient = popClient;
        this.smtpClient = smtpClient;
    }

    public MailClientImpl(String server) {
        this.popClient = new POPClientImpl(server);
        this.smtpClient = new SMTPClientImpl(server);
    }

    public POPClient getPopClient() {
        return popClient;
    }

    public SMTPClient getSmtpClient() {
        return smtpClient;
    }

    @Override
    public void connect() throws IOException {
        popClient.connect();
        smtpClient.connect();
    }

    @Override
    public boolean login(String username, String password) {
        return popClient.login(username, password) //
                && smtpClient.login(username, password);
    }

    @Override
    public void close() throws IOException {
        popClient.close();
        smtpClient.close();
    }

}
