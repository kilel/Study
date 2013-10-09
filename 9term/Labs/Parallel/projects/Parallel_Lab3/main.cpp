#include <cstdlib>
#include <iostream>
#include <string>
#include <mpi.h>
#include <sstream>

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
        printf("Rank: %d (in comm = %d), coords:(%d, %d)\n", grid.Get_cart_rank(coords), comm.Get_rank(),
                coords[0], coords[1]);

    }

    void task3_dummy() {
        barrier("Task 3 (dummy edition)");
        int numDims = 2;
        int dims[] = {4, 4};
        bool periodic[] = {true, true};
        bool reorder = true;
        Cartcomm grid = comm.Create_cart(numDims, dims, periodic, reorder);
        int *coords = new int[numDims];
        grid.Get_coords(grid.Get_rank(), numDims, coords);

        int *coordsTo = new int[numDims];
        int dimToShift = 0;
        for (int i = 0; i < numDims; ++i) {
            coordsTo[i] = coords[i];
        }
        coordsTo[dimToShift] = (coordsTo[dimToShift] + 1) % dims[dimToShift];
        int toRank = grid.Get_cart_rank(coordsTo);

        printf("Rank: %d (in comm = %d), coords:(%d, %d) sends to rank %d, cooords (%d, %d)\n",
                grid.Get_cart_rank(coords), comm.Get_rank(), coords[0], coords[1],
                toRank, coordsTo[0], coordsTo[1]);

    }

    void task3() {
        barrier("Task 3");
        int numDims = 2;
        int dims[] = {4, 4};
        bool periodic[] = {true, true};
        bool reorder = true;
        Cartcomm grid = comm.Create_cart(numDims, dims, periodic, reorder);

        int fromRank = grid.Get_rank();
        int toRank;
        grid.Shift(0, 1, fromRank, toRank);

        int *coords = new int[numDims];
        int *coordsTo = new int[numDims];
        int *currCoords = new int[numDims];
        grid.Get_coords(fromRank, numDims, coords);
        grid.Get_coords(toRank, numDims, coordsTo);
        grid.Get_coords(grid.Get_rank(), numDims, currCoords);

        printf("Current rank: %d (%d, %d). Before rank %d, coords:(%d, %d), next rank %d, cooords (%d, %d)\n",
                grid.Get_rank(), currCoords[0], currCoords[1],
                fromRank, coords[0], coords[1],
                toRank, coordsTo[0], coordsTo[1]);
    }

    void task4() {
        barrier("Task 4");
        int numV = 7;
        int degrees[] = {4, 8, 12, 13, 14, 15, 16};
        int edges[] = {1, 1, 2, 2,
            0, 0, 3, 4,
            0, 0, 5, 6,
            1, 1, 2, 2};
        Graphcomm gcomm = comm.Create_graph(numV, &degrees[0], &edges[0], true);

        if (gcomm != COMM_NULL) {
            int rank = gcomm.Get_rank();
            int deg = gcomm.Get_neighbors_count(rank);
            int *neigh = new int[deg];
            gcomm.Get_neighbors(rank, deg, neigh);
            string nei = "";
            stringstream st;
            for (int i = 0; i < deg; ++i) {
                st << neigh[i] << ", ";
            }
            nei = st.str();
            printf("rank = %d, deg = %d, neighboars = %s\n", rank, deg, &nei[0]);

        }
    }

};

int main(int argc, char** argv) {
    srand(time(0));
    Lab3 &lab = *(new Lab3());
    lab.task1();
    lab.task2();
    lab.task3_dummy();
    lab.task3();
    lab.task4();

    lab.barrier("Finished lab 2");
    delete &lab;
    return 0;
}


