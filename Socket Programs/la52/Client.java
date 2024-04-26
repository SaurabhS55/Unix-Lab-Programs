import java.net.*;
import java.io.*;

public class Client {
    private static final String SERVER_IP = "127.0.0.1";
    private static final int PORT = 8080;
    private static final int BUFFER_SIZE = 1024;

    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket();
            InetAddress serverAddress = InetAddress.getByName(SERVER_IP);
            byte[] buffer = "Hello from client".getBytes();

            DatagramPacket packet = new DatagramPacket(buffer, buffer.length, serverAddress, PORT);
            socket.send(packet);
            System.out.println("Hello message sent to server");

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
