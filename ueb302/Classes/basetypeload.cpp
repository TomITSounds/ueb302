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


string basetypeload::loadstr(string& line, int tagsize){
            line.erase(0,tagsize-1); //Anfangstag loeschen
            line.erase((line.size()-tagsize), tagsize); // Endtag loeschen
    return line;
}
    
long basetypeload::loadlong(string& line, int tagsize){
    line.erase(0,tagsize-1); //Anfangstag loeschen
    line.erase((line.size()-tagsize), tagsize); // Endtag loeschen
    return stol(line);

}
    
int basetypeload::loadint(string& line, int tagsize){
    line.erase(0, (tagsize-1)); //Anfangstag loeschen
    line.erase((line.size()-tagsize), tagsize); // Endtag loeschen

    return stoi(line);
    

}
    
double basetypeload::loaddouble(string& line, int tagsize){
    line.erase(0,tagsize-1); //Anfangstag loeschen
    line.erase((line.size()-tagsize), tagsize); // Endtag loeschen

       return stod(line);
}
    
    

