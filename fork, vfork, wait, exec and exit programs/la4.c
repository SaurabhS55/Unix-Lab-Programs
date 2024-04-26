// Write a program to open any application using vfork sysem call.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int pid;
    pid=vfork();
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