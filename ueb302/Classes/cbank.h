

#ifndef cbank_hpp
#define cbank_hpp


#include <iostream>
#include <string>
#include <cstdio>
#include "caccount.h"
#include <vector>

using namespace std;

class CAccount;

class CBank{

private:
    string name;
    string bic;
    int count;
    vector <CAccount*> Accounts;
    
public:
    CBank(string, string);
    ~CBank();
    
    void set(string, string);
    void print();
    bool addAccount(CAccount *newacc);
    string getbic(){return bic;};
    
    static CBank load(ifstream&);
    
};

#endif /* cbank_hpp */
