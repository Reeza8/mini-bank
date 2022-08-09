#include "../headers/date.h"
#include<iostream>
using namespace std;
#include <vector>

Date::Date(int d, int m, int y)
{
	//constructor
    set_date(d, m, y);
}

bool is_leap_year(int year)
{
    int r = year % 33;
    return r==1 || r==5 || r==9 || r==13 || r==17 || r==22 || r==26 || r==30;
}

int max_day_for_month(int m, int y)
{
    if (m < 7)
        return 31;
    else if (m < 12)
        return 30;
    else if (m == 12)
        return is_leap_year(y) ? 30 : 29;
    else  
        abort();
}

Date::Date()
{
	//default constructor
    set_date(1, 1, 1950);
}

Date Date ::operator+(const Date& d) const
{
  int _day=0,_month=0,_year=0;
  _month=month+d.month;
  if (_month>12)
  {
    _month-=12;
    _year++;   
  }
  _year+=year+d.year;
  _day=day+d.day;
  int max=max_day_for_month(_month,_year);
  if (_day>max)
  {
      _day-=max_day_for_month(_month,_year);
      _month++;
      if (_month>12)
      {
        _month-=12;
        _year++;   
      }
  }

  if (_day>max_day_for_month(_month,_year))
  {
      _day-=max_day_for_month(_month,_year);
      _month++;
      if (_month>12)
      {
        _month-=12;
        _year++;   
      }
  }
   return Date(_day,_month,_year);
}

Date Date::operator-(const Date& d) const
{
  int _day=0,_month=0,_year=0;
  _year=year-d.year;
  if (_year<=0)
  {
      abort();
  }
  _month=month-d.month;
  if (_month<=0)
  {
      _year--;
      _month+=12;
  }
  _day=day-d.day;
  if (_day<=0)
  {
    _day+=max_day_for_month(_month,_year);
     _month--;
    if (_month<=0)
    {
      _year--;
      _month+=12;
    }
  }
  if (_day>max_day_for_month(_month,_year))
  {
      _day-=max_day_for_month(_month,_year);
      _month++;
  }
  
  return Date(_day,_month,_year);
}

Date& Date ::operator+=(const Date& d)
{
 int _day=0,_month=0,_year=0;
  _month=month+d.month;
  if (_month>12)
  {
    _month-=12;
    _year++;   
  }
  _year+=year+d.year;
  _day=day+d.day;
  int max=max_day_for_month(_month,_year);
  if (_day>max)
  {
      _day-=max_day_for_month(_month,_year);
      _month++;
      if (_month>12)
      {
        _month-=12;
        _year++;   
      }
  }

  if (_day>max_day_for_month(_month,_year))
  {
      _day-=max_day_for_month(_month,_year);
      _month++;
      if (_month>12)
      {
        _month-=12;
        _year++;   
      }
  }
  day=_day;
  month=_month;
  year=_year;
  return *this;
}

Date& Date::operator=(const Date& d)
{
  day=d.day;
  year=d.year;
  month=d.month;
  return *this;
}

void Date::inc_one_day()
{
    day++;
    if (day > max_day_for_month(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

bool Date::equals(Date d) 
{
	
    return day == d.day && month == d.month && year == d.year;
}

int Date::compare(Date d2)
{
if (year>d2.year)
{
 return 1;
}
if ((year==d2.year)&&(month>d2.month))
{
   return 1;
}
if ((year==d2.year)&&(month==d2.month)&&(day>d2.day))
{
   return 1;
}
if ((year==d2.year)&&(month==d2.month)&&(day==d2.day))
{
    return 0;
}
else 
 return -1;
}

int Date:: operator-( Date d)
{


  int count=0;
  Date temp;
    if (this->compare(d)==1)
    {
        temp=d;
        d=*this;
        *this=temp;
        
    }
  while (!this->equals(d))
  {
    this->inc_one_day();
    count++;
  }
  return count;
  
}

void Date::set_date(int d, int m, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > max_day_for_month(m, y))
        abort();

    day = d;
    month = m;
    year = y;
}

void Date::print_date()
{
	//baraye chape tarikh
    cout << day << '/' << month << '/' << year << endl;
}

int days_between(Date d1, Date d2) 
{
    // Assuming d1 is not later than d2
    int count = 1;
    while (!d1.equals(d2))
    {
        d1.inc_one_day();
        count++;
    }
    return count;
}