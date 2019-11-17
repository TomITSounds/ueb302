

#ifndef csavingsaccount_hpp
#define csavingsaccount_hpp

#include <stdio.h>
#include "caccount.h" 

class CSavingsAccount: public CAccount{
private:
    double interest;
    
public:
    CSavingsAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance, double);
    ~CSavingsAccount();
    
    void print();
};

#endif /* csavingsaccount_hpp */
