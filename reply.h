#ifndef REPLY_H
#define REPLY_H
#include <string>
#include <iostream>
using namespace std;
class Reply {
    public:
        Reply(int _id, string _content) : id(_id), content(_content) {}
        int return_id(){ return id; }
        string return_content(){ return content; }
    private:
        int id;
        string content;
};
#endif