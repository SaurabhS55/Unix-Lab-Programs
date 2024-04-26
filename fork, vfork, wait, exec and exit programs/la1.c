// Write a program to use fork system call to create 5 child processes and assign 5 operations
// to childs.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    for(int i=0;i<5;i++){
        int pid=fork();
        if(pid<0){
            perror("Error in forking");
            exit(-1);
        }
        else if(pid==0){
            int n1=10,n2=5,n3;
            switch(i){
                case 0: n3=n1+n2; printf("Addition: %d\n",n3); break;
                case 1: n3=n1-n2; printf("Subtraction: %d\n",n3); break;
                case 2: n3=n1*n2; printf("Multiplication: %d\n",n3); break;
                case 3: n3=n1/n2; printf("Division: %d\n",n3); break;
                case 4: n3=n1%n2; printf("Modulus: %d\n",n3); break;
                default: break;
            }
            exit(0);
        }
    }
    for(int i=0;i<5;i++){
        wait(NULL);
    }
    return 0;
}