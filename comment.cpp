#include "comment.h"
#include <iostream>
#include <vector>
using namespace std;

void comment::add_reply(string _content)
{
    Reply *r = new Reply(reply_id++, _content);
    replies.push_back(r);
    cout<<"OK"<<endl;
}
int comment::return_id(){ return id; }
int comment::return_film_id(){ return film_id; }
string comment::return_publisher(){ return publisher; }
string comment::return_content(){ return content; }
vector<Reply*> comment::return_replies(){ return replies; }
