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
    CMoney(vector <string>&, int=0);
    
    void set(double);
    void set(double, string);
    void set(CMoney);
    
    double getAmount(){return Amount;};
    string getCurrency(){return Currency;};
    void print();
    void lprint();
    
    static CMoney* load(ifstream&, vector <string>&, int=0, string="</Balance>", bool=false);
    static void loadvalues(ifstream&, vector <string>&, int=0, string="</Balance>");
    
        friend bool operator== (const CMoney &m1, const CMoney &m2);
        friend bool operator!= (const CMoney &m1, const CMoney &m2);
    };
     

#endif /* cmoney_hpp */
