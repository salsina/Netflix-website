#include "film.h"
#include <iostream>
#include "comment.h"

using namespace std;
film::film(int _id,string _publisher,string _name,string _year,string _length,string _price,string _summary,string _director)
{
    id=_id;
    publisher=_publisher;
    name=_name;
    year=_year;
    length=_length;
    price=_price;
    summary=_summary;
    director=_director;
}
void film::edit_info(string _name,string _year,string _length,string _summary,string _director)
{
    name=_name;
    year=_year;
    length=_length;
    summary=_summary;
    director=_director;
}

void film::add_buyer(string _buyer)
{
    buyers.push_back(_buyer);
}

void film::change_film_rate(int _rate)
{
    rates.push_back(_rate);
    int sum=0;
    for(int i=0;i<rates.size();i++)
    {
        sum+=rates[i];
    }
    film_rate=sum/rates.size();
}

void film::add_comment(string content, string publisher){
    comment *c = new comment(cmntId++, id, publisher, content);
    cmnts.push_back(c);
}

void film::delete_comment(int id){
    for(int i = 0; i < cmnts.size(); i++){
        if(cmnts[i]->return_id() == id){
            cmnts.erase(cmnts.begin() + i--);
            cout<<"OK"<<endl;
            return;
        }
    }
    cout << "Not Found" << endl;
}
