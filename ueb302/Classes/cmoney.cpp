#include "cmoney.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "basetypeload.hpp"
#include <vector>

using namespace std;

CMoney::CMoney(): Amount(0.0), Currency("EUR"){};

CMoney::CMoney(double Amount, string Currency):
    Amount(Amount), Currency(Currency){
}

CMoney::CMoney(vector <string>& loadvalues, int i):
    Amount(stod(loadvalues.at(0+i))),
    Currency(loadvalues.at(1+i)){
    }

void CMoney::set(double Amount){
    this->Amount = Amount;
}

void CMoney::set(double Amount, string Currency){
    this->Amount = Amount;
    this->Currency = Currency;
}

void CMoney::set(CMoney copy){
    Amount= copy.getAmount();
    Currency= copy.getCurrency();
}

void CMoney::print(){
    cout    << setfill('0') << setprecision(2)
            << "Kontostand: " << Amount << " " << Currency ;
}

void CMoney::lprint(){
    cout    << setfill('0') << setprecision(2) << Amount
            << " "
            << setfill(' ') << setw(3) << Currency
            << endl;
}

CMoney* CMoney::load(ifstream &pdata, vector <string>& loadvalues, int i, string endtag){
    
    CMoney::loadvalues(pdata, loadvalues, i, endtag);
    
    return new CMoney(loadvalues, i);
}

void CMoney::loadvalues(ifstream &pdata, vector<string> &loadvalues, int i, string endtag){
    string line;

    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft CMoney"<<endl;
            return;
        }
        getline(pdata>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 8)=="<Amount>"){
            basetypeload::loadstr(line, 9);
            loadvalues.at(0+i) = line;
        }
        if(line.substr(0, 10)=="<Currency>"){
            basetypeload::loadstr(line, 11);
            loadvalues.at(1+i) = line;
        }
    
    } while(line != endtag);
}



 bool operator==(const CMoney &m1, const CMoney &m2)
{
    return (m1.Amount == m2.Amount &&
            m2.Currency == m2.Currency);
}
 
 bool operator!=(const CMoney &m1, const CMoney &m2)
{
    return !(m1 == m2);
}
