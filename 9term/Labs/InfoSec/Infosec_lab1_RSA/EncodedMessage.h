#ifndef ENCODEDMESSAGE_H
#define	ENCODEDMESSAGE_H

#include "BigInt.h"
#include "../InfoSec_lab2_Hash/MD5Algorithm.h"


namespace RSA {
    using namespace long_math;
    using namespace hashAlgo;

    class EncodedMessage {
    public:
        EncodedMessage();
        EncodedMessage(const EncodedMessage& orig);
        virtual ~EncodedMessage();

        static EncodedMessage* readFromFile(string path);
        void save(string path);

        vector<BigInt*>* getData() {
            return data;
        }

        string getHash();

        void setDecodedDigest(string digest) {
            this->digest = digest;
        }
        
        string getDecodedDigest() {
            return digest;
        }
    private:
        MD5Algorithm md5;
        vector<BigInt*> *data;
        string digest;
    };
}

#endif	/* ENCODEDMESSAGE_H */

