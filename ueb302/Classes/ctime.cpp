#include "ctime.h"
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "basetypeload.hpp"

using namespace std;

CTime::CTime(){
    time_t Now;
    time(&Now);
    tm NowNow = (*localtime(&Now));         //Conversion
    Hour = NowNow.tm_hour;
    Minute = NowNow.tm_min ;
    Second = NowNow.tm_sec;
}
    
CTime::CTime(int Hour, int Minute, int Second):
    Hour(Hour), Minute(Minute), Second(Second){
}

CTime::CTime(vector<string>& loadvalues, int i):
    Hour(stoi(loadvalues.at(0+i))), Minute(stoi(loadvalues.at(1+i))), Second(stoi(loadvalues.at(2+i))){
}

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

CTime* CTime::load(ifstream& pdata, vector<string>& loadvalues, int i, string endtag){
    CTime::loadvalues(pdata, loadvalues, i, endtag);
    
    return new CTime(loadvalues, i);
}
void CTime::loadvalues(ifstream& pdata, vector<string>& loadvalues, int i, string endtag){
    do{
        if(pdata.eof()){
            cout<<"Datei fehlerhaft CTime"<<endl;
            return;
        }
        getline(pdata>>ws, loadvalues.back());
        loadvalues.back().pop_back();
        
        CTime::loadsinglevalue(loadvalues, i);
    }while(loadvalues.back() != endtag);
}
void CTime::loadsinglevalue(vector<string>& loadvalues, int i){
    if(loadvalues.back().substr(0, 6)=="<Hour>"){
        basetypeload::loadstr(loadvalues.back(),7);
        loadvalues.at(0+i) = loadvalues.back();
        return;
    }
    if(loadvalues.back().substr(0, 8)=="<Minute>"){
        basetypeload::loadstr(loadvalues.back(), 9);
        loadvalues.at(1+i) = loadvalues.back();
        return;
    }
    if(loadvalues.back().substr(0, 8)=="<Second>"){
        basetypeload::loadstr(loadvalues.back(), 9);
        loadvalues.at(2+i) = loadvalues.back();
    }
}
