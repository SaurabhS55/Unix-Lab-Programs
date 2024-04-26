// Write a program to use alarm and signal sytem call(check i/p from user within time)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
void alarm_handler(){
    printf("Time out\n");
    exit(0);
}
int main(){
    int n;
    printf("Enter a number: ");
    alarm(10);
    signal(SIGALRM,alarm_handler);
    scanf("%d",&n);
    printf("You entered: %d\n",n);
    return 0;
}