#include "EncodedMessage.h"
#include "Message.h"

namespace RSA {

    EncodedMessage::EncodedMessage() {
        data = new vector<BigInt*>();
    }

    EncodedMessage::EncodedMessage(const EncodedMessage& orig) {
        data = new vector<BigInt*>();
        data->insert(data->begin(), orig.data->begin(), orig.data->end());
    }

    EncodedMessage::~EncodedMessage() {
        delete[] data;
    }

    EncodedMessage* EncodedMessage::readFromFile(string path) {
        EncodedMessage* message = new EncodedMessage();
        vector<BigInt*> *data = message->data;
        cout << "Reading encoded message from file: " << path << endl;

        int length;
        ifstream in;
        in.open(path);

        in >> length;
        //cout << "Readed length: " << length << endl;
        in >> message->digest;
        cout << "Readed decoded message digest: " << message->digest << endl;
        string encodedDigest;
        in >> encodedDigest;
        cout << "Readed encoded message digest: " << encodedDigest << endl;

        for (int i = 0; i < length; ++i) {
            string temp;
            in >> temp;
            //cout << "Readed token [" << i << "]: " << temp << endl;
            data->push_back(new BigInt(temp));
        }

        in.close();

        string calcHash = message->getHash();
        cout << "Checking digest via MD5:\n\tExpected=[" << encodedDigest << "]\n\t"
                << "Calculated=[" << calcHash << "]" << endl;
        if (calcHash != encodedDigest) {
            cout << "Error, encoded message is broken!" << endl;
            assert(false);
        }

        return message;
    }

    void EncodedMessage::save(string path) {
        cout << "Saving encrypted message to file: " << path << endl;
        ofstream out;
        out.open(path);
        out << data->size() << endl;
        out << digest << endl;
        out << getHash() << endl;

        for (auto it = data->begin(); it != data->end(); ++it) {
            out << (*it)->toString() << endl;
        }
        out.close();
    }

    string EncodedMessage::getHash() {
        stringstream out;
        out << data->size() << endl;
        for (auto it = data->begin(); it != data->end(); ++it) {
            out << (*it)->toString() << endl;
        }
        return md5.hash(out.str());
    }

}

