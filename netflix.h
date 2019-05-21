#ifndef NETFLIX
#define NETFLIX
#include <iostream>
#include<vector>
#include <string>
#include <sstream>
#include "handle_input.h"
#include <map>

using namespace std;

class netflix{
public:
    vector<string> removeDupWord(string str);
    map<string, string> seperate_input();
    user* online_user();
    publisher* online_publisher();
    vector<film*> search_v_films();
    bool does_exist(string user_name);
    void signup();
    bool check_exceptions();
    void put_films();
    void post_followers();
    void post_money_user();
    void post_money_publisher();
    void post_films();
    void post_buy();
    void post_rate();
    void post_comments();
    void post_replies();
    void delete_films();
    void delete_comments();
    void get_notifications_user();
    void get_notifications_publisher();
    void get_published();
    void get_purchased();
    void get_films_filter();
    void get_films();
    void get_followers();
    void signup_command();
    void login_command();
    void post_film_command();
    void post_followers_command();
    void post_money_command();
    void post_rate_command();
    void post_buy_command();
    void post_comment_command();
    void post_reply_command();
    void put_film_command();
    void delete_film_command();
    void delete_comment_command();
    void get_notification_command();
    void get_followers_command();
    void get_published_command();
    void get_purchased_command();
    void get_film_command();
    void post_commands();
    void put_commands();
    void delete_commands();
    void get_commands();
    void run();
    
private:
    vector<string> line;
    map<string, string> info;
    string str;
    vector<publisher*> tempPub; 
    handle_input* HandleInput= new handle_input();

};
#endif