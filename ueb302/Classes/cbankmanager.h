//
//  cbankmanager.hpp
//  ueb302
//
//  Created by Tom Mertens on 17.11.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef cbankmanager_h
#define cbankmanager_h

#include <stdio.h>
#include "cbank.h"
#include "ccustomer.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class CBankManager{
private:
    static vector <CCustomer*> cuslist;
    static vector <CBank*> banklist;
    static vector <CMoney> dispolist;
    
public:
    CBankManager(string);
    ~CBankManager();
    
    void printCustomerList();
    void printBankList();
    
    static CBank *getbankptr(string);
    static CCustomer *getcusptr(long);
    
    
};

#endif /* cbankmanager_hpp */
