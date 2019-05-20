#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <string>
#include <vector>
using namespace std;

class notification{
public:
    notification(int _user_id,string _notification);
    notification(string _publisher_name,string _notification);
    void add_notification(string _publisher_name,string _notification);
    string return_publisher_name(){return publisher_name;}
    void print_notifs_unread();
    void print_notifs_read(int _limit);
    int find_user_id(int _user_id);
    void add_notification_2(int _user_id,string _notification);

private:
    string publisher_name;
    vector<int> user_ids;
    vector<string> notifs;
    vector<int> seen;
};
#endif