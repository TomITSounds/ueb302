#include "caddress.h"
#include "basetypeload.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

CAddress::CAddress(string Street, string Zip, string City):Street(Street), City(City), Zip(Zip)
{
}

CAddress::CAddress(const CAddress& old): Street(old.Street), Zip(old.Zip), City(old.City){// *this= old aequivalent?}
}

CAddress::CAddress(vector<string>& loadvalues,int i):
    Street(loadvalues.at(0+i)),
    Zip(loadvalues.at(1+i)),
    City(loadvalues.at(2+i)){
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

CAddress* CAddress::load(ifstream &pdata, vector <string>& loadvalues, int i, string endtag){
    CAddress::loadvalues(pdata, loadvalues);
    
    return new CAddress(loadvalues, i);
}

    void CAddress::loadvalues(ifstream &pdata, vector<string> &loadvalues, int i, string endtag){
        string line;
        do{
            if(pdata.eof()){
                    cout << "Datei fehlerhaft CAddress"<<endl;
                    break;
            }
            getline(pdata>>ws, line);
            line.pop_back();
            if(line.substr(0, 8)=="<Street>"){
                basetypeload::loadstr(line, 9);
                loadvalues.at(0+i) = line;
            }
            if(line.substr(0, 10)=="<Postcode>"){
                basetypeload::loadstr(line, 11);
                loadvalues.at(1+i) = line;
            }
            if(line.substr(0, 6)=="<Town>"){
                basetypeload::loadstr(line, 7);
                loadvalues.at(2+i) = line;
            }
        }while(line != endtag);
    }
