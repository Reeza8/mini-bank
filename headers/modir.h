#ifndef MODIR
#define MODIR
#include "person.h"
#include "karmand.h"
class modir:public person
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
    modir(const string&,const string&,const string&,int,int,int,int,const string&,const string&,const long int&,const long int&,const vector<karmand*>&list);
    void print_info_karmand(int,vector<karmand*>)const;
    void sabte_karmand(vector<karmand*>&)const;
    string get_user()const{return _user_id;}
    string get_password()const{return _pass;}
     void darkhast_ezafe_kar(int&,int);
     void sabte_moshtari(vector<moshtari*>&)const;
     void masdod_kardan_hesab(const string&,const string&,vector<moshtari*>&)const;
     void namyesh_etelaat_moshtari(const vector<moshtari*>&,const string&)const;
     void darkhast_morakhasi(int&,int);
     void print_info()const;
     void hazfe_hesab(const string&,vector<moshtari*>&);
     void hazfe_karmand(const int&,vector<karmand*>&);
     void write_file(ofstream&);
     void read_file(ifstream&);
     string get_kode_melli()const{return _kode_meli;}
    ~modir();
};











#endif