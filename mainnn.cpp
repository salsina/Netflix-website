#include "md5.h"
#include <iostream>
using namespace std;
int main(){
    md5 hash;
    string str = "sina";
    hash.update(str.begin(),str.end());
    hash.hex_digest(str);
    cout << str << endl;
}