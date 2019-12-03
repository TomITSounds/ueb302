

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

CBank::CBank(string name, string bic):
    name(name),
    bic(bic){
}

CBank::CBank(vector<string>& loadvalues):
    name(loadvalues.at(0)),
    bic(loadvalues.at(1)){
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
        if(Accounts.size()){
            if(newacc->getIBAN() != Accounts.back()->getIBAN()){
                Accounts.push_back(newacc);
                return true;
            }
        }
        else{
            Accounts.push_back(newacc);
            return true;
        }
    }
    return false;
}

void CBank::replaceLastAccount(CAccount *newacc){
    Accounts.back() = newacc;
}
CBank* CBank::load(ifstream &pdata, vector <string>& loadvalues){
    
    CBank::loadvalues(pdata, loadvalues);
    
    return new CBank(loadvalues);
}

void CBank::loadvalues(ifstream &pdata, vector<string> &loadvalues){
    string line;
    do{
        if(pdata.eof()){
            cout << "Datei fehlerhaft Bank"<<endl;
            break;
        }
        
        getline(pdata>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 6)=="<Name>"){
            basetypeload::loadstr(line, 7);
            loadvalues.at(0) = line;
        }
        if(line.substr(0, 5)=="<BIC>"){
            basetypeload::loadstr(line, 6);
            loadvalues.at(1) = line;
            }
    
    }while (line != "</Bank>");
}
