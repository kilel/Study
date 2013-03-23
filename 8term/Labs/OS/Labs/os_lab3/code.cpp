/* 
 * File:   code.cpp
 * Author: hkyten
 *
 * Created on 9 Март 2013 г., 17:58
 */

#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <cmath>
#include <unistd.h>
#include <time.h>

using namespace std;

//[consts]
const int cntPhil = 5;
//end [consts]

int mod(int a, int m) {
    return a >= 0 ? a % m : (a % m + m) % m;
}
timespec tsleep;

/*
class DinningPhilosophers {
private:
    int *fork; // who is using. -1 if no one
    int *phil; //0 -- want eat, 1 -- want sleep.
    int *isDinning;
    int *isForkBlocked;
    int *cntDinned;
    int curr;
    int maxPhil;
    int outputBlock;
    int numUsedForks;
    int numDinningPh;

    void fightForTheFork(int numPhil, int wantage) {//wantage is 0 left or 1 right
        int currFork = (numPhil + wantage) % maxPhil;
        phil[numPhil] = currFork;
        int neigh = (numPhil + (wantage ? 1 : -1))%maxPhil;
        fork[currFork] = neigh;
        while ((fork[currFork] == neigh && phil[neigh] == (currFork)) || isForkBlocked[currFork])
            nanosleep(&tsleep, &tsleep);
        //write, that you took this one;
        while (outputBlock)
            nanosleep(&tsleep, &tsleep); //sleep for 100ns

        outputBlock = 1;
        cout << "ph [" << numPhil << "] took fork [" << currFork << "]\n";
        outputBlock = 0;
        //block fork
        isForkBlocked[currFork] = 1;
        ++numUsedForks;
        phil[numPhil] = -1;
    }
    void putForkDown(int numPhil, int currFork){
        isForkBlocked[currFork] = 0;
        --numUsedForks;
        
        while (outputBlock)
            nanosleep(&tsleep, &tsleep); //sleep for 100ns

        outputBlock = 1;
        cout << "ph [" << numPhil << "] put down fork [" << currFork << "]\n";
        outputBlock = 0;
    }
public:

    DinningPhilosophers(int number) {
        fork = new int[number];
        phil = new int[number];
        isDinning = new int[number];
        isForkBlocked = new int[number];
        cntDinned = new int[number];
        for (int i = 0; i < number; ++i) {
            fork[i] = i;
            phil[i] = -1;
            isDinning[i] = 0;
            isForkBlocked[i] = 0;
            cntDinned[i] = 0;
        }
        curr = -1;
        maxPhil = number;
        outputBlock = 0;
        numUsedForks = 0;
        numDinningPh = 0;
    }

    DinningPhilosophers() {
        DinningPhilosophers(0);
    }

    ~DinningPhilosophers() {
        delete[] fork;
    }

    void main(int numPhil) {
        int wantage;
        int neigh;
        int currFork;
        while (1) {
            if (!(numUsedForks == maxPhil - 1 && numDinningPh == 0)) {

                //i'm hungry! want to eat!
                wantage = rand() % 2;
                //try to get first fork
                fightForTheFork(numPhil, wantage);
                fightForTheFork(numPhil, 1 - wantage);
                //dinning
                ++numDinningPh;
                isDinning[numPhil] = 1;
                ++cntDinned[numPhil];
                while (outputBlock)
                    nanosleep(&tsleep, &tsleep); //sleep for 200ns

                outputBlock = 1;
                for (int i = 0; i < maxPhil; ++i)
                    cout << isDinning[i] << " ";
                cout << "\n";
                for (int i = 0; i < maxPhil; ++i)
                    cout << cntDinned[i] << " ";
                cout << "\n";
                outputBlock = 0;
                sleep(1);
                //nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);
                isDinning[numPhil] = 0;
                --numDinningPh;
                
                putForkDown(numPhil, numPhil);
                putForkDown(numPhil, (numPhil + 1) % maxPhil);
                

            }
            sleep(1); //sleeping after dinner
            //nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);

        }

    }
};
*/

class DinningPhilosophers {
private:
    int *fork; // who is using. -1 if no one
    int *phil; //0 -- want eat, 1 -- want sleep.
    int *isDinning;
    int *cntDinned;
    int maxPhil;
    int outputBlock;
public:
    DinningPhilosophers(int number) {
        fork = new int[number];
        phil = new int[number];
        isDinning = new int[number];
        cntDinned = new int[number];
        for (int i = 0; i < number; ++i) {
            fork[i] = i;
            phil[i] = -1;
            isDinning[i] = 0;
            cntDinned[i] = 0;
        }
        maxPhil = number;
        outputBlock = 0;
    }
    DinningPhilosophers() {
        DinningPhilosophers(0);
    }
    ~DinningPhilosophers() {
        delete[] fork;
        delete[] isDinning;
        delete[] phil;
        delete[] cntDinned;
    }
    void main(int numPhil) {
        /*int left = mod(numPhil-1, maxPhil), right = (numPhil+1)%maxPhil;
        while (1) {
            phil[numPhil] = 1;
            fork[numPhil] = left;
            fork[right] = right;
            while( (phil[left] && fork[numPhil] == left) || (phil[right] && fork[right] == right) )
                nanosleep(&tsleep, &tsleep);
            isDinning[numPhil] = 1;
            cntDinned[numPhil]++;
            
            //writing out
            while (outputBlock)
                nanosleep(&tsleep, &tsleep); 
            outputBlock = 1;
            for (int i = 0; i < maxPhil; ++i)
                cout << isDinning[i] << " ";
            cout << "\n";
            outputBlock = 0;
            //eating
            nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);
            //free resources
            isDinning[numPhil] = 0;
            phil[numPhil] = 0;
            //thinking about smth
            nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);
        }*/
        while(1){
        int t = maxPhil;
        asm(
        "xor %%rdi, %%rdi\n\t" //rdi = 0
        "mov %[n], %%edi\n\t"  // rdi = n
        "mov %[p], %%r14\n\t"
        "mov %[f], %%r15\n\t"
        "mov %[isD], %%r10\n\t" //is
        "mov %[cnt], %%r11\n\t" //cnt
        "mov %%rdi, %%rcx\n\t" // rcx - left
        "mov %%rdi, %%rdx\n\t" // rdx - right
        "xor %%eax, %%eax\n\t"
        "mov %[m], %%eax\n\t"
        "sub $1, %%eax\n\t"     //eax = max-1
        "xor %%rbx, %%rbx\n\t" //rbx  = 0
        "cmp %%rcx, %%rbx\n\t" //cmp to 0
        "jne m1\n\t"          //
        "mov %%rax, %%rcx\n\t" // cur == 0 => cur = max-1
        "jmp m11\n\t"         //exit
        "m1: "
        "dec %%rcx\n\t" // else
        
        "m11: \n\t"
        "cmp %%rdx, %%rax\n\t"
        "jne m2\n\t"
        "mov %%rbx, %%rdx\n\t"
        "jmp m22\n\t"
        "m2: "
        "inc %%rdx\n\t"  //end data reading
        
        "m22: \n\t"
        "inc %%ebx\n\t"
        "mov %%ebx, (%%r14, %%rdi, 4)\n\t"
        "dec %%ebx \n\t"
        
        "mov %%ecx, (%%r15, %%rdi, 4)\n\t"
        "mov %%edx, (%%r15, %%rdx, 4)\n\t"
        "xor %%rsi, %%rsi\n\t"
        
        "mainCycle: \n\t"
        "mov (%%r15, %%rdi, 4), %%esi\n\t"
        "cmp %%esi, %%ecx\n\t"
        "jne step2\n\t"
        "mov (%%r14, %%rcx, 4), %%esi\n\t"
        "cmp %%esi, %%ebx\n\t"
        "je step2\n\t"
        "jmp mainCycle\n\t"
        
        "step2:\n\t"
        "mov (%%r15, %%rdx, 4), %%esi\n\t"
        "cmp %%esi, %%edx\n\t"
        "jne crit\n\t"
        "mov (%%r14, %%rdx, 4), %%esi\n\t"
        "cmp %%esi, %%ebx\n\t"
        "je crit\n\t"
        "jmp mainCycle\n\t"
        
        "crit:\n\t"
        "inc %%ebx\n\t"
        "mov %%ebx, (%%r10, %%rdi, 4)\n\t"
        "add %%ebx, (%%r11, %%rdi, 4)\n\t"
        "dec %%ebx\n\t"
        "\n\t"
        "\n\t"
        "\n\t"
        "\n\t"
        "\n\t"
        "\n\t"
        :
        :[n]"m"(numPhil), [m]"m"(t), [f]"m"(fork), [p]"m"(phil), [isD]"m"(isDinning), [cnt]"m"(cntDinned) 
        );
        //writing out
        while (outputBlock)
             nanosleep(&tsleep, &tsleep); 
        outputBlock = 1;
        for (int i = 0; i < maxPhil; ++i)
            cout <<" " << isDinning[i];
        cout << "\n";
        outputBlock = 0;
        //eating
        nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);nanosleep(&tsleep, &tsleep);
        //free resources
        isDinning[numPhil] = 0;
        phil[numPhil] = 0;
    }
    }
};

DinningPhilosophers dp;

void* enterTable(void* index) {
    dp.main(*((int*) index));
}

int main(int argc, char** argv) {
    srand(time(0));

    tsleep.tv_nsec = 200;

    dp = DinningPhilosophers(cntPhil);
    pthread_t *philThreads = new pthread_t[cntPhil];
    int *numPhil = new int[cntPhil];

    for (int it = 0; it < cntPhil; ++it) {
        numPhil[it] = it;
        pthread_create(&philThreads[it], 0, enterTable, (void*) &numPhil[it]);
        //cout << *((int*)((void*)&numPhil[it])) << endl;
    }
    timespec a, b;
    
    sleep(20);
    
    for (int it = 0; it < cntPhil; ++it) {
        pthread_cancel(philThreads[it]);
    }
    return 0;
}