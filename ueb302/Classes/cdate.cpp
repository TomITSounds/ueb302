#include "cdate.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include "basetypeload.hpp"
#include <string>
#include <fstream>
#include <vector>

using namespace std;


CDate::CDate(){
    time_t Now;
    time(&Now);
    tm NowNow = (*localtime(&Now));         //Conversion
    Year    = NowNow.tm_year + 1900;
    Month   = NowNow.tm_mon ;
    Day     = NowNow.tm_mday;
    
}


    
CDate::CDate(int Day, int Month, int Year):
    Year(Year),
    Month(Month),
    Day(Day){
}

CDate::CDate(vector <string>& loadvalues, int i):
    Year(stoi(loadvalues.at(0+i))),
    Month(stoi(loadvalues.at(1+i))),
    Day(stoi(loadvalues.at(2+i))){
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

CDate* CDate::load(ifstream &pdata, vector <string>& loadvalues, int i, string endtag){
    CDate::loadvalues(pdata, loadvalues, i, endtag);
    return new CDate(loadvalues, i);
}

void CDate::loadvalues(ifstream &pdata, vector<string> &loadvalues, int i, string endtag){
    string line;
    
    do{
        if(pdata.eof()){
            cout<<"Datei fehlerhaft CDate"<<endl;
            return;
        }
        
        getline(pdata>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 6)=="<Year>"){
            basetypeload::loadstr(line, 7);
            loadvalues.at(0+i) = line;
        }
        if(line.substr(0, 7)=="<Month>"){
            basetypeload::loadstr(line, 8);
            loadvalues.at(1+i) = line;
        }
        if(line.substr(0, 5)=="<Day>"){
            basetypeload::loadstr(line,6);
            loadvalues.at(2+i) = line;
        }
            
    }while(line != endtag);
}
