package com.github.kilel.net.chat.message;

import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.text.ParseException;
import java.util.Date;

public class MessageTransferer implements Closeable {
    private static final int LENGTH_HEADER_TYPE = 4;
    private static final int LENGTH_HEADER_LENGTH = 8;
    private static final int LENGTH_HEADER_USER_ID = 100;
    private static final int LENGTH_HEADER_DATE = Message.DATE_FORMAT.length();
    private static final int MAX_PAYLOAD_LENGTH = 99999999;

    // buffers, used in reading message
    private final byte[] buffReadType;
    private final byte[] buffReadDate;
    private final byte[] buffReadLength;
    private final byte[] buffReadUserId;
    private final byte[] buffReadPayload;

    private Socket target;

    public MessageTransferer(Socket target) {
        this.target = target;

        buffReadType = new byte[LENGTH_HEADER_TYPE];
        buffReadDate = new byte[LENGTH_HEADER_DATE];
        buffReadLength = new byte[LENGTH_HEADER_LENGTH];
        buffReadUserId = new byte[LENGTH_HEADER_USER_ID];
        buffReadPayload = new byte[MAX_PAYLOAD_LENGTH];
    }

    public MessageTransferer(InetSocketAddress server) throws IOException {
        this(new Socket());
        target.connect(server);
    }

    public void send(MessageType type, String userId, String payload) throws IOException {
        OutputStream out = target.getOutputStream();
        byte[] buffType = type.toString().getBytes();
        byte[] buffDate = Message.getDateFormat().format(new Date()).getBytes();
        byte[] buffUserId = getAlignedbuffer(userId, LENGTH_HEADER_USER_ID);
        byte[] buffPayload = payload.trim().getBytes("UTF-8");

        int length = buffPayload.length;
        if (length > MAX_PAYLOAD_LENGTH) {
            length = MAX_PAYLOAD_LENGTH;
        }

        byte[] buffLength = getAlignedbuffer(Integer.toString(length), LENGTH_HEADER_LENGTH);

        out.write(buffType, 0, LENGTH_HEADER_TYPE);
        out.write(buffDate, 0, LENGTH_HEADER_DATE);
        out.write(buffUserId, 0, LENGTH_HEADER_USER_ID);
        out.write(buffLength, 0, LENGTH_HEADER_LENGTH);
        out.write(buffPayload, 0, length);
    }

    public Message waitForMessage() throws IOException {
        InputStream in = target.getInputStream();

        String type = read(in, buffReadType, LENGTH_HEADER_TYPE);
        String date = read(in, buffReadDate, LENGTH_HEADER_DATE);
        String userId = read(in, buffReadUserId, LENGTH_HEADER_USER_ID);
        String length = read(in, buffReadLength, LENGTH_HEADER_LENGTH);
        int payloadLength = new Integer(length);
        String payload = read(in, buffReadPayload, payloadLength);

        Message resp;
        try {
            resp = new Message(MessageType.valueOf(type),//
                    Message.getDateFormat().parse(date), userId, payload);
        } catch (ParseException e) {
            throw new IOException(e);
        }

        return resp;
    }

    private String read(InputStream in, byte[] buffer, int length) throws IOException {
        int readed = 0;
        int read;
        if ((read = in.read(buffer, readed, length)) > 0) {
            readed += read;
        }
        if (readed != length) {
            throw new IOException("Error reading from socket!");
        }
        return new String(buffer, 0, length, "UTF-8").trim();
    }

    private byte[] getAlignedbuffer(String source, int bufferSize) {
        byte[] buffer = new byte[bufferSize];
        byte[] temp;
        try {
            temp = source.trim().getBytes("UTF-8");
            for (int i = 0; i < bufferSize; ++i) {
                if (i < temp.length) {
                    buffer[i] = temp[i];
                } else {
                    buffer[i] = 32;
                }
            }
        } catch (UnsupportedEncodingException e) {
        }
        return buffer;
    }

    public InetAddress getAddress() {
        return target.getInetAddress();
    }

    public boolean isClosed() {
        return target.isClosed();
    }

    @Override
    public void close() throws IOException {
        target.close();
    }

}
