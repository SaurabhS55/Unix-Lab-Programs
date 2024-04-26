// Write a program to open any application using fork sysem call.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int pid;
    pid=fork();
    if(pid==0){
        system("vi");
        exit(0);
    }
    else if(pid>0){
        wait(NULL);
        exit(0);
    }
    else{
        printf("\n Error");
        exit(-1);
    }
    return 0;
}