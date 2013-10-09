#include <sstream>

#include "MD5Algorithm.h"

namespace hashAlgo {

    /**
     * Create MD5 with default parameters.
     */
    MD5Algorithm::MD5Algorithm() {
        initialize();
    }

    /**
     * Create MD5 with specified initial parameters.
     * @param a
     * @param b
     * @param c
     * @param d
     */
    MD5Algorithm::MD5Algorithm(unsigned int a, unsigned int b, unsigned int c, unsigned int d) :
    A(a), B(b), C(c), D(d) {
        initialize();
    }

    MD5Algorithm::MD5Algorithm(const MD5Algorithm& orig) :
    A(orig.A), B(orig.B), C(orig.C), D(orig.D) {
        initialize();
    }

    void MD5Algorithm::initialize() {
        for (int i = 0; i < 64; ++i) {
            HASHSIN[i] = (((long long) 2) << 32) * fabs(sin(i + 1));
        }
    }

    MD5Algorithm::~MD5Algorithm() {
    }

    uint32_t MD5Algorithm::NOT(uint32_t value) {
        return value ^ 0xFFFFFFFF;
    }

    uint32_t MD5Algorithm::F(uint32_t a, uint32_t b, uint32_t c) {
        return (a & b) | (NOT(a) & c);
    }

    uint32_t MD5Algorithm::G(uint32_t a, uint32_t b, uint32_t c) {
        return (a & c) | (NOT(c) & b);
    }

    uint32_t MD5Algorithm::H(uint32_t a, uint32_t b, uint32_t c) {
        return a ^ b ^ c;
    }

    uint32_t MD5Algorithm::I(uint32_t a, uint32_t b, uint32_t c) {
        return b ^ (NOT(c) | a);
    }

    uint32_t MD5Algorithm::cycleShift(uint32_t value, uint32_t length) {
        return (value << length) | (value >> (32 - length));
    }

    vector<uint32_t>* MD5Algorithm::getData(string source) {
        vector<char> *charData = new vector<char>(0);
        vector<uint32_t> *data = new vector<uint32_t>(0);
        unsigned long long length = source.length();
        uint32_t len_1 = length;
        uint32_t len_2 = length >> 32;

        {//align data
            for (int i = 0; i < length; ++i) {
                charData->push_back(source[i]);
            }
            charData->push_back(0x80); // 1000 0000 pushed to end
            charData->push_back(0);
            while (charData->size() % 64 != 56) {
                charData->push_back(0);
            }
        }
        {//rewrite to uint32_t
            for (auto it = charData->begin(); it != charData->end();) {
                uint32_t temp = *it++;
                temp = temp << 8 + *it++;
                temp = temp << 8 + *it++;
                temp = temp << 8 + *it++;
                data->push_back(temp);
            }
        }
        data->push_back(len_1);
        data->push_back(len_2);
        delete charData;
        return data;
    }

    void MD5Algorithm::processDataBlock(uint32_t *block, uint32_t *result) {
        for (int step = 0; step < 4; ++step) {
            for (int substep = 0; substep < 16; ++substep) {
                int funcRes = 0;

                switch (step) {
                    case 0:
                        funcRes = F(result[(substep + 1) % 4], result[(substep + 2) % 4], result[(substep + 3) % 4]);
                        break;
                    case 1:
                        funcRes = G(result[(substep + 1) % 4], result[(substep + 2) % 4], result[(substep + 3) % 4]);
                        break;
                    case 2:
                        funcRes = H(result[(substep + 1) % 4], result[(substep + 2) % 4], result[(substep + 3) % 4]);
                        break;
                    case 3:
                        funcRes = I(result[(substep + 1) % 4], result[(substep + 2) % 4], result[(substep + 3) % 4]);
                        break;
                }
                result[substep % 4] = result[(substep + 1) % 4]
                        + cycleShift(result[substep % 4]
                        + funcRes + block[(numInBlock[step][1] + numInBlock[step][1] * substep) % 16]
                        + HASHSIN[step * 16 + substep],
                        shift[step][substep % 4]);
            }
        }
    }

    string MD5Algorithm::hash(string source) {
        vector<uint32_t> *data = getData(source);
        uint32_t *tempData = new uint32_t[16];
        uint32_t *result = new uint32_t[4];
        result[0] = A;
        result[1] = B;
        result[2] = C;
        result[3] = D;

        const int delta = 16;
        for (int i = 0; i < data->size(); i += delta) {
            for (int j = 0; j < delta; ++j) {
                tempData[j] = data->at(i+j);
            }
            processDataBlock(tempData, result);
        }
        //return "";
        stringstream out;
        out << hex << result[0] << result[1] << result[2] << result[3];
        return out.str();
    }
}

