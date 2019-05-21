#ifndef RATE_H
#define RATE_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class rate{
public:
    rate(int rater)
    {
        rater_ids.push_back(rater);
    }
    vector<int> return_rater_ids();
    vector<int> return_v_rates();
    float return_rate();
    void change_film_rate(int _rate);

private:
    vector<int> rater_ids;
    vector<int> rates;
    float film_rate=0;

};
#endif