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
        int return_id(){ return id; }
        int return_film_id(){ return film_id; }
        std::string return_publisher(){ return publisher; }
        std::string return_content(){ return content; }
        void add_reply(string _content);
        std::vector<Reply*> return_replies(){ return replies; }
    private:
        int id;
        int film_id;
        string publisher;
        string content;
        std::vector<Reply*> replies;
        int reply_id = 1;
};
#endif