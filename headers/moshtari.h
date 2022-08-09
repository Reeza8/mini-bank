#ifndef MOSHTARI
#define MOSHTARI

#include "hesab.h"
#include "vector"
#include<ctime>
#include "person.h"
#include "bad_data.h"

class moshtari:public person
{
private:
    string _user_id;
    string _pass;
    vector<Hesab> _hesabs;
public:
    moshtari(string name,string l_name,string kod,int d,int m,int y,string user,string p,long int,string,bool,vector<moshtari*> list);
     vector<Hesab>& get_hesab();
     bool bardasht_az_hesab(long int m,const string&);
     bool variz_be_hesab(long int m,const string&);
     void print_info()const;
     void masdod_kardan(int );
     string get_kode_meli()const{return _kode_meli;}
     void write_file(ofstream&,vector<moshtari*>)const;
     void read_file(ifstream&,vector<moshtari*>&)const;
     void add_hesab(const string&,const string&,int ,int ,int ,const long int&,bool ,vector<moshtari*>& );
     void hazfe_hesab(vector<moshtari*>&);
     string get_user()const{return _user_id;}
     string get_password()const{return _pass;}
     void print_info_hesab()const;
    ~moshtari();
};







#endif