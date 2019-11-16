#include "cdate.h"
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;


CDate::CDate(){
    time_t Now;
    time(&Now);
    tm NowNow = (*localtime(&Now));         //Conversion
    Year    = NowNow.tm_year + 1900;
    Month   = NowNow.tm_mon ;
    Day     = NowNow.tm_mday;
    
}
    
CDate::CDate(int Day, int Month, int Year){
    this->Year = Year;
    this->Month = Month;
    this->Day = Day;
}

CDate::~CDate(){
    cout << "Dekonstruktor CDate" << endl;
};

void CDate::setDate(int Day, int Month, int Year){
    this->Year = Year;
    this->Month = Month;
    this->Day = Day;
}

void CDate::print(){
    cout
    << setfill('0')
    <<setw(2) << Day
    << "."
    << setw(2) << Month
    << "."
    << setw(4) << Year << endl;
}
