#ifndef MANAGE
#define MANAGE
#include <iostream>
#include <map>
#include "handle_input.h"

using namespace std;
class manage_functions{
public:
    bool does_exist(string user_name,handle_input* HandleInput);
    void signup(map<string, string> info,handle_input* HandleInput);

private:

};
#endif