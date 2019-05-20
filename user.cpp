#include "user.h"
#include <string>
#include <iostream>
#include "film.h"
using namespace std;
user::user(int _user_id,string _email,string _username,string _password,string _age,string _Publisher,int _loginstatus)
{
    user_id=_user_id;
    email=_email;
    username=_username;
    password=_password;
    publisher=_Publisher;
    age=_age;
    login_status=_loginstatus;
}

void user::manage_login_status(int _loginstatus)
{
    login_status=_loginstatus;
}

void user::follow_publisher(string publisher_name)
{
    int found=0;
    for(int i=0;i<following_publishers.size();i++)
        if(publisher_name==following_publishers[i])
            found =1;
    if(found==0)
    {
        following_publishers.push_back(publisher_name);
        cout<<"OK"<<endl;
    }
    else 
        cout<<"Bad Request"<<endl;
}

void user::add_money(int amount)
{
    money+=amount;
    cout<<"OK"<<endl;
}

void user::print_notifications_unread()
{
    cout<<"#. Notification Message"<<endl;
    //cout<<v_notifications.size()<<endl;
    for(int i=0;i<v_notifications.size();i++)
    {
        if(v_notifications[i]->return_publisher_name()==username)
        {
            v_notifications[i]->print_notifs_unread();
        }
    }
}

void user::print_notifications_read(int _limit)
{
    cout<<"#. Notification Message"<<endl;
    for(int i=0;i<v_notifications.size();i++)
    {
        if(v_notifications[i]->return_publisher_name()==username)
        {
            v_notifications[i]->print_notifs_read(_limit);
        }
    }
}
