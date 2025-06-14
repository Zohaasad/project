#include<iostream>
#ifndef PLAYER_H
#define PLAYER_H
#include<fstream>
#include<algorithm>
#include<random>
#include<fstream>
#include<limits>
#include<ctime>
#include"String.h"
#include"myvector.h"
using namespace std;

class player {
    protected:
    String name;
    int score;
    public:
    player (String n);
    virtual~player();
    String getname()const ;
    int getscore()const;
    void addscore();
    virtual pair<int,int>pick(const myvector<bool>&revealed)=0; 
    
};
#endif
