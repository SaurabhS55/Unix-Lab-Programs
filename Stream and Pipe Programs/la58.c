// Write a program using FIFO, to Send file from parent to child over a pipe. (named pipe)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SIZE 250

int main(){
    int pid,fd;
    char buf[SIZE];
    if(mkfifo("newfifo", 0666) == -1){
        perror("mkfifo");
        exit(1);
    }
    pid = fork();
    if(pid == -1){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        fd = open("newfifo", O_RDONLY);
        int file = open("f.txt", O_WRONLY | O_CREAT, 0666);
        read(fd, buf, SIZE);
        write(file, buf, strlen(buf));
        close(file);
        close(fd);
    }
    else{
        int file = open("in.txt", O_RDONLY);
        fd = open("newfifo", O_WRONLY);
        read(file, buf, SIZE);
        printf("Parent sending: %s\n", buf);
        write(fd, buf, strlen(buf));
        close(fd);
        wait(NULL);
    }
    return 0;
}