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
    }

CFixedDepositAccount::CFixedDepositAccount(CAccount base, double rate, CMoney* dispo)
:CAccount(base), CCurrentAccount(base, dispo), CSavingsAccount(base, rate){
}

CFixedDepositAccount::CFixedDepositAccount(vector <string>& loadvalues):
    CAccount(loadvalues),
    CSavingsAccount(loadvalues),
    CCurrentAccount(loadvalues){
} 

CFixedDepositAccount::~CFixedDepositAccount(){
    cout << "FixedDepositAccount:Konto (" << flush;
    printIBAN();
    cout << ") vernichtet!" << endl;
}


CFixedDepositAccount* CFixedDepositAccount::load(ifstream &pdata, vector <string> &loadvalues){
    CFixedDepositAccount::loadvalues(pdata, loadvalues);
    return new CFixedDepositAccount(loadvalues);
}

void CFixedDepositAccount::loadvalues(ifstream &pdata, vector<string> &loadvalues){
    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft FixDepo"<<endl;
            break;
        }
        
        getline(pdata>>ws, loadvalues.back());
        loadvalues.back().pop_back();
        
        CFixedDepositAccount::loadsinglevalue(pdata, loadvalues);
        
    }while (loadvalues.back() != "</FixedDepositAccount>");
}

void CFixedDepositAccount::loadsinglevalue(ifstream &pdata, vector <string> &loadvalues){
    if(loadvalues.back().substr(0, 7)=="<Dispo>"){
        CMoney::load(pdata, loadvalues, 6, "</Dispo>");
        return;
    }
    if(loadvalues.back().substr(0, 14)=="<InterestRate>"){
        basetypeload::loadstr(loadvalues.back(), 15);
        loadvalues.at(5) = loadvalues.back();
        return;
    }
    else
        CAccount::loadsinglevalue(pdata, loadvalues);
}

void CFixedDepositAccount::print(){
    CCurrentAccount::print();
    CSavingsAccount::printInterest();
}
