package com.github.kilel.net.mail.gui;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFormattedTextField;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.SpringLayout;
import javax.swing.border.EmptyBorder;

import com.github.kilel.net.mail.SMTPClient;

public class SendMessageDialog extends JDialog {

    private static final long serialVersionUID = 8990863795280926011L;
    private final JPanel contentPanel = new JPanel();
    private JTextArea messageField;
    private JFormattedTextField fromField;
    private JButton okButton;

    private final SMTPClient client;
    private JFormattedTextField toField;
    private JFormattedTextField subjectField;

    static public void open(SMTPClient client) {
        SendMessageDialog dialog = new SendMessageDialog(client);
        dialog.setVisible(true);
    }

    public SendMessageDialog(SMTPClient client) {
        initialize();
        this.client = client;
    }

    private void send() {
        String from = fromField.getText().trim();
        String to = toField.getText().trim();
        String subj = subjectField.getText().trim();
        String data = messageField.getText().trim();
        if (client.sendMessage(from, to, subj, data)) {
            dispose();
        } else {
            setTitle("Error sending message, check data");
        }
    }

    private void initialize() {
        setTitle("Send message");
        setBounds(100, 100, 547, 412);
        getContentPane().setLayout(new BorderLayout());
        contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
        getContentPane().add(contentPanel, BorderLayout.CENTER);
        SpringLayout sl_contentPanel = new SpringLayout();
        contentPanel.setLayout(sl_contentPanel);

        JLabel lblFrom = new JLabel("From");
        sl_contentPanel.putConstraint(SpringLayout.NORTH, lblFrom, 10, SpringLayout.NORTH, contentPanel);
        sl_contentPanel.putConstraint(SpringLayout.WEST, lblFrom, 10, SpringLayout.WEST, contentPanel);
        contentPanel.add(lblFrom);

        fromField = new JFormattedTextField();
        sl_contentPanel.putConstraint(SpringLayout.NORTH, fromField, 6, SpringLayout.SOUTH, lblFrom);
        sl_contentPanel.putConstraint(SpringLayout.WEST, fromField, 10, SpringLayout.WEST, contentPanel);
        sl_contentPanel.putConstraint(SpringLayout.EAST, fromField, -10, SpringLayout.EAST, contentPanel);
        fromField.setColumns(50);
        contentPanel.add(fromField);

        JLabel lblTo = new JLabel("To");
        sl_contentPanel.putConstraint(SpringLayout.NORTH, lblTo, 6, SpringLayout.SOUTH, fromField);
        sl_contentPanel.putConstraint(SpringLayout.WEST, lblTo, 0, SpringLayout.WEST, lblFrom);
        contentPanel.add(lblTo);

        toField = new JFormattedTextField();
        sl_contentPanel.putConstraint(SpringLayout.NORTH, toField, 6, SpringLayout.SOUTH, lblTo);
        sl_contentPanel.putConstraint(SpringLayout.WEST, toField, 0, SpringLayout.WEST, lblFrom);
        sl_contentPanel.putConstraint(SpringLayout.EAST, toField, -10, SpringLayout.EAST, contentPanel);
        contentPanel.add(toField);

        JLabel lblSubject = new JLabel("Subject");
        sl_contentPanel.putConstraint(SpringLayout.NORTH, lblSubject, 6, SpringLayout.SOUTH, toField);
        sl_contentPanel.putConstraint(SpringLayout.WEST, lblSubject, 0, SpringLayout.WEST, lblFrom);
        contentPanel.add(lblSubject);

        subjectField = new JFormattedTextField();
        sl_contentPanel.putConstraint(SpringLayout.EAST, subjectField, -10, SpringLayout.EAST, contentPanel);
        sl_contentPanel.putConstraint(SpringLayout.NORTH, subjectField, 6, SpringLayout.SOUTH, lblSubject);
        sl_contentPanel.putConstraint(SpringLayout.WEST, subjectField, 0, SpringLayout.WEST, lblFrom);
        contentPanel.add(subjectField);

        JLabel lblMessage = new JLabel("Message");
        sl_contentPanel.putConstraint(SpringLayout.NORTH, lblMessage, 6, SpringLayout.SOUTH, subjectField);
        sl_contentPanel.putConstraint(SpringLayout.WEST, lblMessage, 0, SpringLayout.WEST, lblFrom);
        contentPanel.add(lblMessage);

        JScrollPane scrollPane = new JScrollPane();
        sl_contentPanel.putConstraint(SpringLayout.NORTH, scrollPane, 6, SpringLayout.SOUTH, lblMessage);
        sl_contentPanel.putConstraint(SpringLayout.SOUTH, scrollPane, 0, SpringLayout.SOUTH, contentPanel);
        sl_contentPanel.putConstraint(SpringLayout.WEST, scrollPane, 10, SpringLayout.WEST, contentPanel);
        sl_contentPanel.putConstraint(SpringLayout.EAST, scrollPane, -10, SpringLayout.EAST, contentPanel);
        contentPanel.add(scrollPane);

        messageField = new JTextArea();
        scrollPane.setViewportView(messageField);
        {
            JPanel buttonPane = new JPanel();
            buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
            getContentPane().add(buttonPane, BorderLayout.SOUTH);
            {
                okButton = new JButton("Send");
                okButton.addActionListener(new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        send();
                    }
                });
                okButton.setActionCommand("OK");
                buttonPane.add(okButton);
                getRootPane().setDefaultButton(okButton);
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
    }

}
