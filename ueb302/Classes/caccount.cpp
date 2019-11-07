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
};

CAccount::~CAccount(){
    printf("Dekonstruktor CAccount");
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
    printf("%s", dummy.c_str());
}
    
void CAccount::print(){
    printf("Kunde:       ");
    printf("%s (Kd-Nr. %ld)\n", (Owner->getName()).c_str(), Owner->getCusNr());  //oder geht auch (Owner->getName()).c_str() ??
    printf("IBAN:        ");
    printIBAN();
    printf("\n");
    Balance.print();
}
