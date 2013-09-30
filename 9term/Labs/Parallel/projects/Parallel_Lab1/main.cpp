#include <cstdlib>
#include <iostream>
#include <string>
#include <mpi.h>

using namespace std;
using namespace MPI;


void task1(){
    int tag = 0;
    int receivedData = 0;
    
    Intracomm &comm = COMM_WORLD;
    int rank = comm.Get_rank();
    int size = comm.Get_size();
    
    printf("Started task1, node: [%d]\n", rank);
    
    if(rank == 0) {
        int initData = rand();
        printf("generated data to send: %d\n", initData);
        comm.Send(&initData, 1, INTEGER, (rank + 1)% size, tag);
        printf("Node [%d] sent data: %d\n", rank, initData);
        comm.Recv(&receivedData, 1, INTEGER, size - 1, tag);
        printf("Node [%d] catched data: %d\n", rank, receivedData);
    } else {
        comm.Recv(&receivedData, 1, INTEGER, rank - 1, tag);
        printf("Node [%d] catched data: %d\n", rank, receivedData);
        comm.Send(&receivedData, 1, INTEGER, (rank + 1)% size, tag);
        printf("Node [%d] sent data: %d\n", rank, receivedData);
    }
    comm.Barrier();
    if(rank == 0) {
        printf("\n\n");
    }
}

void task2(){
    int tag = 0;
    int receivedData = 0;
    int initData = rand();
    
    Intracomm &comm = COMM_WORLD;
    int rank = comm.Get_rank();
    int size = comm.Get_size();
    
    int from = rank - 1;
    from = from < 0 ? size - 1: from;
    int to = (rank + 1) % size;
    
    initData = rank;
    
    printf("Started task2, node: [%d]\n", rank);
    
    comm.Send(&initData, 1, INTEGER, to, tag);
    printf("Node [%d] sent data: %d\n", rank, initData);
    comm.Recv(&receivedData, 1, INTEGER, from, tag);
    printf("Node [%d] catched data: %d\n", rank, receivedData);   
}


int main(int argc, char** argv) {
    srand(time(0));
    Init();
    
    task1();
    task2();
    
    Finalize();
    
    return 0;
}

