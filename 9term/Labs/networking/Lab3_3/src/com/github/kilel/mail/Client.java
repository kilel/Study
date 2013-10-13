package com.github.kilel.mail;

public class Client {

    private POPClient popClient;
    private SMTPClient smtpClient;

    public Client(POPClient popClient, SMTPClient smtpClient) {
        this.popClient = popClient;
        this.smtpClient = smtpClient;
    }

    public POPClient getPopClient() {
        return popClient;
    }

    public SMTPClient getSmtpClient() {
        return smtpClient;
    }

}
