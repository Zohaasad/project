#include<iostream>
using namespace std;
#include"Card.h"

   Card:: Card():matched(false){}
  Card::~Card(){}
    bool  Card::ismatched()const {
        return matched;
        
    }
    void  Card::setmatched(bool m ){
        matched=m;
    }
  
