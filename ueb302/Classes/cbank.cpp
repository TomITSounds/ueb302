

#include "cbank.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caccount.h"
#include <iomanip>

using namespace std;

CBank::CBank(string name, string bic){
    this->name = name;
    this->bic = bic;
    count = 0;
}
CBank::~CBank(){
    cout << "Dekonstruktor CBank" << endl;
}

void CBank::set(string name, string bic){
    this->name = name;
    this->bic = bic;}

void CBank::print(){
    //print Name, Bic, Anzahl
    cout    << name << endl
            << "BIC " << bic << endl
            << "Anzahl Konten: " << count << endl;
    //Liste falls Konten vorhanden
    if (count){
        // flag linksbuendig
        int oldflag;
        int lflag = ios::left;
        int rflag = ios::right;
        oldflag = cout.flags(lflag);
        cout
        << "Kontenliste:" << endl
        << setw(28) << "IBAN"
        << setw(23) << "| Kundenname"
        << setw(16) << "| Anz. Buchungen"
        << setw(16) << "| Kontostand" << endl;
        
        //Line
        for(int i=0; i< (28+23+16+16); i++)
            cout << "-";
        cout << endl;
    
        
        for(int i=0; i<count; i++){
            cout.flags(lflag); //flag linksbuendig
            Accounts[i]->printIBAN();
            cout
            << " | "
            << setw(21) << Accounts[i]->getOwner()->getName()
            << "|";
            cout.flags(rflag); //flag rechtsbuendig
            cout
            << setw(15) << "0"
            << "|"
            << setw(11) << Accounts[i]->getBalance().getAmount()
            << setw(3) << Accounts[i]->getBalance().getCurrency()
            << endl;
            
        }
        
        cout.flags(oldflag);
    
    }
}

bool CBank::addAccount(CAccount *newacc){
    if(newacc){
        Accounts[count] = newacc;
        count++;
        return true;
    }
    return false;
}
