// Write programs to simulate linux commands cat, ls, cp, mv, head etc.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10
#define BUFFER_SIZE 1024

void my_cat(int argc, char *argv[]) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    fp=fopen(argv[2], "r");
    fgets(buffer, BUFFER_SIZE, fp);
    printf("%s", buffer);
}

void my_ls() {
    system("ls");
}

void my_cp(int argc, char *argv[]) {
    rename(argv[2], argv[3]);
}

void my_mv(int argc, char *argv[]) {
    rename(argv[2], argv[3]);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s {cat|ls|cp|mv|head} [arguments]\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "cat") == 0) {
        my_cat(argc, argv);
    } else if (strcmp(argv[1], "ls") == 0) {
        my_ls();
    } else if (strcmp(argv[1], "cp") == 0) {
        my_cp(argc, argv);
    } else if (strcmp(argv[1], "mv") == 0) {
        my_mv(argc, argv);
    } else if (strcmp(argv[1], "head") == 0) {
        my_head(argc, argv);
    } else {
        fprintf(stderr, "Invalid command: %s\n", argv[1]);
        exit(1);
    }

    return 0;
}
