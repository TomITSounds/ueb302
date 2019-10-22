#include "ccustomer.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
#include "caccount.h"
#include "cmoney.h"

using namespace std;

CAccount::CAccount(string IBAN, CCustomer *Owner, CMoney Balance){
    this->IBAN = IBAN;
    this->Owner = Owner;
    Owner->addAccount(this);        //Account im Ownerobjekt hinzufuegen
    this->Balance = Balance;
};

void CAccount::set(string IBAN, CCustomer *Owner, CMoney Balance){
    this->IBAN = IBAN;
    this->Owner = Owner;
    this->Balance = Balance;
};

void CAccount::printIBAN(){
    string dummy = IBAN;                //dummy da sons Original veraendert wird
    dummy.insert(20, " ");            //Leerstellen von hinten nach vorne
    dummy.insert(16, " ");
    dummy.insert(8, " ");
    dummy.insert(4, " ");
    printf("%s", dummy.c_str());
}
    
void CAccount::print(){
    printf("Kunde:       ");
    string dummy = Owner->getName();
    long dummy2 = Owner->getCusNr();
    printf("%s (Kd-Nr. %ld)\n", dummy.c_str(), dummy2);  //oder geht auch (Owner->getName()).c_str() ??
    printf("IBAN:        ");
    printIBAN();
    printf("\n");
    Balance.print();
}
