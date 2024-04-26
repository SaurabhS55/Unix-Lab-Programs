// Write a program to give statistics of a given file using fstat system call. (few imp field like FAP, file type)

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(){
    char fname[100];
    printf("Enter the file name: ");
    scanf("%s", fname);
    struct stat filestat;
    int fd=fileno(fopen(fname, "r"));
    if(fstat(fd, &filestat)==-1){
        printf("Error\n");
        exit(-1);
    }
    printf("File type: ");
    if(S_ISREG(filestat.st_mode))
        printf("Regular file\n");
    else if(S_ISDIR(filestat.st_mode))
        printf("Directory\n");
    else if(S_ISCHR(filestat.st_mode))
        printf("Character special file\n");
    else if(S_ISBLK(filestat.st_mode))
        printf("Block special file\n");
    else if(S_ISFIFO(filestat.st_mode))
        printf("FIFO special file\n");
    else if(S_ISLNK(filestat.st_mode))
        printf("Symbolic link\n");
    else if(S_ISSOCK(filestat.st_mode))
        printf("Socket\n");
    else
        printf("Unknown file type\n");

    printf("File inode: %ld\n", filestat.st_ino);
    printf("File UID: %d\n", filestat.st_uid);
    printf("File GID: %d\n", filestat.st_gid);
    return 0;

}