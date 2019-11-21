//
//  cfixedeposit.cpp
//  ueb302
//
//  Created by Tom Mertens on 17.11.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include "cfixedepositaccount.h"
#include "caccount.h"
#include "csavingsaccount.h"
#include "ccurrentaccount.h"
#include <fstream>
#include "basetypeload.hpp"
#include <iostream>

using namespace std;

CFixedDepositAccount::CFixedDepositAccount(CCurrentAccount base, double rate)
:   CAccount(base.bank, base.IBAN, base.Owner, base.Balance),
    CCurrentAccount(base),
    CSavingsAccount(base.bank, base.IBAN, base.Owner, base.Balance, rate){
        bank->replaceLastAccount(this);
        Owner->replaceLastAccount(this);
    }

CFixedDepositAccount::CFixedDepositAccount(CAccount base, double rate, CMoney* dispo)
:CAccount(base), CCurrentAccount(base, dispo), CSavingsAccount(base, rate){
}

CFixedDepositAccount::~CFixedDepositAccount(){
    cout << "FixedDepositAccount:Konto (" << flush;
    printIBAN();
    cout << ") vernichtet!" << endl;
}


CFixedDepositAccount CFixedDepositAccount::load(ifstream &pdata){
    
    int ret = pdata.tellg();
    string line;
    double interest;
    
    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft FixDepo"<<endl;
            break;
        }
        
        getline(pdata>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 14) == "<InterestRate>")
            interest = basetypeload::loaddouble(line, 15);
        
    
    }while (line != "</FixedDepositAccount>");
    
    pdata.seekg(ret);
    
    return CFixedDepositAccount(CCurrentAccount::load(pdata, "</FixedDepositAccount>"), interest);
}

void CFixedDepositAccount::print(){
    CCurrentAccount::print();
    cout << endl<< interest<< endl;
}
