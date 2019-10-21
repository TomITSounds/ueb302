//
//  cmoney.hpp
//  ueb302
//
//  Created by Tom Mertens on 21.10.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef cmoney_h
#define cmoney_h

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class CMoney{
    private:
    double Amount;
    string Currency;
    
    public:
    CMoney();
    CMoney(double);
    CMoney(double, string);
    ~CMoney();
    
    void set(double);
    void set(double, string);
    
    double getAmount(){return Amount;};
    string getCurrency(){return Currency;};
    void print();
};
#endif /* cmoney_hpp */