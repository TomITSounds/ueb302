

#ifndef ccurrentaccount_hpp
#define ccurrentaccount_hpp

#include <stdio.h>
#include "caccount.h"

class CCurrentAccount: public CAccount{
private:
    CMoney *dispo;
    
public:
    CCurrentAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance, CMoney *dispo);
    ~CCurrentAccount();
    
    void print();
};

#endif /* ccurrentaccount_hpp */
