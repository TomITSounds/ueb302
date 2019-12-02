

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
    CBank(vector<string>& loadvalues);
    ~CBank();
    
    void set(string, string);
    void print();
    bool addAccount(CAccount *);
    void replaceLastAccount(CAccount*);
    string getbic(){return bic;};
    
    static CBank load(ifstream&, vector <string>&);
    static void loadvalues(ifstream&, vector <string>&);
    
};

#endif /* cbank_hpp */
