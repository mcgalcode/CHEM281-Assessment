#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    const int N = 100; // Size of the array
    int array[N];
    int local_sum = 0;
    int global_sum = 0;

    if (world_rank == 0) {
        for (int i = 0; i < N; ++i) {
            array[i] = i + 1; // Fill the array with values 1 to 100
        }
    }

    MPI_Bcast(array, N, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = world_rank; i < N; i += world_size) {
        local_sum += array[i];
    }

    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print the result only on the root process
    if (world_rank == 0) {
        std::cout << "Sum of the array: " << global_sum << std::endl;
    }

    MPI_Finalize(); // Finalize the MPI environment
    return 0;
}

