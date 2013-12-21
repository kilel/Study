#include <cstdlib>
#include <string>
#include <mpi.h>
#include <math.h>
#include "util.h"

using namespace std;
using namespace MPI;

int mpi_rank = 0;
int mpi_size = 0;
Intracomm *comm;

void floid_MPI(int** a, int n) {
    //send
    for (int i = 0; i < n; ++i) {
        comm->Bcast(a[i], n, INT, 0);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) {
                a[i][j] = 1e8;
            }
        }
    }

    comm->Barrier();

    for (int k = 0; k < n; ++k) {
        //build new data
        if (mpi_rank == k % mpi_size) {
            for (int i = 0; i < mpi_size; ++i) {
                if (i != mpi_rank) {
                    comm->Send(a[k], n, INT, i, 0);
                }
            }
        } else {
            comm->Recv(a[k], n, INT, k % mpi_size, 0); 
        }

        for (int i = mpi_rank; i < n; i += mpi_size) {
            for (int j = 0; j < i; ++j) {
                a[i][j] = Min(a[i][j], a[i][k] + a[k][i]);
                a[j][i] = a[i][j];
            }
        }
        //send to all
        /*
        for (int i = 0; i < n; ++i) {
            int sender = i % mpi_size;
            comm->Bcast(a[i], n, INT, sender);
        }
         */
    }
}

void testFloid_MPI(int n, int count, void (*floidFunk)(int**, int)) {
    int **a, **b;
    a = new int*[n];
    b = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        b[i] = new int[n];
    }
    if (mpi_rank == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                a[i][j] = rand() % 10;
                a[j][i] = a[i][j];
            }
        }
    }

    double result = 0;

    for (int st = 0; st < count; ++st) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                b[i][j] = a[i][j];
                b[j][i] = a[i][j];
            }
        }

        comm->Barrier();
        uint64_t start = getTime();
        floidFunk(b, n);
        comm->Barrier();
        uint64_t finish = getTime() - start;

        result += (double) finish / count;
        //cout << finish << endl;
    }
    if (mpi_rank == 0) {
        printf("%10lf", result);
    }
    delete[] a;
}

int main(int argc, char** argv) {
    srand(time(0));
    ofstream out;
    //out.open("floid_result");

    Init();
    comm = &COMM_WORLD;
    mpi_rank = comm->Get_rank();
    mpi_size = comm->Get_size();


    for (int i = 0; i < numStarts; ++i) {
        testFloid_MPI(start[i], 10, floid_MPI);
        if (mpi_rank == 0) {
            cout << '\n';
        }
    }

    Finalize();

    out.close();
    return 0;
}


