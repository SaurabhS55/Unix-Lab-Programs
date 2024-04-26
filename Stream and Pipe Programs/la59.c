// Write a program using PIPE, to convert uppercase to lowercase filter to read command/ from file

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>

#define SIZE 200

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
        int fd = open("f.txt", O_WRONLY | O_CREAT, 0666);
        read(pipefd[0], buf, SIZE);
        for(int i = 0; i < strlen(buf); i++){
            buf[i] = tolower(buf[i]);
        }
        write(fd, buf, strlen(buf));
        close(fd);
        close(pipefd[0]);
    }
    else{
        close(pipefd[0]);
        int fd = open("in.txt", O_RDONLY);
        read(fd, buf, SIZE);
        printf("Parent sending: %s\n", buf);
        write(pipefd[1], buf, strlen(buf));
        close(fd);
        close(pipefd[1]);
        wait(NULL);
    }
    return 0;
}