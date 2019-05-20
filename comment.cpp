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
