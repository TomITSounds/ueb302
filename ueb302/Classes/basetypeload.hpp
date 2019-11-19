//
//  basetypeload.hpp
//  ueb302
//
//  Created by Tom Mertens on 18.11.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef basetypeload_hpp
#define basetypeload_hpp

#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

class basetypeload{
public:
    static string load(string, string, string* =NULL);
    
    static long load(string, string, long* =NULL);
    
    static int load(string, string, int* =NULL);
    
    static double load(string, string, double* =NULL);
    
    
};
#endif /* basetypeload_hpp */
