//
//  cmoney.cpp
//  ueb302
//
//  Created by Tom Mertens on 21.10.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include "cmoney.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

CMoney::CMoney(): Amount(0.0), Currency("EUR"){};

CMoney::CMoney(double Amount, string Currency){
    this->Amount = Amount;
    this->Currency = Currency;
}

CMoney::CMoney(double Amount){
    this->Amount = Amount;
    Currency = "EUR";
}

CMoney::~CMoney(){};

void CMoney::set(double Amount){
    this->Amount = Amount;
    Currency = "EUR";
}

void CMoney::set(double Amount, string Currency){
    this->Amount = Amount;
    this->Currency = Currency;
}


void CMoney::print(){
    printf("%02.2f %s", Amount, Currency.c_str());
}
