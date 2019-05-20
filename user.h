#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "film.h"
#include "notification.h"

using namespace std;
class user{
public:
    user(int _user_id,string _email,string _username,string _password,string _age,string _publisher,int _loginstatus);
    void manage_login_status(int _loginstatus);
    string return_username(){return username;}
    string return_password(){return password;}
    int return_login_status(){return login_status;}
    string return_publisher(){return publisher;}
    void follow_publisher(string publisher_name);
    void add_money(int amount);
    // film* find_film(string _film_id);
    int return_user_id(){return user_id;}
    string return_email(){return email;}
    void makeOffline(){ online = false; }
    void makeOnline(){ online = true; }      
    bool isOnline(){ return online; }
    int return_money(){return money;}
    void print_notifications_unread();
    void print_notifications_read(int _limit);
    vector<notification*> return_v_notifications(){return v_notifications;}
    void pushback_v_notfs(string _notification){ 
    for(int i=0;v_notifications.size();i++)
    {
        if(v_notifications[i]->find_user_id(user_id)==user_id)
        {
            v_notifications[i]->add_notification_2(user_id,_notification);
            return;
        }
    }
    v_notifications.push_back(new notification(user_id,_notification));
    return;

    }
protected:
    string email;
    string username;
    string password;
    string publisher;
    string age;
    int login_status;
    bool online = true;
    int user_id;
    vector<string> following_publishers;
    vector<film*> films;
    int money=0;
    vector<notification*> v_notifications;
};

#endif 