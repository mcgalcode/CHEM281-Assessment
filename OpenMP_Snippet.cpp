#include <iostream>
#include <omp.h>

int main() {
    const int N = 100;
    int array[N];
    int sum = 0;

    // Initialize the array
    for (int i = 0; i < N; ++i) {
        array[i] = i + 1; // Fill the array with values 1 to 100
    }

    #pragma omp parallel
    {
        int thread_sum = 0;

        #pragma omp for
        for (int i = 0; i < N; ++i) {
            thread_sum += array[i];
        }

        #pragma omp critical
        {
            sum += thread_sum;
        }
    }

    std::cout << "Sum of the array: " << sum << std::endl;

    return 0;
}