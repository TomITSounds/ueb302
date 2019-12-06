#ifndef ctime_h
#define ctime_h

#include <iostream>
#include <string>


using namespace std;

class CTime{
    private:
        int Hour;
        int Minute;
        int Second;
    
    public:
        CTime();
        CTime(int, int, int = 0);
        CTime(vector<string>&, int=0);
    
        void setTime(int, int, int = 0);
        virtual void print();
    
    virtual CTime* load(ifstream&, vector<string>&, int=0, string="</Time>");
    virtual void loadvalues(ifstream&, vector<string>&, int=0, string="</Time>");
    virtual void loadsinglevalue(vector<string>&, int=0);
};
#endif /* ctime_hpp */
