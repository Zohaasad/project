#include<iostream>
#ifndef AIPLAYER_H
#define AIPLAYER_H
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
class aiplayer :public player{
    myvector<String>symbols;
    myvector<myvector<int >>indices;
    public:
    aiplayer(String n );
    void cleanupmemory(const myvector <bool>&revealed);
void updatememory (const myvector<bool>&revealed);
 void remembercards(const myvector<bool>&revealed);
pair<int,int>pick(const myvector<bool>&revealed)override;
    
};
#endif
