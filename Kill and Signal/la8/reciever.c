#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signal_num) {
    printf("Receiver received the signal");
    exit(0);
}

int main() {
    pid_t pid;
    pid = getpid(); 

    printf("Receiver process started. PID: %d\n", pid);

    signal(SIGUSR1, signal_handler);

    printf("Receiver process waiting for signals...\n");

    for(;;);

    return 0;
}
