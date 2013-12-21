#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <mpi.h>
#include <algorithm>

using namespace std;
using namespace MPI;

const double eps = 1e-8;

Intracomm *comm;
int myRank;
int size;
struct Coord;
void readInputRand(int &n, Coord *&first, Coord *&second);
void readInputFile(int &n, Coord *&first, Coord *&second);

int starts = 7;
int randStartNum = 0;
int startVal[] = {100, 300, 500, 700, 900, 1100, 1300};

void (*readInput)(int &n, Coord *&first, Coord *&second) = readInputRand;

double Min(double a, double b) {
    return a < b ? a : b;
}

double Max(double a, double b) {
    return a > b ? a : b;
}

double getRand() {
    return (double) rand() / RAND_MAX * 20;
}

uint64_t getTime() {
    uint64_t lo, hi;
    __asm__ __volatile__(
            "xorl %%eax, %%eax\n"
            "cpuid\n"
            "rdtsc\n"
            : "=a" (lo), "=d" (hi)
            :
            : "%ebx", "%ecx");
    return (uint64_t) hi << 32 | lo;
}

struct Coord {
    double x;
    double y;

    Coord(double x_, double y_) : x(x_), y(y_) {
    }

    Coord() : x(0), y(0) {
    }
};

struct GradCoord {
    int x;
    int y;

    GradCoord(int x_, int y_) : x(x_), y(y_) {
    }

    GradCoord() : x(0), y(0) {
    }
};

void readInputRand(int &n, Coord *&first, Coord *&second) {
    n = startVal[randStartNum++];
    first = new Coord[n];
    second = new Coord[n];
    for (int i = 0; i < n; ++i) {
        first[i] = Coord(getRand(), getRand());
        second[i] = Coord(getRand(), getRand());
    }
}

void readInputFile(int &n, Coord *&first, Coord *&second) {
    ifstream in;
    in.open("input");
    in >> n;
    first = new Coord[n];
    second = new Coord[n];
    for (int i = 0; i < n; ++i) {
        double x, y;
        in >> x >> y;
        first[i] = Coord(x, y);
        in >> x >> y;
        second[i] = Coord(x, y);
    }
    in.close();
}

int getIndex(double value, double *sortedArray, int m) {
    int l = 0, r = m;
    while (r > l) {
        int c = (l + r) >> 1;
        if (fabs(sortedArray[c] - value) < eps) {
            return c;
        }
        if (sortedArray[c] > value) {
            r = c - 1;
        } else {
            l = c + 1;
        }
    }
    return r;
}

void prepareData(int n, Coord *first, Coord *second) {
    for (int i = 0; i < n; ++i) {
        double x1 = first[i].x, x2 = second[i].x, y1 = first[i].y, y2 = second[i].y;
        first[i].x = Min(x1, x2);
        second[i].x = Max(x1, x2);

        first[i].y = Min(y1, y2);
        second[i].y = Max(y1, y2);
    }
}

int** createMatrix(int m) {
    int **a = new int*[m];
    for (int i = 0; i < m + 1; ++i) {
        a[i] = new int[m];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = 0;
        }
    }
    return a;
}

double solve_poster(int n, Coord *first, Coord *second) {
    double sum = 0;
    //broadcast number of rectangles
    comm->Bcast(&n, 1, INT, 0);

    int m = 2 * n;

    int *x1, *x2, *y1, *y2;
    x1 = new int[n];
    x2 = new int[n];
    y1 = new int[n];
    y2 = new int[n];

    double *xSorted;
    double *ySorted;

    if (myRank == 0) {
        //get sorted lists
        xSorted = new double[m];
        ySorted = new double[m];
        for (int i = 0; i < m; ++i) {
            xSorted[i] = i < n ? first[i].x : second[i - n].x;
            ySorted[i] = i < n ? first[i].y : second[i - n].y;
        }

        sort(xSorted, xSorted + m);
        sort(ySorted, ySorted + m);

        //build indexies for input values in sorted.
        //GradCoord *gFirst, *gSecond;int *x1, *x2, *y1, *y2;
        //gFirst = new GradCoord[n];
        //gSecond = new GradCoord[n];

        for (int i = 0; i < n; ++i) {
            /*gFirst[i].x = getIndex(first[i].x, xSorted, m);
            gFirst[i].y = getIndex(first[i].y, ySorted, m);
            gSecond[i].x = getIndex(second[i].x, xSorted, m);
            gSecond[i].y = getIndex(second[i].y, ySorted, m);
             */
            x1[i] = getIndex(first[i].x, xSorted, m);
            y1[i] = getIndex(first[i].y, ySorted, m);
            x2[i] = getIndex(second[i].x, xSorted, m);
            y2[i] = getIndex(second[i].y, ySorted, m);
        }



    }

    if (size > 1) {
        comm->Bcast(x1, n, INT, 0);
        comm->Bcast(x2, n, INT, 0);
        comm->Bcast(y1, n, INT, 0);
        comm->Bcast(y2, n, INT, 0);
    }

    //main solving
    int **a = createMatrix(m);
    int** reduceMatrix = createMatrix(m);

    for (int k = myRank; k < n; k += size) {
        for (int i = x1[k]; i < x2[k]; ++i) {
            for (int j = y1[k]; j < y2[k]; ++j) {
                a[i][j] = 1;
            }
        }
    }



    if (size > 1) {

        for (int k = 0; k < m; ++k) {
            comm->Reduce(a[k], reduceMatrix[k], m, INT, LOR, 0);
        }
    }



    if (myRank == 0) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (reduceMatrix[i][j]) {
                    sum += (xSorted[i + 1] - xSorted[i]) * (ySorted[j + 1] - ySorted[j]);
                }
            }
        }
        delete[] xSorted;
        delete[] ySorted;
    }

    delete[] a;
    delete[] reduceMatrix;
    delete[] x1;
    delete[] x2;
    delete[] y1;
    delete[] y2;

    return sum;
}

int main(int argc, char** argv) {
    srand(time(0));
    Init();

    comm = &COMM_WORLD;
    myRank = comm->Get_rank();
    size = comm->Get_size();

    int n;
    Coord *first, *second;
    for (int i = 0; i < starts; ++i) {
        if (myRank == 0) {
            readInput(n, first, second);
            prepareData(n, first, second);
        }
        comm->Barrier();
        uint64_t start = getTime();
        double result = solve_poster(n, first, second);
        uint64_t timeLength = getTime() - start;

        if (myRank == 0) {
            cout << timeLength << endl;
        }
    }

    Finalize();
    return 0;
}



