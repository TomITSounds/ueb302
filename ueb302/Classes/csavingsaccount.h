

#ifndef csavingsaccount_hpp
#define csavingsaccount_hpp

#include <stdio.h>
#include "caccount.h"
#include <fstream>


class CSavingsAccount:   virtual public CAccount{
protected:
    double interest;
    
public:
    CSavingsAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance, double);
    CSavingsAccount(CAccount, double);
    CSavingsAccount(const CSavingsAccount&);
    ~CSavingsAccount();
    
    void print();
    
    static CSavingsAccount load(ifstream&, string);
    
};

#endif /* csavingsaccount_hpp */
