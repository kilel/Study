#include <cstdlib>
#include <string>
#include <mpi.h>
#include <math.h>
#include "util.h"

using namespace std;
using namespace MPI;


void floid(int** a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) {
                a[i][j] = 1e8;
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        //#pragma omp parallel for
        for (int i = 0; i < n; ++i) {
            //#pragma omp parallel for
            for (int j = 0; j < i; ++j) {
                a[i][j] = Min(a[i][j], a[i][k] + a[k][i]);
                a[j][i] = a[i][j];
            }
        }
    }
}

void testFloid(int n, int count, void (*floidFunk)(int**, int)) {
    int **a, **b;
    a = new int*[n];
    b = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        b[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            a[i][j] = rand() % 10;
            a[j][i] = a[i][j];
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

        uint64_t start = getTime();
        floidFunk(b, n);
        uint64_t finish = getTime() - start;

        result += (double) finish / count;
        //cout << finish << endl;
    }
    printf("%10lf", result);
    delete[] a;
}

int main(int argc, char** argv) {
    srand(time(0));
    ofstream out;
    out.open("floid_result");


    for (int i = 0; i < numStarts; ++i) {
        testFloid(start[i], 10, floid);
        cout << '\n';
    }
    cout << '\n';

    out.close();
    return 0;
}


