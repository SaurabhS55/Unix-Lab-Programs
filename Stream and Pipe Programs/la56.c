// Write a program using FIFO, to Send data from parent to child over a pipe. (named pipe)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SIZE 100

int main(){
    int pid,fd;
    char buf[SIZE];
    if(mkfifo("fifo", 0666) == -1){
        perror("mkfifo");
        exit(1);
    }
    pid = fork();
    if(pid == -1){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        fd = open("fifo", O_RDONLY);
        read(fd, buf, SIZE);
        printf("Child received: %s\n", buf);
        close(fd);
    }
    else{
        fd = open("fifo", O_WRONLY);
        char * str = "Hello from parent";
        printf("Parent sending: %s\n", str);
        write(fd, str, strlen(str) + 1);
        close(fd);
        wait(NULL);
    }
    return 0;
}