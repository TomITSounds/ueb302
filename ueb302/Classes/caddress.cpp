#include "caddress.h"
#include "basetypeload.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

CAddress::CAddress(string Street, string Zip, string City){
    this->Street = Street;
    this->Zip = Zip;
    this-> City = City;
}

CAddress::CAddress(const CAddress& old): Street(old.Street), Zip(old.Zip), City(old.City){// *this= old aequivalent?}
}

void CAddress::set(string Street, string Zip, string City){
    this->Street = Street;
    this->Zip = Zip;
    this-> City = City;
}

void CAddress::printStreet(){
    cout << Street << flush;
}

void CAddress::printZipCity(){
    cout << Zip << " " << City << flush;
}

void CAddress::print(){
    printStreet();
    cout << endl;
    printZipCity();
    cout << endl;
}

CAddress CAddress::load(ifstream& data, string endtag){
    string line;
    string *street = NULL;
    string *zip = NULL;
    string *city = NULL;
    
    do{
        if(data.eof()){
                cout << "Datei fehlerhaft CAddress"<<endl;
                break;
        }
        getline(data>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 8)=="<Street>")
            street = new string(basetypeload::load(line, "</Street>", street));
        
        if(line.substr(0, 10)=="<Postcode>")
            zip = new string(basetypeload::load(line, "</Postcode>", zip));
        
        if(line.substr(0, 6)=="<Town>")
            city = new string(basetypeload::load(line, "</Town>", city));
            
    }while(line != endtag);
    
    CAddress add(*street, *zip, *city);
    
    return add;
}
