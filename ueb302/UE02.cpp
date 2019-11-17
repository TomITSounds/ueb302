#include <iostream>

using namespace std;

#include "cbankmanager.h"

int main()
{
   CBankManager BankManager("daten.xml");

   cout << endl;
   BankManager.printCustomerList();
   cout << endl;
   BankManager.printBankList();
   cout << endl;

   return 0;
}
