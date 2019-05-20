#include <iostream>
#include"netflix.h"

using namespace std;

int main()
{
    netflix* Netflix=new netflix;
    Netflix->run();
    free (Netflix);
    return 0;
}