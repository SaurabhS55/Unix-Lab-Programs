// Write a program to ensure that function f1 should executed before executing function f2 using  semaphore.

import java.util.concurrent.Semaphore;

public class PreExec {
    static Semaphore semaphore = new Semaphore(1);

    public static void main(String[] args) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    semaphore.acquire();
                    f1();
                    semaphore.release();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }).start();

        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    semaphore.acquire();
                    f2();
                    semaphore.release();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }

    public static void f1() {
        System.out.println("f1");
    }

    public static void f2() {
        System.out.println("f2");
    }
}