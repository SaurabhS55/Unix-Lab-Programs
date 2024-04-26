// Write a program to give statistics of a given file using stat system call. (few imp field like FAP, file type)

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
    struct stat buf;
    char fname[20];
    printf("\n Enter file name: ");
    scanf("%s",fname);
    if(stat(fname,&buf)==-1){
        perror("\n fstat error");
        exit(0);
    }
    
    printf("\n File type: ");
    if(S_ISREG(buf.st_mode)){
        printf("Regular file\n");
    }
    else if(S_ISDIR(buf.st_mode)){
        printf("Directory\n");
    }
    else if(S_ISCHR(buf.st_mode)){
        printf("Character special file\n");
    }
    else if(S_ISBLK(buf.st_mode)){
        printf("Block special file\n");
    }
    else if(S_ISFIFO(buf.st_mode)){
        printf("FIFO special file\n");
    }
    else if(S_ISLNK(buf.st_mode)){
        printf("Symbolic link\n");
    }
    else if(S_ISSOCK(buf.st_mode)){
        printf("Socket\n");
    }
    else{
        printf("Unknown file type\n");
    }

    printf("\n File inode: %ld",buf.st_ino);
    printf("\n File UID: %d",buf.st_uid);
    printf("\n File GID: %d",buf.st_gid);
    return 0;
}