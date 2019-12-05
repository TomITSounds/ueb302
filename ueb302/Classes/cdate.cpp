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
    Day(stoi(loadvalues.at(0+i))),
    Month(stoi(loadvalues.at(1+i))),
    Year(stoi(loadvalues.at(2+i))){
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

CDate* CDate::load(ifstream &pdata, vector <string>& loadvalues, int i, string endtag, bool alloc){
    CDate::loadvalues(pdata, loadvalues, i, endtag);

    if(alloc)
       return new CDate(loadvalues, i);
    else
       return NULL;
}

void CDate::loadvalues(ifstream &pdata, vector<string> &loadvalues, int i, string endtag){
do{
    if(pdata.eof()){
        cout<<"Datei fehlerhaft CDate"<<endl;
        break;
    }
    
    getline(pdata>>ws, loadvalues.back());
    loadvalues.back().pop_back();
    
    if(loadvalues.back().substr(0, 5)=="<Day>"){
        basetypeload::loadstr(loadvalues.back(),6);
        loadvalues.at(0+i) = loadvalues.back();
        continue;
    }
    if(loadvalues.back().substr(0, 7)=="<Month>"){
        basetypeload::loadstr(loadvalues.back(), 8);
        loadvalues.at(1+i) = loadvalues.back();
        continue;
    }
    if(loadvalues.back().substr(0, 6)=="<Year>"){
        basetypeload::loadstr(loadvalues.back(), 7);
        loadvalues.at(2+i) = loadvalues.back();
    }
    
}while(loadvalues.back() != endtag);
    
}
