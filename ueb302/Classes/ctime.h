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
        CTime(int, int, int = 0);
        ~CTime();
    
        void setTime(int, int, int = 0);
        void print();
    
};
#endif /* ctime_hpp */
