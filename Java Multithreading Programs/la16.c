// Write a multithread program in linux to use the pthread library.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *thread_id) {
    long tid;
    tid = (long)thread_id;
    printf("Thread %ld: Hello World!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int rc;
    long t;
    
    // Create threads
    for(t = 0; t < 3; t++) {
        rc = pthread_create(&threads[t], NULL, thread_function, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to complete
    for(t = 0; t < 3; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads completed. Exiting.\n");

    pthread_exit(NULL);
    return 0;
}
