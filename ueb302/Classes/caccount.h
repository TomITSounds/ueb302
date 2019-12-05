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
#include <fstream>

using namespace std;

class CCustomer;
class CBank;

class CAccount{
protected:
    string IBAN;
    CCustomer *Owner;
    CMoney Balance;
    CBank *bank;
    
public:
    CAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance);
    CAccount(const CAccount&);
    CAccount(vector<string>&);
    virtual ~CAccount();
    
    CCustomer *getOwner(){return Owner;};
    void set(string IBAN, CCustomer *Owner, CMoney Balance);
    virtual void print();
    void printIBAN();
    string getIBAN(){return IBAN;}
    CMoney getBalance(){return Balance;}
    CBank* getbank(){return bank;}
    
    static CAccount* load(ifstream&, vector <string>&, string="</Account>");
    static void loadvalues( ifstream&, vector <string>&, string="</Account>");
    static void loadsinglevalue(ifstream&, vector <string>&);
     
    /*friend class CCurrentAccount;
    friend class CSavingsAccount;
    friend class CFixedDepositAccount;*/
};
#endif /* caccount_hpp */
