#ifndef ccustomer_h
#define ccustomer_h

#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
#include "caccount.h"
using namespace std;


#define MAX_ACCOUNTS 10

class CCustomer{
private:
    long CusNr;
    string Name;
    CAddress Address;
    CDate DOB;
    CAccount *Accounts[MAX_ACCOUNTS];
    int AccCount;

public:
    CCustomer(long CusNr, string Name, CDate DOB, CAddress Address);
    ~CCustomer();
    void set(long CusNr, string Name, CDate DOB, CAddress Address);
    void get();
    void print();
    bool addAccount(CAccount *New);

};


#endif /* ccustomer_hpp */
