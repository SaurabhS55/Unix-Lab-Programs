// Write a program to demonstrate IPC using shared memory (shmget,  shmat, shmdt). In this, one process will take numbers as input from user and second process will sort the numbers and put back to shared memory. Third process will display the shared memory.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int shm_id;
    key_t key = 1234;// Generate a key for shared memory
    shm_id=shmget(key,SHM_SIZE,IPC_CREAT | 0666);
    // Create a shared memory segment
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to the process
    int *shm_ptr = shmat(shm_id, NULL, 0);
    if ((intptr_t)shm_ptr == -1) {
        perror("shmat");
        exit(1);
    }

    // Process 1: Input numbers
    printf("Process 1: Enter numbers (-1 to end):\n");
    int num, index = 0;
    while (scanf("%d", &num) == 1 && num != -1) {
        shm_ptr[index++] = num;
    }
    shm_ptr[index] = -1; // Mark end of input
    printf("Process 1: Numbers stored in shared memory.\n");

    // Detach shared memory segment
    shmdt(shm_ptr);

    // Process 2: Sort numbers
    printf("Process 2: Sorting numbers...\n");
    sleep(2); // Simulate sorting process

    // Re-attach shared memory segment
    shm_ptr = shmat(shm_id, NULL, 0);
    if ((intptr_t)shm_ptr == -1) {
        perror("shmat");
        exit(1);
    }

    // Bubble sort (can be replaced with any other sorting algorithm)
    int i, j, temp;
    for (i = 0; shm_ptr[i] != -1; i++) {
        for (j = 0; shm_ptr[j + 1] != -1; j++) {
            if (shm_ptr[j] > shm_ptr[j + 1]) {
                temp = shm_ptr[j];
                shm_ptr[j] = shm_ptr[j + 1];
                shm_ptr[j + 1] = temp;
            }
        }
    }
    printf("Process 2: Numbers sorted and stored in shared memory.\n");

    // Detach shared memory segment
    shmdt(shm_ptr);

    // Process 3: Display sorted numbers
    printf("Process 3: Sorted numbers:\n");
    shm_ptr = shmat(shm_id, NULL, 0);
    if ((intptr_t)shm_ptr == -1) {
        perror("shmat");
        exit(1);
    }
    for (i = 0; shm_ptr[i] != -1; i++) {
        printf("%d ", shm_ptr[i]);
    }
    printf("\n");

    // Detach shared memory segment
    shmdt(shm_ptr);

    // Remove shared memory segment
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}
