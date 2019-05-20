#ifndef FILM_H
#define FILM_H
#include <iostream>
#include <string>
#include <vector>
//#include <map>
#include "comment.h"

using namespace std;

class film{
public:
    film(int _id,string _publisher,string _name,string _year,string _length,string _price,string _summary,string _director);
    string return_name(){return name;}
    string return_year(){return year;}
    string return_length(){return length;}
    string return_summary(){return summary;}
    string return_director(){return director;}
    int return_id(){return id;}
    string return_publisher(){return publisher;}
    void edit_info(string _name,string _year,string _length,string _summary,string _director);
    string return_deleted_status(){return deleted;}
    void change_delete_status(string _delete_status){deleted=_delete_status;}
    void add_buyer(string _buyer);
    string return_price(){return price;}
    void change_film_rate(int _rate);
    vector<string> return_buyers(){return buyers;}
    string return_commentor(int _comment_id);
    float return_rate(){return film_rate;}
    void add_comment(string content, string publisher);
    vector<comment*> return_comments(){ return cmnts; }
    void delete_comment(int id);
    vector<int> return_v_rates(){return rates;}
private:
    string publisher;
    string name;
    int id;
    string length;
    string price;
    vector<int> rates;
    float film_rate;
    string year;
    string director;
    string summary;
    string deleted="NO";
    vector<string> buyers;
    //vector <comment*> v_comments;
    vector<comment*> cmnts;
    int cmntId = 1;
};
#endif