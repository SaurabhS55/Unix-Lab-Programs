
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
    msgrcv(msgid,&msg,sizeof(msg),1,0);
    printf("Process 2: %s\n",msg.mtext);
    strcpy(msg.mtext,"Loud and Clear");
    msg.mtype=2;
    msgsnd(msgid,&msg,sizeof(msg),0);
    msgrcv(msgid,&msg,sizeof(msg),3,0);
    printf("Process 2: %s\n",msg.mtext);
    return 0;
}