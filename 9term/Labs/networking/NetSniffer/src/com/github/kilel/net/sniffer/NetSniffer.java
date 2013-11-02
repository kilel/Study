package com.github.kilel.net.sniffer;

import static java.text.MessageFormat.format;

import java.io.Closeable;
import java.io.IOException;

import org.jnetpcap.Pcap;
import org.jnetpcap.nio.JMemory;
import org.jnetpcap.packet.PcapPacket;
import org.jnetpcap.protocol.network.Ip4;
import org.jnetpcap.protocol.network.Ip6;
import org.jnetpcap.protocol.tcpip.Tcp;
import org.jnetpcap.protocol.tcpip.Udp;

public class NetSniffer implements Closeable {
    private Pcap pcap;
    private Thread writer;

    public NetSniffer() {
        StringBuilder errBuff = new StringBuilder();
        pcap = Pcap.openLive("wlan0", Pcap.DEFAULT_SNAPLEN, Pcap.DEFAULT_PROMISC, Pcap.DEFAULT_TIMEOUT, errBuff);
        writer.start();
    }

    @Override
    public void close() throws IOException {
        writer.interrupt();
        pcap.close();
    }

    {
        writer = new Thread(new Runnable() {
            public void run() {
                PcapPacket packet = new PcapPacket(JMemory.POINTER);
                while (true) {
                    pcap.nextEx(packet);

                    Udp udpHeader = new Udp();
                    Tcp tcpHeader = new Tcp();
                    Ip4 ip4header = new Ip4();
                    Ip6 ip6header = new Ip6();
                    packet.getHeader(ip4header);
                    packet.getHeader(ip6header);
                    packet.getHeader(tcpHeader);
                    packet.getHeader(udpHeader);

                    String toPrint;
                    String src;
                    String dest;
                    String srcPort;
                    String destPort;
                    String protocol;
                    if (ip4header.isInitialized() || ip6header.isInitialized()) {
                        if (ip4header.isInitialized()) {
                            src = ip4ToString(ip4header.source());
                            dest = ip4ToString(ip4header.destination());
                        } else {
                            src = ip6ToString(ip6header.source());
                            dest = ip6ToString(ip6header.destination());
                        }

                        if (udpHeader.isInitialized()) {
                            protocol = "UDP";
                            srcPort = new Integer(udpHeader.source()).toString();
                            destPort = new Integer(udpHeader.destination()).toString();
                        } else if (tcpHeader.isInitialized()) {
                            protocol = "TCP";
                            srcPort = new Integer(tcpHeader.source()).toString();
                            destPort = new Integer(tcpHeader.destination()).toString();
                        } else {
                            protocol = "UNKNOWN";
                            srcPort = "?";
                            destPort = "?";
                        }
                        toPrint = format("{0} from {1}___{2} to {3}___{4}", //
                                protocol, src, srcPort, dest, destPort);
                    } else {
                        toPrint = "Not an IP packet";
                    }

                    System.out.println(toPrint);

                    if (writer.isInterrupted()) {
                        return;
                    }
                }
            }
        });
    }

    private String ip4ToString(byte[] ip) {
        StringBuilder builder = new StringBuilder();
        boolean first = true;
        for (byte digit : ip) {
            if (!first) {
                builder.append(".");
            }
            int d = digit;
            d = d < 0 ? 256 + d : d;
            builder.append(d);
            first = false;
        }
        return builder.toString();
    }

    private String ip6ToString(byte[] ip) {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < ip.length; i+=2) {
            if (i != 0) {
                builder.append(":");
            }
            int d1 = ip[i];
            int d2 = ip[i + 1];
            d1 += d1 < 0 ? 256 : 0;
            d2 += d2 < 0 ? 256 : 0;
            builder.append(Integer.toHexString(d1 << 8 | d2));
        }
        return builder.toString();
    }

    public static void main(String[] args) throws IOException {
        NetSniffer sniffer = new NetSniffer();
        while (System.in.read() != 10) {
            ;
        }
        sniffer.close();
    }

}
