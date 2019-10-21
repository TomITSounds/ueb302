//
//  caccount.cpp
//  ueb302
//
//  Created by Tom Mertens on 21.10.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include "ccustomer.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
#include "caccount.h"
#include "cmoney.h"

using namespace std;

CAccount::CAccount(string IBAN, CCustomer *Owner, CMoney Balance){
    this->IBAN = IBAN;
    this->Owner = Owner;
    this->Balance = Balance;
};

CAccount::set(string IBAN, CCustomer *Owner, CMoney Balance){
    this->IBAN = IBAN;
    this->Owner = Owner;
    this->Balance = Balance;
};

void CAccount::print(){
    printf("Kunde:       ");
    printf("%s (Kd-Nr. %ld\n", Owner->Name.c_str(), Owner->CusNr);
    printf("IBAN:        ");
    printIBAN();
};
