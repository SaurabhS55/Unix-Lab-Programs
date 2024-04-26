#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/wait.h>

#define KEY 1234

int main(){
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
    return 0;
}