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
//Entfernt Tags von strings und speichert diesen in der uebergebenen Referenz, i gibt grosse des Endtag an ->Anfangstag = endtag -1
class basetypeload{
public:
    static void loadstr(string&, int);
};
#endif /* basetypeload_hpp */
