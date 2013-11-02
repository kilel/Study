#include <cstdlib>

#include "DesMessage.h"
#include "DesKey.h"

using namespace std;
using namespace DES;

string KEY_ENCODE = "code";
string KEY_DECODE = "decode";

int main(int argc, char** argv) {
    string *args = new string[argc];
    for(int i = 0; i < argc; ++i) {
        args[i] = argv[i];
    }
    
    //DesMessage *irn = DesMessage::fromFile("test.cpp");
    //DesKey *ds = new DesKey("");
    //ds->encrypt(irn)->save("en");
    //ds->decrypt(ds->encrypt(irn))->save("res");;
    //return 0;
    
    if(argc > 4) {
        string action = args[1];
        string from = args[2];
        string to = args[3];
        string key = args[4];
        
        DesMessage *in = DesMessage::fromFile(from);
        DesMessage *out;
        DesKey *desKey = new DesKey(key);
        if(action == KEY_DECODE) {
            out = desKey->decrypt(in);
        } else if(action == KEY_ENCODE) {
            out = desKey->encrypt(in);
        } else {
            cout << "Unknown action " << action << ". Valid are code and decode." << endl;
            return 1;
        }
        out->save(to);
        return 0;
    }
    
    cout << "Format:\n\t" 
            << "des code from to key\n\t"
            << "des decode from to key\n\t" << endl;
    
    return 0;
}

