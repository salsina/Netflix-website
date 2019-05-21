#include "rate.h"

vector<int> rate::return_v_rates(){return rates;}

float rate::return_rate(){return film_rate;}

vector<int> rate::return_rater_ids(){return rater_ids;}

void rate::change_film_rate(int _rate)
{
    rates.push_back(_rate);
    float sum=0;
    for(int i=0;i<rates.size();i++)
    {
        sum+=rates[i];
    }
    film_rate=sum/float(rates.size());
}
