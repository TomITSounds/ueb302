
#include "ccurrentaccount.h"
#include <iostream>
#include <string>
#include "caccount.h" //noetig?
#include <iomanip>
#include <fstream>
#include "cmoney.h"
#include "cbankmanager.h"
#include "basetypeload.hpp"

using namespace std;

CCurrentAccount::CCurrentAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance, CMoney *dispo)
: dispo(dispo), CAccount(bank, IBAN, Owner, Balance){}

CCurrentAccount::CCurrentAccount(CAccount topclass, CMoney *dispo): CAccount(topclass),
dispo(dispo){
    bank->replaceLastAccount(this);
    Owner->replaceLastAccount(this);
}

CCurrentAccount::CCurrentAccount(const CCurrentAccount& copy): CAccount(copy.bank, copy.IBAN, copy.Owner, copy.Balance), dispo(copy.dispo){}

CCurrentAccount::CCurrentAccount(vector <string>& loadvalues):
    dispo(checkdispoptr(loadvalues, 5)),
    CAccount(loadvalues){
}
    

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

CCurrentAccount* CCurrentAccount::load(ifstream &pdata, vector <string>& loadvalues, string endtag){
    string line;
    
    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft Currentaccount"<<endl;
            break;
        }
        
        getline(pdata>>ws, line);
        line.pop_back();
        
        CCurrentAccount::loadvalues(pdata, loadvalues, line);
        
    }while(line != endtag);

    return new CCurrentAccount(loadvalues);
}

void CCurrentAccount::loadvalues(ifstream &pdata, vector<string> &loadvalues, string line){
    
        if(line.substr(0, 7)=="<Dispo>")
            CMoney::load(pdata, loadvalues, 5, "</Dispo>");
        else
            CAccount::loadvalues(line, loadvalues, pdata);
}

CMoney* CCurrentAccount::checkdispoptr(vector <string>& loadvalues, int i){
    CMoney *dispo = new CMoney(loadvalues, i);
    if(!CBankManager::dispolistsize()){
        CBankManager::dispolist.push_back(dispo);
        return dispo;
    }
    else{
        for(i=0; i<CBankManager::dispolistsize(); i++){  //repurpose i
            if(*dispo == *(CBankManager::dispolist.at(i))){
                    delete dispo;
                    return CBankManager::dispolist.at(i); //falls Dispo betrag schon vorhanden, i=pos im Vektor
                }
            }
            CBankManager::dispolist.push_back(dispo);
            return dispo;
            }
        }
