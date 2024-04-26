// Write a program in which different processes will perform different operation on shared memory. Operation: create memory, delete, attach/ detach(using shmget, shmat, shmdt).


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<string.h>
#define SIZE 1024
int main(){
    int shmid,key=3456;
    char *c;

    shmid=shmget(key,SIZE,IPC_CREAT|0666);
    if(shmid<0){
        perror("shmem not created");
        return 0;
    }
    c=(char*)shmat(shmid,NULL,0);
    if(c==(char*)-1){
        perror("error");
        return 0;
    }
    
    int pid=fork();
    if(pid<0){
        perror("process not created");
        return 0;
    }
    else if(pid==0){
        strcpy(c,"World");
        printf("Child process: %s\n",c);
        shmdt(c);
        exit(0);
    }
    else{
        wait(NULL);
        printf("Parent process: %s\n",c);
        shmdt(c);
        shmctl(shmid,IPC_RMID,NULL);
    }
    return 0;
}