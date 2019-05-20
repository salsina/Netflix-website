#ifndef HANDLE_INPUT_H
#define HANDLE_INPUT_H

#include <string>
#include <vector>
#include "user.h"
#include "publisher.h"
#include "film.h"

using namespace std;

class handle_input{
public:
    void signup(string _email,string  _username,string _password,string _age,string _publisher="false");
    void login(string _username,string _password);
    vector<publisher*> return_v_publishers(){return v_publishers;}
    vector<user*> return_v_users(){return v_users;}
    void set_all_users_off();
    void post_film(string username,string _name,string _year,string _length,string _price,string _summary,string _director);
    film* find_film(string _film_id);
    void delete_film(string _film_id);
    void buy_film(string _film_id,user* user);
    void add_rate(string _film_id,int _rate,user* user,int &done);
    void add_comment(string _content,user* user,film* film,int &done);
    void delete_comment(int _comment_id,film* film);
    void reply_comment(int _comment_id,string _reply,film* film);
    string return_commentor(int _comment_id, film *film);
    void search_info(vector<film*> &v_films_save,string info);
    void search_min_rate(vector<film*> &v_films_save,float rate);
    void search_min_year(vector<film*> &v_films_save,string min_year);
    void search_max_year(vector<film*> &v_films_save,string max_year);
    vector<film*> return_v_films(){ return v_films;}
    void get_published(vector<film*> v_films_save,publisher* publisher);
    void get_purchased(vector<film*> v_films_save,user* user);
    void get_films_filter(vector<film*> v_films_save);
    void get_films(film* film);

    int find_user_id_by_username(string username){
        for(int i = 0; i < v_users.size(); i++){
            if(v_users[i]->return_username() == username)
                return v_users[i]->return_user_id();
        }
    }
private:
    vector<user*> v_users;
    vector<publisher*> v_publishers;
    vector<film*> v_films;
};
#endif