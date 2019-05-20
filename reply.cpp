#include "reply.h"
using namespace std;


Reply::Reply(int _id, string _content) : id(_id), content(_content) {}

int Reply::return_id()
{ 
    return id;
}

string Reply::return_content()
{ 
    return content; 
}
