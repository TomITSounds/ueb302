#include "cdate.h"
#include <ctime>
#include<stdio.h>


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
    printf("Dekonstruktor CDate");
};

void CDate::setDate(int Day, int Month, int Year){
    this->Year = Year;
    this->Month = Month;
    this->Day = Day;
}

void CDate::print(){
    printf("%02d.%02d.%4d", Day, Month, Year);
}
