//
//  basetypeload.cpp
//  ueb302
//
//  Created by Tom Mertens on 18.11.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include "basetypeload.hpp"
#include <stdio.h>
#include <string>
#include <fstream>
#include <string>

using namespace std;


void basetypeload::loadstr(string& line, int tagsize){
            line.erase(0,tagsize-1); //Anfangstag loeschen
            line.erase((line.size()-tagsize), tagsize); // Endtag loeschen
    return;
}



