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

CDate CDate::load(ifstream& data, string endtag){
    string line;
    CDate date;
    
    do{
        if(data.eof()){
            cout<<"Datei fehlerhaft CDate"<<endl;
        }
        
        getline(data>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 5)=="<Day>")
            basetypeload::load(line, "</Day>", &(date.Day));
        
        if(line.substr(0, 7)=="<Month>")
            basetypeload::load(line, "</Month>", &(date.Month));
        
        if(line.substr(0, 6)=="<Year>")
            basetypeload::load(line, "</Year>", &(date.Year));
            
    }while(line != endtag);
    
    return date;
}
