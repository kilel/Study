#include <vector>

#include "Message.h"

namespace RSA {

    Message::Message() {
        data = new vector<int>(0);
    }

    Message::Message(string value) {

    }

    Message::Message(const Message& orig) {
    }

    Message::~Message() {
    }

    Message* Message::getFromFile(string path) {
        Message *out = new Message();
        ifstream in;
        in.open(path, ios_base::in);
        char *buff = new char[3];
        while (!in.eof()) {
            buff[0] = buff[1] = 0;
            in.read(buff, 2);

            int temp = (((int) buff[0]) << 8) + buff[1];
            out->getData()->push_back(temp);
        }

        in.close();
        return out;
    }

    void Message::save(string path) {
        ofstream out;
        out.open(path, ios_base::out);

        char *buff = new char[3];
        for (MessageData::iterator it = data->begin(); it != data->end(); ++it) {
            buff[0] = *it >> 8;
            buff[1] = *it % 0x100;
            int toWrite = 2;

            if (buff[0] == 0 && buff[1] == 0) {
                toWrite = 0;
            } else if (buff[1] == 0) {
                toWrite = 1;
            }

            out.write(&buff[0], toWrite);
        }
        out.close();
    }

    vector<BigInt*>* Message::readEncoded(string path) {
        vector<BigInt*> *data = new vector<BigInt*>();
        int length;
        ifstream in;
        in.open(path);

        in >> length;
        for (int i = 0; i < length; ++i) {
            string temp;
            in >> temp;
            data->push_back(new BigInt(temp));
        }
        in.close();
        return data;
    }

    void Message::writeEncoded(string path, vector<BigInt*>* data) {
        ofstream out;
        out.open(path);
        out << data->size() << endl;
        for (auto it = data->begin(); it != data->end(); ++it) {
            out << (*it)->toString() << endl;
        }
        out.close();
    }

}
