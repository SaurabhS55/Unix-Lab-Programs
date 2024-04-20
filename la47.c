// Write a program using OpenMP library to parallelize the for loop in sequential program of  finding  prime numbers in given range.

#include <stdio.h>
#include <omp.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = 100;
    int count = 0;

    #pragma omp parallel for reduction(+:count)
    for (int i = 2; i <= n; i++) {
        count += is_prime(i);
    }

    printf("Number of prime numbers in the range 1 to %d: %d\n", n, count);

    return 0;
}