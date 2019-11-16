#include "timestamp.h"
#include <stdio.h>
#include <iostream>
#include "ctime.h"
#include "cdate.h"

using namespace std;

CTimestamp::CTimestamp(int y, int mo, int d, int h, int mi, int s){
    year = y;
    mon = mo;
    day = d;
    hour = h;
    day = d;
    min = mi;
    sec = s;
}

CTimestamp::~CTimestamp(){
    cout << "Dekonstruktor Timestamp" << endl;
}

void CTimestamp::print(){
    CDate::print();
    cout<< " "<< endl;
    CTime::print();
    
}
