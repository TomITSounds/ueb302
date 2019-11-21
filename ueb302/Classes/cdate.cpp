#include "cdate.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include "basetypeload.hpp"
#include <string>
#include <fstream>

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

CDate CDate::load(ifstream &pdata, string endtag){
    string line;
    int day, month, year;
    int ret = pdata.tellg();
    
    do{
        if(pdata.eof()){
            cout<<"Datei fehlerhaft CDate"<<endl;
        }
        
        getline(pdata>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 5)=="<Day>")
            day = basetypeload::loadint(line,6);
        
        if(line.substr(0, 7)=="<Month>")
            month = basetypeload::loadint(line, 8);
        
        if(line.substr(0, 6)=="<Year>")
            year = basetypeload::loadint(line, 7);
            
    }while(line != endtag);
    
    pdata.seekg(ret);
    
    return CDate(day, month, year);
}
