#ifndef caccount_h
#define caccount_h

#include "ccustomer.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
#include "cmoney.h"
#include "cbank.h"

using namespace std;

class CCustomer;
class CBank;

class CAccount{
private:
    string IBAN;
    CCustomer *Owner;
    CMoney Balance;
    CBank *bank;
    
public:
    CAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance);
    ~CAccount();
    
    void set(string IBAN, CCustomer *Owner, CMoney Balance);
    void print();
    void printIBAN();
     
};
#endif /* caccount_hpp */
