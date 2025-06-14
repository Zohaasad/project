#include<iostream>
#ifndef GAME_H
#define GAME_H
#include<fstream>
#include<algorithm>
#include<random>
#include<fstream>
#include<limits>
#include<ctime>
#include"String.h"
#include"myvector.h"
#include"player.h"
class game{
    private:
    player *p1;
    player *p2;
    myvector<bool>revealed;
    int turn;
    aiplayer *ap;
    public:
    game (bool hard,bool vsai);
    ~game();
     void printresult();
    void play();
       
};
#endif
