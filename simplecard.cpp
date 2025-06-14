 #include<iostream>
#include"String.h"
#include"Card.h"
#include"simplecard.h"
using namespace std;


   simplecard:: simplecard():symbol(' '){}
    
    simplecard::simplecard(char s): symbol(s){}
    String  simplecard::getsymbol()const {
        return String (&symbol);
    }
    void simplecard::display()const {
        cout<<symbol;
    }
