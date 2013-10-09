#ifndef RSAKEY_H
#define	RSAKEY_H

#include "BigInt.h"
#include "RSAKey.h"
#include <cstdlib>
#include <time.h>

namespace RSA {
    using namespace long_math;
    
    class RSAKeySet {
    public:
        RSAKeySet(int length);
        virtual ~RSAKeySet();

        RSAKey* getPrivate() {
            return privateKey;
        }

        RSAKey* getPublic() {
            return publicKey;
        }
    private:
        RSAKey *publicKey;
        RSAKey *privateKey;
    };

}
#endif

