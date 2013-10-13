package com.github.kilel.mail.gui;

import java.awt.Component;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPopupMenu;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTextArea;
import javax.swing.SpringLayout;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import com.github.kilel.mail.Client;
import javax.swing.KeyStroke;
import java.awt.event.KeyEvent;
import java.awt.event.InputEvent;

public class MailClient {

    private JFrame coreFrame;
    private JList<String> messagesList;
    private JMenuItem updateItem;
    private JMenuItem connectItem;
    private JMenuItem disconnectItem;

    private Client client;
    private JMenuItem saveChangesItem;

    private JScrollPane scrollPane;
    private JTextArea messageText;
    private JPopupMenu popupMenu;
    private JMenuItem deleteSelectedItem;

    private DefaultListModel<String> model;
    private int selectedElement = -1;
    private String[] messages;
    private Set<Integer> deletedMessages;
    private JMenuItem mntmNewMenuItem;

    /**
     * Launch the application.
     */
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    MailClient window = new MailClient();
                    window.coreFrame.setVisible(true);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    public MailClient() {
        initialize();
        model = new DefaultListModel<String>();
        messagesList.setModel(model);
        deletedMessages = new HashSet<Integer>();

        popupMenu = new JPopupMenu();
        addPopup(messagesList, popupMenu);

        deleteSelectedItem = new JMenuItem("Mark deleted");
        deleteSelectedItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_D, InputEvent.CTRL_MASK | InputEvent.SHIFT_MASK));
        deleteSelectedItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                markDeleted();
            }
        });
        popupMenu.add(deleteSelectedItem);

        mntmNewMenuItem = new JMenuItem("Unmark");
        mntmNewMenuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_A, InputEvent.CTRL_MASK | InputEvent.SHIFT_MASK));
        mntmNewMenuItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                unmarkDeleted();
            }
        });
        popupMenu.add(mntmNewMenuItem);
    }

    private void connect() {
        client = ConnectionDialog.showDialog(coreFrame);

        if (client != null) {
            update();
            connectItem.setEnabled(false);
            saveChangesItem.setEnabled(true);
            updateItem.setEnabled(true);
            disconnectItem.setEnabled(true);
        }
    }

    private void disconnect() {
        try {
            client.getPopClient().close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        connectItem.setEnabled(true);
        saveChangesItem.setEnabled(false);
        updateItem.setEnabled(false);
        disconnectItem.setEnabled(false);
    }

    private void save() {
        for (int key : deletedMessages) {
            client.getPopClient().deleteMessage(key);
        }
        client.getPopClient().save();
        update();
    }

    private void refresh() {
        try {
            client.getPopClient().refresh();
        } catch (IOException e) {
            e.printStackTrace();
        }
        update();
    }

    private void update() {
        messages = client.getPopClient().getMessages();

        deletedMessages.clear();
        model.removeAllElements();
        for (String message : messages) {
            model.addElement(message);
        }
    }

    private void markDeleted() {
        if (!deletedMessages.contains(selectedElement)) {
            deletedMessages.add(selectedElement);
            model.setElementAt("-DELETED " + messages[selectedElement], selectedElement);
        }
    }

    private void unmarkDeleted() {
        if (deletedMessages.contains(selectedElement)) {
            deletedMessages.remove(selectedElement);
            model.setElementAt(messages[selectedElement], selectedElement);
        }
    }

    private void selectionChanged(ListSelectionEvent e) {
        if (e.getValueIsAdjusting()) {
            int toSelect = e.getFirstIndex() == selectedElement ? e.getLastIndex() : e.getFirstIndex();

            messageText.setText(model.get(toSelect));
            selectedElement = toSelect;
        }
    }

    /**
     * Initialize the contents of the frame.
     */
    private void initialize() {
        coreFrame = new JFrame();
        coreFrame.setTitle("Mail client");
        coreFrame.setBounds(100, 100, 630, 399);
        coreFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        SpringLayout springLayout = new SpringLayout();
        coreFrame.getContentPane().setLayout(springLayout);

        JSplitPane splitPane = new JSplitPane();
        splitPane.setDividerSize(8);
        springLayout.putConstraint(SpringLayout.NORTH, splitPane, 0, SpringLayout.NORTH, coreFrame.getContentPane());
        springLayout.putConstraint(SpringLayout.WEST, splitPane, 0, SpringLayout.WEST, coreFrame.getContentPane());
        springLayout.putConstraint(SpringLayout.SOUTH, splitPane, 0, SpringLayout.SOUTH, coreFrame.getContentPane());
        springLayout.putConstraint(SpringLayout.EAST, splitPane, 0, SpringLayout.EAST, coreFrame.getContentPane());
        splitPane.setOneTouchExpandable(true);
        splitPane.setContinuousLayout(true);
        coreFrame.getContentPane().add(splitPane);

        messagesList = new JList<String>();
        messagesList.addListSelectionListener(new ListSelectionListener() {
            public void valueChanged(ListSelectionEvent e) {
                selectionChanged(e);
            }
        });
        splitPane.setLeftComponent(messagesList);

        scrollPane = new JScrollPane();
        splitPane.setRightComponent(scrollPane);

        messageText = new JTextArea();
        scrollPane.setViewportView(messageText);
        splitPane.setDividerLocation(150);

        JMenuBar menuBar = new JMenuBar();
        coreFrame.setJMenuBar(menuBar);

        JMenu connectionMenu = new JMenu("Connection");
        menuBar.add(connectionMenu);

        connectItem = new JMenuItem("Connect");
        connectItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_N, InputEvent.CTRL_MASK));
        connectItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                connect();
            }
        });
        connectionMenu.add(connectItem);

        updateItem = new JMenuItem("Refresh");
        updateItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_R, InputEvent.CTRL_MASK));
        updateItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                refresh();
            }
        });

        saveChangesItem = new JMenuItem("Save changes");
        saveChangesItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, InputEvent.CTRL_MASK | InputEvent.SHIFT_MASK));
        saveChangesItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                save();
            }
        });
        saveChangesItem.setEnabled(false);
        connectionMenu.add(saveChangesItem);
        updateItem.setEnabled(false);
        connectionMenu.add(updateItem);

        disconnectItem = new JMenuItem("Disconnect");
        disconnectItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_W, InputEvent.CTRL_MASK));
        disconnectItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                disconnect();
            }
        });
        disconnectItem.setEnabled(false);
        connectionMenu.add(disconnectItem);
    }

    private static void addPopup(Component component, final JPopupMenu popup) {
        component.addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                if (e.isPopupTrigger()) {
                    showMenu(e);
                }
            }

            public void mouseReleased(MouseEvent e) {
                if (e.isPopupTrigger()) {
                    showMenu(e);
                }
            }

            private void showMenu(MouseEvent e) {
                popup.show(e.getComponent(), e.getX(), e.getY());
            }
        });
    }
}
