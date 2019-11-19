
#include "ccurrentaccount.h"
#include <iostream>
#include <string>
#include "caccount.h" //noetig?
#include <iomanip>
#include <fstream>
#include "cmoney.h"

using namespace std;

CCurrentAccount::CCurrentAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance, CMoney *dispo)
: dispo(dispo), CAccount(bank, IBAN, Owner, Balance){}

CCurrentAccount::CCurrentAccount(CAccount topclass, CMoney *dispo): CAccount(topclass),
dispo(dispo){}

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

CCurrentAccount CCurrentAccount::load(ifstream& data, string endtag, CMoney *dispolist, int listsize){
    string line;
    long long pos = data.tellg();
    int i;
    
    CAccount *dummy = NULL;
    CMoney *dispo =NULL;
    
    dummy = new CAccount(CAccount::load(data, endtag));
    
    data.seekg(pos);
    
    do{
        if(data.eof()){
            cout << "Datei fehlerhaft Currentaccount"<<endl;
            break;
        }
        
        getline(data>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 7)=="<Dispo>"){
            dispo = new CMoney(CMoney::load(data,"</Dispo>"));
        }
        
    }while(line != endtag);
    
    for(i=0; i<listsize; i++){
        if((dispolist+i)->getAmount()==dispo->getAmount())
            if((dispolist+i)->getCurrency()==dispo->getCurrency()){
                dispo = (dispolist+1);
                break;
            }
        else
            if(i==4)
                (dispolist+4)->set(*dispo);
                
    }
    delete dispo; //Speicherwiederfreigeben da Dispobetrag schon existiert
    
    CCurrentAccount ret(*dummy, (dispolist+i));
    
    return ret;
}
