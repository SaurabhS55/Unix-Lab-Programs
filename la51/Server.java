// Write a program for TCP to demonstrate the socket system calls in c/python 

import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(1234);
            Socket socket = serverSocket.accept();
            DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());
            DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());
            String message = dataInputStream.readUTF();
            System.out.println("Client: " + message);
            dataOutputStream.writeUTF("Hello from server");
            serverSocket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}