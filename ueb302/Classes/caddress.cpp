#include "caddress.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//Copy Konstruktor zur Initialisierung eines Objekt mit den werden eines anderen Objekt gleicher Klasse
CAddress::CAddress(const CAddress &Copy){
    Street = Copy.Street;
    Zip = Copy.Zip;
    City = Copy.City;
}

CAddress::CAddress(string Street, string Zip, string City){
    this->Street = Street;
    this->Zip = Zip;
    this-> City = City;
}

void CAddress::set(string Street, string Zip, string City){
    this->Street = Street;
    this->Zip = Zip;
    this-> City = City;
}

void CAddress::printStreet(){
    printf("%s", Street.c_str());
}

void CAddress::printZipCity(){
    printf("%s %s", Zip.c_str(), City.c_str());
}

