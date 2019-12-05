#ifndef cfixedeposit_h
#define cfixedeposit_h

#include <stdio.h>
#include "caccount.h"
#include "csavingsaccount.h"
#include "ccurrentaccount.h"
#include <fstream>

class CFixedDepositAccount:  virtual public CCurrentAccount, virtual public CSavingsAccount{
    
public:
    CFixedDepositAccount(CCurrentAccount, double);
    CFixedDepositAccount(CAccount, double, CMoney*);
    CFixedDepositAccount(vector <string>&);
    virtual ~CFixedDepositAccount() ;
    
    void print() ;
    static CFixedDepositAccount* load(ifstream&, vector <string>&);
    static void loadvalues(ifstream&, vector <string>&);
    static void loadsinglevalue(ifstream&, vector <string>&);
};

#endif /* cfixedeposit_hpp */
