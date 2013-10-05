#ifndef PUBLICKEY_H
#define	PUBLICKEY_H

#include "BigInt.h"
#include "Message.h"


namespace RSA {
    using namespace long_math;

    class RSAKey {
    public:
        RSAKey(BigInt* module, BigInt* value);
        RSAKey(string file);
        RSAKey(const RSAKey& orig);
        virtual ~RSAKey();
        
        vector<BigInt*>* encrypt(Message *message);
        Message* decrypt(vector<BigInt*> *data);
        void save(string file);
        
        string toString();
    private:
        BigInt* module;
        BigInt* key;
    };

}

#endif	/* PUBLICKEY_H */

