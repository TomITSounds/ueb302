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

    string line;
    
    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft FixDepo"<<endl;
            break;
        }
        
        getline(pdata>>ws, line);
        line.pop_back();
        
        CFixedDepositAccount::loadvalues(pdata, loadvalues, line);
        
    
    }while (line != "</FixedDepositAccount>");
    
    
    return new CFixedDepositAccount(loadvalues);
}

void CFixedDepositAccount::loadvalues(ifstream &pdata, vector<string> &loadvalues, string line){
    if(line.substr(0, 7)=="<Dispo>"){
        CMoney::load(pdata, loadvalues, 5, "</Dispo>");
        return;
    }
    if(line.substr(0, 14)=="<InterestRate>"){
         basetypeload::loadstr(line, 15);
         loadvalues.at(5) = line;
    }
    else
        CAccount::loadvalues(line, loadvalues, pdata);
}

void CFixedDepositAccount::print(){
    CCurrentAccount::print();
    cout << endl<< interest<< endl;
}
