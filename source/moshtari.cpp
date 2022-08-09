#include "../headers/moshtari.h"




moshtari::moshtari(string name,string l_name,string kod,int d,int m,int y,string user,string pass,long int mojodi,string shomare_hesab,bool ac,vector<moshtari*> list):person(name,l_name, kod, d, m, y)
{               
        bool flag=true;                     
        for (int i = 0; i <list.size(); i++)
        {
            if(list.at(i)->_kode_meli==kod)
                flag=false;
        }
        if (flag==true)
        {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            _user_id=user;
            _pass=pass;
            _hesabs.push_back(Hesab(shomare_hesab,kod,ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year,mojodi,ac,list));
        }
        else 
        throw bad_data("kode melli mojod mibashad\n");
                                          
                                        
        
}

moshtari::~moshtari()
{
}

bool moshtari:: bardasht_az_hesab(long int m,const string& shomre)
{
    int index;
    for (int i = 0; i <_hesabs.size(); i++)
    {
       if(shomre==_hesabs.at(i).get_shomare_hesab())
            index=i;
    }
    return _hesabs.at(index).bardash_az_hesab(m);
    
}

bool moshtari:: variz_be_hesab(long int m,const string& shomare)
{
    int index;
    for (int i = 0; i <_hesabs.size(); i++)
    {
       if(shomare==_hesabs.at(i).get_shomare_hesab())
            index=i;
    }
    return _hesabs.at(index).variz_be_hesab(m);
}

void moshtari::print_info()const
{
  cout<<"\nname moshtari:"<<_name<<"\nname khanevadegi:"<<_l_name<<"\nkode meli:"<<_kode_meli;
  cout<<"\ntarikh tavalod:"<<_tavalod<<"\nuser id:"<<_user_id<<"\npassword:"<<_pass<<endl;
  for (int i = 0; i <_hesabs.size(); i++)
  {
      cout<<"hesab"<<i+1<<"\tmojodi="<<_hesabs[i].get_mojodi()<<" ";
      if(_hesabs.at(i).get_active()==false)
      cout<<"\thesab masdod ast\n";
  }
}

vector<Hesab>& moshtari:: get_hesab()
{
    return _hesabs;
}

void moshtari:: masdod_kardan(int index)
{
     _hesabs.at(index).di_actice();
}

void moshtari:: write_file(ofstream& write,vector<moshtari*> list)const
{
 for (int i = 0; i <list.size(); i++)
 {
     write<<"name:"<<list.at(i)->_name<<" lastname:"<<list.at(i)->_l_name<<" kode_melli:"<<list.at(i)->_kode_meli<<" tavalod:"<<list.at(i)->_tavalod<<" username:"<<list.at(i)->_user_id<<" password:";
     write<<list.at(i)->_pass;
     for (int b = 0; b <list.at(i)->get_hesab().size(); b++)
     {
         write<<" shomare_hesab="<<list.at(i)->get_hesab().at(b).get_shomare_hesab()<<" tarikhe_eftetah="<<list.at(i)->get_hesab().at(b).get_eftetah();
         write<<" mojodi="<<list.at(i)->get_hesab().at(b).get_mojodi()<<" active="<<list.at(i)->get_hesab().at(b).get_active();
     }
     if(i!=list.size()-1)
     write<<endl;
 }
}

void moshtari:: add_hesab(const string& hesab,const string& kod,int d,int m,int y,const long int& money,bool ac,vector<moshtari*>& list)
{
    _hesabs.push_back(Hesab(hesab,kod,d,m,y,money,ac,list));
}

void moshtari:: read_file( ifstream& read,vector<moshtari*>& list)const
{
   
    string info;
    int donoghte,counter=0,counter2=-1;
    int space;
    bool active;
    string name,l_name,kode_melli,user,pass,tavalod,temp,shomare;
    int day,month,year,index_tavalod,day_e,month_e,year_e;
    long int mojod;
    while (!read.eof())
    {
        getline(read,info);
        counter=0;
        counter2++;
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
        while (info.find('=')>0&&space>0)
        {
        donoghte=info.find('=');
        space=info.find(' ');
        shomare=info.substr(donoghte+1,space-donoghte-1);
        info=info.substr(space+1);
        
        donoghte=info.find('=');
        space=info.find(' ');
        tavalod=info.substr(donoghte+1,space-donoghte-1);
        info=info.substr(space+1);
       
        index_tavalod=tavalod.find('/');
        temp=tavalod.substr(0,index_tavalod);
        year_e=stof(temp);
        tavalod=tavalod.substr(index_tavalod+1);
        index_tavalod=tavalod.find('/');
        temp=tavalod.substr(0,index_tavalod);
        month_e=stof(temp);
        tavalod=tavalod.substr(index_tavalod+1);
        day_e=stof(tavalod);
        donoghte=info.find('=');
        space=info.find(' ');
        temp=info.substr(donoghte+1,space-donoghte-1);
        info=info.substr(space+1);
        mojod=stof(temp);
        donoghte=info.find('=');
        space=info.find(' ');
        temp=info.substr(donoghte+1,space-donoghte-1);
        info=info.substr(space+1);
        if(temp=="1")
           active=true;
        else 
         active=false;
        if(counter==0)
        {
            moshtari* m=new moshtari(name,l_name,kode_melli,day,month,year,user,pass,mojod,shomare,active,list);
            list.push_back(m);
        }
        else
        list.at(counter2)->add_hesab(shomare,kode_melli,day,month,year,mojod,active,list);
       
        counter++;
        }
        
       
    }
    
}

void moshtari::hazfe_hesab(vector<moshtari*>& list)
{
    string t;
    int index=-1;
    if (_hesabs.size()>1)
    {
        cout<<"shomare hesab mored nazar ra vared konid\n";
        getline(cin,t);
        for (int i = 0; i <_hesabs.size(); i++)
        {
            if (_hesabs.at(i).get_shomare_hesab()==t)
                index=i;    
        }
        if(index==-1)
        cout<<"shomare hesab yaft nashod\n";
        else
        {
            _hesabs.erase(_hesabs.begin()+index-1);
            cout<<"hesab mored nazar hazf shod\n";

        }
        
    }
    else
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (_kode_meli==list.at(i)->get_kode_meli())
                index=i;
        }
        list.erase(list.begin()+index-1);
    }
    

}

void moshtari:: print_info_hesab()const
{
    for (int i = 0; i <_hesabs.size(); i++)
    {
        cout<<"shomare hesaab: "<<_hesabs.at(i).get_shomare_hesab()<<"  mojodi: "<<_hesabs.at(i).get_mojodi();
        cout<<"  tarikh eftetah: "<<_hesabs.at(i).get_eftetah();
        if (_hesabs.at(i).get_active()==false)
            cout<<"  hesab masdod ast\n";
        else
        cout<<endl;    
    }
    
}




