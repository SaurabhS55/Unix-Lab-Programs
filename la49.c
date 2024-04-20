// Implement the program for IPC using MPI library (“Hello world” program). 

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv){
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hello World from process %d\n", rank);
    MPI_Finalize();
    return 0;
}