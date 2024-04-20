// Write a program to use fork system call to create 5 child processes and assign 5 operations
// to childs.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    for(int i=0;i<5;i++){
        int pid=fork();
        if(pid<0){
            printf("Error");
            exit(-1);
        }
        else if(pid==0){
            int n1=10,n2=5,ans=-1;
            switch(i){
                case 0:ans=n1+n2;break;
                case 1:ans=n1-n2;break;
                case 2:ans=n1*n2;break;
                case 3:ans=n1/n2;break;
                case 4:ans=n1%n2;break;
                default: break;
            }
            printf("\nChild %d",i);
            printf("\nAnswer= %d",ans);
            exit(0);
        }
    }
    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }
    return 0;
}