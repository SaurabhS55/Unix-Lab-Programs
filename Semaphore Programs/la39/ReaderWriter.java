import java.util.concurrent.Semaphore;

class SharedResource {
    static int data = 0;
    static Semaphore mutex = new Semaphore(1);
    static Semaphore readerMutex = new Semaphore(1);
    static int readerCount = 0;

    static void startRead() throws InterruptedException {
        readerMutex.acquire();
        if (readerCount == 0) mutex.acquire(); // First reader acquires mutex to block writers
        readerCount++;
        readerMutex.release();
    }

    static void endRead() throws InterruptedException {
        readerMutex.acquire();
        readerCount--;
        if (readerCount == 0) mutex.release(); // Last reader releases mutex to allow writers
        readerMutex.release();
    }

    static void startWrite() throws InterruptedException {
        mutex.acquire(); // Writer acquires mutex to block other writers and readers
    }

    static void endWrite() {
        mutex.release(); // Writer releases mutex
    }
}

class Reader implements Runnable {
    public void run() {
        try {
            for (int i = 0; i < 5; i++) {
                SharedResource.startRead();
                System.out.println("Reader read: " + SharedResource.data);
                SharedResource.endRead();
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class ReaderWriter {
    public static void main(String[] args) {
        new Thread(new Runnable(){
            public void run(){
                try {
                    for (int i = 0; i < 5; i++) {
                        SharedResource.startWrite();
                        SharedResource.data = i;
                        System.out.println("Writer wrote: " + SharedResource.data);
                        SharedResource.endWrite();
                        Thread.sleep(1000);
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                    }
                }
        }).start();

        new Thread(new Reader()).start();
        new Thread(new Reader()).start();
        
    }
}
