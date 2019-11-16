#include "ctime.h"
#include <ctime>
#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>

using namespace std;

CTime::CTime(){
    time_t Now;
    time(&Now);
    tm NowNow = (*localtime(&Now));         //Conversion
    Hour = NowNow.tm_hour;
    Minute = NowNow.tm_min ;
    Second = NowNow.tm_sec;
}
    
CTime::CTime(int Hour, int Minute, int Second){
    this->Hour = Hour;
    this->Minute = Minute;
    this->Second = Second;
}

CTime::~CTime(){
    cout << "Dekonstruktor CTime" << endl;
};

void CTime::setTime(int Hour, int Minute, int Second){
     this->Hour = Hour;
     this->Minute = Minute;
     this->Second = Second;
}

void CTime::print(){
    cout
    << setfill('0')
    <<setw(2) << Hour
    << "."
    << setw(2)<< Minute
    << "." << setw(2)
    << Second << endl;
}
