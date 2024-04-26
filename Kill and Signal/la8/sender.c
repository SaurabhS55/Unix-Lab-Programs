#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <receiver_pid>\n", argv[0]);
        return 1;
    }

    pid_t receiver_pid = atoi(argv[1]);

    printf("Sender process started. PID: %d\n", getpid());
    printf("Sending SIGUSR1 signal to process with PID %d...\n", receiver_pid);
    kill(receiver_pid, SIGUSR1);

    return 0;
}
