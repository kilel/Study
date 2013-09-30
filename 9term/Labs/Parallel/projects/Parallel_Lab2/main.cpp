#include <cstdlib>
#include <iostream>
#include <string>
#include <mpi.h>

using namespace std;
using namespace MPI;

class Lab2 {
private:
    Intracomm &comm = COMM_WORLD;
    int id;
    int size;
    static const int master = 0;

public:

    Lab2() {
        Init();
        id = comm.Get_rank();
        size = comm.Get_size();
    }

    ~Lab2() {
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
        printf("Process %d of %d\n", id, size);

    }

    void task2() {
        barrier("Task 2");
        if (id == master) {
            int data = rand();
            comm.Send(&data, 1, INTEGER, 1, 0);
            printf("Process %d sent data [%d] to %d\n", id, data, 1);
        } else if (id == 1) {
            int recv = 0;
            comm.Recv(&recv, 1, INTEGER, 0, 0);
            printf("Process %d recieved data [%d] from %d\n", id, recv, 0);
        }
    }

    void task3() {
        barrier("Task 3");
        if (id % 2 == 0 && id + 1 != size) {
            int data = rand();
            int to = id + 1;
            comm.Send(&data, 1, INTEGER, to, 0);
            printf("Process %d sent data [%d] to %d\n", id, data, to);
        } else if (id != master) {
            int recv = 0;
            int from = id - 1;
            comm.Recv(&recv, 1, INTEGER, from, 0);
            printf("Process %d recieved data [%d] from %d\n", id, recv, from);
        }
    }

    void task4() {
        barrier("Task 4");
        int * buffer;
        int buffSize = 1 + BSEND_OVERHEAD;
        buffer = new int[buffSize];

        Attach_buffer(buffer, buffSize);
        
        if (id == master) {
            int toSend = rand();
            *buffer = toSend;
            int to = 1;
            comm.Bsend(buffer, 1, INTEGER4, to, 0);
            printf("Process %d sent data [%d] to %d\n", id, toSend, to);
        } else if (id == 1) {
            int from = 0;
            comm.Recv(buffer, 1, INTEGER4, from, 0);
            printf("Process %d recieved data [%d] from %d\n", id, *buffer, from);
        }
        comm.Barrier();
        //MPI_Buffer_detach(buffer, &buffSize);
        Detach_buffer((void*&)buffer);
        delete [] buffer;
    }

    void task5() {
        barrier("Task 5");
        if (id != size - 1) {
            int data = rand();
            int to = size - 1;
            comm.Send(&data, 1, INTEGER, to, 0);
            printf("Process %d sent data [%d] to %d\n", id, data, to);
        } else {
            Status s;
            comm.Probe(ANY_SOURCE, ANY_TAG, s);
            int count = s.Get_count(INTEGER);
            int* buffer = new int[count];
            int from = s.Get_source();
            comm.Recv(buffer, count, INTEGER, from, 0);
            for (int i = 0; i < count; ++i) {
                printf("Process %d recieved data [%d] from %d\n", id, *(buffer + i), from);
            }
            delete buffer;
        }
    }

    void task6() {
        barrier("Task 6");
        int data = 0;
        if (id == master) {
            data = rand();
            printf("Process %d initialized data [%d]\n", id, data);
            comm.Bcast(&data, 1, INTEGER, master);
            printf("Process %d sent data [%d]\n", id, data);
        } else {
            comm.Bcast(&data, 1, INTEGER, master);
            printf("Process %d catched data [%d]\n", id, data);
        }
    }

    void task7() {
        barrier("Task 7");
        string data = "";
        //int dataLen = 3;
        if (id == master) {
            char * temp = new char[100];
            scanf("%s", temp);
            data = temp;
            delete temp;
            printf("Process %d initialized data [%s]\n", id, data.data());  
        }
        comm.Barrier();
        if(id == master){
            int len = data.length();
            comm.Bcast(&len, 1, INTEGER, master);
            printf("Process %d sent length [%d]\n", id, data.length());
            comm.Bcast((char *) data.data(), len + 1, CHAR, master);
            printf("Process %d sent data [%s]\n", id, data.data());
        } else {
            char *resp;
            int len = 0;
            comm.Bcast(&len, 1, INTEGER, master);
            printf("Process %d catched length [%d]\n", id, len);
            resp = new char[len + 1];
            comm.Bcast(resp, len + 1, CHAR, master);
            printf("Process %d catched data [%s]\n", id, resp);
            delete resp;
        }    
    }
    
    void task8() {
        barrier("Task 8");
        int excludeNode = size - 1;
        Group group = comm.Get_group().Excl(1, &excludeNode);
        Intracomm newComm = comm.Create(group);

        string data = "default";
        if (newComm != COMM_NULL) {
            if (newComm.Get_rank() == master) {
                data = "task8";
                printf("Process %d initialized data [%s]\n", id, &data[0]);
            }
            newComm.Barrier();
            if(id == master) {
                int len = data.length();
                newComm.Bcast(&len, 1, INTEGER, master);
                newComm.Bcast(&data[0], len + 1, CHAR, master);
                printf("Process %d sent data [%s]\n", id, &data[0]);
            } else {
                int len = 0;
                newComm.Bcast(&len, 1, INTEGER, master);
                char *resp = new char[len + 1];
                newComm.Bcast(resp, len + 1, CHAR, master);
                printf("Process %d catched data [%s]\n", id, resp);
                delete resp;
            }
            newComm.Free();
            group.Free();
        }
    }

    void task9() {
        barrier("Task 9");
        int excludeNode = size - 1;
        int elements[] = {0, 2};
        Group group = comm.Get_group().Incl(2, elements);
        Intracomm newComm = comm.Create(group);

        int data = 5;
        int dataLen = 1;
        if (newComm != COMM_NULL) {
            if (newComm.Get_rank() == master) {
                data = 3;
                printf("Process %d initialized data [%d]\n", id, data);
            }
            int red = 0;
            newComm.Reduce(&data, &red, dataLen, INTEGER, SUM, 0);
            if (newComm.Get_rank() == master) {
                printf("Reduced data: [%d]\n", red);
            }
            newComm.Free();
            group.Free();
        }
    }
};

int main(int argc, char** argv) {
    srand(time(0));
    Lab2 &lab = *(new Lab2());
    lab.task1();
    lab.task2();
    lab.task3();
    lab.task4();
    lab.task5();
    lab.task6();
    lab.task7();
    lab.task8();
    lab.task9();

    lab.barrier("Finished lab 2");
    delete &lab;
    return 0;
}

