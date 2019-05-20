#ifndef REPLY_H
#define REPLY_H
#include <string>
#include <iostream>
using namespace std;
class Reply {
    public:
        Reply(int _id, string _content);
        int return_id();
        string return_content();
    private:
        int id;
        string content;
};
#endif