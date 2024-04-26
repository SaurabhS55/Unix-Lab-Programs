// Write a program to illustrate the semaphore concept. Use fork so that 2 process running simultaneously and communicate via semaphore. (give diff between sem.h/semaphore.h)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include<sys/wait.h>

#define KEY 1234
struct sembuf buf;
void wait_semaphore(int sem_id, const char *process) {
    buf.sem_num = 0;
    //  Wait Operation is decrementing one
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;
    printf("%s attempting wait (P) operation on semaphore...\n", process);
    semop(sem_id, &buf, 1);
    int sem_value = semctl(sem_id, 0, GETVAL, 0);
    printf("%s successfully completed wait (P) operation on semaphore. Semaphore value: %d\n", process, sem_value);
}


void signal_semaphore(int sem_id, const char *process) {
    buf.sem_num = 0;
    buf.sem_op = 1;
    buf.sem_flg = SEM_UNDO;
    printf("%s attempting signal (V) operation on semaphore...\n", process);
    semop(sem_id, &buf, 1);
    int sem_value = semctl(sem_id, 0, GETVAL, 0);
    printf("%s successfully completed signal (V) operation on semaphore. Semaphore value: %d\n", process, sem_value);
}

int main() {
    
    int sem_id = semget(KEY,1, IPC_CREAT | 0666);

    if(sem_id == -1){
        perror("Error creating semaphore");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore created with ID: %d\n",sem_id);

    if(semctl(sem_id,0,SETVAL,1) == -1){
        perror("Error in initializing Semaphore");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if(pid == -1){
        perror("Error in forking");
        exit(EXIT_FAILURE);
    }

    else if(pid == 0){
        wait_semaphore(sem_id,"Child Process");
        printf("Child Process performing operations\n");
        sleep(2);
        signal_semaphore(sem_id,"Child Process");
    }
    else{
        wait_semaphore(sem_id,"Parent Process");
        printf("Parent Process performing in critical section\n");
        sleep(2);
        signal_semaphore(sem_id,"Parent Process");

        wait(NULL);


        if(semctl(sem_id,0,IPC_RMID,0) == -1){
            perror("Error in removing semaphore");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

