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
    map<string, string> seperate_input(vector<string> line);
    user* online_user(handle_input* HandleInput);
    publisher* online_publisher(handle_input* HandleInput);
    vector<film*> search_v_films(map<string, string> info,handle_input* HandleInput);
    bool does_exist(string user_name,handle_input* HandleInput);
    void signup(map<string, string> info, handle_input* HandleInput);
    bool check_exceptions(map<string, string> info,handle_input* HandleInput);
    void put_films(map<string, string> info,handle_input* HandleInput);
    void post_followers(map<string, string> info,handle_input* HandleInput);
    void post_money_user(map<string, string> info,handle_input* HandleInput);
    void post_money_publisher(handle_input* HandleInput);
    void post_films(map<string, string> info,handle_input* HandleInput);
    void post_buy(map<string, string> info,handle_input* HandleInput);
    void post_rate(map<string, string> info,handle_input* HandleInput);
    void post_comments(map<string, string> info,handle_input* HandleInput);
    void post_replies(map<string, string> info,handle_input* HandleInput);
    void delete_films(map<string, string> info,handle_input* HandleInput);
    void delete_comments(map<string, string> info,handle_input* HandleInput);
    void get_notifications_user(handle_input* HandleInput);
    void get_notifications_publisher(map<string, string> info,handle_input* HandleInput);
    void get_published(map<string, string> info,handle_input* HandleInput);
    void get_purchased(map<string, string> info,handle_input* HandleInput);
    void get_films_filter(map<string, string> info,handle_input* HandleInput);
    void get_films(map<string, string> info,handle_input* HandleInput);
    void get_followers(handle_input* HandleInput);
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