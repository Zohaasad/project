
#include<iostream>
#include<fstream>
#include<algorithm>
#include<random>
#include<fstream>
#include<limits>
#include<ctime>
#include"String.h"
#include"myvector.h"
#include"player.h"
#include"humanplayer.h"
#include"logger.h"
#include"board.h"

    humanplayer::humanplayer(String n):player (n){}
    pair<int,int>humanplayer::pick(const myvector<bool>&revealed){
        try{
            
        
    int a=-1;
    int b=-1;
    bool valid=false;
    while(!valid){
        cout<<name<<", pick 2 cards (0 to 15 ) :";
        cin>>a>>b;
        if(cin.fail()){
            cout<<"error :invalid input type try again.\n";
            logger::getInstance().writeerror("invalid input type");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
           //if the user type the wrong input this lines rmoves all of it no matter how long so the game dosent break and ask again streamsize is just a type that is use to tell how much to rmove  and numericlimit <streamsize>::max()gives teh biggest amount to ignore .
        
            continue;
        }
        if(a>=0&&a<16 &&b>=0&&b<16&&a!=b&&!revealed[a]&&!revealed[b]&&!Board::getinstance()->getcard(a)->ismatched()&&!Board::getinstance()->getcard(b)->ismatched()){
            valid=true;
        }
        else{
            cout<<"inavlid pick try again.\n";
            logger::getInstance().writeerror("invalid card pick attempt");
        }
        }
        return{a,b};
    }
    catch(const char *msg){
        logger::getInstance().writeerror(String("exception in human player ")+msg);
        throw;
    }
}
