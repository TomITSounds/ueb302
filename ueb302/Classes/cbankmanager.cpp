//
//  cbankmanager.cpp
//  ueb302
//
//  Created by Tom Mertens on 17.11.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include "cbankmanager.h"
#include <stdio.h>
#include "cbank.h"
#include "ccustomer.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

CBankManager::CBankManager(string file){
    ifstream daten = ios::open(file, ios::in);
}
