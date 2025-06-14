#include<iostream>
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include<fstream>
#include<algorithm>
#include<random>
#include<fstream>
#include<limits>
#include<ctime>
#include"String.h"
#include"myvector.h"
#include"player.h"

using namespace std;

class humanplayer:public player {
    public:
    humanplayer(String n);
    pair<int,int>pick(const myvector<bool>&revealed)override;
    
   
};
#endif
