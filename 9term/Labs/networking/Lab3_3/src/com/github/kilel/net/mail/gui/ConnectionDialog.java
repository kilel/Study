package com.github.kilel.net.mail.gui;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFormattedTextField;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.SpringLayout;
import javax.swing.border.EmptyBorder;

import com.github.kilel.net.mail.impl.MailClientImpl;
import com.github.kilel.net.mail.impl.POPClientImpl;
import com.github.kilel.net.mail.impl.SMTPClientImpl;

public class ConnectionDialog extends JDialog {

    private static final long serialVersionUID = -7662560242292775336L;
    private final JPanel contentPanel = new JPanel();
    private JPasswordField passwordField;
    private JFormattedTextField usernameField;
    private JFormattedTextField pop3NameField;

    private MailClientImpl client;
    private JLabel logLabel;
    private JButton connectButton;
    private JFormattedTextField smtpPortField;
    private JFormattedTextField pop3PortField;
    private JFormattedTextField smtpNameField;

    public static void main(String[] args) {
        try {
            showDialog(null);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void createClient() {
        try {
            String pop3Server = pop3NameField.getText().trim();
            int pop3Port = new Integer(pop3PortField.getText().trim());
            String smtpServer = smtpNameField.getText().trim();
            int smtpPort = new Integer(smtpPortField.getText().trim());

            client = new MailClientImpl(new POPClientImpl(pop3Server, pop3Port),//
                    new SMTPClientImpl(smtpServer, smtpPort));
            getContentPane().setEnabled(false);
            logLabel.setText("Connecting to servers");
            client.connect();
            logLabel.setText("Connected");
            logLabel.setText("Logging in...");

            String userName = usernameField.getText().trim();
            String password = new String(passwordField.getPassword());

            if (client.login(userName, password)) {
                logLabel.setText("Ok");
            } else {
                logLabel.setText("Wrong username or password");
                client.close();
                client = null;
            }

            getContentPane().setEnabled(true);
        } catch (Exception e) {
            logLabel.setText("Error connecting to server");
            client = null;
        }
    }

    public MailClientImpl getClient() {
        return client;
    }

    private void clicked() {
        connectButton.setEnabled(false);
        createClient();
        connectButton.setEnabled(true);
        if (client != null) {
            this.dispose();
        }

    }

    public static MailClientImpl showDialog(JFrame frame) {
        ConnectionDialog dialog = new ConnectionDialog(frame);
        return dialog.getClient();
    }

    /**
     * Create the dialog.
     */
    public ConnectionDialog(JFrame frame) {
        super(frame, true);
        setTitle("Connection dialog");
        setBounds(100, 100, 450, 300);
        getContentPane().setLayout(new BorderLayout());
        contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
        getContentPane().add(contentPanel, BorderLayout.CENTER);
        SpringLayout sl_contentPanel = new SpringLayout();
        contentPanel.setLayout(sl_contentPanel);

        JLabel lblNewLabel = new JLabel("Username");
        sl_contentPanel.putConstraint(SpringLayout.NORTH, lblNewLabel, 10, SpringLayout.NORTH, contentPanel);
        sl_contentPanel.putConstraint(SpringLayout.WEST, lblNewLabel, 10, SpringLayout.WEST, contentPanel);
        contentPanel.add(lblNewLabel);

        usernameField = new JFormattedTextField();
        sl_contentPanel.putConstraint(SpringLayout.NORTH, usernameField, 6, SpringLayout.SOUTH, lblNewLabel);
        sl_contentPanel.putConstraint(SpringLayout.EAST, usernameField, -10, SpringLayout.EAST, contentPanel);
        usernameField.setColumns(30);
        sl_contentPanel.putConstraint(SpringLayout.WEST, usernameField, 10, SpringLayout.WEST, contentPanel);
        contentPanel.add(usernameField);

        JLabel lblNewLabel_1 = new JLabel("Password");
        sl_contentPanel.putConstraint(SpringLayout.NORTH, lblNewLabel_1, 6, SpringLayout.SOUTH, usernameField);
        sl_contentPanel.putConstraint(SpringLayout.WEST, lblNewLabel_1, 0, SpringLayout.WEST, lblNewLabel);
        contentPanel.add(lblNewLabel_1);

        passwordField = new JPasswordField();
        sl_contentPanel.putConstraint(SpringLayout.EAST, passwordField, -10, SpringLayout.EAST, contentPanel);
        passwordField.setColumns(30);
        sl_contentPanel.putConstraint(SpringLayout.NORTH, passwordField, 6, SpringLayout.SOUTH, lblNewLabel_1);
        sl_contentPanel.putConstraint(SpringLayout.WEST, passwordField, 0, SpringLayout.WEST, lblNewLabel);
        contentPanel.add(passwordField);

        JLabel lblServer = new JLabel("POP3 server");
        sl_contentPanel.putConstraint(SpringLayout.NORTH, lblServer, 6, SpringLayout.SOUTH, passwordField);
        sl_contentPanel.putConstraint(SpringLayout.WEST, lblServer, 0, SpringLayout.WEST, lblNewLabel);
        contentPanel.add(lblServer);

        pop3NameField = new JFormattedTextField();
        pop3NameField.setText("pop.yandex.ru");
        pop3NameField.setColumns(30);
        sl_contentPanel.putConstraint(SpringLayout.NORTH, pop3NameField, 6, SpringLayout.SOUTH, lblServer);
        sl_contentPanel.putConstraint(SpringLayout.WEST, pop3NameField, 0, SpringLayout.WEST, lblNewLabel);
        contentPanel.add(pop3NameField);

        logLabel = new JLabel("");
        sl_contentPanel.putConstraint(SpringLayout.WEST, logLabel, 0, SpringLayout.WEST, lblNewLabel);
        contentPanel.add(logLabel);

        JLabel lblPopPort = new JLabel("Port");
        sl_contentPanel.putConstraint(SpringLayout.WEST, lblPopPort, 207, SpringLayout.WEST, contentPanel);
        sl_contentPanel.putConstraint(SpringLayout.EAST, lblServer, -235, SpringLayout.EAST, lblPopPort);
        sl_contentPanel.putConstraint(SpringLayout.SOUTH, lblPopPort, 0, SpringLayout.SOUTH, lblServer);
        sl_contentPanel.putConstraint(SpringLayout.EAST, lblPopPort, -10, SpringLayout.EAST, contentPanel);
        contentPanel.add(lblPopPort);

        pop3PortField = new JFormattedTextField();
        sl_contentPanel.putConstraint(SpringLayout.WEST, pop3PortField, 207, SpringLayout.WEST, contentPanel);
        sl_contentPanel.putConstraint(SpringLayout.EAST, pop3NameField, -235, SpringLayout.EAST, pop3PortField);
        sl_contentPanel.putConstraint(SpringLayout.SOUTH, pop3PortField, 0, SpringLayout.SOUTH, pop3NameField);
        sl_contentPanel.putConstraint(SpringLayout.EAST, pop3PortField, -10, SpringLayout.EAST, contentPanel);
        pop3PortField.setText("110");
        pop3PortField.setColumns(30);
        contentPanel.add(pop3PortField);

        JLabel lblSmtpServer = new JLabel("SMTP server");
        sl_contentPanel.putConstraint(SpringLayout.NORTH, lblSmtpServer, 6, SpringLayout.SOUTH, pop3NameField);
        sl_contentPanel.putConstraint(SpringLayout.WEST, lblSmtpServer, 0, SpringLayout.WEST, lblNewLabel);
        contentPanel.add(lblSmtpServer);

        smtpNameField = new JFormattedTextField();
        sl_contentPanel.putConstraint(SpringLayout.NORTH, logLabel, 10, SpringLayout.SOUTH, smtpNameField);
        sl_contentPanel.putConstraint(SpringLayout.NORTH, smtpNameField, 6, SpringLayout.SOUTH, lblSmtpServer);
        sl_contentPanel.putConstraint(SpringLayout.WEST, smtpNameField, 0, SpringLayout.WEST, lblNewLabel);
        smtpNameField.setText("smtp.yandex.ru");
        smtpNameField.setColumns(30);
        contentPanel.add(smtpNameField);

        smtpPortField = new JFormattedTextField();
        sl_contentPanel.putConstraint(SpringLayout.NORTH, smtpPortField, 50, SpringLayout.SOUTH, lblPopPort);
        sl_contentPanel.putConstraint(SpringLayout.EAST, smtpNameField, -235, SpringLayout.EAST, smtpPortField);
        sl_contentPanel.putConstraint(SpringLayout.WEST, smtpPortField, 20, SpringLayout.EAST, smtpNameField);
        sl_contentPanel.putConstraint(SpringLayout.EAST, smtpPortField, -10, SpringLayout.EAST, contentPanel);
        smtpPortField.setText("25");
        smtpPortField.setColumns(30);
        contentPanel.add(smtpPortField);
        {
            JPanel buttonPane = new JPanel();
            buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
            getContentPane().add(buttonPane, BorderLayout.SOUTH);
            {
                connectButton = new JButton("Connect");
                connectButton.addActionListener(new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        clicked();
                    }
                });
                connectButton.setActionCommand("OK");
                buttonPane.add(connectButton);
                getRootPane().setDefaultButton(connectButton);
            }
            {
                JButton cancelButton = new JButton("Cancel");
                cancelButton.addActionListener(new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        dispose();
                    }
                });
                cancelButton.setActionCommand("Cancel");
                buttonPane.add(cancelButton);
            }
        }

        setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
        setVisible(true);
    }
}
