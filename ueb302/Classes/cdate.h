#ifndef cdate_h
#define cdate_h

class CDate{
    private:
        int Day;
        int Month;
        int Year;
    
    public:
        CDate();
        CDate(int, int, int);
        ~CDate();
    
        void setDate(int, int, int);
        void print();
    
};

#endif /* CBank_h */
