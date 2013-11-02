#include "DesMessage.h"

namespace DES {

    DesMessage::DesMessage() {
        data = new MessageData();
    }

    DesMessage::DesMessage(const DesMessage& orig) {
        data = new MessageData();
        data->insert(data->begin(), orig.data->begin(), orig.data->end());
    }

    DesMessage::~DesMessage() {
        data->clear();
        delete data;
    }

    DesMessage* DesMessage::fromFile(string path) {
        cout << "Reading message from file " << path << endl;
        DesMessage *message = new DesMessage();
        ifstream in;
        in.open(path, ios_base::in);
        MessageData *data = message->getData();
        if (!in.is_open()) {
            cout << "Can't open file" << endl;
            assert(false);
        }
        uint64_t temp;
        while (!in.eof()) {
            temp = 0;
            for (int i = 0; i < 8; ++i) {
                char getted = 0;
                if (!in.eof()) {
                    in.read(&getted, 1);
                    //cout << "Readed " << (int) getted << endl;
                }
                temp = temp << 8 | (uint8_t) getted;
            }
            if (temp != 0) {
                data->push_back(temp);
            }
        }

        in.close();
        return message;
    }

    void DesMessage::save(string path) {
        cout << "Saving message to file " << path << endl;
        ofstream out;
        out.open(path);
        uint64_t mask = 0xFF000000;
        for (MessageData::iterator it = data->begin(); it != data->end(); ++it) {
            uint64_t temp = *it;
            for (int i = 0; i < 8; ++i) {
                char toPut = ((temp >> 32) & mask) >> 24;
                temp <<= 8;
                if (it != data->end() - 1 || toPut != 0) {
                    //cout << "Written " << (int) toPut << endl;
                    out.put(toPut);
                }
            }
        }
        out.close();
    }

}

