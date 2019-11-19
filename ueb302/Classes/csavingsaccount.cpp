
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

CSavingsAccount::CSavingsAccount(CAccount topclass, double interest): CAccount(topclass), interest(interest){}

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

CSavingsAccount CSavingsAccount::load(ifstream& data, string endtag){

        string line;
        long long pos = data.tellg();
        
        CAccount *dummy = NULL;
        double *intrate = NULL;
        
        dummy = new CAccount(CAccount::load(data, "</SavingsAccount>"));
        
        
    data.seekg(pos);
        
        do{
            if(data.eof()){
                cout << "Datei fehlerhaft SAvings"<<endl;
                break;
            }
            
            getline(data>>ws, line);
            line.pop_back();
            
            if(line.substr(0, 14)=="<InterestRate>"){
                intrate = new double(basetypeload::load(line, "</InterestRate>", intrate));
            }
            
        }while(line != endtag);
        
        CSavingsAccount ret(*dummy, *intrate);
        
        return ret;
    }
