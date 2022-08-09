#ifndef KARMAND
#define KARMAND

#include "person.h"
#include<limits>
#include"moshtari.h"

class karmand:public person
{
private:
 int _kode_personeli;
 int _paye_daryafti;
 int _morakhasi;
 int _ezafe_kar;
 int _pay;
 string _user_id;
 string _pass;
    
public:
    karmand(const string&,const string&,const string&,int,int,int,int,const string&,const string&,const long int&,const long int&,const vector<karmand*>&list);
    karmand(const string&,const string&,const string&,int,int,int,int,const string&,const string&,const long int&,const long int&,int,int,const vector<karmand*>&list);
    void darkhast_ezafe_kar(int&,int);//h
    void sabte_moshtari(vector<moshtari*>&)const;//h
    void masdod_kardan_hesab(const string&,const string&,vector<moshtari*>&)const;//h
    void namyesh_etelaat_moshtari(const vector<moshtari*>&,const string&)const;//h
    void darkhast_morakhasi(int&,int);//h
    void print_info()const;//h
    int get_kode_personeli()const{return _kode_personeli;}
    void write_file(ofstream& write,vector<karmand*> list)const;
    void read_file(istream& read,vector<karmand*>& list)const;
    string get_user()const{return _user_id;}
    string get_password()const{return _pass;}
    void hazfe_hesab(const string&,vector<moshtari*>&);//h
    string get_kode_melii()const{return _kode_meli;}
    ~karmand();
};






#endif