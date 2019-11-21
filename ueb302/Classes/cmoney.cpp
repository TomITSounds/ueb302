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

CMoney CMoney::load(ifstream &pdata, string endtag){
    string line;
    double amount;
    string currency;
    int ret = pdata.tellg();

    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft CMoney"<<endl;
            break;
        }
        getline(pdata>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 8)=="<Amount>")
            amount = basetypeload::loaddouble(line, 9);
        
        if(line.substr(0, 10)=="<Currency>")
            currency = basetypeload::loadstr(line, 11);
    
    } while(line != endtag);
    
    pdata.seekg(ret);
    
    return CMoney(amount, currency);
}

 /*bool CMoney::operator==(const CMoney &m1, const CMoney &m2)
{
    return (m1.Amount == m2.Amount &&
            m2.Currency == m2.Currency);
}
 
 bool CMoney::operator!=(const CMoney &m1, const CMoney &m2)
{
    return !(m1 == m2);
}*/
