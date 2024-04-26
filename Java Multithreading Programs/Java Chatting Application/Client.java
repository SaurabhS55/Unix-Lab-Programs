import java.util.*;
import java.io.*;
import java.net.*;

class Client{
    public static void main(String []args){
        try{
            Socket s=new Socket("localhost",3200);
            DataInputStream dis=new DataInputStream(s.getInputStream());
            DataOutputStream dos=new DataOutputStream(s.getOutputStream());
            Scanner sc=new Scanner(System.in);


            new Thread(new Runnable() {
                @Override
                public void run() {
                    while(true){
                        try{
                            String received = dis.readUTF();
                            System.out.println(received);
                        }
                        catch(Exception e){
                            e.printStackTrace();
                        }
                    }
                }
            }).start();

            new Thread(new Runnable() {
                @Override
                public void run() {
                    while(true){
                        try{
                            String msg = sc.nextLine();
                            dos.writeUTF(msg);
                        }
                        catch(Exception e){
                            e.printStackTrace();
                        }
                    }
                }
            }).start();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
}