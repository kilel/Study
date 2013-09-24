/* 
 * File:   BITest.cpp
 * Author: hkyten
 *
 * Created on 22.09.2013, 13:19:35
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include "BigInt.h"

using namespace std;
using namespace long_math;

void test1() {
    std::cout << "BITest test 1" << std::endl;
}

/*void test2() {
    std::cout << "BITest test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (BITest) message=error message sample" << std::endl;
}*/


void testSum(){
    cout << "testing add\n";
    BigInt a = *(new BigInt(1234567));
    a.println("a");
    BigInt b = *(new BigInt(1000001));
    b.println("b");
    (a + b).println("a + b");
    (b + a).println("b + a");
    (a + 1000001).println("a + 13646");
}

void testSub(){
    cout << "\ntesting sub\n";
    BigInt a = *(new BigInt(1234567));
    a.println("a");
    BigInt b = *(new BigInt(1000001));
    b.println("b");
    (a - b).println("a - b");
    (b - a).println("b - a");
    (a - 1000001).println("a - 1000001");
}

void testMult(){
    cout << "\ntesting mult\n";
    BigInt a = *(new BigInt(1234567));
    a.println("a");
    BigInt b = *(new BigInt(1000001));
    b.println("b");
    (a * b).println("a * b");
    (b * a).println("b * a");
    (a * 1000001).println("a * 1000001");

    BigInt c = *(new BigInt(2));
    BigInt d = *(new BigInt(256));
    BigInt mod = *(new BigInt(100000));
    mod.mult(mod);
    c.powMod(d, mod)->println("2^256 % 100000 00000");

}

void testDiv(){
    cout << "\ntesting div\n";
    BigInt a = *(new BigInt(1234567));
    BigInt b = *(new BigInt(1000001));
    BigInt c = *(new BigInt(2756199));
    BigInt d = *(new BigInt(24624));
    a.println("a");
    b.println("b");
    //a.div(123)->println("a div 123");
    (a*b*c).println("a*b*c");
    ((a*b*c) / b).println("(a*b*c) / (b)");
    (a*c).println("(a*c)");
    ((a*b*c*d) / (d * b)).println("(a*b*c*d) / (d * b)");
    ((a*b*c*d + b*d + c*b + a*d) % (d * b)).println("((a*b*c*d + b*d + c*b + a*d) % (d * b))");
    ((c*b + a*d) % (d * b)).println("((c*b + a*d) % (d * b))");
    (* (new BigInt(256)) % *(new BigInt(4))).println("256 % 4");
    string num = "-1245692834295329834";
    BigInt init = *(new BigInt(num));
    init.println("Init test [1245692834295329834]");
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% BITest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (BITest)" << std::endl;
    testSum();
    std::cout << "%TEST_FINISHED% time=0 test1 (BITest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

