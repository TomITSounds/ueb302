//
//  caddress.cpp
//  ueb302
//
//  Created by Tom Mertens on 21.10.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

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
void CAddress::set(string Street, string Zip, string City){
    this->Street = Street;
    this->Zip = Zip;
    this-> City = City;
}


void CAddress::print(){
    printf("%s, %s %s", Street.c_str(), Zip.c_str(), City.c_str());
}

void CAddress::printStreet(){
    printf("%s", Street.c_str());
}

void CAddress::printZipCity(){
    printf("%s %s", Zip.c_str(), City.c_str());
}
