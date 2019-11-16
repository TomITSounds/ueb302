#include "caddress.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

CAddress::CAddress(string Street, string Zip, string City){
    this->Street = Street;
    this->Zip = Zip;
    this-> City = City;
}

CAddress::~CAddress(){
    cout << "Dekonstruktor CAddress" << endl;
};

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
