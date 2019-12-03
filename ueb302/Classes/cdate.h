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
        CDate(vector<string>&, int=0);
    
        void setDate(int, int, int);
        virtual void print();
    
    static CDate* load(ifstream&, vector <string>&, int=0,string="</Birthday>");
    static void loadvalues(ifstream&, vector <string>&, int=0, string="</Birthday>");
    
};

#endif /* CBank_h */
