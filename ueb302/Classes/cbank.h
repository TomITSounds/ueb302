

#ifndef cbank_hpp
#define cbank_hpp


#include <iostream>
#include <string>
#include <cstdio>
#include "caccount.h"

using namespace std;

class CAccount;

#define MAX_ACCOUNTS 100

class CBank{

private:
    string name;
    string bic;
    int count;
    CAccount *Accounts[MAX_ACCOUNTS];
    
public:
    CBank(string, string);
    
    void set(string, string);
    void print();
    bool addAccount(CAccount *newacc);
    string getbic(){return bic;};
    
};

#endif /* cbank_hpp */
