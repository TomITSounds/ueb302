//
//  caddress.hpp
//  ueb302
//
//  Created by Tom Mertens on 21.10.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef caddress_h
#define caddress_h

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class CAddress{
private:
    string Street;
    string Zip;
    string City;
    
public:
    CAddress(string Street, string Zip, string City);
    void set(string Street, string Zip, string City);
    string get(){return Street+", "+Zip+", "+City;};
    string getStreet(){return Street;};
    string getZip(){return Zip;};
    string getCity(){return City;};
    void print();
    void printStreet();
    void printZipCity();
    
};
#endif /* caddress_hpp */
