#ifndef HASHALGORITHM_H
#define	HASHALGORITHM_H

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <cstdint>

namespace hashAlgo {
    using namespace std;

    class HashAlgorithm {
    public:
        virtual string hash(string source) = 0;
    private:

    };
}

#endif	/* HASHALGORITHM_H */

