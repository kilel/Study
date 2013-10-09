#ifndef CRCALGORITHM_H
#define	CRCALGORITHM_H

#include "HashAlgorithm.h"
#include <cstdint>

namespace hashAlgo {

    class CRCAlgorithm : public HashAlgorithm{
    public:
        CRCAlgorithm();
        CRCAlgorithm(const CRCAlgorithm& orig);
        virtual ~CRCAlgorithm();
        virtual string hash(string source);
    private:
        uint32_t hashTable[256];
        
        uint32_t crcBase = 0xEDB88320;

    };
}

#endif	/* CRCALGORITHM_H */

