#include "../headers/person.h"

#include<iostream>
using namespace std;
#include <vector>


person::person(string name,string l_name,string kod,int d,int m,int y):_tavalod(d,m,y)
{
        _name=name;
        _l_name=l_name;
        _kode_meli=kod;
}

person::~person()
{
}