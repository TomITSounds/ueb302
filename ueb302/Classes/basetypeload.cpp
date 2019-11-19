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


string basetypeload::load(string line, string tag, string* result){

    int tagsize = tag.size();
    
            line.erase(0,tagsize-1); //Anfangstag loeschen
            line.erase((line.size()-tagsize), tagsize); // Endtag loeschen
            if(result)
                *result = line;
            else
                result = new string (line);

    return *result;
}
    
long basetypeload::load(string line, string tag, long* result){
    
    int tagsize = tag.size();
    
            line.erase(0,tagsize-1); //Anfangstag loeschen
            line.erase((line.size()-tagsize), tagsize); // Endtag loeschen
            if(result)
                *result = stoi(line);
            else
                result = new long (stoi(line));

    return *result;

}
    
int basetypeload::load(string line, string tag, int* result){
     
    int tagsize = tag.size();
    
            line.erase(0,tagsize-1); //Anfangstag loeschen
            line.erase((line.size()-tagsize), tagsize); // Endtag loeschen
            if(result)
                *result = stoi(line);
            else
                result = new int (stoi(line));

    return *result;
}
    
double basetypeload::load(string line, string tag, double* result){
       
       int tagsize = tag.size();
       
               line.erase(0,tagsize-1); //Anfangstag loeschen
               line.erase((line.size()-tagsize), tagsize); // Endtag loeschen
               if(result)
                   *result = stod(line);
               else
                   result = new double (stod(line));

       return *result;
}
    
    

