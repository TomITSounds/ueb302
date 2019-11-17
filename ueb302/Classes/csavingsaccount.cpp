
#include "csavingsaccount.h"
#include <iostream>
#include <string>
#include "caccount.h" //noetig?
#include <iomanip>

using namespace std;

CSavingsAccount::CSavingsAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance, double interest)
: interest(interest), CAccount(bank, IBAN, Owner, Balance){};

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
