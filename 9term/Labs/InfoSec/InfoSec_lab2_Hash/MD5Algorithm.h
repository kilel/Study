#ifndef MD5ALGORITHM_H
#define	MD5ALGORITHM_H

#include "HashAlgorithm.h"

namespace hashAlgo {

    class MD5Algorithm : public HashAlgorithm {
    public:
        MD5Algorithm();
        MD5Algorithm(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
        MD5Algorithm(const MD5Algorithm& orig);
        virtual ~MD5Algorithm();
        virtual string hash(string source);
    private:
        uint32_t A = 0x3fa5bb4a;
        uint32_t B = 0xa826cf96;
        uint32_t C = 0x13ab5b2c;
        uint32_t D = 0x7af5bc4a;

        const int positionModule = 16;
        int numInBlock[4][2] = {//position + shift per iteration.
            {0, 1},
            {1, 5},
            {5, 3},
            {0, 7}
        };

        int shift[4][4] = {
            {7, 12, 17, 22},
            {5, 9, 14, 20},
            {4, 11, 16, 23},
            {6, 10, 15, 21}
        };
        
        long long HASHSIN[64];
        
        void initialize();
        
        uint32_t F(uint32_t a, uint32_t b, uint32_t c);
        uint32_t G(uint32_t a, uint32_t b, uint32_t c);
        uint32_t H(uint32_t a, uint32_t b, uint32_t c);
        uint32_t I(uint32_t a, uint32_t b, uint32_t c);
        uint32_t NOT(uint32_t value);
        uint32_t cycleShift(uint32_t value, uint32_t length);
        
        vector<uint32_t>* getData(string value);
        void processDataBlock(uint32_t *block, uint32_t *result);
        
    };

}

#endif	/* MD5ALGORITHM_H */

