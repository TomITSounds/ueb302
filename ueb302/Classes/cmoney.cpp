#include "cmoney.h"
#include <iostream>
#include <string>
#include <iomanip>

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
