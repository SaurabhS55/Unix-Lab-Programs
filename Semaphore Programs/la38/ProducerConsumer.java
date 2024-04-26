// Write program to implement producer consumer problem using semaphore.h in C/JAVA

import java.io.*;
import java.util.*;
import java.util.concurrent.Semaphore;

class ProducerConsumer{
    static final int BUFFER_SIZE = 5;
    static int[] buffer = new int[BUFFER_SIZE];
    static int in = 0, out = 0;
    static Semaphore empty = new Semaphore(BUFFER_SIZE);
    static Semaphore full = new Semaphore(0);

    public static void main(String args[]){
        new Thread(new Runnable(){
            @Override
            public void run(){
                for(int i = 0; i < 5; i++){
                    try{
                        empty.acquire();
                        buffer[in] = (int)(Math.random() * 100);
                        System.out.println("Produced: " + buffer[in]);
                        in = (in + 1) % BUFFER_SIZE;
                        full.release();
                    }catch(InterruptedException e){
                        e.printStackTrace();
                    }
                }
            }
        }).start();

        new Thread(new Runnable(){
            @Override
            public void run(){
                for(int i = 0; i < 5; i++){
                    try{
                        full.acquire();
                        System.out.println("Consumed: " + buffer[out]);
                        out = (out + 1) % BUFFER_SIZE;
                        empty.release();
                    }catch(InterruptedException e){
                        e.printStackTrace();
                    }
                }
            }
        }).start();
    }
}