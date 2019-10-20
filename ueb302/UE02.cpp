#include <iostream>

using namespace std;

#include <stdio.h>
#include "cdate.h"
#include "ctime.h"
#include "cmoney.h"
#include "caddress.h"
#include "caccount.h"
#include "ccustomer.h"

int main()
{
   CTime Jetzt, SUBeginn(8, 0);
   CDate Geburtsdatum(7, 7, 1977);
   CMoney Startkapital(150.0);
   CAddress Adresse("Mustergasse 3a", "D - 99889", "Musterstadt");
   CCustomer Kunde(4711, "Egon Muster", Geburtsdatum, Adresse);
   CAccount Konto1("DE99123456781234567890", &Kunde, Startkapital);

   printf("Dieses Programm wurde um ");
   Jetzt.print();
   printf(" gestartet.\n\n");

   printf("Das Startkapital fuer alle Kunden betraegt ");
   Startkapital.print();
   printf(".\n\n");

   printf("Personenbezogene Daten des Bank-Kunden:\n");
   Kunde.print();
   printf("\n\n");

   printf("Daten des Konto 1:\n");
   Konto1.print();
   printf("\n\n");

   CAccount Konto2("DE99876543210987654321", &Kunde, CMoney(100.0, "$"));

   printf("Personenbezogene Daten des Bank-Kunden (ein Konto mehr):\n");
   Kunde.print();
   printf("\n\n");

   printf("Daten des Konto 2:\n");
   Konto2.print();
   printf("\n\n");

   return 0;
}
