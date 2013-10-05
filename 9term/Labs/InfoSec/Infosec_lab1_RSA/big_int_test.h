#include <iostream>
#include <vector>
#include <string>
#include "BigInt.h"

using namespace std;
using namespace long_math;

void testInit() {
    cout << "\ntesting init\n";
    string num = "-1245692834295329834";
    BigInt init = *(new BigInt(num));
    init.println("Init test [-1245692834295329834]");
    
    num = "1413a3bc345ef4d23d2b23db2da";
    init = *(new BigInt(num));
    init.println("Init test [1413a3bc345ef4d23d2b23db2da]");
}

void testSum() {
    cout << "\ntesting add\n";
    BigInt a = *(new BigInt(1234567));
    a.println("a");
    BigInt b = *(new BigInt(1000001));
    b.println("b");
    (a + b).println("a + b");
    (b + a).println("b + a");
    (a + 1000001).println("a + 13646");
    (a - 0).println("a + 0");
}

void testSub() {
    cout << "\ntesting sub\n";
    BigInt a = *(new BigInt(1234567));
    a.println("a");
    BigInt b = *(new BigInt(1000001));
    BigInt c = *(new BigInt(-1));
    BigInt d = *(new BigInt(-5));
    b.println("b");
    (a - b).println("a - b");
    (b - a).println("b - a");
    (a - 1000001).println("a - 1000001");
    (d - 0).println("4 ?");
}

void testMult() {
    cout << "\ntesting mult\n";
    BigInt a = *(new BigInt(1234567));
    a.println("a");
    BigInt b = *(new BigInt(1000001));
    b.println("b");
    (a * b).println("a * b");
    (b * a).println("b * a");
    (a * (-1000001)).println("a * 1000001");
}

void testPow() {
    cout << "\ntesting pow\n";
    BigInt c = *(new BigInt(2));
    BigInt d = *(new BigInt(256));
    BigInt mod = *(new BigInt(100000));
    c.powMod(d, mod*mod)->println("2^256 % 100000 00000");
    c = *(new BigInt(2));
    c.powMod(d, mod)->println("2^256 % 100000");
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
    (*(new BigInt(-42849)) % *(new BigInt(67))).println("div < 0");
    
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
    string cs = "245928492468";
    string ds = "24829846797";
    BigInt a = *(new BigInt(1234567));
    BigInt b = *(new BigInt(1000001));
    BigInt c = *(new BigInt(cs));
    BigInt d = *(new BigInt(ds));
    string getBool[] = {"false", "true"};
    a.println(string("prime test, " + getBool[a.isPrime()]));
    b.println(string("prime test, " + getBool[b.isPrime()]));
    c.println(string("prime test, " + getBool[c.isPrime()]));
    d.println(string("prime test, " + getBool[d.isPrime()]));
}

void testInverce() {
    cout << "\ntesting inverce\n";
    BigInt a = *(new BigInt(45));
    BigInt b = *(new BigInt(3484));
    BigInt c;
    c.copy(a);
    a.println("a");
    b.println("mod");
    a.inverseMod(b)->println("a inverce mod");
    a.mult(c)->mod(b)->println("a * a^-1 mod");
    
    string sb = "247020623";
    a = *(new BigInt(2834659));
    b = *(new BigInt(sb));
    c.copy(a);
    a.println("a");
    b.println("mod");
    a.inverseMod(b)->println("a inverce mod");
    a.mult(c)->mod(b)->println("a * a^-1 mod");
}

int big_int_test() {
    testInit();
    testSum();
    testSub();
    testMult();
    testPow();
    testDiv();
    testGcd();
    //testPrime();
    testInverce();

    return 0;
}
