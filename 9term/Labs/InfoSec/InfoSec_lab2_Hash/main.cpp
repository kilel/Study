#include <cstdlib>
#include "MD5Algorithm.h"
#include "CRCAlgorithm.h"

using namespace std;
using namespace hashAlgo;

/*
 * 
 */
int main(int argc, char** argv) {
    MD5Algorithm *md5 = new MD5Algorithm();
    CRCAlgorithm *crc = new CRCAlgorithm();
    string s = "dfsdf";
    
    cout << md5->hash(s) << endl;
    cout << crc->hash(s) << endl;
    s = "dfsdd";
    cout << md5->hash(s) << endl;
    cout << crc->hash(s) << endl;
    return 0;
}

