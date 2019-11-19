#include "ccustomer.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
#include <iomanip>
#include <fstream>
#include <vector>
#include "basetypeload.hpp"

using namespace std;

//Muss ueber Liste initialisiert werden da Address kein Standardkonstruktur
CCustomer::CCustomer(long CusNr, string Name, CAddress Address, CDate DOB): CusNr(CusNr), Name(Name), DOB(DOB), Address(Address){}

//Copy Constructor
CCustomer::CCustomer(const CCustomer &Old): CusNr(Old.CusNr), Name(Old.Name), DOB(Old.DOB), Address(Old.Address){}

CCustomer::~CCustomer(){
        cout<< "Kunde " << Name << " wurde vernichtet!"<< endl;
    
}

void CCustomer::set(long CusNr, string Name, CAddress Address, CDate DOB){
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
    cout << "geboren am: ";
    DOB.print();
    cout << "Konten:";
    for(int i = 0; i<Accounts.size(); i++){
        cout << endl << "- Kontonr.: ";
        Accounts.at(i)->printIBAN();
    }
}

bool CCustomer::addAccount(CAccount *New){
    if(New){    //checks for Null
        Accounts.push_back(New);           //Hinzufuegen zu Zeigerarray
        return true;
    }
    return false;
}

CCustomer CCustomer::load(ifstream &data){
    string line;
    long *CusNr = NULL;
    string *Name = NULL;
    CDate *DOB = NULL;
    CAddress *add =NULL;
    
    do{
        if(data.eof()){
            cout << "Datei fehlerhaft Customer"<<endl;
            break;
        }
        getline(data>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 9)=="<Address>"){
            add = new CAddress(CAddress::load(data, "</Address>"));
        }
        if(line.substr(0, 6)=="<Name>"){
            Name = new string (basetypeload::load(line, "</Name>", Name));
        }
        if(line.substr(0, 10)=="<Birthday>"){
            DOB = new CDate (CDate::load(data, "</Birthday>"));
        }
        if(line.substr(0, 4)=="<ID>"){
            CusNr = new long (basetypeload::load(line, "</ID>", CusNr));
        }
        
    }while (line != "</Customer>");
    
    return CCustomer( *CusNr,  *Name,  *add,  *DOB);
}

