//
//  caccount.hpp
//  ueb302
//
//  Created by Tom Mertens on 21.10.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef caccount_h
#define caccount_h

#include "ccustomer.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
#include "cmoney.h"

using namespace std;

class CAccount{
private:
    string IBAN;
    CCustomer *Owner;
    CMoney Balance;
    
public:
    CAccount(string IBAN, CCustomer *Owner, CMoney Balance);
    void set(string IBAN, CCustomer *Owner, CMoney Balance);
    void print();
    void printIBAN();
     
    
    
};
#endif /* caccount_hpp */
