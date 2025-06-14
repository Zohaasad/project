#include<iostream>
#include<algorithm>
#include<random>
#include<fstream>
#include<limits>
#include<ctime>
#include"String.h"
#include"myvector.h"
#include"Card.h"
#include"hardcard.h"
#include"simplecard.h"
#include"logger.h"
#include"player.h"
#include"humanplayer.h"
#include"aiplayer.h"
#include"board.h"
#include"game.h"
using namespace std;


    game::game (bool hard,bool vsai):turn (0),p1(nullptr),p2(nullptr),ap(nullptr){
        try{
            revealed= myvector<bool>(Board::getinstance()->getsize(),false);
            p1=new humanplayer("player1");
            if(vsai){
                ap=new aiplayer("ai");
                p2=ap;
            }
            else p2=new humanplayer("player2");
        }
        catch(const char *msg){
            logger::getInstance().writeerror(String("exception in game :")+msg);
            throw;
        }
    }
    
   game:: ~game(){
        try {
            delete p1;
            if(p2!=p1)
            delete p2;
        }
        catch(const char *msg){
            logger::getInstance().writeerror(String("exception in destructor of game: ")+msg);
        }
    }
    
     void game::printresult(){
        try{
            cout<<"game over\n";
            cout<<p1->getname()<<"score:"<<p1->getscore()<<"\n";
            cout<<p2->getname()<<"score:"<<p2->getscore()<<"\n";
            if(p1->getscore()>p2->getscore())
            cout<<p1->getname()<<"wins!\n";
            else if (p2->getscore()>p1->getscore())
            cout<<p2->getname()<<"wins!\n";
            else
            cout<<"its a tie !\n";
        }
        catch(const char *msg){
            logger::getInstance().writeerror(String("exception in printing the result:")+msg);
        }
    }
    
void game::play(){
    try{
        int totalmatched=0;
        for(int i=0;i<Board::getinstance()->getsize();i++)
        if(Board::getinstance()->getcard(i)->ismatched())
        totalmatched++;
        Board::getinstance()->show(revealed);
        while(totalmatched<Board::getinstance()->getsize()){
            player *cp;
            if(turn%2==0){
                cp=p1;
            }
            else{
                cp=p2;
            }
            auto pick=cp->pick(revealed);
            //auto beacuse it return pair
            int a=pick.first;
            int b=pick.second;
            if(a==b){
                for(int i =0;i<revealed.size();i++){
                    if(i!=a && !revealed[i]&&!Board::getinstance()->getcard(i)->ismatched()){
                        b=i;
                        break;
                    }
                }
            }
            revealed[a]=true;
            revealed[b]=true;
            Board::getinstance()->show(revealed);
            if(ap) {
            ap->remembercards(revealed);
                
            }
            
            if(Board::getinstance()->getcard(a)->getsymbol()==Board::getinstance()->getcard(b)->getsymbol()){
                cout<<"matched!\n";
                Board::getinstance()->setmatched(a,b);
                cp->addscore();
                totalmatched+=2;
                
            }
            else{
                cout<<"not a match .\n";
                revealed[a]=false;
                revealed[b]=false;
                turn++;
            }
            cout<<"enter s to save and quit press anyother key to continue the game ";
            String option;
            cin>>option;
            if(option=="S"||option=="s"){
                if(Board::getinstance()->saveboard("board_save.txt")){
                    std::cout<<"board saved.";
                }
                else{
                    cout<<"failed to save";
                    logger::getInstance().writeerror("failed to save board ");
                }
                logger::getInstance().cleanup();
                exit(0);
                
            }
        }
        printresult();
        if(Board ::getinstance()->saveboard("board_save.txt")){
            cout<<"board saved";
        }
        else{
            cout<<"failed to save final board";
            logger::getInstance().writeerror("failed to save final board ");
        }
        logger::getInstance().cleanup();
        
    }
    catch(const char *msg){
        cout<<"exception during game play :"<<msg<<'\n';
        logger::getInstance().writeerror(String("exception during game play:")+msg);
   logger::getInstance().cleanup();
   throw;
    }
}
       
