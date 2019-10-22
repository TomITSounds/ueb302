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
    //CAddress();
    //CAddress(const CAddress&);
    CAddress(string , string , string );
    
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
