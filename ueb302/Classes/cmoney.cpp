#include "cmoney.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "basetypeload.hpp"

using namespace std;

CMoney::CMoney(): Amount(0.0), Currency("EUR"){};

CMoney::CMoney(double Amount, string Currency){
    this->Amount = Amount;
    this->Currency = Currency;
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

CMoney CMoney::load(ifstream& data, string endtag){
    string line;
    string *currency = NULL;
    double *amount = NULL;
    
    
    do{
        if(data.eof()){
            cout << "Datei fehlerhaft CMoney"<<endl;
            break;
        }
        getline(data>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 8)=="<Amount>")
            amount = new double(basetypeload::load(line, "</Amount>", amount));
        
        if(line.substr(0, 10)=="<Currency>")
            currency = new string(basetypeload::load(line, "</Currency>", currency));
    
    } while(line != endtag);
    
    CMoney ret(*amount, *currency);
    return ret;
}
