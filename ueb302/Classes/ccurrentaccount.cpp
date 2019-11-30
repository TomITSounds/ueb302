
#include "ccurrentaccount.h"
#include <iostream>
#include <string>
#include "caccount.h" //noetig?
#include <iomanip>
#include <fstream>
#include "cmoney.h"
#include "cbankmanager.h"

using namespace std;

CCurrentAccount::CCurrentAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance, CMoney *dispo)
: dispo(dispo), CAccount(bank, IBAN, Owner, Balance){}

CCurrentAccount::CCurrentAccount(CAccount topclass, CMoney *dispo): CAccount(topclass),
dispo(dispo){
    bank->replaceLastAccount(this);
    Owner->replaceLastAccount(this);
}

CCurrentAccount::CCurrentAccount(const CCurrentAccount& copy): CAccount(copy.bank, copy.IBAN, copy.Owner, copy.Balance), dispo(copy.dispo){}

CCurrentAccount::~CCurrentAccount(){
    cout << "CurrentAccount:     Konto (" << flush;
    printIBAN();
    cout << ") vernichtet!" << endl;
}

void CCurrentAccount::print(){
    int oldflag, fixflag = ios::fixed;
    oldflag = cout.flags(fixflag);
    
    CAccount::print();
    cout << endl << "Dispo     : " ;
    dispo->lprint();
    
    cout.flags(oldflag);
}

CCurrentAccount CCurrentAccount::load(ifstream &pdata, string endtag){
    string line;
    int ret = pdata.tellg();
    int i=0;
    CMoney* dispo= NULL;
    
    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft Currentaccount"<<endl;
            break;
        }
        
        getline(pdata>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 7)=="<Dispo>"){
            dispo = new CMoney(CMoney::load(pdata,"</Dispo>"));
                if(!CBankManager::dispolistsize())
                    CBankManager::dispolist.push_back(*dispo);
                else{
                    for(i=0; i<CBankManager::dispolistsize(); i++){
                        if(CBankManager::dispolist.at(i).getAmount()==dispo->getAmount()){
                            if(CBankManager::dispolist.at(i).getCurrency()==dispo->getCurrency()){
                                delete dispo;
                                break; //falls Dispo betrag schon vorhanden, i=pos im Vektor
                            }
                        }
                        else{
                            CBankManager::dispolist.push_back(*dispo);
                            break; //i++; //falls nicht vorhanden, i = letzte pos neue groesse
                        }
                    }
                }
        }
    }while(line != endtag);
    
    
    pdata.seekg(ret);
    
    return CCurrentAccount(CAccount::load(pdata, endtag), &CBankManager::dispolist.at(i));
}
