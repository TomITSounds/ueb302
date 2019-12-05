
#include "csavingsaccount.h"
#include <iostream>
#include <string>
#include "caccount.h" //noetig?
#include <iomanip>
#include <fstream>
#include "basetypeload.hpp"
#include <vector>

using namespace std;

CSavingsAccount::CSavingsAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance, double interest)
: interest(interest), CAccount(bank, IBAN, Owner, Balance){};

CSavingsAccount::CSavingsAccount(CAccount topclass, double interest): CAccount(topclass), interest(interest){
}

CSavingsAccount::CSavingsAccount(const CSavingsAccount& copy): CAccount(copy.bank, copy.IBAN, copy.Owner, copy.Balance), interest(copy.interest){}

CSavingsAccount::CSavingsAccount(vector <string>& loadvalues):
    interest(stod(loadvalues.at(5))),
    CAccount(loadvalues){
}

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

CSavingsAccount* CSavingsAccount::load(ifstream &pdata, vector <string>& loadvalues, string endtag){

    CSavingsAccount::loadvalues(pdata, loadvalues, endtag);

    return new CSavingsAccount(loadvalues);
}

void CSavingsAccount::loadvalues(ifstream &pdata, vector<string> &loadvalues, string endtag){
        do{
            if(pdata.eof()){
                cout << "Datei fehlerhaft CSavingsaccount"<<endl;
                break;
            }
            getline(pdata>>ws, loadvalues.back());
            loadvalues.back().pop_back();
            
        CSavingsAccount::loadsinglevalue(pdata, loadvalues);
                
        }while(loadvalues.back() != endtag);
}

void CSavingsAccount::loadsinglevalue(ifstream &pdata, vector<string> &loadvalues){
    if(loadvalues.back().substr(0, 14)=="<InterestRate>"){
         basetypeload::loadstr(loadvalues.back(), 15);
         loadvalues.at(5) = loadvalues.back();
    }
    else
        CAccount::loadsinglevalue(pdata, loadvalues);
}
