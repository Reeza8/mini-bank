#include "../headers/hesab.h"
#include<iostream>
using namespace std;
#include <vector>
#include "../headers/moshtari.h"
#include "../headers/bad_data.h"

Hesab::Hesab(const string& hesab,const string& kod,int d,int m,int y,const long int& money,bool ac,const vector<moshtari*>& list):eftetah(d,m,y)
{
    bool flag=true;
    for (int i = 0; i <list.size(); i++)
    {
       
        for (int b = 0; b <list.at(i)->get_hesab().size(); b++)
        {
            if (hesab==list.at(i)->get_hesab().at(b)._shomare_hesab)
            flag=false;
        }
    }
    if(flag==true&&money>50000)
    {
        _shomare_hesab=hesab;
        _kode_meli=kod; 
        mojodi=money;
        active=ac;
    }
    else if(money<=50000)
        throw bad_data("mabalgh nmitavand kam tar az 50000 toman bashad\n");
    else if(flag==false)
        throw bad_data("in shomare hesab mojod mibashad\n");
    
}

Hesab::~Hesab()
{
}

bool Hesab::bardash_az_hesab(const long int& m)
{
    if (m>0&&mojodi>=m&&active==true)
    {
      mojodi-=m;
      return true;
    }
    else if(mojodi<m)
    {
         cout<<"mojodi kafi nmibashad\n";
         return false;
    }
    else if(active==false)
    {
        cout<<"hesab masdod ast\n";
        return false;

    }
    else 
    return false;
}

bool Hesab::variz_be_hesab(const long int& m)
{
    if (m>0)
    {
        mojodi+=m;
        return true;
    }
    else
    return false;


}

