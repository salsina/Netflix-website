#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include <vector>
#include <map>
#include "reply.h"

using namespace std;


class comment {
public:
    comment(int _id, int _film_id, string _publisher, string _content) : id(_id), film_id(_film_id), publisher(_publisher), content(_content) {}
    int return_id();
    int return_film_id();
    string return_publisher();
    string return_content();
    vector<Reply*> return_replies();
    void add_reply(string _content);
private:
    int id;
    int film_id;
    string publisher;
    string content;
    std::vector<Reply*> replies;
    int reply_id = 1;
};
#endif