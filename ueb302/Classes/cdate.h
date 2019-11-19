#ifndef cdate_h
#define cdate_h

#include <fstream>
#include <string>

using namespace std;

class CDate{
    private:
        int Day;
        int Month;
        int Year;
    
    public:
        CDate();
        CDate(int, int, int);
    
        void setDate(int, int, int);
        virtual void print();
    
    static CDate load(ifstream&, string);
    
};

#endif /* CBank_h */
