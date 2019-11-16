#include <iostream>
#include <cstdio>

using namespace std;

#include "cdate.h"
#include "ctime.h"
#include "cmoney.h"
#include "caddress.h"
#include "caccount.h"
#include "ccurrentaccount.h"
#include "csavingsaccount.h"
#include "ccustomer.h"
#include "cbank.h"

int main()
{
   CDate Geburtsdatum(7, 7, 1977);
   CMoney Startkapital(150.0);
   CMoney Dispo(250.0);
   double Zinsen = -2.5;
   CAddress Adresse("Mustergasse 3a", "D - 99889", "Musterstadt");
   // Egon, Anton und Paul sind Drillinge, die noch bei Mutti wohnen
   CCustomer Egon(4711, "Egon Muster", Geburtsdatum, Adresse);
   CCustomer Anton(815, "Anton Muster", Geburtsdatum, Adresse);
   CCustomer Paul(1234, "Paul Muster", Geburtsdatum, Adresse);
   CBank Spasskasse("Berliner Spasskasse", "BESPKADEXXX");
   CBank HochschulBank("Deutsche Hochschul-Bank", "DEHOBADEXXX");
   CAccount Konto1(&Spasskasse, "DE99123456781234567890", &Egon,  Startkapital);
   CCurrentAccount Konto2(&HochschulBank, "DE99876543210987654321", &Egon,  Startkapital, &Dispo);
   CSavingsAccount Konto3(&Spasskasse, "DE11223344556677889900", &Anton, Startkapital, Zinsen);
   CAccount Konto4(&HochschulBank, "DE99887766554433221100", &Paul,  CMoney(100.0, "$"));

   printf("Daten der Konten:\n=================\n\n");
   printf("Konto 1:\n");   Konto1.print();   printf("\n\n");
   printf("Konto 2:\n");   Konto2.print();   printf("\n\n");
   printf("Konto 3:\n");   Konto3.print();   printf("\n\n");
   printf("Konto 4:\n");   Konto4.print();   printf("\n\n");

   printf("\nDaten der Banken:\n=================\n\n");
   printf("Bank 1:\n");   Spasskasse.print();      printf("\n\n");
   printf("Bank 2:\n");   HochschulBank.print();   printf("\n\n");

   return 0;
}
