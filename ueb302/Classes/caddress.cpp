#include "caddress.h"
#include "basetypeload.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

CAddress::CAddress(string Street, string Zip, string City):Street(Street), City(City), Zip(Zip)
{
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

CAddress CAddress::load(ifstream &pdata, string endtag){
    string line, street, zip, city;
    int ret = pdata.tellg();
   
    do{
        if(pdata.eof()){
                cout << "Datei fehlerhaft CAddress"<<endl;
                break;
        }
        getline(pdata>>ws, line);
        line.pop_back();
        
        if(line.substr(0, 8)=="<Street>")
            street = basetypeload::loadstr(line, sizeof("</Street>"));
        
        if(line.substr(0, 10)=="<Postcode>")
            zip = basetypeload::loadstr(line, sizeof("</Postcode>"));
        
        if(line.substr(0, 6)=="<Town>")
            city = basetypeload::loadstr(line, sizeof("</Town>"));
            
    }while(line != endtag);
    
    pdata.seekg(ret);
    
    return CAddress(street, zip, city);
}
