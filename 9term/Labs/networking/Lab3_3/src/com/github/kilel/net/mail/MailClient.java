package com.github.kilel.net.mail;

public interface MailClient extends ClientBaseOperations {

    public POPClient getPopClient();

    public SMTPClient getSmtpClient();
}
