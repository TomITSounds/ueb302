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

CAccount::CAccount(const CAccount &copy): IBAN(copy.IBAN), Owner(copy.Owner), Balance(copy.Balance), bank(copy.bank){};

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

CAccount CAccount::load(ifstream& data, string endtag){
    string line;
    string *iban = NULL;
    CCustomer *owner = NULL;
    CBank *bank = NULL;
    CMoney *amount = NULL;
    string bankcmp;
    long idcmp;
    
    do{
        if(data.eof()){
            cout << "Datei fehlerhaft Account"<<endl;
            break;
        }
        
        getline(data>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 6) == "<IBAN>")
            iban = new string(basetypeload::load(line, "</IBAN>", iban));
        
        if(line.substr(0, 9) == "<Balance>")
            amount = new CMoney(CMoney::load(data, "</Balance>"));
        
        if(line.substr(0, 6) == "<Bank>"){
            basetypeload::load(line, "</Bank>", &bankcmp);
            bank = CBankManager::getbankptr(bankcmp);
        }
        if(line.substr(0, 10) == "<Customer>"){
                   basetypeload::load(line, "</Customer>", &idcmp);
                   owner = CBankManager::getcusptr(idcmp);
               }
        
    }while(line != endtag);
    
    CAccount ret(bank, *iban, owner, *amount);
    return ret;
}
