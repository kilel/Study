#include <cstdlib>
#include "big_int_test.h"
#include "RSAKeyFactory.h"

using namespace std;
using namespace RSA;

const string programName = "rsa";

const string keyGenFlag = "k";
const string encryptFlag = "code";
const string decryptFlag = "decode";
const string helpFlag = "help";

void printParams() {
    cout << "Format:" << endl;
    cout << "\t" << programName << " " << keyGenFlag << " keyLength privateKeyPath publicKeyPath" << endl;
    cout << "\t" << programName << " " << encryptFlag << "|" << decryptFlag << " inFile outFile RSAKey" << endl;
}

int main(int argc, char** argv) {
    srand(time(0));
    //big_int_test(); return 0;
    

    string *args = new string[argc];
    for (int i = 0; i < argc; ++i) {
        args[i] = argv[i];
        //cout << args[i] << endl;
    }

    if (argc > 1) {
        if (args[1] == helpFlag) {
            printParams();
            return 0;
        } else if (args[1] == keyGenFlag) {
            if (argc < 4) {
                cout << "Incorrect parameters\nFormat:\n\t k keyLength privateKeyPath publicKeyPath\n\n";
            }
            int keyLength = atoi(argv[2]);
            string privateKeyPath = args[3];
            string publicKeyPath = args[4];
            
            RSAKeySet *keySet = new RSAKeySet(keyLength);
            keySet->getPrivate()->save(privateKeyPath);
            keySet->getPublic()->save(publicKeyPath);

            cout << "Keys created:\nPrivate = " << privateKeyPath << "\nPublic = " << publicKeyPath << endl;
            return 0;
        } else if (args[1] == encryptFlag || args[1] == decryptFlag) {
            if (argc < 4) {
                cout << "Incorrect parameners\nFormat:\n\t{code|decode} inFile outFile RSAKey\n\n";
            }
            string inputFile = args[2];
            string outFile = args[3];
            string keyPath = args[4];
            
            RSAKey *key = new RSAKey(keyPath);

            if (args[1] == encryptFlag) {
                Message *in = Message::getFromFile(inputFile);
                key->encrypt(in)->save(outFile);
                cout << "Successfully encrypted" << endl;
            } else {
                EncodedMessage *in = EncodedMessage::readFromFile(inputFile);
                key->decrypt(in)->save(outFile);
                cout << "Successfully decrypted" << endl;
            }
            return 0;
        }
    }
    printParams();
    return 0;
}

