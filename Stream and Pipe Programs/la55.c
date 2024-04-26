// Write a program using PIPE, to Send data from parent to child over a pipe. (unnamed pipe )

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define SIZE 100

int main(){
    int pipefd[2];
    int pid;
    char buf[SIZE];
    if(pipe(pipefd) == -1){
        perror("pipe");
        exit(1);
    }
    pid = fork();
    if(pid == -1){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        close(pipefd[1]);
        read(pipefd[0], buf, SIZE);
        printf("Child received: %s\n", buf);
        close(pipefd[0]);
    }
    else{
        close(pipefd[0]);
        char * str = "Hello from parent";
        printf("Parent sending: %s\n", str);
        write(pipefd[1], str, strlen(str) + 1);
        close(pipefd[1]);
        wait(NULL);
    }
    return 0;
}