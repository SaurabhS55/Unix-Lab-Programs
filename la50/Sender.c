// Write a 2 programs that will both send and messages and construct the following dialog between them 
// (Process 1) Sends the message "Are you hearing me?" 
// (Process 2) Receives the message and replies "Loud and Clear". 
// (Process 1) Receives the reply and then says "I can hear you too". 
// IPC:Message Queues:msgget, msgsnd, msgrcv.

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
    int key =1234;
    msgid=msgget(key,0666|IPC_CREAT);
    msg.mtype=1;
    strcpy(msg.mtext,"Are you hearing me?");
    msgsnd(msgid,&msg,sizeof(msg),0);
    msgrcv(msgid,&msg,sizeof(msg),2,0);
    printf("Process 2: %s\n",msg.mtext);
    strcpy(msg.mtext,"I can hear you");
    msg.mtype=3;
    msgsnd(msgid,&msg,sizeof(msg),0);
    return 0;
}
