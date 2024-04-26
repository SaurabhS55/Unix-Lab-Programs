#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/wait.h>


#define KEY 1234

void P(int sem_id){
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;
    semop(sem_id, &buf, 1);
    printf("P operation performed\n");
}
int main(){
    int sem_id = semget(KEY,1, IPC_CREAT | 0666);

    if(sem_id == -1){
        perror("Error creating semaphore");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore created with ID: %d\n",sem_id);

    P(sem_id);
    return 0;
}
