import java.util.*;
import java.io.*;
import java.net.*;

class Server{
    static Vector<ClientHandler> ar=new Vector<>();
    static int i=0;
    public static void main(String arg[]){
        try{
            ServerSocket ss=new ServerSocket(3200);
            while(true){
                Socket s=ss.accept();
                DataInputStream dis=new DataInputStream(s.getInputStream());
                DataOutputStream dos=new DataOutputStream(s.getOutputStream());
                ClientHandler ch = new ClientHandler(s,"client"+i, dis, dos);
                ar.add(ch);
                Thread t = new Thread(ch);
                t.start();
                i++;
            }
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
}
class ClientHandler implements Runnable{
    Socket s;
    DataInputStream dis;
    DataOutputStream dos;
    String name;
    public ClientHandler(Socket s, String name, DataInputStream dis, DataOutputStream dos){
        this.s = s;
        this.name = name;
        this.dis = dis;
        this.dos = dos;
    }
    @Override
    public void run(){
        String received;
        while(true){
            try{
                received = dis.readUTF();
                System.out.println(received);
                if(received.equals("exit") ){
                    this.s.close();
                    break;
                }
                StringTokenizer st = new StringTokenizer(received, "#");
                String recipient = st.nextToken();
                String msg = st.nextToken();
                for(ClientHandler ch: Server.ar){
                    if(ch.name.equals(recipient)){
                        ch.dos.writeUTF(this.name + " : " + msg);
                        break;
                    }
                }
            }catch(Exception e){
                e.printStackTrace();
            }
        }
        try{
            this.dis.close();
            this.dos.close();
        }catch(Exception e){e.printStackTrace();}
    }
}
