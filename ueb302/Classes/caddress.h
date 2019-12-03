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
    CAddress(string , string , string );
    CAddress(const CAddress&);
    CAddress(vector<string>&, int=0);
    
    void set(string Street, string Zip, string City);
    string get(){return Street+", "+Zip+", "+City;};
    string getStreet(){return Street;};
    string getZip(){return Zip;};
    string getCity(){return City;};
    void print();
    void printStreet();
    void printZipCity();
    
    static CAddress* load(ifstream&, vector <string>&, int=0, string="</Address>");
    static void loadvalues(ifstream&, vector <string>&, int=0, string="</Address>");
};
#endif /* caddress_hpp */
