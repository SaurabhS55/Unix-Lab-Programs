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
    key_t key=1234;
    msgid=msgget(key,0666|IPC_CREAT);
    msg.mtype=1;
    while(1){
        msgrcv(msgid,&msg,sizeof(msg),1,0);
        printf("Received message: %s",msg.mtext);
        if(strncmp(msg.mtext,"exit",4)==0){
            break;
        }
    }
    return 0;
}