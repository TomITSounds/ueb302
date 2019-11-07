#include "ccustomer.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
using namespace std;


//Muss ueber Liste initialisiert werden da Address kein Standardkonstruktur
CCustomer::CCustomer(long CusNr, string Name, CDate DOB, CAddress Address): CusNr(CusNr), Name(Name), DOB(DOB), Address(Address), AccCount(0){}

CCustomer::~CCustomer(){
    printf("Dekonstruktor CCustomer");
}


void CCustomer::set(long CusNr, string Name, CDate DOB, CAddress Address){
    this->CusNr = CusNr;
    this->Name = Name;
    this->DOB = DOB;
    this->Address = Address;
}


void CCustomer::print(){
    printf("%s (Kd-Nr. %ld)\n", Name.c_str(), CusNr);
    Address.printStreet();
    printf("\n");
    Address.printZipCity();
    printf("\n");
    printf("geboren am: ");
    DOB.print();
    printf("\nKonten:");
    for(int i = 0; i<AccCount; i++){
        printf("\n- Kontonr.: ");
        Accounts[i]->printIBAN();
    }
}

bool CCustomer::addAccount(CAccount *New){
    /*if (AccCount > MAX_ACCOUNTS){             //Sicherheitsabfrage fuer MaxAccount, noch nicht noetig...
        printf("MaxAccounts ueberschritten!");
        return false;
    }*/
    Accounts[AccCount] = New;           //Hinzufuegen zu Zeigerarray
    AccCount++;
    return true;
}


