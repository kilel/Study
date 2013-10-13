package com.github.kilel.mail.gui;

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

import com.github.kilel.mail.Client;
import com.github.kilel.mail.impl.POPClientImpl;
import com.github.kilel.mail.impl.SMTPClientImpl;

public class ConnectionDialog extends JDialog {

    private static final long serialVersionUID = -7662560242292775336L;
    private final JPanel contentPanel = new JPanel();
    private JPasswordField passwordField;
    private JFormattedTextField usernameField;
    private JFormattedTextField servernameField;

    private Client client;
    private JLabel logLabel;
    private JButton connectButton;

    public static void main(String[] args) {
        try {
            showDialog(null);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void createClient() {
        try {
            String serverName = servernameField.getText().trim();
            client = new Client(new POPClientImpl(serverName), new SMTPClientImpl());
            getContentPane().setEnabled(false);
            logLabel.setText("Connecting to " + serverName);
            client.getPopClient().connect();
            logLabel.setText("Connected");
            logLabel.setText("Logging in...");

            String userName = usernameField.getText().trim();
            String password = new String(passwordField.getPassword());

            if (client.getPopClient().login(userName, password)) {
                logLabel.setText("Ok");
            } else {
                logLabel.setText("Wrong username or password");
                client.getPopClient().close();
                client = null;
            }

            getContentPane().setEnabled(true);
        } catch (Exception e) {
            logLabel.setText("Error connecting to server");
            client = null;
        }
    }

    public Client getClient() {
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

    public static Client showDialog(JFrame frame) {
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
        usernameField.setColumns(30);
        sl_contentPanel.putConstraint(SpringLayout.NORTH, usernameField, 9, SpringLayout.SOUTH, lblNewLabel);
        sl_contentPanel.putConstraint(SpringLayout.WEST, usernameField, 10, SpringLayout.WEST, contentPanel);
        contentPanel.add(usernameField);

        JLabel lblNewLabel_1 = new JLabel("Password");
        sl_contentPanel.putConstraint(SpringLayout.NORTH, lblNewLabel_1, 12, SpringLayout.SOUTH, usernameField);
        sl_contentPanel.putConstraint(SpringLayout.WEST, lblNewLabel_1, 0, SpringLayout.WEST, lblNewLabel);
        contentPanel.add(lblNewLabel_1);

        passwordField = new JPasswordField();
        passwordField.setColumns(30);
        sl_contentPanel.putConstraint(SpringLayout.NORTH, passwordField, 6, SpringLayout.SOUTH, lblNewLabel_1);
        sl_contentPanel.putConstraint(SpringLayout.WEST, passwordField, 0, SpringLayout.WEST, lblNewLabel);
        contentPanel.add(passwordField);

        JLabel lblServer = new JLabel("Server");
        sl_contentPanel.putConstraint(SpringLayout.NORTH, lblServer, 35, SpringLayout.SOUTH, passwordField);
        sl_contentPanel.putConstraint(SpringLayout.WEST, lblServer, 0, SpringLayout.WEST, lblNewLabel);
        contentPanel.add(lblServer);

        servernameField = new JFormattedTextField();
        servernameField.setText("pop.yandex.ru");
        servernameField.setColumns(30);
        sl_contentPanel.putConstraint(SpringLayout.NORTH, servernameField, 6, SpringLayout.SOUTH, lblServer);
        sl_contentPanel.putConstraint(SpringLayout.WEST, servernameField, 0, SpringLayout.WEST, lblNewLabel);
        contentPanel.add(servernameField);

        logLabel = new JLabel("");
        sl_contentPanel.putConstraint(SpringLayout.NORTH, logLabel, 7, SpringLayout.SOUTH, servernameField);
        sl_contentPanel.putConstraint(SpringLayout.WEST, logLabel, 0, SpringLayout.WEST, lblNewLabel);
        contentPanel.add(logLabel);
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
