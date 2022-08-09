using namespace std;
#include<vector>
#include<iostream>
#include<ctime>
#include "headers/date.h"
#include "headers/bad_data.h"
#include "headers/person.h"
#include "headers/moshtari.h"
#include "headers/karmand.h"
#include "headers/modir.h"

char menu_karmand()
{
    char p;
    cout<<"\n1-darkhaste morakhasi\n2-darkhaste ezafe kar\n3-namyaesh etelaat shakhsi\n4-moshahede etelaat yek moshtari\n";
    cout<<"5-ijad hesab\n6-hazfe heesab\n7-masdod kardan hesab\nq-khoroj\n";
    cin>>p;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return p;
}

char menu_modir()
{
    char p;
    cout<<"\n1-darkhaste morakhasi\n2-darkhaste ezafe kar\n3-namyaesh etelaat shakhsi\n4-moshahede etelaat yek moshtari\n";
    cout<<"5-ijad hesab\n6-hazfe heesab\n7-masdod kardan hesab\n8-namayesh etelaat karmand\n9-afzodan karmand\n";
    cout<<"d-hazfe karmand\nq-khoroj\n";
    cin>>p;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return p;

}

char menu_moshtari()
{
    char p;
    cout<<"\n1-afzayesh mojodi hesab\n2-bardasht az hesab\n3-namayesh etelaat shakhsi\n4-namyesh etelaat hesab\nq-khoroj\n";
    cin>>p;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return p;
}


int main()    
{   // karmand* ka=new karmand("reza","ghanbarzadeh","0150059280",21,11,1380,344,"wead123","231321qw",40000,40000,k);
    
       
    char menu_1='3';  char menu_k='9';  char menu_m='7';
    string user,password,temp_s,shomare_hesab;
    int index=-1,temp_int=-1;
    static int mah=0;
    long int money;

    vector<karmand*> list_karmand;
    vector<moshtari*> list_moshtari;
    modir modir1("hhosein","aa","123123",1,1,1350,22,"1sdd","12",67,1,list_karmand);
    moshtari* m=new moshtari("rzaa","ghanbarzadeh","015009",3,4,333,"reza4","1234",2342234,"622101612",true,list_moshtari);
    karmand* ka2=new karmand("zahra","ashary","00433242",1,1,1350,3433,"za4hra","50225666",6056677,13132132,list_karmand);
    
    time_t now = time(0);
    tm *ltm = localtime(&now);


    ifstream read_m("moshtari.txt",ios::in);
    ifstream read_k("karmand.txt",ios::in);
    ifstream read_modir("modir.txt",ios::in);
    ifstream read_mah("mah.txt",ios::in);
    ofstream write_gozareh("report.txt",ios::app);


    

    
    m->read_file(read_m,list_moshtari);
    
    modir1.read_file(read_modir);
    
    ka2->read_file(read_k,list_karmand);

    read_mah>>mah;
    



    while (menu_1!='q')
    {
        cout<<"1-karmand\n2-moshtari\nq-khoroj\n";
        cin>>menu_1;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        menu_k='6';
        menu_m='7';
        switch (menu_1)
        {
        case '1':
            cout<<"username ra vared konid\n";
            getline(cin,user);
            cout<<"password ra vared konid\n";
            getline(cin,password);
            if(modir1.get_password()==password&&modir1.get_user()==user)
             index=-2;

            for (int i = 0; i <list_karmand.size(); i++)
            {
                if(list_karmand.at(i)->get_user()==user&&list_karmand.at(i)->get_password()==password)
                    index=i;
            }
                
                if(index==-1)
                {
                    cout<<"password ya name karbari ghalat ast\n";
                    break;
                }
                else if(index==-2)///modir
                {
                    write_gozareh<<"modir ba kode melli "<<modir1.get_kode_melli()<<"vared shod";
                    write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                    write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                    while (menu_k!='q')//modir
                    {
                        menu_k=menu_modir();
                        switch (menu_k)
                        {
                        case '1':
                        cout<<"saate morakhasi ra vared konid\n";
                        cin>>temp_int;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        modir1.darkhast_morakhasi(mah,temp_int);
                        temp_int=-1;
                        write_gozareh<<"modir ba kode melli "<<modir1.get_kode_melli()<<" morakahasi sabt kard "<<temp_int<<"saat sabt shod";
                        write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                        write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;

                        break;
                        
                        case '2':
                        cout<<"saate ezafe kari ra vared konid\n";
                        cin>>temp_int;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        modir1.darkhast_ezafe_kar(mah,temp_int);
                        temp_int=-1;
                        write_gozareh<<"modir ba kode melli "<<modir1.get_kode_melli()<<" ezafe kari sabt kard "<<temp_int<<"saat sabt shod";
                        write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                        write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;

                        break;

                        case '3':
                        modir1.print_info();

                        break;

                        case '4':
                        cout<<"kode melli ra vared konid\n";
                        getline(cin,temp_s);
                        try
                        {
                            modir1.namyesh_etelaat_moshtari(list_moshtari,temp_s);
                            
                        }
                        catch(bad_data e)
                        {
                            e.get_error();
                        }
                        
                        

                        break;

                        case '5':
                        cout<<"kode melli moshtari ra vared konid\n";
                        getline(cin,temp_s);
                        for (int i = 0; i <list_moshtari.size(); i++)
                        {
                            if(temp_s==list_moshtari.at(i)->get_kode_meli())
                                temp_int=i;
                            
                        }
                        
                         if(temp_int==-1)
                         {
                            cout<<"moshtari dakhel bank sabt nashode ast\n";
                            try
                            {
                                modir1.sabte_moshtari(list_moshtari);
                                write_gozareh<<"modir ba kode melli "<<modir1.get_kode_melli()<<" moshtari sabt kard";
                                write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                                write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                            }
                            catch(bad_data e)
                            {
                                e.get_error();
                            }
                            
                            
                            
                         }
                         else
                         {
                          time_t now = time(0);
                          tm *ltm = localtime(&now);
                          cout<<"shomare hesab jadid ra vared konid\n";
                          getline(cin,shomare_hesab);
                          cout<<"hesab ba che meghdar poli baz shavad\n";
                          cin>>money;
                          cin.ignore(numeric_limits<streamsize>::max(),'\n');
                          try
                          {
                            list_moshtari.at(temp_int)->add_hesab(shomare_hesab,temp_s,ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year,money,true,list_moshtari);
                            
                            write_gozareh<<"modir ba kode melli "<<list_karmand.at(index)->get_kode_melii()<<" hesab ijad kard ba shomare hesab: "<<shomare_hesab;
                            write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                            write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                          }
                          catch(bad_data e)
                          {
                              e.get_error();
                          }
                          
                          

                         }
                         temp_int=-1;


                        break;

                        case '6':
                        cout<<"kode melli moshtari ra vared konid\n";
                        getline(cin,temp_s);
                        modir1.hazfe_hesab(temp_s,list_moshtari);
                        write_gozareh<<"modir ba kode melli "<<modir1.get_kode_melli()<<" hesab moshtari ba kode melli "<<temp_s<<" ra hazf kard";
                        write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                        write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;


                        break;
                        case '7':
                        cout<<"kode melli moshtari ra vared konid\n";
                        getline(cin,temp_s);
                        cout<<"shomare hesab ra vared konid\n";
                        getline(cin,shomare_hesab);
                        modir1.masdod_kardan_hesab(temp_s,shomare_hesab,list_moshtari);
                        write_gozareh<<"modir ba kode melli "<<modir1.get_kode_melli()<<" hesab moshtari ba kode melli "<<temp_s<<" ra masdod kard";
                        write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                        write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;

                        break;
                        case '8':
                        cout<<"kode personeli ra vared konid\n";
                        cin>>temp_int;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        modir1.print_info_karmand(temp_int,list_karmand);
                        break;
                        case '9':
                        modir1.sabte_karmand(list_karmand);
                        write_gozareh<<"modir ba kode melli "<<modir1.get_kode_melli()<<" karmand ba kode personeli "<<list_karmand.at(list_karmand.size()-1)->get_kode_personeli();
                        write_gozareh<<" ra sabt kard";
                        write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                        write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                        break;
                        case 'd':
                        cout<<"kode personeli ra vared konid\n";
                        cin>>temp_int;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        modir1.hazfe_karmand(temp_int,list_karmand);
                        write_gozareh<<"modir ba kode melli "<<modir1.get_kode_melli()<<" karmand ba kode personeli "<<temp_int;
                        write_gozareh<<" ra hazf kard";
                        write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                        write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                        break;





                        }
                        
                    }

                }
                else
                {
                    while (menu_k!='q')//karmand
                    {
                         menu_k=menu_karmand();
                         write_gozareh<<"karmand ba kode melli "<<list_karmand.at(index)->get_kode_melii()<<" vared shod";
                         write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                         write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;

                        switch (menu_k)
                        {
                        case '1':
                        
                        cout<<"saate morakhasi ra vared konid\n";
                        cin>>temp_int;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        list_karmand.at(index)->darkhast_morakhasi(mah,temp_int);
                        
                        write_gozareh<<"karmand ba kode melli "<<list_karmand.at(index)->get_kode_melii()<<" morakahasi sabt kard "<<temp_int<<"saat sabt shod";
                        write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                        write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                        temp_int=-1;
                        break;
                        
                        case '2':
                        cout<<"saate ezafe kari ra vared konid\n";
                        cin>>temp_int;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        list_karmand.at(index)->darkhast_ezafe_kar(mah,temp_int);
                        
                        write_gozareh<<"karmand ba kode melli "<<list_karmand.at(index)->get_kode_melii()<<" ezafe kari sabt kard "<<temp_int<<"saat sabt shod";
                        write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                        write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                        temp_int=-1;
                        break;

                        case '3':
                        list_karmand.at(index)->print_info();

                        break;

                        case '4':
                        cout<<"kode melli ra vared konid\n";
                        getline(cin,temp_s);
                        try
                        {
                            list_karmand.at(index)->namyesh_etelaat_moshtari(list_moshtari,temp_s);
                        }
                        catch(bad_data e)
                        {
                            e.get_error();
                        }
                        
                        

                        break;

                        case '5':
                        cout<<"kode melli moshtari ra vared konid\n";
                        getline(cin,temp_s);
                        for (int i = 0; i <list_moshtari.size(); i++)
                        {
                            if(temp_s==list_moshtari.at(i)->get_kode_meli())
                                temp_int=i;
                            
                        }
                        
                         if(temp_int==-1)
                         {
                            cout<<"moshtari dakhel bank sabt nashode ast\n";
                            try
                            {
                                list_karmand.at(index)->sabte_moshtari(list_moshtari);
                                write_gozareh<<"karmand ba kode melli "<<list_karmand.at(index)->get_kode_melii()<<" moshtari sabt kard";
                                write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                                write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                            }
                            catch(bad_data e)
                            {
                                e.get_error();
                            }
                            
                         }
                         else
                         {
                          time_t now = time(0);
                          tm *ltm = localtime(&now);
                          cout<<"shomare hesab jadid ra vared konid\n";
                          getline(cin,shomare_hesab);
                          cout<<"hesab ba che meghdar poli baz shavad\n";
                          cin>>money;
                          cin.ignore(numeric_limits<streamsize>::max(),'\n');
                          try
                          {
                            list_moshtari.at(temp_int)->add_hesab(shomare_hesab,temp_s,ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year,money,true,list_moshtari);
                            write_gozareh<<"karmand ba kode melli "<<list_karmand.at(index)->get_kode_melii()<<" moshtari sabt kard";
                            write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                            write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                          }
                          catch(bad_data e)
                          {
                            e.get_error();
                          }
                         }
                         temp_int=-1;


                        break;

                        case '6':
                        cout<<"kode melli moshtari ra vared konid\n";
                        getline(cin,temp_s);
                        list_karmand.at(index)->hazfe_hesab(temp_s,list_moshtari);
                        write_gozareh<<"karmand ba kode melli "<<list_karmand.at(index)->get_kode_melii()<<" hesab moshtari ba kode melli "<<temp_s<<" ra hazf kard";
                        write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                        write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;


                        break;
                        case '7':
                        cout<<"kode melli moshtari ra vared konid\n";
                        getline(cin,temp_s);
                        cout<<"shomare hesab ra vared konid\n";
                        getline(cin,shomare_hesab);
                        list_karmand.at(index)->masdod_kardan_hesab(temp_s,shomare_hesab,list_moshtari);
                        write_gozareh<<"karmand ba kode melli "<<list_karmand.at(index)->get_kode_melii()<<" hesab moshtari ba kode melli "<<temp_s<<" ra masdod kard";
                        write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                        write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;


                        break;



                        }
                        
                    }
                    
                }

            
            break;
            case '2':
            cout<<"username ra vared konid\n";
            getline(cin,user);
            cout<<"password ra vared konid\n";
            getline(cin,password);
            for (int i = 0; i <list_moshtari.size(); i++)
            {
                if(list_moshtari.at(i)->get_user()==user&&list_moshtari.at(i)->get_password()==password)
                    index=i;
            }
            if (index!=-1)
            {
                while (menu_m!='q')
                {
                    menu_m=menu_moshtari();
                    write_gozareh<<"moshtari ba kode melli "<<list_moshtari.at(index)->get_kode_meli()<<" vared shod";
                    write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                    write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                    switch (menu_m)
                    {
                    case '1':
                       cout<<"shomare hesab ra vared konid\n";
                       getline(cin,shomare_hesab);
                       cout<<"che meghdar poli mikhahid bardasht konid\n";
                       cin>>temp_int;
                       cin.ignore(numeric_limits<streamsize>::max(),'\n');
                       list_moshtari.at(index)->variz_be_hesab(temp_int,shomare_hesab);
                       write_gozareh<<"moshtari ba kode melli "<<list_moshtari.at(index)->get_kode_meli()<<"be hesab ba shomare "<<shomare_hesab;
                       write_gozareh<<" meghdar "<<temp_int<<" variz kard";
                       write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                       write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                    break;
                    case '2':
                       cout<<"shomare hesab ra vared konid\n";
                       getline(cin,shomare_hesab);
                       cout<<"che meghdar poli mikhahid bardasht konid\n";
                       cin>>temp_int;
                       cin.ignore(numeric_limits<streamsize>::max(),'\n');
                       list_moshtari.at(index)->bardasht_az_hesab(temp_int,shomare_hesab);
                       write_gozareh<<"moshtari ba kode melli "<<list_moshtari.at(index)->get_kode_meli()<<"az hesab ba shomare "<<shomare_hesab;
                       write_gozareh<<" meghdar "<<temp_int<<" bardasht kard";
                       write_gozareh<<" Date:"<<1900 + ltm->tm_year<<"/";
                       write_gozareh<<1+ltm->tm_mon<<"/"<<ltm->tm_mday<<" Time "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
                      
                    break;    
                    case '3':
                    list_moshtari.at(index)->print_info();
 
                    break;
                    case '4':
                    list_moshtari.at(index)->print_info_hesab();
                    break;
            
            
                    }
                }
            }
            else
            {
                cout<<"password ya name karbari eshtebah ast\n";
            }
            break;
            case 'q':
            {
                mah++;
                ofstream write_m("moshtari.txt",ios::out);
                ofstream write_k("karmand.txt",ios::out);
                ofstream write_modir("modir.txt",ios::out);
                ofstream write_mah("mah.txt",ios::out);
                modir1.write_file(write_modir);
                m->write_file(write_m,list_moshtari);
                ka2->write_file(write_k,list_karmand);
                write_mah<<mah;
                for (int i = 0; i <list_karmand.size(); i++)
                    delete list_karmand.at(i);

                for (int i = 0; i <list_moshtari.size(); i++)
                {
                    delete list_moshtari.at(i);
                }
                
                delete ka2;
                delete m;
                
                
            }
            break;
        }
    }
    

    
/*karmand
wead123
231321qw
moshtari zahra
zahra22
123132a
melli 12312322
*/

    
    
    
    




    
    
}




