#include <iostream>
#include <vector>
#include <string>
#include "BigInt.h"

using namespace std;
using namespace long_math;

void testSum() {
    cout << "\ntesting add\n";
    BigInt a = *(new BigInt(1234567));
    a.println("a");
    BigInt b = *(new BigInt(1000001));
    b.println("b");
    (a + b).println("a + b");
    (b + a).println("b + a");
    (a + 1000001).println("a + 13646");
}

void testSub() {
    cout << "\ntesting sub\n";
    BigInt a = *(new BigInt(1234567));
    a.println("a");
    BigInt b = *(new BigInt(1000001));
    b.println("b");
    (a - b).println("a - b");
    (b - a).println("b - a");
    (a - 1000001).println("a - 1000001");
}

void testMult() {
    cout << "\ntesting mult\n";
    BigInt a = *(new BigInt(1234567));
    a.println("a");
    BigInt b = *(new BigInt(1000001));
    b.println("b");
    (a * b).println("a * b");
    (b * a).println("b * a");
    (a * 1000001).println("a * 1000001");
}

void testPow() {
    cout << "\ntesting pow\n";
    BigInt c = *(new BigInt(2));
    BigInt d = *(new BigInt(256));
    BigInt mod = *(new BigInt(100000));
    mod.mult(mod);
    c.powMod(d, mod)->println("2^256 % 100000 00000");
}

void testDiv() {
    cout << "\ntesting div\n";
    BigInt a = *(new BigInt(1234567));
    BigInt b = *(new BigInt(1000001));
    BigInt c = *(new BigInt(2756199));
    BigInt d = *(new BigInt(24624));
    a.println("a");
    b.println("b");
    //a.div(123)->println("a div 123");
    (a * b * c).println("a*b*c");
    ((a * b * c) / b).println("(a*b*c) / (b)");
    (a * c).println("(a*c)");
    ((a * b * c * d) / (d * b)).println("(a*b*c*d) / (d * b)");
    ((a * b * c * d + b * d + c * b + a * d) % (d * b)).println("((a*b*c*d + b*d + c*b + a*d) % (d * b))");
    ((c * b + a * d) % (d * b)).println("((c*b + a*d) % (d * b))");
    (* (new BigInt(256)) % *(new BigInt(4))).println("256 % 4");
}

void testInit() {
    cout << "\ntesting init\n";
    string num = "-1245692834295329834";
    BigInt init = *(new BigInt(num));
    init.println("Init test [1245692834295329834]");
}

void testGcd() {
    cout << "\ntesting gcd\n";
    BigInt a = *(new BigInt(1234567));
    BigInt b = *(new BigInt(1000001));
    BigInt c = *(new BigInt(2 * 3 * 3 * 5 * 5));
    BigInt d = *(new BigInt(2 * 5 * 5));
    (a.gcd(b))->println("gcd test (prime)");
    (c.gcd(d))->println("gcd test (not prime)");
}

void testPrime() {
    cout << "\ntesting prime\n";
    BigInt a = *(new BigInt(1234567));
    BigInt b = *(new BigInt(1000001));
    BigInt c = *(new BigInt("245928492468"));
    BigInt d = *(new BigInt("24829846797"));
    string getBool[] = {"false", "true"};
    a.println(string("prime test, " + getBool[a.isPrime()]));
    b.println(string("prime test, " + getBool[b.isPrime()]));
    c.println(string("prime test, " + getBool[c.isPrime()]));
    d.println(string("prime test, " + getBool[d.isPrime()]));
}

int test() {
    testInit();
    testSum();
    testSub();
    testMult();
    testDiv();
    testPow();
    testGcd();
    testPrime();

    return 0;
}
