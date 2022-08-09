#ifndef PERSON
#define PERSON
#include<iostream>
using namespace std;
#include <vector>
#include "date.h"
#include "bad_data.h"
#include<string>
#include<fstream>
class person
{
protected:
    string _name;
    string _l_name;
    string _kode_meli;
    Date _tavalod;
public:
    person(string,string,string,int d,int m,int y);
    virtual ~person();
};






#endif