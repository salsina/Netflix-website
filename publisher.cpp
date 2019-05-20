#include "publisher.h"
#include "film.h"
//#include "notification.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void publisher::post_film(string _name,string _year,string _length,string _price,string _summary,string _director)
{
    cout<<films.size()<<endl;
    films.push_back(new film(films.size()+1,username,_name,_year,_length,_price,_summary,_director));
    cout<<"OK"<<endl;
}

publisher::publisher(int _user_id,string _email,string _username,string _password,string _age,int _loginstatus):user(_user_id,_email,_username,_password,_age,"true",1)
{

}

void publisher::put_film(string _film_id,string _name,string _year,string _length,string _summary,string _director,film* film)
{
    film->edit_info(_name,_year,_length,_summary,_director);
}

void publisher::add_notification(string _notification)
{
    if(v_notifications.size()==0)
        v_notifications.push_back(new notification(username,_notification));
    else{
    for(int i=0;i<v_notifications.size();i++)
    {
        if(v_notifications[i]->return_publisher_name()==username)
        {
            v_notifications[i]->add_notification(username,_notification);
        }
        else if(i+1==v_notifications.size()&&v_notifications[i]->return_publisher_name()!=username)
        {
            v_notifications.push_back(new notification(username,_notification));
            break;
        }
    }
    }
}

void publisher::add_follower(int _follower_id,string _follower_username,string _follower_email)
{
    int found=0;
    for(int i=0;i<follower_ids.size();i++)
        if(follower_ids[i]==_follower_id)
            found=1;
    if(found==0)
    {
        follower_ids.push_back(_follower_id);
        follower_usernames.insert(pair<int,string>(_follower_id,_follower_username));
        followe_emails.insert(pair<int,string>(_follower_id,_follower_email));
    }
}

void publisher::send_notification_to_followers(string _notification)
{
    for(int i=0;i<follower_ids.size();i++)
    {
        if(v_notifications.size()==0)
            v_notifications.push_back(new notification(follower_ids[i],_notification));
        else{
            for(int i=0;i<v_notifications.size();i++)
            {
                if(v_notifications[i]->find_user_id(follower_ids[i])==follower_ids[i])
                {
                    v_notifications[i]->add_notification_2(follower_ids[i],_notification);
                }
                else if(i+1==v_notifications.size()&&v_notifications[i]->return_publisher_name()!=username)
                {
                    v_notifications.push_back(new notification(follower_ids[i],_notification));
                    cout<<"notification not found but added"<<endl;
                    break;
                }
            }
        }
    }
}

void publisher::send_notification_to_a_user(int _users_id,string _notification)
{
    for(int i=0;i<v_notifications.size();i++)
    {
        if(v_notifications[i]->find_user_id(_users_id)==_users_id)
        {
            v_notifications[i]->add_notification_2(_users_id,_notification);
            return;
        }
    }
    v_notifications.push_back(new notification(_users_id,_notification));
            cout<<v_notifications.size()<<endl;

    return;

}

void publisher::print_list_of_followers()
{
    cout<<"List of Followers"<<endl;
    cout<<"#. User Id | User Username | User Email"<<endl;
    sort(follower_ids.begin(), follower_ids.end()); 
    for(int i=0;i<follower_ids.size();i++)
    {
        cout<<i+1<<". "<<follower_ids[i]<<" | "<<follower_usernames.find(follower_ids[i])->second<<" | "<<followe_emails.find(follower_ids[i])->second<<endl;
    }
}

void publisher::take_money()
{
    money=0;
    cout<<"OK"<<endl;
}

void publisher::add_money_to_publisher(film* film,string _film_id)
{
    if(film->return_rate()<5)
        money+=(stoi(film->return_price())*80)/100;
    if(film->return_rate()>=5 && film->return_rate()<8)
        money+=(stoi(film->return_price())*90)/100;
    if(film->return_rate()>=8)
        money+=(stoi(film->return_price())*95)/100;
}