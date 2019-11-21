
#include "csavingsaccount.h"
#include <iostream>
#include <string>
#include "caccount.h" //noetig?
#include <iomanip>
#include <fstream>
#include "basetypeload.hpp"

using namespace std;

CSavingsAccount::CSavingsAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance, double interest)
: interest(interest), CAccount(bank, IBAN, Owner, Balance){};

CSavingsAccount::CSavingsAccount(CAccount topclass, double interest): CAccount(topclass), interest(interest){
    bank->replaceLastAccount(this);
    Owner->replaceLastAccount(this);
}

CSavingsAccount::CSavingsAccount(const CSavingsAccount& copy): CAccount(copy.bank, copy.IBAN, copy.Owner, copy.Balance), interest(copy.interest){}

CSavingsAccount::~CSavingsAccount(){
    cout << "SavingsAccount:     Konto (" << flush;
    printIBAN();
    cout << ") vernichtet!" << endl;
}

void CSavingsAccount::print(){
    CAccount::print();
    int oldflag, fixflag = ios::fixed;
    oldflag = cout.flags(fixflag);
    cout << endl << "Sparzinsen: " << interest << " %" << flush;
    
    cout.flags(oldflag);
}

CSavingsAccount CSavingsAccount::load(ifstream &pdata, string endtag){
    int ret = pdata.tellg();
    string line;
    double intrate;
        
        do{
            if(pdata.eof()){
                cout << "Datei fehlerhaft SAvings"<<endl;
                break;
            }
            
            getline(pdata>>ws, line);
            line.pop_back();
            
            if(line.substr(0, 14)=="<InterestRate>"){
                intrate = basetypeload::loaddouble(line, 15);
            }
            
        }while(line != endtag);
                                     
    pdata.seekg(ret);
                                     
        return CSavingsAccount(CAccount::load(pdata, "</SavingsAccount>"), intrate);
    }
