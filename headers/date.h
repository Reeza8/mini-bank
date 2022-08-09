#ifndef DATE
#define DATE
#include<iostream>
using namespace std;

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
                                                                                
class Date {
    friend ostream& operator<<( ostream& out,const Date& d)
    {
        out<<d.year<<"/"<<d.month<<"/"<<d.day;
        return out;

    }
public:
    Date(int d, int m, int y);
    Date();
    void set_date(int d, int m, int y);
    void print_date();
    bool equals(Date d);
    Date operator+(const Date& d) const; //1
    Date operator-(const Date& d) const; //2
    Date& operator+=(const Date& d);//3
    int operator-( Date d);         //bejaye days_between
    Date& operator=(const Date& d);
     int compare(Date d2);
    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }
	void inc_one_day();
private:
    int day;
    int month;
    int year;
};
                                                                                








#endif