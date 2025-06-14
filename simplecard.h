#include<iostream>
#include"String.h"
#include"Card.h"
using namespace std;
#ifndef SIMPLECARD_H
#define SIMPLECARD_H
class simplecard: public Card{
    char symbol ;
    public:
    simplecard();
    
    simplecard(char s);
    String getsymbol()const override;
    void display()const override;
};
#endif
