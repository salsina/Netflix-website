#ifndef PUBLISHER_H
#define PUBLISHER_H
#include "user.h"
#include "film.h"
#include <vector>
#include <map>


using namespace std;

class publisher:public user{
public:
    publisher(int _user_id,string _email,string _username,string _password,string _age,int _loginstatus);
    void post_film(string _name,string _year,string _length,string _price,string _summary,string _director);
    void put_film(string _film_id,string _name,string _year,string _length,string _summary,string _director,film* film);
    void delete_film(string _film_id);
    void add_notification(string _notification);
    void send_notification_to_followers(string _notification);
    void add_follower(int _follower_id,string _follower_username,string _follower_email);
    void print_list_of_followers();
    void take_money();
    void add_money_to_publisher(film* film,string _film_id);
private:
    vector<int> follower_ids;
    map<int,string> follower_usernames;
    map<int,string> followe_emails;
};
#endif