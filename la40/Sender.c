// Write a program for chatting between two/three users to demonstrate IPC using message passing (msgget, msgsnd, msgrcv ). 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main(){
    int msgid;
    struct msgbuf msg;
    key_t key=1234
    msgid=msgget(key,0666|IPC_CREAT);
    if(msgid==-1){
        printf("Error in creating message queue\n");
        exit(1);
    }
    int pid;
    pid=fork();
    if(pid==0){
        while(1){
            msgrcv(msgid,&msg,sizeof(msg.mtext),1,0);
            printf("User 1: %s\n",msg.mtext);
        }
    }
    else if(pid>0){
        while(1){
            msgrcv(msgid,&msg,sizeof(msg.mtext),2,0);
            printf("User 2: %s\n",msg.mtext);
        }
    }
    else{
        printf("Error\n");
        exit(1);
    }
    return 0;
}