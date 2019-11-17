#include "ccustomer.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
#include <iomanip>

using namespace std;

//Muss ueber Liste initialisiert werden da Address kein Standardkonstruktur
CCustomer::CCustomer(long CusNr, string Name, CDate DOB, CAddress Address): CusNr(CusNr), Name(Name), DOB(DOB), Address(Address), AccCount(0){}

void CCustomer::set(long CusNr, string Name, CDate DOB, CAddress Address){
    this->CusNr = CusNr;
    this->Name = Name;
    this->DOB = DOB;
    this->Address = Address;
}

void CCustomer::print(){
    cout << Name << " (Kd-Nr. " << CusNr << ")" << endl;
    Address.printStreet();
    cout << endl;
    Address.printZipCity();
    cout << endl;
    cout << "geboren am: " << endl;
    DOB.print();
    cout << endl << "Konten:";
    for(int i = 0; i<AccCount; i++){
        cout << endl << "- Kontonr.: ";
        Accounts[i]->printIBAN();
    }
}

bool CCustomer::addAccount(CAccount *New){
    if(New){    //checks for Null
        Accounts[AccCount] = New;           //Hinzufuegen zu Zeigerarray
        AccCount++;
        return true;
    }
    return false;
}


