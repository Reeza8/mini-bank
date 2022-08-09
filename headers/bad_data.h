#ifndef BAD_DATA
#define BAD_DATA
#include<iostream>
using namespace std;

class bad_data
{
private:
    string error;
public:
    bad_data(string);
    ~bad_data();
    void get_error(){cout<<error<<endl;}
};

#endif