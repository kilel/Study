#include "DesKey.h"
#include "DesMessage.h"

namespace DES {

    DesKey::DesKey(string _key) : key(_key) {
        generateKeys();
        assert(permutate(permutate(123456, 64, inputPermutation, inPermLen), 64, endPermutation, inPermLen) == 123456);
    }

    DesKey::~DesKey() {
    }

    uint64_t DesKey::permutate(uint64_t number, int numLen, int* permutation, int permLen) {
        uint64_t result = 0;
        for (int i = 0; i < permLen; ++i) {
            result = result << 1 | ((number >> (numLen - permutation[i])) & 1);
        }
        for (int i = 0; i < permLen; ++i) {
            assert(((result >> (permLen - i - 1)) & 1) == ((number >> (numLen - permutation[i])) & 1));
        }
        return result;
    }

    uint64_t DesKey::cycleShiftLeft(uint64_t val, int length, int count) {
        count = (count % length + length) % length;
        uint64_t mask = 0;
        for (int i = 0; i < length; ++i) {
            uint64_t one = 1;
            mask |= one << i;
        }
        return ((val << count) | (val >> (length - count))) & mask;
    }

    void DesKey::generateKeys() {
        uint64_t keyVal = 0;
        for (int i = 0; i < 8; ++i) {
            if (key.length() >= i) {
                keyVal = keyVal << 8 | key[i];
            } else {
                keyVal = keyVal << 8 | 32;
            }
        }
        uint64_t leftKey = 0, rightKey = 0;
        leftKey = permutate(keyVal, 64, leftKeyPerm, keyPermLen);
        rightKey = permutate(keyVal, 64, rightKeyPerm, keyPermLen);
        for (int i = 0; i < keyCount; ++i) {
            leftKey = cycleShiftLeft(leftKey, keyPermLen, keyShift[i]);
            rightKey = cycleShiftLeft(rightKey, keyPermLen, keyShift[i]);
            uint64_t rawKey = (leftKey << keyPermLen) | rightKey;
            keys[i] = permutate(rawKey, 56, finalKeyPerm, extensionPermLen);
        }
    }

    uint64_t DesKey::coreFunction(uint64_t val, uint64_t key) {
        uint64_t mask = 0x3F; //00111111
        uint64_t ext = permutate(val, 32, extension, extensionPermLen);
        uint64_t res = ext ^ key;
        uint64_t ret = 0;
        for (int i = 0; i < 8; ++i) {
            uint64_t base = (res >> ((7 - i) * 6)) & mask;
            int a = ((base >> 5) << 1) | (base & 1);
            int b = (base >> 1) & 0xF;
            ret = ret << 4 | coreSPermtation[i][a][b];
        }
        return permutate(ret, 32, coreEndPermutation, coreEndPermLen);
    }

    uint64_t DesKey::encrypt(uint64_t val) {
        cout << "Encripting token " << val << endl;
        uint64_t toProcess = permutate(val, 64, inputPermutation, inPermLen);
        for (int i = 0; i < keyCount; ++i) {

            uint64_t left = toProcess >> 32;
            uint64_t right = toProcess & 0xFFFFFFFFULL;

            uint64_t nextLeft = right;
            uint64_t nextRight = left ^ coreFunction(right, keys[i]);

            toProcess = nextLeft << 32 | nextRight;
        }
        uint64_t ret = permutate(toProcess, 64, endPermutation, inPermLen);
        cout << "Result: " << ret << endl;
        return ret;
    }

    uint64_t DesKey::decrypt(uint64_t val) {
        cout << "Decripting token " << val << endl;
        uint64_t toProcess = permutate(val, 64, inputPermutation, inPermLen);
        for (int i = keyCount - 1; i >= 0; --i) {
            uint64_t left = toProcess >> 32;
            uint64_t right = toProcess & 0xFFFFFFFFULL;

            uint64_t nextLeft = right ^ coreFunction(left, keys[i]);
            uint64_t nextRight = left;

            toProcess = nextLeft << 32 | nextRight;
        }
        uint64_t ret = permutate(toProcess, 64, endPermutation, inPermLen);
        cout << "Result: " << ret << endl;
        return ret;
    }

    DesMessage* DesKey::encrypt(DesMessage *message) {
        cout << "Encrypting message, length = " << message->getData()->size() << endl;
        DesMessage *ret = new DesMessage();
        MessageData *inData = message->getData();
        MessageData *outData = ret->getData();
        for (MessageData::iterator it = inData->begin(); it != inData->end(); ++it) {
            outData->push_back(encrypt(*it));
        }
        return ret;
    }

    DesMessage* DesKey::decrypt(DesMessage *message) {
        cout << "Decrypting message, length = " << message->getData()->size() << endl;
        DesMessage *ret = new DesMessage();
        MessageData *inData = message->getData();
        MessageData *outData = ret->getData();
        for (MessageData::iterator it = inData->begin(); it != inData->end(); ++it) {
            outData->push_back(decrypt(*it));
        }
        return ret;
    }

}
