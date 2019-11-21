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
    static string loadstr(string&, int);
    
    static long loadlong(string&, int);
    
    static int loadint(string&, int);
    
    static double loaddouble(string&, int);
    
    
};
#endif /* basetypeload_hpp */
