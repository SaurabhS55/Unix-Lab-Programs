// Write a program for UDP to demonstrate the socket system calls

import java.net.*;
import java.io.*;

public class Server {
    private static final int PORT = 8080;
    private static final int BUFFER_SIZE = 1024;

    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket(PORT);
            byte[] buffer = new byte[BUFFER_SIZE];

            System.out.println("Server started. Waiting for messages...");

            while (true) {
                DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                socket.receive(packet);

                String message = new String(packet.getData(), 0, packet.getLength());
                System.out.println("Client: " + message);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
