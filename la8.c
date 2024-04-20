// Write a program to demonstrate the kill system call to send signals between unrelated processes.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void signal_handler(int signum){
    printf("\nSignal received");
}
int main(){
    int pid1,pid2;
    pid1=fork();
    pid2=fork();
    if(pid1==0){
        printf("\nChild process 1");
        signal(SIGUSR1,signal_handler);
        while(1);
        exit(0);
    }
    else if(pid1>0){
        if(pid2==0){
            printf("\nChild process 2");
            kill(pid1,SIGUSR1);
            exit(0);
        }
        else if(pid2>0){
            wait(NULL);
            printf("\nParent process");
            exit(0);
        }
        else{
            printf("\n Error");
            exit(-1);
        }
    }
    else{
        printf("\n Error");
        exit(-1);
    }
    return 0;
}