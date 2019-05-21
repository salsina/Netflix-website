#include "netflix.h"

vector<string> netflix::removeDupWord(string str) 
{ 
    vector<string> res;
    istringstream ss(str); 
      do { 
        string word; 
        ss >> word; 
        res.push_back(word);
      } while (ss); 
      return res;
} 

map<string, string> netflix::seperate_input()
{
    map<string, string> temp_info;
    for(int i=0;i<line.size();i++)
    {        
        if(line[i]=="?")
            temp_info.insert(pair<string, string>("?", line[i+1]));
        if(line[i]=="email")
        {
            temp_info.insert(pair<string, string>("email", line[i+1]));
            for(int j=0;j<line[i+1].size();j++)
            {
                if(line[i+1][j]=='@')
                    temp_info.insert(pair<string, string>("@", "@"));
                if (line[i+1][j]=='.')
                    temp_info.insert(pair<string, string>(".", "."));
            }
        }
        if(line[i]=="username")
            temp_info.insert(pair<string, string>("username", line[i+1]));
        if(line[i]=="password")
            temp_info.insert(pair<string, string>("password", line[i+1]));
        if(line[i]=="age")
            temp_info.insert(pair<string, string>("age", line[i+1]));
        if(line[i]=="name")
            temp_info.insert(pair<string, string>("name", line[i+1]));
        if(line[i]=="year")
            temp_info.insert(pair<string, string>("year", line[i+1]));
        if(line[i]=="length")
            temp_info.insert(pair<string, string>("length", line[i+1]));
        if(line[i]=="price")
            temp_info.insert(pair<string, string>("price", line[i+1]));
        if(line[i]=="summary")
            temp_info.insert(pair<string, string>("summary", line[i+1]));
        if(line[i]=="director")
            temp_info.insert(pair<string, string>("director", line[i+1]));
        if(line[i]=="publisher")
            temp_info.insert(pair<string, string>("publisher", line[i+1]));
        if(line[i]=="film_id")
            temp_info.insert(pair<string, string>("film_id", line[i+1]));
        if(line[i]=="user_id")
            temp_info.insert(pair<string, string>("user_id", line[i+1]));
        if(line[i]=="amount")
            temp_info.insert(pair<string, string>("amount", line[i+1]));
        if(line[i]=="score")
            temp_info.insert(pair<string, string>("score", line[i+1]));
        if(line[i]=="content")
            temp_info.insert(pair<string, string>("content", line[i+1]));
        if(line[i]=="limit")
            temp_info.insert(pair<string, string>("limit", line[i+1]));
        if(line[i]=="comment_id")
            temp_info.insert(pair<string, string>("comment_id", line[i+1]));
        if(line[i]=="min_rate")
            temp_info.insert(pair<string, string>("min_rate", line[i+1]));
        if(line[i]=="min_year")
            temp_info.insert(pair<string, string>("min_year", line[i+1]));
        if(line[i]=="max_year")
            temp_info.insert(pair<string, string>("max_year", line[i+1]));
   }
    return temp_info;
}

bool netflix::does_exist(string user_name)
{
for(int i=0;i<HandleInput->return_v_users().size();i++)
    if(HandleInput->return_v_users()[i]->return_username()==user_name)
        return true;
}

void netflix::signup()
{
    if(info.count("email")!=1||info.count("username")!=1||info.count("password")!=1||info.count("age")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    if(info.count("@")==1 && info.count(".")==1 && !does_exist(info.find("username")->second))
    {
        if(info.count("publisher") == 1)
            HandleInput->signup(info.find("email")->second,info.find("username")->second,info.find("password")->second,info.find("age")->second,info.find("publisher")->second);
        else
            HandleInput->signup(info.find("email")->second,info.find("username")->second,info.find("password")->second,info.find("age")->second,"false");
    }
    else
        cout<<"Bad Request"<<endl;                   
}

user* netflix::online_user()
{
    for(int i = 0; i < HandleInput->return_v_users().size(); i++){
        if(HandleInput->return_v_users()[i]->isOnline()){
            return HandleInput->return_v_users()[i];
        }
    }
    return nullptr;
}

publisher* netflix::online_publisher()
{
    vector<publisher*> p = HandleInput->return_v_publishers();
    for(int i = 0; i < p.size(); i++){
        if(p[i]->isOnline()){
            return HandleInput->return_v_publishers()[i];
        }
    }
    return nullptr;               
}

void netflix::post_films()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Permission Denied" << endl;
        return;
    }
    if(online->return_publisher() != "true"){
        cout << "Permission Denied" << endl;
        return;
    }
    if(info.count("name")!=1 || info.count("year")!=1 || info.count("length")!=1 ||info.count("price")!=1 ||info.count("summary")!=1 ||info.count("director")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    HandleInput->post_film(online_publisher()->return_username(),info.find("name")->second,info.find("year")->second,info.find("length")->second,info.find("price")->second,info.find("summary")->second,info.find("director")->second);
    online_publisher()->send_notification_to_followers("Publisher "+ online_publisher()->return_username()+ " with id "+to_string(online_publisher()->return_user_id())+" register new film.");
}

bool netflix::check_exceptions()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Permission Denied" << endl;
        return true;
    }
    if(online->return_publisher() != "true"){
        cout << "Permission Denied" << endl;
        return true;
    }
    publisher *p = online_publisher();
    string filmId = info.find("film_id")->second;
    film *f = HandleInput->find_film(filmId);
    if(f==nullptr)
    {
        cout << "Not Found" << endl;
        return true;
    }         
    if(f->return_publisher() != p->return_username())
    {
        cout << "Permission Denied" << endl;
        return true;
    }
    return false;
}

void netflix::put_films()
{
    if(info.count("film_id")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    string filmId = info.find("film_id")->second;
    film *f = HandleInput->find_film(filmId);
    publisher *p = online_publisher();

    if(check_exceptions())
        return;

    if(info.count("name") == 1)
        p->put_film(filmId, info.find("name")->second, f->return_year(), f->return_length(), f->return_summary(), f->return_director(),f);
    if(info.count("year") == 1)
        p->put_film(filmId, f->return_name(), info.find("year")->second, f->return_length(), f->return_summary(), f->return_director(),f);
    if(info.count("length") == 1)
        p->put_film(filmId, f->return_name(), f->return_year(), info.find("length")->second, f->return_summary(), f->return_director(),f);
    if(info.count("summary") == 1)
        p->put_film(filmId, f->return_name(), f->return_year(), f->return_length(), info.find("summary")->second, f->return_director(),f);
    if(info.count("director") == 1)
        p->put_film(filmId, f->return_name(), f->return_year(), f->return_length(), f->return_summary(), info.find("director")->second,f);
    cout << "OK" << endl;
}

void netflix::delete_films()
{
    if(check_exceptions())
        return;
    if(info.count("film_id")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }

    HandleInput->delete_film(info.find("film_id")->second);
}

void netflix::post_followers()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("user_id")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    user* _user=HandleInput->find_user_by_user_id(stoi(info.find("user_id")->second));
    if(_user==nullptr)
    {
        cout<<"Not Found"<<endl;
        return;
    }
    online->follow_publisher(_user->return_username());
    for(int i=0;i<HandleInput->return_v_publishers().size();i++)
    {         
        if(HandleInput->return_v_publishers()[i]->return_user_id()==stoi(info.find("user_id")->second))
        {
            HandleInput->return_v_publishers()[i]->add_follower(online->return_user_id(),online->return_username(),online->return_email());
            HandleInput->return_v_publishers()[i]->add_notification("User "+online->return_username()+" with id "+to_string(online->return_user_id())+" follow you");
            return;
        }
    }
    if(stoi(info.find("user_id")->second)>HandleInput->return_v_publishers().size() || stoi(info.find("user_id")->second)<1)
    {
        cout<<"Not Found"<<endl;
        return;
    }
    cout << "Permission Denied" << endl;
}

void netflix::get_followers()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(online->return_publisher() != "true"){
        cout << "Permission Denied" << endl;
        return;
    }
    publisher *p = online_publisher();
    p->print_list_of_followers();  
}

void netflix::post_money_user()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("amount")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }

    online->add_money(stoi(info.find("amount")->second));
}

void netflix::post_money_publisher()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(online->return_publisher() != "true"){
        cout << "Permission Denied" << endl;
        return;
    }
    publisher *p = online_publisher();
    p->take_money();
}

void netflix::post_buy()
{      
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("film_id")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }

    string filmId = info.find("film_id")->second;
    film *f = HandleInput->find_film(filmId);
    if(f==nullptr)
    {
        cout << "Not Found" << endl;
        return;
    }         

    HandleInput->buy_film(info.find("film_id")->second,online);
    for(int i=0;i<HandleInput->return_v_publishers().size();i++)
    if(f->return_publisher()==HandleInput->return_v_publishers()[i]->return_username())
    {  
        HandleInput->return_v_publishers()[i]->add_notification("User "+online->return_username()+" with id "+to_string(online->return_user_id())+" buy your film "+f->return_name()+" with id "+to_string(f->return_id()));
        HandleInput->return_v_publishers()[i]->add_money_to_publisher(f,info.find("film_id")->second);
    }
}

void netflix::post_rate()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("film_id")!=1 || info.count("score")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }

    string filmId = info.find("film_id")->second;
    film *f = HandleInput->find_film(filmId);
    if(f==nullptr)
    {
        cout << "Not Found" << endl;
        return;
    }         
    int done=0;
    HandleInput->add_rate(info.find("film_id")->second,stoi(info.find("score")->second),online,done);
    if(done ==0)
        return;
    for(int i=0;i<HandleInput->return_v_publishers().size();i++)
        if(f->return_publisher()==HandleInput->return_v_publishers()[i]->return_username())
            HandleInput->return_v_publishers()[i]->add_notification("User "+online->return_username()+" with id "+to_string(online->return_user_id())+" rate your film "+f->return_name()+" with id "+to_string(f->return_id()));
}

void netflix::post_comments()
{        
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("film_id")!=1||info.count("content")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }

    string filmId = info.find("film_id")->second;
    film *f = HandleInput->find_film(filmId);
    if(f==nullptr)
    {
        cout << "Not Found" << endl;
        return;
    }         
    int done=0;
    HandleInput->add_comment(info.find("content")->second,online,f,done);
    if(done ==0)
        return;
    for(int i=0;i<HandleInput->return_v_publishers().size();i++)
        if(f->return_publisher()==HandleInput->return_v_publishers()[i]->return_username())
            HandleInput->return_v_publishers()[i]->add_notification("User "+online->return_username()+" with id "+to_string(online->return_user_id())+" comment on your film "+f->return_name()+" with id "+to_string(f->return_id()));
}

void netflix::delete_comments()
{
    if(check_exceptions())
        return;
    if(info.count("film_id")!=1||info.count("comment_id")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }

    user *online = online_user();
    string filmId = info.find("film_id")->second;
    film *f = HandleInput->find_film(filmId);

    HandleInput->delete_comment(stoi(info.find("comment_id")->second),f);
}

void netflix::post_replies()
{
    if(check_exceptions())
        return;
    if(info.count("film_id")!=1||info.count("comment_id")!=1||info.count("content")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }

    user *online = online_user();
    string filmId = info.find("film_id")->second;
    film *f = HandleInput->find_film(filmId);
    publisher *p = online_publisher();
    int done=0;
    HandleInput->reply_comment(stoi(info.find("comment_id")->second),info.find("content")->second,f,done);
    if(done==0)
        return;
    string commentor = HandleInput->return_commentor(stoi(info.find("comment_id")->second), f);
    HandleInput->send_notification_to_a_user(HandleInput->find_user_id_by_username(commentor),"Publisher "+p->return_username() +" with id "+to_string(p->return_user_id()) +" reply to your comment");
}

void netflix::get_notifications_user()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    online->print_notifications_unread();
}

void netflix::get_notifications_publisher()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("limit")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }

    online->print_notifications_read(stoi(info.find("limit")->second));
}

vector<film*> netflix::search_v_films()
{
    vector<film*> v_films_save=HandleInput->return_v_films();
    if(info.count("name")==1)
        HandleInput->search_info(v_films_save,info.find("name")->second);
    if(info.count("min_rate")==1)
        HandleInput->search_min_rate(v_films_save,stof(info.find("min_rate")->second));
    if(info.count("min_year")==1)
        HandleInput->search_min_year(v_films_save,info.find("min_year")->second);
    if(info.count("max_year")==1)
        HandleInput->search_max_year(v_films_save,info.find("max_year")->second);
    if(info.count("price")==1)
        HandleInput->search_info(v_films_save,info.find("price")->second);
    if(info.count("director")==1)
        HandleInput->search_info(v_films_save,info.find("director")->second);

    return v_films_save;
}

void netflix::get_published()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(online->return_publisher() != "true"){
        cout << "Permission Denied" << endl;
        return;
    }
    publisher *p = online_publisher();
    vector<film*> v_films_save=search_v_films();
    HandleInput->get_published(v_films_save,p);
    
}

void netflix::get_purchased()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }

    vector<film*> v_films_save=search_v_films();
    HandleInput->get_purchased(v_films_save,online);
}

void netflix::get_films_filter()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }

    vector<film*> v_films_save=search_v_films();
    HandleInput->get_films_filter(v_films_save);
}

void netflix::get_films()
{
    user *online = online_user();
    if(online == nullptr){
        cout << "Bad Request" << endl;
        return;
    }
    if(info.count("film_id")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }

    string filmId = info.find("film_id")->second;
    film *f = HandleInput->find_film(filmId);
    if(f==nullptr)
    {
        cout << "Not Found" << endl;
        return;
    }         

    HandleInput->get_films(f,online);    
}

void netflix::signup_command()
{
    if (line.size()==12 || line.size()==14)
        signup();
    else
        cout<<"Bad Request"<<endl;
}
void netflix::login_command()
{
    if(info.count("username")!=1 || info.count("password")!=1)
    {
        cout<<"Bad Request"<<endl;
        return;
    }
    if(line.size()==8)
        HandleInput->login(info.find("username")->second,info.find("password")->second);
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::post_film_command()
{
    if(line.size()==16)
        post_films();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::post_followers_command()
{
    if(line.size()==6)
        post_followers();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::post_money_command()
{
    if(info.count("?")==1)
    {
        if(line.size()==6)
            post_money_user();
        else 
            cout<<"Bad Request"<<endl;
    }
    else if(info.count("?")==0)
    {
        if(line.size()==3)
            post_money_publisher();
        else 
            cout<<"Bad Request"<<endl;
    }
}

void netflix::post_rate_command()
{
    if(line.size()==8)
        post_rate();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::post_buy_command()
{
    if(line.size()==6)
        post_buy();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::post_comment_command()
{
    if(line.size()==8)
        post_comments();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::post_reply_command()
{
    if(line.size()==10)
        post_replies();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::post_commands()
{
    if(line[1]=="signup")
        signup_command();
    else if(line[1]=="login")
        login_command();
    else if(line[1]=="films")
        post_film_command();
    else if(line[1]=="followers")
        post_followers_command();
    else if(line[1]=="money")
        post_money_command();
    else if(line[1]=="buy")
        post_buy_command();
    else if(line[1]=="rate")
        post_rate_command();
    else if(line[1]=="comments")
        post_comment_command();
    else if(line[1]=="replies")
        post_reply_command();
    else
        cout<<"Not Found"<<endl;
}

void netflix::put_film_command()
{
    if(line.size()==6 ||line.size()==8 ||line.size()==10 ||line.size()==12 ||line.size()==14 ||line.size()==16)
        put_films();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::put_commands()
{
    if(line[1]=="films")
        put_film_command();
    else
        cout<<"Not Found"<<endl;    
}

void netflix::delete_film_command()
{
    if(line.size()==6)
        delete_films();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::delete_comment_command()
{
    if(line.size()==8)
        delete_comments();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::delete_commands()
{
    if(line[1]=="films")
        delete_film_command();
    else if(line[1]=="comments")
        delete_comment_command();
    else
        cout<<"Not Found"<<endl;    
}

void netflix::get_notification_command()
{
    if(line.size()==3)
        get_notifications_user();
    else if(line.size()==7)
        get_notifications_publisher();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::get_followers_command()
{
    if(line.size()==3)
        get_followers();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::get_published_command()
{
    if(line.size()==3 || line.size()==4 || line.size()==6||line.size()==8 ||line.size()==10||line.size()==12||line.size()==14||line.size()==16)
        get_published();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::get_purchased_command()
{
    if(line.size()==3 || line.size()==4 || line.size()==6||line.size()==8 ||line.size()==10||line.size()==12||line.size()==14||line.size()==16)
        get_purchased();
    else 
        cout<<"Bad Request"<<endl;
}

void netflix::get_film_command()
{
    if(info.count("film_id")==0)
    {
        if(line.size()==3 || line.size()==4 || line.size()==6||line.size()==8 ||line.size()==10||line.size()==12||line.size()==14||line.size()==16)
            get_films_filter();
        else 
            cout<<"Bad Request"<<endl;
    }
    else if(info.count("film_id")==1)
    {
        if(line.size()==6)
            get_films();
        else 
            cout<<"Bad Request"<<endl;
    }
    else
        cout<<"Not Found"<<endl;
}

void netflix::get_commands()
{
    if(line[1]=="notifications")
        get_notification_command();
    else if(line[1]=="followers")
        get_followers_command();
    else if(line[1]=="published")
        get_published_command();
    else if(line[1]=="purchased")
        get_purchased_command();
    else if(line[1]=="films")
        get_film_command();
    else
        cout<<"Not Found"<<endl;    
}


void netflix::run()
{
    while(getline(cin,str)) 
    {   
        line=removeDupWord(str);
        info=seperate_input();
        if(str.size()!=0)
        {
            if(line[0]=="POST" )
                post_commands();
            else if(line[0]=="PUT")
                put_commands();
            else if(line[0]=="DELETE")
                delete_commands();
            else if(line[0]=="GET")
                get_commands();
            else 
                cout<<"Bad Request"<<endl;
        }
    }
}