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


class CFixedDepositAccount:  virtual public CCurrentAccount, virtual public CSavingsAccount{
    
public:
    CFixedDepositAccount(CCurrentAccount, double);
    CFixedDepositAccount(CAccount, double, CMoney*);
    CFixedDepositAccount(vector <string>&);
    virtual ~CFixedDepositAccount() ;
    
    void print() ;
    static CFixedDepositAccount load(ifstream&, vector <string>&);
    static void loadvalues(ifstream&, vector <string>&, string);
};

#endif /* cfixedeposit_hpp */
