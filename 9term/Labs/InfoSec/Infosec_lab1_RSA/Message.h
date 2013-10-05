#ifndef MESSAGE_H
#define	MESSAGE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "BigInt.h"

namespace RSA {
    using namespace std;
    using namespace long_math;

    typedef vector<int> MessageData;

    class Message {
    public:
        Message();
        Message(string data);
        Message(const Message& orig);
        virtual ~Message();

        static Message* getFromFile(string path);
        void save(string path);

        static vector<BigInt*>* readEncoded(string path);
        static void writeEncoded(string path, vector<BigInt*>* data);

        MessageData* getData() {
            return data;
        }
    private:
        MessageData *data;
    };
}

#endif	/* MESSAGE_H */

