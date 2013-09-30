#include <cstdlib>
#include <iostream>
#include <string>
#include <mpi.h>

using namespace std;
using namespace MPI;

class Lab3 {
private:
    Intracomm &comm = COMM_WORLD;
    int id;
    int size;
    static const int master = 0;

public:

    Lab3() {
        Init();
        id = comm.Get_rank();
        size = comm.Get_size();
    }

    ~Lab3() {
        Finalize();
    }

    void barrier(string message = "") {
        comm.Barrier();
        if (id == master) {
            printf("\n%s\n", &message.at(0));
        }
        comm.Barrier();
    }

    void task1() {
        barrier("Task 1");

        struct MyType {
            int a;
            int b;
            double c;
        } tempVal;
        int dataLength[] = {1, 1, 1};
        Datatype types[] = {INTEGER, INTEGER, DOUBLE};
        Aint shift[] = {&tempVal.a - (int*) &tempVal,
            &tempVal.b - (int*) &tempVal,
            &tempVal.c - (double*) &tempVal};

        Datatype newType = Datatype::Create_struct(3, dataLength, shift, types);
        newType.Commit();
        if (id == master) {
            MyType val;
            val.a = rand();
            val.b = rand();
            val.c = rand() / 3.45492;
            int to = 1;

            comm.Send(&val, 1, newType, to, 0);
            printf("send: [%d], [%d], [%lf]\n", val.a, val.b, val.c);
        } else if (id == 1) {
            MyType val;
            int from = 0;
            comm.Recv(&val, 1, newType, from, 0);
            printf("recv: [%d], [%d], [%lf]", val.a, val.b, val.c);
        }
        newType.Free();
    }

    void task2() {
        barrier("Task 2");
        int numDims = 2;
        int dims[] = {4, 4};
        bool periodic[] = {true, true};
        bool reorder = true;
        Cartcomm grid = comm.Create_cart(numDims, dims, periodic, reorder);
        int *coords = new int[numDims];
        grid.Get_coords(grid.Get_rank(), numDims, coords);
        printf("Rank: %d (in comm = %d), coords:(%d, %d)\n", grid.Get_rank(), comm.Get_rank(),
                coords[0], coords[1]);
    }
    
    void task3() {
        barrier("Task 2");
        int numDims = 2;
        int dims[] = {4, 4};
        bool periodic[] = {true, true};
        bool reorder = true;
        Cartcomm grid = comm.Create_cart(numDims, dims, periodic, reorder);
        int *coords = new int[numDims];
        grid.Get_coords(grid.Get_rank(), numDims, coords);
        printf("Rank: %d (in comm = %d), coords:(%d, %d)\n", grid.Get_rank(), comm.Get_rank(),
                coords[0], coords[1]);
    }

};

int main(int argc, char** argv) {
    srand(time(0));
    Lab3 &lab = *(new Lab3());
    lab.task1();
    lab.task2();

    lab.barrier("Finished lab 2");
    delete &lab;
    return 0;
}

