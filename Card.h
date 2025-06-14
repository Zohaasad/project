#include<iostream>
#include"String.h"
using namespace std;
#ifndef CARD_H
#define CARD_H
class Card{
    protected:
    bool matched;
    public:
    Card();
    virtual ~Card();
    virtual String getsymbol() const=0;
    bool ismatched()const ;
    void setmatched(bool m );
    virtual void display()const =0;
    
};
#endif
