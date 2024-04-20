// Write a program to create 3 threads, first thread printing even no, second thread printing odd no. and third thread printing prime no.

import java.util.*;
import java.io.*;
public class la15 {
    public boolean isPrime(int n){
        if(n<=1){
            return false;
        }
        for(int i=2; i<=Math.sqrt(n); i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    public static void main(String args[]){
        la15 obj = new la15();
        Thread t1 = new Thread(new Runnable(){
            public void run(){
                for(int i=0; i<10; i++){
                    if(i%2==0){
                        System.out.println(i);
                    }
                }
            }
        });
        Thread t2 = new Thread(new Runnable(){
            public void run(){
                for(int i=0; i<10; i++){
                    if(i%2!=0){
                        System.out.println(i);
                    }
                }
            }
        });
        Thread t3 = new Thread(new Runnable(){
            public void run(){
                for(int i=0; i<10; i++){
                    if(obj.isPrime(i)){
                        System.out.println(i);
                    }
                }
            }
        });
        t1.start();
        t2.start();
        t3.start(); 
    }
}
