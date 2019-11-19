#ifndef cmoney_h
#define cmoney_h

#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

using namespace std;

class CMoney{

private:
    double Amount;
    string Currency;
    
public:
    CMoney();
    CMoney(double, string = "EUR");
    
    void set(double);
    void set(double, string);
    void set(CMoney);
    
    double getAmount(){return Amount;};
    string getCurrency(){return Currency;};
    void print();
    void lprint();
    
    static CMoney load(ifstream&, string);
};
#endif /* cmoney_hpp */
