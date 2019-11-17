#include "ccustomer.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
#include "caccount.h"
#include "cmoney.h"

using namespace std;

CAccount::CAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance){
    this->IBAN = IBAN;
    this->Owner = Owner;
    Owner->addAccount(this);        //Account im Ownerobjekt hinzufuegen
    this->Balance = Balance;
    bank->addAccount(this);
    this->bank = bank;
};

CAccount::~CAccount(){
        cout << "CAccount:           Konto (" << flush;
        printIBAN();
        cout << ") vernichtet!" << endl;
    }


void CAccount::set(string IBAN, CCustomer *Owner, CMoney Balance){
    this->IBAN = IBAN;
    this->Owner = Owner;
    this->Balance = Balance;
};

void CAccount::printIBAN(){
    string dummy = IBAN;                //dummy da sons Original veraendert wird
    dummy.insert(20, " ");            //Leerstellen von hinten nach vorne
    dummy.insert(16, " ");
    dummy.insert(12, " ");
    dummy.insert(8, " ");
    dummy.insert(4, " ");
    cout << dummy << flush;
}
    
void CAccount::print(){
    int oldflag, fixflag = ios::fixed;
    oldflag = cout.flags(fixflag);
    cout
    << "Kunde     : "<< Owner->getName()
    << " (Kd-Nr. " << Owner->getCusNr()
    << ")" << endl
    << "IBAN / BIC: " << flush;
    printIBAN();
    cout << " / " << bank->getbic() << endl;
    Balance.print();
    
    cout.flags(oldflag);
}

