#include<iostream>
#ifndef BOARD_H
#define BOARD_H
#include"logger.h"
#include"myvector.h"
#include"Card.h"
#include"simplecard.h"
#include"hardcard.h"
#include"String.h"
#include<ctime>
#include<algorithm>
#include<random>
#include<limits>
#include<fstream>
using namespace std;

class Board {
    private:
    static Board* instance;
    static const int size=16;
    bool hardmode;
    simplecard sc[16];
    hardcard hc[16];
    Card * card[16];
    Board();
    public:
    static Board *getinstance();
    void sethardmode(bool hm);
    void setupsimple();
    void setuphard();
   
     void show(const myvector<bool>&revealed);
    int getsize()const ;
   bool ishardmode()const ;
   void showall();
   Card *getcard (int index);
   void setmatched(int i ,int j);
    bool saveboard(const String &filename);

    bool loadboard(const String &filename);

};

#endif
   
