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
    string return_username();
    string return_password();
    vector<notification*> return_v_notifications();
    string return_publisher();
    string return_email();
    int return_login_status();
    int return_user_id();
    int return_money();
    bool isOnline();
    void manage_login_status(int _loginstatus);
    void follow_publisher(string publisher_name);
    void add_money(int amount);
    void makeOffline();
    void makeOnline();    
    void print_notifications_unread();
    void print_notifications_read(int _limit);
    void pushback_v_notfs(string _notification);

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