#ifndef MESSAGE_H
#define	MESSAGE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "BigInt.h"
#include "../InfoSec_lab2_Hash/MD5Algorithm.h"

namespace RSA {
    using namespace std;
    using namespace long_math;
    using namespace hashAlgo;

    typedef vector<int> MessageData;

    class Message {
    public:
        Message();
        Message(string data);
        Message(const Message& orig);
        virtual ~Message();

        static Message* getFromFile(string path);
        void save(string path);
        string getHash();

        MessageData* getData() {
            return data;
        }
    private:
        MessageData *data;
        MD5Algorithm md5;
    };
}

#endif	/* MESSAGE_H */

