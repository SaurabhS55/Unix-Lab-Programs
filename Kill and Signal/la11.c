// Write a program for alarm clock using alarm and signal system call.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void handler() {
    printf("Alarm clock\n");
    exit(0);
}
int main(){
    alarm(5);
    signal(SIGALRM, handler);
    for(;;);
    return 0;
}