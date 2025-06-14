#include<iostream>
#include"String.h"
#include"Card.h"
using namespace std;
#ifndef HARDCARD_H
#define HARDCARD_H
class hardcard: public Card{
    String symbol;
    public:
    hardcard();
    hardcard(const String &s);
    String getsymbol()const override;
    void display()const override ;
    
};
#endif
