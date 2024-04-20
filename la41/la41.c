// Write a program to demonstrate IPC using shared memory (shmget,  shmat, shmdt). In this, one process will send A to Z/1 to 100 as input from user and another process will receive it.        
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate a unique key for the shared memory segment
    key = 1234;
    // Create a shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process's address space
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Parent process - sending data
    if (fork() == 0) {
        printf("Enter characters A to Z or numbers 1 to 100 (separated by spaces):\n");
        fgets(shm, SHM_SIZE, stdin);
        printf("Data sent to shared memory: %s\n", shm);
        shmdt(shm); // Detach from shared memory
        exit(0);
    } 
    // Child process - receiving data
    else {
        wait(NULL); // Wait for the child process to finish
        printf("Received data from shared memory: %s\n", shm);
        shmdt(shm); // Detach from shared memory
        shmctl(shmid, IPC_RMID, NULL); // Delete the shared memory segment
    }

    return 0;
}
