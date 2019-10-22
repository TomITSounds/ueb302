#include "ctime.h"
#include <ctime>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

CTime::CTime(){
    time_t Now;
    time(&Now);
    tm NowNow = (*localtime(&Now));         //Conversion
    Hour    = NowNow.tm_hour;
    Minute   = NowNow.tm_min ;
    Second     = NowNow.tm_sec;
    
}

CTime::CTime(int Hour, int Minute){
    this->Hour = Hour;
    this->Minute = Minute;
    Second = 0;
}

    
CTime::CTime(int Hour, int Minute, int Second){
    this->Hour = Hour;
    this->Minute = Minute;
    this->Second = Second;
}

CTime::~CTime(){};

void CTime::setTime(int Hour, int Minute, int Second){
     this->Hour = Hour;
     this->Minute = Minute;
     this->Second = Second;
}

void CTime::print(){
    printf("%02d:%02d:%02d", Hour, Minute, Second);
}
