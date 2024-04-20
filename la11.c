// Write a program for alarm clock using alarm and signal system call.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void handler() {
    printf("Alarm clock\n");
    signal(SIGALRM, handler);
}
int main(){
    signal(SIGALRM, handler);
    alarm(5);
    for(;;);
    return 0;
}