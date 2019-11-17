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

class CAccount;

class CCustomer{

private:
    long CusNr;
    string Name;
    CAddress Address;
    CDate DOB;          //Date ofBirth
    CAccount *Accounts[MAX_ACCOUNTS];
    int AccCount;

public:    
    CCustomer(long CusNr, string Name, CDate DOB, CAddress Address);
    
    void set(long CusNr, string Name, CDate DOB, CAddress Address);
    long getCusNr(){return CusNr;};
    void print();
    string getName(){return Name;};
    bool addAccount(CAccount *New);

};


#endif /* ccustomer_hpp */
