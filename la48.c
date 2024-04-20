// Using OpemnMP library write a program  in which master thread count the total no. of threads created, and others will print their thread numbers.

#include <stdio.h>
#include <omp.h>

int main() {
    int total_threads, thread_num;

    // Parallel region starts here
    #pragma omp parallel private(thread_num)
    {
        // Get the total number of threads
        #pragma omp master
        {
            total_threads = omp_get_num_threads();
            printf("Total number of threads created by master thread: %d\n", total_threads);
        }
        
        // Get the thread number of the current thread
        thread_num = omp_get_thread_num();
        printf("Hello from thread %d\n", thread_num);
    } // Parallel region ends here

    return 0;
}
