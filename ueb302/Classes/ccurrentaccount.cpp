
#include "ccurrentaccount.h"
#include <iostream>
#include <string>
#include "caccount.h" //noetig?
#include <iomanip>

using namespace std;

CCurrentAccount::CCurrentAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance, CMoney *dispo)
: dispo(dispo), CAccount(bank, IBAN, Owner, Balance){};

CCurrentAccount::~CCurrentAccount(){
    cout << "CurrentAccount:     Konto (" << flush;
    printIBAN();
    cout << ") vernichtet!" << endl;
}

void CCurrentAccount::print(){
    int oldflag, fixflag = ios::fixed;
    oldflag = cout.flags(fixflag);
    
    CAccount::print();
    cout << endl << "Dispo     : " ;
    dispo->lprint();
    
    cout.flags(oldflag);
}
