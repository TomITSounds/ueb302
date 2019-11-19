

#include "cbank.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caccount.h"
#include <iomanip>
#include <fstream>
#include "basetypeload.hpp"
#include <vector>

using namespace std;

CBank::CBank(string name, string bic){
    this->name = name;
    this->bic = bic;
}

CBank::~CBank(){
    for( int i=0; i<Accounts.size(); i++){
        delete Accounts.at(i);
    }
    Accounts.clear();
    cout<< "Bank " << name << " wurde vernichtet!"<< endl;
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
    if (Accounts.size()){
        // flag linksbuendig
        int oldflag;
        int lflag = ios::left | ios::fixed;
        int rflag = ios::right | ios::fixed;
        oldflag = cout.flags(lflag);
        cout
        << "Kontenliste:" << endl << setfill(' ') 
        << setw(28) << "IBAN"
        << setw(23) << "| Kundenname"
        << setw(16) << "| Anz. Buchungen"
        << setw(16) << "| Kontostand" << endl;
        
        //Line
        for(int i=0; i< (28+23+16+16); i++)
            cout << "-";
        cout << endl;
    
        
        for(int i=0; i<Accounts.size(); i++){
            cout.flags(lflag); //flag linksbuendig
            Accounts.at(i)->printIBAN();
            cout
            << " | "
            << setw(21) << Accounts.at(i)->getOwner()->getName()
            << "|";
            cout.flags(rflag); //flag rechtsbuendig
            cout
            << setw(15) << "0"
            << "|"
            << setw(11) << setprecision(2) << Accounts.at(i)->getBalance().getAmount();
            cout.flags(lflag);
            cout  <<  " " << setw(3) << Accounts.at(i)->getBalance().getCurrency()
            << endl;
            
        }
        
        cout.flags(oldflag);
    
    }
}

bool CBank::addAccount(CAccount *newacc){
    if(newacc){
        Accounts.push_back(newacc);
        return true;
    }
    return false;
}

CBank CBank::load(ifstream &data){
    string *name = NULL;
    string *bic = NULL;
    string line;
    
    do{
        if(data.eof()){
            cout << "Datei fehlerhaft Bank"<<endl;
            break;
        }
        
        getline(data>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 6)=="<Name>")
            name = new string(basetypeload::load(line, "</Name>", name));
            
        if(line.substr(0, 5)=="<BIC>")
            bic = new string (basetypeload::load(line, "</BIC>", bic));
    
    }while (line != "</Bank>");
    
    CBank bank(*name, *bic);
    return bank;
}
