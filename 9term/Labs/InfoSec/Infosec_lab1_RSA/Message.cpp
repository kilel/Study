#include <vector>

#include "Message.h"

namespace RSA {

    Message::Message() {
        data = new MessageData(0);
    }

    Message::Message(string value) {
        data = new MessageData(0);
        int len = value.length();
        for (int i = 0; i < len; i += 2) {
            int temp = ((int) value[i]) << 4;
            if (i + 1 < len) {
                temp |= (int) value[i + 1];
            }
            data->push_back(temp);
        }
    }

    Message::Message(const Message& orig) {
        data = new MessageData(0);
        data->insert(data->begin(), orig.data->begin(), orig.data->end());
    }

    Message::~Message() {
    }

    Message* Message::getFromFile(string path) {
        cout << "Opening message from file: " << path << endl;
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
        cout << "Saving message to file: " << path << endl;
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

    string Message::getHash() {
        stringstream out;

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
        return md5.hash(out.str());
    }
}
