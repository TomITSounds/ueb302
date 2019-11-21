#include "ccustomer.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caddress.h"
#include "cdate.h"
#include "caccount.h"
#include "cmoney.h"
#include <fstream>
#include "cbankmanager.h"
#include "basetypeload.hpp"


using namespace std;

CAccount::CAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance): bank(bank), IBAN(IBAN), Owner(Owner), Balance(Balance){
    Owner->addAccount(this);        //Account im Ownerobjekt hinzufuegen
    bank->addAccount(this);
};

CAccount::CAccount(const CAccount &copy): IBAN(copy.IBAN), Owner(copy.Owner), Balance(copy.Balance), bank(copy.bank){
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

CAccount CAccount::load(ifstream &pdata, string endtag){
    string line;
    string iban;
    CCustomer *owner = NULL;
    CBank *bank =NULL;
    int ret = pdata.tellg();
    
    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft Account"<<endl;
            break;
        }
        
        getline(pdata>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 6) == "<IBAN>")
            iban = basetypeload::loadstr(line, 7);
        
        /*if(line.substr(0, 9) == "<Balance>")
            posmoney = pdata.tellg();*/
        
        if(line.substr(0, 6) == "<Bank>"){
            basetypeload::loadstr(line, 7);
            bank = CBankManager::getbankptr(line);
        }
        if(line.substr(0, 10) == "<Customer>"){
            basetypeload::loadstr(line, 11);
            owner = CBankManager::getcusptr(stol(line));
               }
        
    }while(line != endtag);
    
    pdata.seekg(ret);
    
    return CAccount(bank,iban, owner,
                    CMoney::load(pdata, "</Balance>"));
}
