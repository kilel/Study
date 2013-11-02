package com.github.kilel.net.heartbeat;

import static com.github.kilel.net.heartbeat.HeartBeat.print;

import java.util.Date;
import java.util.Map;

public class LiveClientsWriter implements Runnable {

    private static final int WRITE_LIVE_DELAY = 3000;
    private static final int ASSUME_LIVE_TIME = 5000;

    private Map<String, Date> lastAccessDate;

    public LiveClientsWriter(Map<String, Date> lastAccessDate) {
        this.lastAccessDate = lastAccessDate;
    }

    @Override
    public void run() {
        while (true) {
            writeAlive();
            try {
                Thread.sleep(WRITE_LIVE_DELAY);
            } catch (InterruptedException e) {
                print("Closing write-live thread");
                return;
            }
        }
    }

    private void writeAlive() {
        Date curr = new Date();
        StringBuilder builder = new StringBuilder();
        builder.append("Alive:\n");
        for (String key : lastAccessDate.keySet()) {
            Date temp = lastAccessDate.get(key);
            if (temp.getTime() + ASSUME_LIVE_TIME > curr.getTime()) {
                builder.append("\t");
                builder.append(key);
                builder.append("\n");
            }
        }
        print(builder.toString());
    }
}
