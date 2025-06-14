#include<iostream>
#include"String.h"
#include"Card.h"
#include"hardcard.h"
using namespace std;

     hardcard:: hardcard():symbol(" "){}
     hardcard::hardcard(const String &s):symbol(s){}
    String  hardcard::getsymbol()const {
        return symbol;
        
    }
    void  hardcard::display()const {
        cout<<symbol;
    }
    
