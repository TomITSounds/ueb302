#ifndef caccount_h
#define caccount_h

#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
#include "cmoney.h"
#include "ccustomer.h"

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
