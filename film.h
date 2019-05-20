#ifndef FILM_H
#define FILM_H
#include <iostream>
#include <string>
#include <vector>
#include "comment.h"

using namespace std;

class film{
public:
    film(int _id,string _publisher,string _name,string _year,string _length,string _price,string _summary,string _director);
    string return_name();
    string return_year();
    string return_length();
    string return_summary();
    string return_director();
    string return_commentor(int _comment_id);
    string return_publisher();
    string return_deleted_status();
    string return_price();
    vector<comment*> return_comments();
    vector<string> return_buyers();
    vector<int> return_v_rates();
    int return_id();
    float return_rate();
    void change_delete_status(string _delete_status){deleted=_delete_status;}
    void edit_info(string _name,string _year,string _length,string _summary,string _director);
    void add_buyer(string _buyer);
    void change_film_rate(int _rate);
    void add_comment(string content, string publisher);
    void delete_comment(int id);
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
    vector<comment*> cmnts;
    int cmntId = 1;
};
#endif