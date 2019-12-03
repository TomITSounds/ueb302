#ifndef ccustomer_h
#define ccustomer_h

#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
#include "caccount.h"
#include <fstream>
#include <vector>

using namespace std;

class CAccount;

class CCustomer{

private:
    long CusNr;
    string Name;
    CAddress Address;
    CDate DOB;          //Date ofBirth
    vector <CAccount*> Accounts;

public:    
    CCustomer(long CusNr, string Name, CAddress Address, CDate DOB);
    CCustomer(const CCustomer&);
    CCustomer(vector<string>&);
    ~CCustomer();
    
    void set(long CusNr, string Name, CAddress Address, CDate DOB);
    long getCusNr(){return CusNr;};
    void print();
    string getName(){return Name;};
    bool addAccount(CAccount *New);
    void replaceLastAccount(CAccount*);
    
    static CCustomer* load(ifstream&, vector <string>&);
    static void loadvalues(ifstream&, vector <string>&);
};


#endif /* ccustomer_hpp */
