#include <iostream>
#include <vector>
#include <string>
#include "include/BigInt.h"

using namespace std;
using namespace long_math;

void print(BigInt value, string s) {
    BigIntData* data = value.getData();
    cout << s;
    for(BigIntData::iterator it = data->begin(); it != data->end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

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
    (a*b*c).div(b)->println("(a*b*c).div(b)");
    (a*c).println("(a*c)");
}

int main() {
    testSum();
    testSub();
    testMult();
    testDiv();

    return 0;
}
