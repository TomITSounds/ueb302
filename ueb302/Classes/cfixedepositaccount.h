//
//  cfixedeposit.hpp
//  ueb302
//
//  Created by Tom Mertens on 17.11.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef cfixedeposit_h
#define cfixedeposit_h

#include <stdio.h>
#include "caccount.h"
#include "csavingsaccount.h"
#include "ccurrentaccount.h"
#include <fstream>

class CSavingsAccount;
class CCurrentAccount;


class CFixedDepositAccount:  public CCurrentAccount, public CSavingsAccount{
    
public:
    CFixedDepositAccount(CCurrentAccount, double);
    CFixedDepositAccount(CAccount, double, CMoney*);
    virtual ~CFixedDepositAccount() ;
    
    void print() ;
    void printIBAN(){};
    static CFixedDepositAccount load(ifstream&, CMoney*, int);
};

#endif /* cfixedeposit_hpp */
