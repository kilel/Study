#include "RSAKey.h"
#include "EncodedMessage.h"
#include <fstream>
#include <sstream>
#include <string>

namespace RSA {

    RSAKey::RSAKey(BigInt* module, BigInt* value) {
        this->module = new BigInt(*module);
        this->key = new BigInt(*value);
    }

    RSAKey::RSAKey(string file) {
        ifstream in;
        in.open(file);
        string data;
        in >> data;
        module = new BigInt(data);
        in >> data;
        key = new BigInt(data);
        in.close();
    }

    void RSAKey::save(string file) {
        ofstream out;
        out.open(file);
        out << module->toString() << endl;
        out << key->toString() << endl;
        out.close();
    }

    RSAKey::RSAKey(const RSAKey& orig) {
        module = new BigInt(*orig.module);
        key = new BigInt(*orig.key);
    }

    RSAKey::~RSAKey() {
        delete module;
        delete key;
    }

    string RSAKey::toString() {
        stringstream out;
        out << module->toString() << endl;
        out << key->toString() << endl;
        return out.str();
    }

    EncodedMessage* RSAKey::encrypt(Message *message) {
        cout << "Encrypting message" << endl;
        //message is a array of 2-bytes unsigned shorts
        MessageData* data = message->getData();
        int moduleLength = module->getData()->size();
        int dataBlock = moduleLength - 1;
        //clean data from zero elments
        while (data->back() == 0) {
            data->pop_back();
        }
        //create messages as BigInt values
        BigIntData *tempData = new BigIntData();
        EncodedMessage *retMessage = new EncodedMessage();
        retMessage->setDecodedDigest(message->getHash());
        vector<BigInt*> *partMessages = retMessage->getData();
        for (int i = 0; i < data->size(); i += dataBlock) {
            tempData->clear();
            for (int j = 0; j < dataBlock && i + j < data->size(); ++j) {
                tempData->push_back(data->at(i + j));
            }
            partMessages->push_back(new BigInt(*tempData));
        }
        //encode partial messages
        for (int i = 0; i < partMessages->size(); ++i) {
            partMessages->at(i)->powMod(*key, *module);
        }
        return retMessage;
    }

    Message* RSAKey::decrypt(EncodedMessage* message) {
        //decode data
        cout << "Decrypting message" << endl;
        vector<BigInt*> *data = message->getData();
        for (int i = 0; i < data->size(); ++i) {
            data->at(i)->powMod(*key, *module);
        }
        //write to response message
        Message *response = new Message();
        for (int i = 0; i < data->size(); ++i) {
            BigInt *value = data->at(i);
            for (BigIntData::iterator it = value->getData()->begin(); it != value->getData()->end(); ++it) {
                response->getData()->push_back(*it);
            }
        }
        //chech hash
        string expectedHash = message->getDecodedDigest();
        string calcHash = response->getHash();
        cout << "Checking decoded message hash:\n\t"
                << "Expected:[" << expectedHash << "]\n\t"
                << "Calculated:[" << calcHash << "]\n";
        if(expectedHash != calcHash) {
            cout << "Invalid hash, message is broken" << endl;
            assert(false);
        }
        //push message
        return response;
    }
}
