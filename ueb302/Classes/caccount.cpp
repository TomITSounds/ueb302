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
}

CAccount::CAccount(vector<string>& loadvalues):
    IBAN(loadvalues.at(0)),
    Owner(CBankManager::getcusptr(stol(loadvalues.at(1)))),
    Balance(CMoney(loadvalues, 2)),
    bank(CBankManager::getbankptr(loadvalues.at(4))){
        Owner->addAccount(this);        //Account im Ownerobjekt hinzufuegen
        bank->addAccount(this);
}
    

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

CAccount* CAccount::load(ifstream &pdata, vector <string>& loadvalues, string endtag){
    CAccount::loadvalues(pdata, loadvalues, endtag);
    return new CAccount(loadvalues);
}

void CAccount::loadvalues(ifstream &pdata, vector <string>& loadvalues, string endtag){
    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft Account"<<endl;
            break;
        }
        getline(pdata>>ws, loadvalues.back());
        loadvalues.back().pop_back();
        CAccount::loadsinglevalue(pdata, loadvalues);
    }while(loadvalues.back() != endtag);
    
}

void CAccount::loadsinglevalue(ifstream& pdata, vector<string> &loadvalues){
    if(loadvalues.back().substr(0, 6) == "<IBAN>"){
        basetypeload::loadstr(loadvalues.back(), 7);
        loadvalues.at(0) = loadvalues.back();
    }
    if(loadvalues.back().substr(0, 10) == "<Customer>"){
        basetypeload::loadstr(loadvalues.back(), 11);
        loadvalues.at(1) = loadvalues.back();
    }
    if(loadvalues.back().substr(0, 9) == "<Balance>")
        CMoney::load(pdata, loadvalues, 2);
    
    if(loadvalues.back().substr(0, 6) == "<Bank>"){
        basetypeload::loadstr(loadvalues.back(), 7);
        loadvalues.at(4) = loadvalues.back();
    }
}
