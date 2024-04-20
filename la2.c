// Write a program to use vfork system call(login name by  child and password by parent

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int pid;
    char login[20],password[20];
    pid=vfork();
    if(pid==0){
        printf("\n Enter login: ");
        scanf("%s",login);
        exit(0);
    }
    else if(pid>0){
        printf("\n Enter password: ");
        scanf("%s",password);
        printf("\n Login=%s",login);
        printf("\n Password=%s",password);
        exit(0);
    }
    else{
        printf("\n Error");
        exit(-1);
    }
    return 0;
}