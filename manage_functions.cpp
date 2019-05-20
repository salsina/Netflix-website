#include "manage_functions.h"
#include <iostream>

using namespace std;

bool does_exist(string user_name,handle_input* HandleInput)
{
for(int i=0;i<HandleInput->return_v_users().size();i++)
    if(HandleInput->return_v_users()[i]->return_username()==user_name)
        return true;
}

void signup(map<string, string> info,handle_input* HandleInput)
{
    if(info.count("@")==1 && info.count(".")==1 && !does_exist(info.find("username")->second,HandleInput))
    {
        if(info.count("publisher") == 1)
            HandleInput->signup(info.find("email")->second,info.find("username")->second,info.find("password")->second,info.find("age")->second,info.find("publisher")->second);
        else
            HandleInput->signup(info.find("email")->second,info.find("username")->second,info.find("password")->second,info.find("age")->second,"false");
    }
    else
        cout<<"Bad Request"<<endl;               
}
