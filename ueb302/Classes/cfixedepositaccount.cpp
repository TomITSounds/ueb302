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
    CSavingsAccount(base.bank, base.IBAN, base.Owner, base.Balance, rate){}

CFixedDepositAccount::CFixedDepositAccount(CAccount base, double rate, CMoney* dispo)
:CAccount(base), CCurrentAccount(base, dispo), CSavingsAccount(base, rate){}

CFixedDepositAccount::~CFixedDepositAccount(){
    cout << "FixedDepositAccount:     Konto (" << flush;
    printIBAN();
    cout << ") vernichtet!" << endl;
}


CFixedDepositAccount CFixedDepositAccount::load(ifstream& data, CMoney* dispolist, int listsize){
    string line;
    long long pos = data.tellg();
    double* interest = NULL;
    
    CCurrentAccount* dummy = NULL;
    CAccount *dummy2 = NULL;
    
    dummy = new CCurrentAccount(CCurrentAccount::load(data, "</FixedDepositAccount>", dispolist, listsize));
    
    data.seekg(pos);
    
    do{
        if(data.eof()){
            cout << "Datei fehlerhaft FixDepo"<<endl;
            break;
        }
        
        getline(data>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 14) == "<InterestRate>")
            interest = new double(basetypeload::load(line, "</InterestRate>", interest));
    
    }while (line != "</FixedDepositAccount>");
    
    dummy2 = dummy;

    CFixedDepositAccount ret(*dummy2, *interest, dummy->dispo);
    return ret;
}

void CFixedDepositAccount::print(){
    CCurrentAccount::print();
    cout << endl<< interest<< endl;
}
