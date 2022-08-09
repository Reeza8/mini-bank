#include "../headers/modir.h"



modir::modir(const string& namee,const string& l_namee,const string& kode,int day,int month,int year,int kode_personeli,const string& user,const string& pass,const long int& paye,const long int& h,const vector<karmand*>& list):person(namee,l_namee, kode, day, month, year)
{
    bool flag=true,flag2=true;
    for (int i = 0; i <list.size(); i++)
        if (list.at(i)->get_kode_personeli()==kode_personeli)
            flag=false;
    for (int i = 0; i <list.size(); i++)
        if (list.at(i)->get_kode_melii()==_kode_meli)
            flag2=false;        
    if (flag==true&&flag2==true)
    {
     _kode_personeli=kode_personeli;
     _morakhasi=0;
     _ezafe_kar=0;
     _user_id=user;
     _pass=pass;
     _paye_daryafti=paye;
     _pay=h;
    }
    else if(flag==false)
    throw bad_data("\nkode personeli mojod moibashad\n");
    else
      throw bad_data("\nkode melli mojod moibashad\n");
}

modir::~modir()
{
}

void modir:: print_info_karmand(int personeli,vector<karmand*> k)const
{
   int index=-1;
   for (int i = 0; i <k.size(); i++)
       if(k.at(i)->get_kode_personeli()==personeli)
        index=i;
   if(index!=-1)     
   k.at(index)->print_info();
   else
   cout<<"karmand yaft nashod\n";
}

void modir::sabte_karmand(vector<karmand*>& k)const
{
    string user,pass,name,l_name,kode_meli;
    int kode_personeli,d,m,y;
    long int paye,hoghogh ;
    cout<<"name ra vared konid\n";
    getline(cin,name);
    cout<<"name khanevadegi ra vared konid\n";
    getline(cin,l_name);
    cout<<"kode melli ra vared konid\n";
    getline(cin,kode_meli);
    cout<<"user name ra vared konid\n";
    getline(cin,user);
    cout<<"ramz ra vared konid\n";
    getline(cin,pass);
    cout<<"kode personeli ra vared konid\n";
    cin>>kode_personeli;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"paye hoghogh ra vared konid\n";
    cin>>paye;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    cout<<"be tartib sal,mah va roz tavalod ra vared konid\n";
    cin>>d>>m>>y;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    karmand* kar=new karmand(name,l_name,kode_meli,d,m,y,kode_personeli,user,pass,paye,paye,k);
    k.push_back(kar);

}///string namee,string l_namee,string kode,int day,int month,int year,int kode_personeli,string user,string pass,vector<karmand*> list

void modir:: darkhast_ezafe_kar(int& mah,int saat_ezafe_kar)
{
    if(mah>30)
    {
        mah=mah-30;
        _morakhasi=0;
        _ezafe_kar=saat_ezafe_kar;
        _pay=_paye_daryafti+_ezafe_kar*120000;
        cout<<"hoghogh shoma ba ezafe kar sabt shode ="<<_pay<<endl;

    }
    else
    {
        
        if(_ezafe_kar+saat_ezafe_kar<12)
        {
            _pay+=saat_ezafe_kar*120000;
            _ezafe_kar+=saat_ezafe_kar;
            cout<<"hoghogh shoma ba ezafe kare sabt shode ="<<_pay<<endl;
        }
        else
            cout<<"saat ezafe kari shoma bish az 12 saat shode ast\n";

    }
}

void modir::sabte_moshtari(vector<moshtari*>& list)const
{
    string name,l_name,kod,user,pass,shomare_hesab;
    int d,m,y;
    long int mojodi;
    cout<<"name ra vared konid\n";
    getline(cin,name);
    cout<<"name khanevadegi ra vared konid\n";
    getline(cin,l_name);
    cout<<"kode melli ra vared konid\n";
    getline(cin,kod);
    cout<<"user name ra vared konid\n";
    getline(cin,user);
    cout<<"ramz ra vared konid\n";
    getline(cin,pass);
    cout<<"shomare hesab ra vared konid\n";
    getline(cin,shomare_hesab);
    cout<<"be tartib sal,mah va roz tavalod ra vared konid\n";
    cin>>d>>m>>y;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"hesab ba che meghdar poli eftetah shavad?\n";
    cin>>mojodi;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    moshtari* mos=new moshtari(name,l_name,kod,d,m,y,user,pass,mojodi,shomare_hesab,true,list);
    list.push_back(mos);
}

void modir:: masdod_kardan_hesab(const string& kode_melli,const string& shomare_hesab,vector<moshtari*>& list)const
{
    int index_moshtari=-1,index_hesab=-1;
    for (int i = 0; i <list.size(); i++)
    {
        if(kode_melli==list.at(i)->get_kode_meli())
        index_moshtari=i;
    }
    for (int i = 0; i < list.at(index_moshtari)->get_hesab().size(); i++)
    {
        if(list.at(index_moshtari)->get_hesab().at(i).get_shomare_hesab()==shomare_hesab)
        index_hesab=i;
         
    }
    if(index_hesab!=-1&&index_moshtari!=-1)
    list.at(index_moshtari)->get_hesab().at(index_hesab).di_actice();
    else 
     cout<<"shomare hesab ya kode melli moshtari ghalat ast\n";
}

void modir:: namyesh_etelaat_moshtari(const vector<moshtari*>& list,const string& kod)const
{
 int index=-1;
 for (int i = 0; i <list.size(); i++)
 {
    if(list.at(i)->get_kode_meli()==kod)
    index=i;
 }
 if(index!=-1)
 list.at(index)->print_info();
 else 
 throw bad_data("kode melli eshtebah ast\n");
}

void modir::darkhast_morakhasi(int& mah,int morakhasi)
{
    if (mah>30)
    {
        mah=mah-30;
        _ezafe_kar=0;
        _morakhasi=morakhasi;
        _pay=_paye_daryafti;
        cout<<"morakhsai sabt shod\n";
        cout<<15-_morakhasi<<" saat morakhasi dar in mah mande ast\n";
    }
    else
    {
        _morakhasi+=morakhasi;
        if (_morakhasi>15)
        {
          
          _pay-=100000*(15-morakhasi);
          cout<<"morakhasi shoma sabt shod va hoghogh shoma ="<<_pay<<" shod\n";
        }
        else
        {
            
            cout<<"morakhsai sabt shod\n";
            cout<<15-_morakhasi<<" saat morakhasi dar in mah mande ast\n";
            
        }
        
    }

}

void modir::print_info()const
{
    cout<<"name karmand:"<<_name<<"\nname khanevadegi:"<<_l_name<<"\nkode meli:"<<_kode_meli;
    cout<<"\ntarikh tavalod:"<<_tavalod<<"\nuser id:"<<_user_id<<"\npassword:"<<_pass<<endl;
    cout<<"kode personeli:"<<_kode_personeli<<"\npaye daryafti:"<<_paye_daryafti<<"\nsaat morakhasi dar in mah:"<<_morakhasi;
    cout<<"\nsaat ezafe kari dar in mah:"<<_ezafe_kar<<"\nhoghogh:"<<_pay<<endl;
    
}

void modir:: hazfe_hesab(const string& kod,vector<moshtari*>& list)
 {
     int index=-1;
     for (int i = 0; i <list.size(); i++)
     {
        if(kod==list.at(i)->get_kode_meli())
        index=i;
     }
     if (index==-1)
        cout<<"moshtari ba kode melli vared shode peyda nashode ast\n\n";
     
     else
     {
         list.at(index)->hazfe_hesab(list);
         cout<<"hazfe hesab anjam shod\n";
     }
     
 }
 
void modir::hazfe_karmand(const int& kod,vector<karmand*>& list)
{
    int index=-1;
    for (int i = 0; i <list.size(); i++)
    {
      if (kod==list.at(i)->get_kode_personeli())
      {
          index=i;
      }
      
    }
    if(index==-1)
    cout<<"karmand yaft nashod\n\n";
    else
    list.erase(list.begin()+index-1);
    

}

void modir:: write_file(ofstream& write)
{
    write<<"name_karmand:"<<_name<<" name_khanevadegi:"<<_l_name<<" kode_meli:"<<_kode_meli;
    write<<" tarikh_tavalod:"<<_tavalod<<" user_id:"<<_user_id<<" password:"<<_pass;
    write<<" kode_personeli:"<<_kode_personeli<<" paye_daryafti:"<<_paye_daryafti<<" saat_morakhasi_dar_in_mah:"<<_morakhasi;
    write<<" saat_ezafe_kari_dar_in_mah:"<<_ezafe_kar<<" hoghogh:"<<_pay;

}

void modir:: read_file(ifstream& read )
{
    string info;
    int donoghte,counter=0,counter2=-1;
    int space;
    
    string name,l_name,kode_melli,user,pass,tavalod,temp;
    int day,month,year,index_tavalod,morakhasi,ezafe_kari,shomare_personeli;
    long int hoghogh,paye;

         getline(read,info);
         donoghte=info.find(':');
         space=info.find(' ');
         name=info.substr(donoghte+1,space-donoghte-1);
         info=info.substr(space+1);

         donoghte=info.find(':');
         space=info.find(' ');
         l_name=info.substr(donoghte+1,space-donoghte-1);
         info=info.substr(space+1);

         donoghte=info.find(':');
         space=info.find(' ');
         kode_melli=info.substr(donoghte+1,space-donoghte-1);
         info=info.substr(space+1);

        donoghte=info.find(':');
        space=info.find(' ');
        tavalod=info.substr(donoghte+1,space-donoghte-1);
        info=info.substr(space+1);
       
        index_tavalod=tavalod.find('/');
        temp=tavalod.substr(0,index_tavalod);
        year=stof(temp);
        tavalod=tavalod.substr(index_tavalod+1);
        index_tavalod=tavalod.find('/');
        temp=tavalod.substr(0,index_tavalod);
        month=stof(temp);
        tavalod=tavalod.substr(index_tavalod+1);
        day=stof(tavalod);
        donoghte=info.find(':');
        space=info.find(' ');
        user=info.substr(donoghte+1,space-donoghte-1);
        info=info.substr(space+1);
        donoghte=info.find(':');
        space=info.find(' ');
        pass=info.substr(donoghte+1,space-donoghte-1);
        info=info.substr(space+1);

        donoghte=info.find(':');
        space=info.find(' ');
        temp=info.substr(donoghte+1,space-donoghte-1);
        info=info.substr(space+1);
        shomare_personeli=stof(temp);

        

        donoghte=info.find(':');
        space=info.find(' ');
        temp=info.substr(donoghte+1,space-donoghte-1);
        paye=stof(temp);
        info=info.substr(space+1);

        donoghte=info.find(':');
        space=info.find(' ');
        temp=info.substr(donoghte+1,space-donoghte-1);
        info=info.substr(space+1);
        morakhasi=stof(temp);

        donoghte=info.find(':');
        space=info.find(' ');
        temp=info.substr(donoghte+1,space-donoghte-1);
        info=info.substr(space+1);
        ezafe_kari=stof(temp);

        donoghte=info.find(':');
        space=info.find(' ');
        temp=info.substr(donoghte+1,space-donoghte-1);
        info=info.substr(space+1);
        hoghogh=stof(temp);
        _name=name;
        _l_name=l_name;
        _kode_meli=kode_melli;
        _tavalod.set_date(day,month,year);
        _user_id=user;
        _pass=pass;
        _kode_personeli=shomare_personeli;
        _paye_daryafti=paye;
        _pay=hoghogh;
        _morakhasi=morakhasi;
        _ezafe_kar=ezafe_kari;
        
    
        

        



}









