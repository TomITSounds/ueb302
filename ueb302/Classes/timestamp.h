#ifndef timestamp_hpp
#define timestamp_hpp

#include <stdio.h>
#include <iostream>
#include "ctime.h"
#include "cdate.h"

using namespace std;

class CTimestamp: public CDate, public CTime{
private:
    int year;
    int mon;
    int day;
    int hour;
    int min;
    int sec;

public:
    CTimestamp();
    CTimestamp(int, int, int, int, int, int=0);
    ~CTimestamp();
    
    void print();
};

#endif /* timestamp_hpp */
