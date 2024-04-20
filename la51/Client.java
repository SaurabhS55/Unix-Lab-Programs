
import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 1234);
            DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());
            DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());
            dataOutputStream.writeUTF("Hello from client");
            String message = dataInputStream.readUTF();
            System.out.println("Server: " + message);
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}