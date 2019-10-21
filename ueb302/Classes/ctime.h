//
//  ctime.hpp
//  ueb302
//
//  Created by Tom Mertens on 21.10.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef ctime_h
#define ctime_h

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class CTime{
    private:
        int Hour;
        int Minute;
        int Second;
    
    public:
        CTime();
        CTime(int, int);
        CTime(int, int, int);
        ~CTime();
    
        void setTime(int, int, int);
        void print();
    
};
#endif /* ctime_hpp */
