// Write a program to demonstrate the kill system call to send signals between related processes(fork). 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void signal_handler(int signum) {
    printf("\nSignal received in process %d\n", getpid());
}

int main() {
    int pid;
    pid = fork();
    if (pid == 0) {
        printf("\nChild process");
        signal(SIGUSR1, signal_handler);
        for (;;); // Child process waits indefinitely
        exit(0);
    } else if (pid > 0) {
        printf("parent pid: %d",getpid());
        printf("child pid: %d",pid);
        printf("\nParent process");
        sleep(1); // Give some time for the child process to set up signal handler
        kill(pid, SIGUSR1);
        wait(NULL);
        exit(0);
    } else {
        printf("\n Error");
        exit(-1);
    }
    return 0;
}
