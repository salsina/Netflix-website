#include "handle_input.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void handle_input::signup(string _email,string  _username,string _password,string _age,string _publisher)
{
    set_all_users_off();
    if(_publisher=="true")
    {
        publisher *p = new publisher(v_users.size() + 1, _email, _username, _password, _age, 1);
        v_users.push_back(p);
        v_publishers.push_back(p);
    }
    else
        v_users.push_back(new user(v_users.size()+1,_email,_username,_password,_age,"false",1)); 
    cout << "OK" << endl;   
}

void handle_input::login(string _username,string _password)
{
    for(int i = 0; i < v_users.size(); i++)
    {
        if(v_users[i]->return_username() == _username && v_users[i]->return_password() == _password){
            set_all_users_off();
            v_users[i]->manage_login_status(1);
            v_users[i]->makeOnline();
            cout << "OK" << endl;
            return;
        }
    }
    cout << "Bad Request" << endl;
}

void handle_input::set_all_users_off()
{
    for(int i=0;i<v_users.size();i++)
    {
        v_users[i]->makeOffline();
        v_users[i]->manage_login_status(0);
    }
}

void handle_input::post_film(string username,string _name,string _year,string _length,string _price,string _summary,string _director)
{
    v_films.push_back(new film(v_films.size()+1,username,_name,_year,_length,_price,_summary,_director));
    cout<<"OK"<<endl;
}

film* handle_input::find_film(string _film_id)
{
    if(v_films.size()==0 || stoi(_film_id)>v_films.size())
    {
        return nullptr;
    }
    for(int i=0;i<v_films.size();i++)
    {
        if(to_string(v_films[i]->return_id()) == _film_id && v_films[i]->return_deleted_status() == "NO")
        {
            return v_films[i];
        }
        if(to_string(v_films[i]->return_id()) == _film_id && v_films[i]->return_deleted_status() != "NO")
            return nullptr;
    }
    return nullptr;
}

void handle_input::delete_film(string _film_id)
{
    find_film(_film_id)->change_delete_status("YES");
    cout<<"OK"<<endl;
}

void handle_input::buy_film(string _film_id,user* user)
{
    if(stoi(find_film(_film_id)->return_price())<=user->return_money())
    {                 
        find_film(_film_id)->add_buyer(user->return_username());
        user->add_money(-stoi(find_film(_film_id)->return_price()));
    }
    else
        cout<<"Permission Denied"<<endl;    
}

void handle_input::add_rate(string _film_id,int _rate,user* user,int &done)
{   
    for(int i=0;i<find_film(_film_id)->return_buyers().size();i++)
        if(find_film(_film_id)->return_buyers()[i]==user->return_username())
            if(_rate>=0 && _rate<=10)
            {
                find_film(_film_id)->change_film_rate(_rate);
                cout<<"OK"<<endl;
                done=1;
                return;
            }
    cout<<"Permission Denied"<<endl;
    done=0;
    return;
}

void handle_input::add_comment(string _content,user* user,film* film,int &done)
{

    for(int i = 0; i < film->return_buyers().size(); i++)
    {
        if(film->return_buyers()[i] == user->return_username())
        {
            film->add_comment(_content, user->return_username());
            cout << "OK" << endl;
            done=1;
            return;
        }
    }
    cout << "Permission Denied" << endl;
    done=0;
    return;
}

void handle_input::delete_comment(int _comment_id,film* film)
{
   film->delete_comment(_comment_id);
}

void handle_input::reply_comment(int _comment_id,string _reply,film* film)
{
    vector<comment*> c = film->return_comments();
    for(int i = 0; i < c.size(); i++){
        if(c[i]->return_id() == _comment_id && c[i]->return_film_id() == film->return_id()){
            c[i]->add_reply(_reply);
            return;
        }
    }
    cout << "Not Found" << endl;
}

string handle_input::return_commentor(int _comment_id, film* film)
{
    vector<comment*> c = film->return_comments();
    for(int i = 0; i < c.size(); i++){
        if(c[i]->return_id() == _comment_id)
            return c[i]->return_publisher();
    }
}

void handle_input:: search_info(vector<film*> &v_films_save,string info)
{
    for(int i=0;i<v_films_save.size();i++)
        if(v_films_save[i]->return_name()!=info)
        {
            v_films_save.erase(v_films_save.begin()+i);
            i--;
        }
}

void handle_input::search_min_rate(vector<film*> &v_films_save,float rate)
{   
    for(int i=0;i<v_films_save.size();i++)
        if(v_films_save[i]->return_rate()<rate)
        {
            v_films_save.erase(v_films_save.begin()+i);
            i--;
        }
}

void handle_input::search_min_year(vector<film*> &v_films_save,string min_year)
{
    for(int i=0;i<v_films_save.size();i++)
        if(v_films_save[i]->return_year()<min_year)
        {
            v_films_save.erase(v_films_save.begin()+i);
            i--;
        }
}

void handle_input::search_max_year(vector<film*> &v_films_save,string max_year)
{
    for(int i=0;i<v_films_save.size();i++)
        if(v_films_save[i]->return_year()>max_year)
        {
            v_films_save.erase(v_films_save.begin()+i);
            i--;
        }
}

void handle_input::get_published(vector<film*> v_films_save,publisher* publisher)
{
    int counter=1;
    cout<<"#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director"<<endl;
    for(int i=0;i<v_films_save.size();i++)
        if(v_films_save[i]->return_publisher()==publisher->return_username() && v_films_save[i]->return_deleted_status()!="YES")
        {
            cout<<counter++<<". "<<v_films_save[i]->return_id()<<" | "<<v_films_save[i]->return_name()<<" | "<<v_films_save[i]->return_length()<<" | "<<v_films_save[i]->return_price()<<" | "<<v_films_save[i]->return_rate()<<" | "<<v_films_save[i]->return_year()<<" | "<<v_films_save[i]->return_director()<<endl;
        }
}

void handle_input::get_purchased(vector<film*> v_films_save,user* user)
{
    int counter=1;
    cout<<"#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director"<<endl;
    for(int i=0;i<v_films_save.size();i++)
        for(int j=0;j<v_films_save[i]->return_buyers().size();j++)
            if(v_films_save[i]->return_buyers()[j]==user->return_username())
            {
                cout<<counter++<<". "<<v_films_save[i]->return_id()<<" | "<<v_films_save[i]->return_name()<<" | "<<v_films_save[i]->return_length()<<" | "<<v_films_save[i]->return_price()<<" | "<<v_films_save[i]->return_rate()<<" | "<<v_films_save[i]->return_year()<<" | "<<v_films_save[i]->return_director()<<endl;
            }

}

void handle_input:: get_films_filter(vector<film*> v_films_save)
{
    int counter=1;
    cout<<"#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director"<<endl;
    for(int i=0;i<v_films_save.size();i++)
        if(v_films_save[i]->return_deleted_status()!="YES")
            cout<<counter++<<". "<<v_films_save[i]->return_id()<<" | "<<v_films_save[i]->return_name()<<" | "<<v_films_save[i]->return_length()<<" | "<<v_films_save[i]->return_price()<<" | "<<v_films_save[i]->return_rate()<<" | "<<v_films_save[i]->return_year()<<" | "<<v_films_save[i]->return_director()<<endl;
}

void handle_input::get_films(film* f)
{
    cout<<"Details of Film "<<f->return_name()<<endl;
    cout<<"Id = "<<f->return_id()<<endl;
    cout<<"Director = "<<f->return_director()<<endl;
    cout<<"Length = "<<f->return_length()<<endl;
    cout<<"Year = "<<f->return_year()<<endl;
    cout<<"Summary = "<<f->return_summary()<<endl;
    cout<<"Rate = "<<f->return_rate()<<endl;
    cout<<"Price = "<<f->return_price()<<endl<<endl;
    cout<<"Comments"<<endl;
    for(int i=0;i<f->return_comments().size();i++)
    {
        cout<<f->return_comments()[i]->return_id()<<". "<<f->return_comments()[i]->return_content()<<endl;
        for(int j=0;j<f->return_comments()[i]->return_replies().size();j++)
            cout<<f->return_comments()[i]->return_id()<<"."<<f->return_comments()[i]->return_replies()[j]->return_id()<<". "<<f->return_comments()[i]->return_replies()[j]->return_content()<<endl;
    }
    cout<<endl;
    cout<<"Recommendation Film"<<endl;
    cout<<"#. Film Id | Film Name | Film Length | Film Director"<<endl;

    vector<film*> recom = v_films;
    sort(recom.begin(), recom.end(), [](film*a, film *b){
        return a->return_rate() > b->return_rate();
    });
    int counter=1;
    if(recom.size()<4)
    {
        for(int i = 0; i < recom.size(); i++)
        {
            if(recom[i]->return_deleted_status()!="YES" && recom[i]->return_id()!=f->return_id())
            cout << counter++ << ". " << recom[i]->return_id() << " | "<<recom[i]->return_name()<<" | "<<recom[i]->return_length()<<" | "<<recom[i]->return_director()<<endl;  
        }
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            if(recom[i]->return_deleted_status()!="YES" && recom[i]->return_id()!=f->return_id())
            cout << counter++ << ". " << recom[i]->return_id() << " | "<<recom[i]->return_name()<<" | "<<recom[i]->return_length()<<" | "<<recom[i]->return_director()<<endl;  
        }
    }
    
}