#include "notification.h"
#include <iostream>
using namespace std;
void notification::add_notification(string _publisher_name,string _notification)
{
    publisher_name=_publisher_name;
    notifs.push_back(_notification);
    seen.push_back(0);
}

void notification::add_notification_2(int _user_id,string _notification)
{
    user_ids.push_back(_user_id);
    notifs.push_back(_notification);
    seen.push_back(0);
}

notification::notification(string _publisher_name,string _notification)
{
    publisher_name=_publisher_name;
    notifs.push_back(_notification);
    seen.push_back(0);
}

notification::notification(int _user_id,string _notification)
{
    user_ids.push_back(_user_id);
    notifs.push_back(_notification);
    seen.push_back(0);
}

int notification::find_user_id(int _user_id)
{
    for(int i=0;i<user_ids.size();i++)
    {
        if(user_ids[i]==_user_id)
            return user_ids[i];
    }
}


void notification::print_notifs_unread()
{
    int counter=1;
    for(int i=notifs.size();i>0;i--)
    {
        if(seen[i-1]==0)
        {
            cout<<counter++<<". "<<notifs[i-1]<<"."<<endl;
            seen[i-1]=1;
        }
    }
}

void notification::print_notifs_read(int _limit)
{
    int counter=1;
    if(_limit<=notifs.size())
    {    
        for(int i=notifs.size();i>notifs.size()-_limit;i--)
        {
            if(seen[i-1]==1)
            {
                cout<<counter++<<". "<<notifs[i-1]<<"."<<endl;
            }
        }
    }
    else
    {
        for(int i=notifs.size();i>0;i--)
        {
            if(seen[i-1]==1)
            {
                cout<<counter<<". "<<notifs[i-1]<<endl;
                counter++;
            }
        }
    }
    
}
