

#include "cbank.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "caccount.h"

using namespace std;

CBank::CBank(string name, string bic){
    this->name = name;
    this->bic = bic;
    count = 0;
}
CBank::~CBank(){
    printf("Dekonstruktor CBank");
}

void CBank::set(string name, string bic){
    this->name = name;
    this->bic = bic;}

void CBank::print(){
    
}
bool CBank::addAccount(CAccount *newacc){
    Accounts[count] = newacc;
    count++;
    return true;
}
