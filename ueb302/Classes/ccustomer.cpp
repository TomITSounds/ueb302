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

CCustomer::CCustomer(vector<string>& loadvalues):
    CusNr(stol(loadvalues.at(0))),
    Name(loadvalues.at(1)),
    DOB(CDate(loadvalues, 5)),
    Address(CAddress(loadvalues, 2)){
}
    

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
    if(New){
        if(Accounts.size()){
            if(New->getIBAN() != Accounts.back()->getIBAN()){    //checks for Null
                Accounts.push_back(New);           //Hinzufuegen zu Zeigerarray
                return true;
            }
        }
        else{
            Accounts.push_back(New);           //Hinzufuegen zu Zeigerarray
            return true;
        }
    }
    return false;
}

void CCustomer::replaceLastAccount(CAccount *newacc){
    Accounts.back() = newacc;
}

CCustomer CCustomer::load(ifstream &pdata, vector <string>&loadvalues){
    
    CCustomer::loadvalues(pdata, loadvalues);
    
    return CCustomer(loadvalues);
}

void CCustomer::loadvalues(ifstream &pdata, vector<string> &loadvalues){
    string line;
    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft Customer"<<endl;
            break;
        }
        getline(pdata>>ws, line);
        line.pop_back();
        
            
        if(line.substr(0, 6)=="<Name>"){
            basetypeload::loadstr(line, 7);
            loadvalues.at(1) = line;
        }
        if(line.substr(0, 4)=="<ID>"){
           basetypeload::loadstr(line, 5);
            loadvalues.at(0) = line;
        }
        if(line.substr(0, 10)=="<Birthday>"){
            CDate::loadvalues(pdata, loadvalues, 5);
        }
        if(line.substr(0, 9)=="<Address>"){
            CAddress::loadvalues(pdata, loadvalues, 2);
        }
        
    }while (line != "</Customer>");
}
