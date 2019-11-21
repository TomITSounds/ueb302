#include "cbankmanager.h"
#include <stdio.h>
#include "cbank.h"
#include "ccustomer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "caccount.h"
#include "ccurrentaccount.h"
#include "csavingsaccount.h"
#include "cfixedepositaccount.h"
#include "cmoney.h"

using namespace std;

vector <CCustomer*> CBankManager::cuslist;
vector <CBank*> CBankManager::banklist;
vector <CMoney> CBankManager::dispolist;

CBankManager::CBankManager(string file){
    ifstream pdata("/Volumes/Data/Beuth/3. Semester/Info 3/Ueb/ueb302/ueb302/Classes/"+file);
    
    if(pdata.is_open())
        cout << "Datei geoeffnet" << endl;
    else{
        cout << "Datei nicht geoeffnet"<< endl;
        return;
    }
    /*ifstream* pdata = NULL;
    pdata = &data;*/
    //data.open(file, ios::in);
    string line;
    
    CCustomer *newcus = NULL;
    CBank *newbank = NULL;
    CAccount *newacc = NULL;
    CCurrentAccount *newcuracc = NULL;
    CSavingsAccount *newsavacc = NULL;
    CFixedDepositAccount *newfixacc = NULL; //Koeente man auch ein Void pointer fuer alle nehmen??
    
    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft BankManager" << endl;
            return;
        }
        
        getline(pdata >>ws, line);
        line.pop_back(); //Da testfile has \r\n
        
        if(line == "<Customer>"){
            
            newcus = new CCustomer(CCustomer::load(pdata));
            cuslist.push_back(newcus);
            newcus = NULL;
        }
        
        if(line == "<Bank>"){
            newbank = new CBank(CBank::load(pdata));
            banklist.push_back(newbank);
            newbank = NULL;
        }
        
        if(line == "<Account>"){
            newacc = new CAccount(CAccount::load(pdata, "</Account>"));
            //pushback
            
            newacc = NULL;
        }
        
        if(line == "<CurrentAccount>"){
            newcuracc = new CCurrentAccount(CCurrentAccount::load(pdata, "</CurrentAccount>"));
            newcuracc->getOwner()->replaceLastAccount(newcuracc);
            // Ersetz Adresse in Owner Account Liste da diese auf Stack zeigt (return by value)
            newcuracc->getbank()->replaceLastAccount(newcuracc); //Same in Bank
            newcuracc = NULL;
        }
        
        if(line == "<SavingsAccount>"){
            newsavacc = new CSavingsAccount(CSavingsAccount::load(pdata, "</SavingsAccount>"));
            newsavacc->getOwner()->replaceLastAccount(newsavacc);
            // Ersetz Adresse in Owner Account Liste da diese auf Stack zeigt (return by value)
            newsavacc->getbank()->replaceLastAccount(newsavacc); //Same in Bank
            newsavacc = NULL;
        }
        
        if(line == "<FixedDepositAccount>"){
            newfixacc = new CFixedDepositAccount(CFixedDepositAccount::load(pdata));
            newfixacc->getOwner()->replaceLastAccount(newfixacc);
            // Ersetz Adresse in Owner Account Liste da diese auf Stack zeigt (return by value)
            newfixacc->getbank()->replaceLastAccount(newfixacc); //Same in Bank
            newfixacc = NULL;
        }
        
    }while(line != "</Data>");

    cout<<"Datei wurde eingelesen!"<<endl;
    
}

CBankManager::~CBankManager(){
    for(int i=0 ; i<cuslist.size(); i++ ){
        delete cuslist.at(i);
    }
    cuslist.clear();
    for(int i=0 ; i<banklist.size(); i++){
        delete banklist.at(i);
    }
    banklist.clear();
}


CBank* CBankManager::getbankptr(string biccmp){
    
    for(int i=0; i<banklist.size(); i++){
        if(banklist.at(i)->getbic() == biccmp)
            return banklist.at(i);
    }
    
    return NULL;
}

CCustomer* CBankManager::getcusptr(long cusnrcmp){
 
    for(int i=0; i<cuslist.size(); i++){
     if(cuslist.at(i)->getCusNr() == cusnrcmp)
         return cuslist.at(i);
    }
 
 return NULL;
    return NULL;
}

void CBankManager::printCustomerList(){
    
    for(int i=0; i<cuslist.size(); i++){
        cuslist.at(i)->print();
        
        cout << endl<<endl;
    }
    cout<< endl;
}

void CBankManager::printBankList(){
    
    for(int i=0; i<banklist.size(); i++){
        banklist.at(i)->print();
        cout << endl;
    }
    cout<< endl;
}
