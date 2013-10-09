#include <sstream>

#include "CRCAlgorithm.h"

namespace hashAlgo {

    CRCAlgorithm::CRCAlgorithm() {
        for (int i = 0; i < 256; ++i) {
            int precalc = i;
            for (int j = 0; j < 8; ++j) {
                precalc = precalc & 1 ? (precalc >> 1)^crcBase : precalc >> 1;
            }
            hashTable[i] = precalc;
        }
    }

    CRCAlgorithm::CRCAlgorithm(const CRCAlgorithm& orig) {
    }

    CRCAlgorithm::~CRCAlgorithm() {
    }

    string CRCAlgorithm::hash(string source) {
        uint32_t hash = 0xFFFFFFFF;
        for(int i = 0; i < source.length(); ++i) {
            hash = hashTable[(hash ^ source[i]) & 0xFF] ^ (hash >> 8);
        }
        hash ^= 0xFFFFFFFF;
        
        stringstream out;
        out << hex << hash;
        return out.str();
    }

}

