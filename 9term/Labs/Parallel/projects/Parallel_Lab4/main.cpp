#include <cstdlib>
#include <mpi.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;
using namespace MPI;

int numStarts = 8;
int startValue[] = {1000, 5000, 10000, 15000, 20000, 25000, 30000, 35000};
bool startSeq = false;
bool startPar = false;
bool startRing = true;

inline unsigned long long getTime() {
    unsigned long long lo, hi;
    __asm__ __volatile__(
            "xorl %%eax, %%eax\n"
            "cpuid\n"
            "rdtsc\n"
            : "=a" (lo), "=d" (hi)
            :
            : "%ebx", "%ecx");
    return (unsigned long long) hi << 32 | lo;
}

int* getRandomArray(int length) {
    int *array = new int[length];
    for (int i = 0; i < length; ++i) {
        array[i] = rand() % 100;
    }
    return array;
}

bool cmp(int a, int b) {
    if (a <= b) {
        return true;
    } else {
        return false;
    }
}

void cmpSwap(int &a, int& b) {
    if (!cmp(a, b)) {
        int temp = a;
        a = b;
        b = temp;
    }
}

bool checkSorted(int* array, int length) {
    for (int i = 0; i < length - 1; ++i) {
        if (!cmp(array[i], array[i + 1])) {
            return false;
        }
    }
    return true;
}

void printArray(Intracomm comm, int *a, int len, int rank, string addlinfo) {
    comm.Barrier();
    cout << "process " << rank << " " << addlinfo << ": ";
    for (int i = 0; i < len; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    comm.Barrier();

}

class BubbleSorter {
public:

    static void sortSequently(int *array, int length) {
        /*for (int i = 0; i < length; ++i) {
            for (int j = i; j < length; ++j) {
                cmpSwap(array[i], array[j]);
            }
        }*/
        for (int i = 0; i < length; ++i) {
            int step = i % 2;
            for (int j = 0; j < length / 2; ++j) {
                if (2 * j + step + 1 < length) {
                    cmpSwap(array[2 * j + step], array[2 * j + step + 1]);
                }
            }
        }
    }

    static void sortParallel(Intracomm comm, int *array, int length) {
        long long start = getTime();

        int rank = comm.Get_rank();
        int size = comm.Get_size();
        int typicalBlockSize = length / size;
        int *blockSize = new int[size];
        for (int i = 0; i < size; ++i) {
            blockSize[i] = typicalBlockSize;
        }
        blockSize[size - 1] = length % size + typicalBlockSize;

        int *toSort = new int[blockSize[rank]];
        int *splitTemp = new int[blockSize[rank]];
        int *temp = new int[blockSize[size - 1]];

        if (rank == 0) {
            //for (int i = 0; i < length; ++i) {
            //    cout << array[i] << " ";
            //}
            //cout << endl;
            //send data to all nodes
            for (int i = 1; i < size; ++i) {
                comm.Send(array + i*typicalBlockSize, blockSize[i], INTEGER, i, 0);
            }
            //set master array
            for (int i = 0; i < blockSize[rank]; ++i) {
                toSort[i] = array[i];
            }
        } else {
            comm.Recv(toSort, blockSize[rank], INTEGER, 0, 0);
        }
        //comm.Barrier();
        //printArray(comm, toSort, blockSize[rank], rank, " unsorted");
        //comm.Barrier();

        //sort my part
        sortSequently(toSort, blockSize[rank]);
        //start magic
        //comm.Barrier();
        //printArray(comm, toSort, blockSize[rank], rank, " sorted");
        //comm.Barrier();

        int prev = rank - 1;
        int next = rank + 1;
        for (int count = 0; count < size; ++count) {
            //cout << "step " << count << endl;
            //printf("\n%d entered step %d", rank, count);
            int step = count % 2;
            if ((rank + step) % 2 == 0) {
                if (next < size) {
                    comm.Send(toSort, blockSize[rank], INTEGER, next, 0);
                    comm.Recv(temp, blockSize[next], INTEGER, next, 0);
                    splitMin(splitTemp, toSort, temp, blockSize[rank], blockSize[next]);
                }
            } else {
                if (prev >= 0) {
                    comm.Send(toSort, blockSize[rank], INTEGER, prev, 0);
                    comm.Recv(temp, blockSize[prev], INTEGER, prev, 0);
                    splitMax(splitTemp, toSort, temp, blockSize[rank], blockSize[prev]);
                }
            }
            //printArray(comm, toSort, blockSize[rank], rank, " sorted");
            //comm.Barrier();
        }


        comm.Barrier();
        if (rank == 0) {
            for (int i = 1; i < size; ++i) {
                comm.Recv(array + i*typicalBlockSize, blockSize[i], INTEGER, i, 0);
            }
            for (int i = 0; i < blockSize[rank]; ++i) {
                array[i] = toSort[i];
            }
        } else {
            comm.Send(toSort, blockSize[rank], INTEGER, 0, 0);
        }

        long long end = getTime();
        comm.Barrier();
        if (rank == 0) {
            cout << length << ": " << end - start << " sorted=" << checkSorted(array, length) << endl;
        }
        comm.Barrier();
    }

private:

    static void splitMax(int *temp, int *a, int*b, int lenA, int lenB) {
        int *apt = a + lenA - 1;
        int *bpt = b + lenB - 1;
        bool isAEmpty = false;
        bool isBEmpty = false;
        for (int i = lenA - 1; i >= 0; --i) {
            if (isAEmpty) {
                temp[i] = *bpt--;
            } else if (isBEmpty) {
                temp[i] = *apt--;
            } else if (*apt > *bpt) {
                temp[i] = *apt--;
            } else {
                temp[i] = *bpt--;
            }
            isAEmpty = apt == a - 1;
            isBEmpty = bpt == b - 1;
        }
        for (int i = 0; i < lenA; ++i) {
            a[i] = temp[i];
        }
    }

    static void splitMin(int *temp, int *a, int*b, int lenA, int lenB) {
        int *apt = a;
        int *bpt = b;
        bool isAEmpty = false;
        bool isBEmpty = false;
        for (int i = 0; i < lenA; ++i) {
            if (isAEmpty) {
                temp[i] = *bpt++;
            } else if (isBEmpty) {
                temp[i] = *apt++;
            } else if (*apt < *bpt) {
                temp[i] = *apt++;
            } else {
                temp[i] = *bpt++;
            }
            isAEmpty = apt == a + lenA;
            isBEmpty = bpt == b + lenB;
        }
        for (int i = 0; i < lenA; ++i) {
            a[i] = temp[i];
        }
    }
};

int main(int argc, char** argv) {
    srand(time(0));

    Init();

    Intracomm comm = COMM_WORLD;
    int rank = comm.Get_rank();
    int size = comm.Get_size();
    //sequent values
    if (rank == 0 && startSeq) {
        for (int i = 0; i < numStarts; ++i) {
            int *toSort = getRandomArray(startValue[i]);
            long long start = getTime();
            BubbleSorter::sortSequently(toSort, startValue[i]);
            long long end = getTime();
            cout << startValue[i] << ": " << end - start << " sorted=" << checkSorted(toSort, startValue[i]) << endl;
        }
    }
    comm.Barrier();
    if (startPar) {
        //parallel, default topology
        for (int i = 0; i < numStarts; ++i) {
            int *toSort = getRandomArray(startValue[i]);
            BubbleSorter::sortParallel(comm, toSort, startValue[i]);
        }
    }
    comm.Barrier();
    if (startRing) {
        //parallel, ring topology
        int *degs = new int[size];
        int *edges = new int[size * 2];
        degs[0] = 2;
        for (int i = 1; i < size; ++i) {
            degs[i] = degs[i - 1] + 2;
        }
        edges[0] = size - 1;
        edges[1] = 1;
        edges[size * 2 - 2] = size - 2;
        edges[size * 2 - 1] = 0;

        for (int i = 1; i < size - 1; ++i) {
            edges[i * 2] = i - 1;
            edges[i * 2 + 1] = i + 1;
        }

        Intracomm ringComm = comm.Create_graph(size, degs, edges, 1);

        for (int i = 0; i < numStarts; ++i) {
            int *toSort = getRandomArray(startValue[i]);
            BubbleSorter::sortParallel(ringComm, toSort, startValue[i]);
        }
    }
    comm.Barrier();

    Finalize();

    return 0;
}


