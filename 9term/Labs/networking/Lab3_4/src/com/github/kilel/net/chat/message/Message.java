package com.github.kilel.net.chat.message;

import java.text.DateFormat;
import java.text.MessageFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Message {
    public static final String DATE_FORMAT = "yyyyMMddHHmmss";
    private final String OUTPUT_DATE_FORMAT = "yyyy'-'MM'-'dd' 'HH':'mm':'ss";
    private static SimpleDateFormat format = new SimpleDateFormat(DATE_FORMAT);
    private SimpleDateFormat outFormat = new SimpleDateFormat(OUTPUT_DATE_FORMAT);

    private final MessageType type;
    private final Date date;
    private final String userId;
    private final String payload;

    public Message(MessageType type, Date date, String userId, String payload) {
        this.type = type;
        this.date = date;
        this.userId = userId;
        this.payload = payload;
    }

    public MessageType getType() {
        return type;
    }

    public Date getDate() {
        return date;
    }

    public String getUserId() {
        return userId;
    }

    public String getPayload() {
        return payload;
    }

    public static DateFormat getDateFormat() {
        return format;
    }

    @Override
    public String toString() {
        String result = "";
        switch (type) {
        case CONN:
            result = payload + " connected to chat";
            break;
        case MSSG:
            result = MessageFormat.format("[{0}] {1}: {2}",//
                    outFormat.format(new Date()), userId, payload);
            break;

        case DCNN:
            result = payload + " disconnected";
            break;

        default:
            break;
        }
        return result;
    }
}
