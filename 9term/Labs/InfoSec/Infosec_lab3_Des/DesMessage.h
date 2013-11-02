#ifndef DESMESSAGE_H
#define	DESMESSAGE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <inttypes.h>
#include <assert.h>

namespace DES {
    using namespace std;
    
    typedef vector<uint64_t> MessageData;

    class DesMessage {
    public:
        DesMessage();
        DesMessage(const DesMessage& orig);
        virtual ~DesMessage();
        
        static DesMessage* fromFile(string path);
        void save(string path);
        
        MessageData *getData() {
            return data;
        }
    private:
        MessageData *data;
    };
}

#endif	/* DESMESSAGE_H */

