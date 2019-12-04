

#ifndef ccurrentaccount_hpp
#define ccurrentaccount_hpp

#include <stdio.h>
#include "caccount.h"
#include <fstream>

class CCurrentAccount:  virtual public CAccount{
protected:
    CMoney *dispo;
    
public:
    CCurrentAccount(CBank *bank, string IBAN, CCustomer *Owner, CMoney Balance, CMoney *dispo);
    CCurrentAccount(CAccount, CMoney*);
    CCurrentAccount(const CCurrentAccount&);
    CCurrentAccount(vector <string>& loadvalues);
    ~CCurrentAccount();
    
    void print();
    
    static CCurrentAccount* load(ifstream&, vector <string>&, string="</CurrentAccount>");
    static void loadvalues(ifstream&, vector <string>&);
    
    static CMoney* checkdispoptr(vector <string>&, int=0);
    
    friend class CFixedDepositAccount;
    
};

#endif /* ccurrentaccount_hpp */
