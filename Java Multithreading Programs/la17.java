// Write a multithreaded program for producer-consumer problem in JAVA.

import java.io.*;
import java.net.*;
import java.util.concurrent.Semaphore;

class la17{
    public static int SIZE=5;
    static int[] v = new int[SIZE];
    public static int in=0,out=0;
    public static Semaphore full=new Semaphore(0);
    public static Semaphore empty=new Semaphore(SIZE);
    public static void main(String args[]){
        new Thread(new Runnable(){
            @Override
            public void run(){
                for(int i=0;i<5;i++){
                    try{
                        empty.acquire();
                        v[in]=i;
                        System.out.println("Produced: "+v[in]);
                        in=(in+1)%SIZE;
                        full.release();
                    }
                    catch(Exception e){
                        e.printStackTrace();
                    }
                }
            }
        }).start();
        new Thread(new Runnable(){
            @Override
            public void run(){
                for(int i=0;i<5;i++){
                    try{
                        full.acquire();
                        System.out.println("Consumed: "+v[out]);
                        out=(out+1)%SIZE;
                        empty.release();
                    }
                    catch(Exception e){
                        e.printStackTrace();
                    }
                }
            }
        }).start();
    }
}
