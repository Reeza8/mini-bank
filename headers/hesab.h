#ifndef HESAB
#define HESAB
#include<iostream>
using namespace std;
#include <vector>
#include "date.h"


class moshtari;
class Hesab
{
    
private:
    long int mojodi;
    bool active=true;
    Date eftetah;
    string _shomare_hesab;
    string _kode_meli;
    
public:
    Hesab(const string&,const string&,int ,int ,int ,const long int&,bool ,const vector<moshtari*>& );
    ~Hesab();
    bool bardash_az_hesab(const long int& );
    bool variz_be_hesab(const long int&);
    long int get_mojodi()const{return mojodi;}
    void di_actice(){active=false;}
    bool get_active()const{return active;}
    Date get_eftetah()const{return eftetah;}
    string get_shomare_hesab()const{return _shomare_hesab;}
    
};







#endif