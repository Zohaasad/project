#include<iostream>
#include"player.h"
#include<fstream>
#include<algorithm>
#include<random>
#include<fstream>
#include<limits>
#include<ctime>
#include"String.h"
#include"myvector.h"
using namespace std;

   
  
   player:: player (String n):name(n),score(0){}
   player::~player(){}
    String  player::getname()const {
        return name;
    }
    int  player::getscore()const{
        return score;
    }
    void  player::addscore(){
        score++;
    }
    
    
