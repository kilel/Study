package com.github.kilel.net.chat.gui;

import java.awt.ComponentOrientation;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.SystemColor;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.InputEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.io.Closeable;
import java.io.IOException;

import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTextArea;
import javax.swing.KeyStroke;
import javax.swing.ScrollPaneConstants;
import javax.swing.SpringLayout;

import com.github.kilel.net.chat.Client;
import com.github.kilel.net.chat.message.Message;
import com.github.kilel.net.chat.message.MessageType;

public class Chat {

    private JFrame coreForm;
    private JTextArea textAreaInput;
    private JTextArea textAreaChat;
    private JList<String> userList;

    private DefaultListModel<String> users;
    private JMenuItem closeItem;

    private final Client client;

    public void open() {
        coreForm.setVisible(true);
    }

    /**
     * Create the application.
     */
    public Chat(final Client client) {
        initialize();
        this.client = client;
        (new Thread(new Runnable() {
            public void run() {

                while (true) {
                    try {
                        revieveMessage();
                    } catch (IOException e) {
                        System.out.println("Closing application");
                        disconnect();
                        return;
                    }
                }
            }
        })).start();
    }

    private void revieveMessage() throws IOException {
        Message message = client.waitForMessage();
        textAreaChat.append("\n" + message);
        if (message.getType() == MessageType.CONN) {
            users.addElement(message.getPayload());
        } else if (message.getType() == MessageType.DCNN) {
            users.removeElement(message.getPayload());
        }
    }

    private void sendMessage() {
        try {
            client.send(textAreaInput.getText().trim());
            textAreaInput.setText("");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void disconnect() {
        Closeable toClose = client;
        if (toClose == null) {
            return;
        }

        try {
            toClose.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        coreForm.dispose();
    }

    /**
     * Initialize the contents of the frame.
     */
    private void initialize() {
        coreForm = new JFrame();
        coreForm.setTitle("Simple chat");
        coreForm.setBounds(100, 100, 618, 443);
        coreForm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        SpringLayout springLayout = new SpringLayout();
        coreForm.getContentPane().setLayout(springLayout);

        JSplitPane splitPane = new JSplitPane();
        splitPane.setLastDividerLocation(50);
        splitPane.setContinuousLayout(true);
        springLayout.putConstraint(SpringLayout.NORTH, splitPane, 0, SpringLayout.NORTH, coreForm.getContentPane());
        springLayout.putConstraint(SpringLayout.WEST, splitPane, 0, SpringLayout.WEST, coreForm.getContentPane());
        springLayout.putConstraint(SpringLayout.SOUTH, splitPane, 0, SpringLayout.SOUTH, coreForm.getContentPane());
        springLayout.putConstraint(SpringLayout.EAST, splitPane, 0, SpringLayout.EAST, coreForm.getContentPane());
        coreForm.getContentPane().add(splitPane);

        JScrollPane scrollPane = new JScrollPane();
        scrollPane.setMinimumSize(new Dimension(120, 200));
        splitPane.setLeftComponent(scrollPane);

        userList = new JList<String>();
        users = new DefaultListModel<String>();
        userList.setModel(users);

        scrollPane.setViewportView(userList);

        JSplitPane splitPane_1 = new JSplitPane();
        splitPane_1.setMinimumSize(new Dimension(242, 300));
        splitPane_1.setContinuousLayout(true);
        splitPane_1.setOrientation(JSplitPane.VERTICAL_SPLIT);
        splitPane.setRightComponent(splitPane_1);

        JScrollPane scrollPane_1 = new JScrollPane();
        scrollPane_1.setMinimumSize(new Dimension(120, 80));
        splitPane_1.setRightComponent(scrollPane_1);

        textAreaInput = new JTextArea();
        textAreaInput.addKeyListener(new KeyAdapter() {
            @Override
            public void keyReleased(KeyEvent e) {
                if (e.isControlDown() && e.getKeyChar() == 10) {
                    sendMessage();
                }
            }
        });
        textAreaInput.setTabSize(2);
        textAreaInput.setLineWrap(true);
        scrollPane_1.setViewportView(textAreaInput);

        JScrollPane scrollPane_2 = new JScrollPane();
        scrollPane_2.setMinimumSize(new Dimension(120, 200));
        scrollPane_2.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        splitPane_1.setLeftComponent(scrollPane_2);

        textAreaChat = new JTextArea();
        textAreaChat.setBackground(SystemColor.controlHighlight);
        textAreaChat.setTabSize(2);
        textAreaChat.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
        textAreaChat.setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
        textAreaChat.setEditable(false);
        textAreaChat.setLineWrap(true);
        scrollPane_2.setViewportView(textAreaChat);
        splitPane_1.setDividerLocation(300);
        splitPane.setDividerLocation(120);

        JMenuBar menuBar = new JMenuBar();
        coreForm.setJMenuBar(menuBar);

        JMenu connectionMenu = new JMenu("Connection");
        menuBar.add(connectionMenu);

        closeItem = new JMenuItem("Close");
        closeItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                disconnect();
            }
        });
        closeItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_W, InputEvent.CTRL_MASK));
        connectionMenu.add(closeItem);
    }
}
