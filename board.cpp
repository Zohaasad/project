#include<iostream>
#include"board.h"
#include"logger.h"
#include"String.h"
#include"myvector.h"
#include"Card.h"
#include"simplecard.h"
#include"hardcard.h"
#include<ctime>
#include<algorithm>
#include<random>
#include<limits>
#include<fstream>
using namespace std;

    Board::Board(): hardmode(false){}
   
    Board* Board::getinstance(){
        static Board instance;
        return &instance;
    }
    void Board::sethardmode(bool hm){
        hardmode=hm;
    }
    void Board::setupsimple(){
        try{
            hardmode=false;
            for(int i=0,j=0;i<8;i++){
                sc[j]=simplecard('A'+i);
                card[j]=&sc[j];
                j++;
            
           
                sc[j]=simplecard('A'+i);
                card[j]=&sc[j];
                j++;
            }
           myvector<int>indices(size,0);
      

          
            for(int i=0;i<size;i++)indices[i]=i;
            random_device rd;
            mt19937 g(rd());
          myvector<int>shuffledindices;
           for(int i=0;i<size;i++)
           shuffledindices.push(indices[i]);


            shuffle(shuffledindices.begin(),shuffledindices.end(),g);
            Card* temp[16];
            for(int i=0;i<size;i++)
            temp[i]=card[shuffledindices[i]];
            for(int i=0;i<size;i++)
            card[i]=temp[i];
            for(int i=0;i<size;i++)
            card[i]->setmatched(false);
            
        }
        catch(const char * msg){
            logger::getInstance().writeerror(String("exception in the set up of simple:")+msg);
            throw;
        }
    }
    void Board::setuphard(){
      try{
          hardmode=true;
          myvector<String>hardsymbols;
          hardsymbols.push(String("PWTU"));
           hardsymbols.push(String("FOQR"));
            hardsymbols.push(String("MNIR"));
             hardsymbols.push(String("ZXST"));
              hardsymbols.push(String("TZWY"));
              hardsymbols.push(String("BMQU"));
               hardsymbols.push(String("SWVO"));
                hardsymbols.push(String("GDFC"));
                for(int i=0,j=0;i<8;i++){
                    hc[j]=hardcard(hardsymbols[i]);
                    card[j]=&hc[j];
                    j++;
                     hc[j]=hardcard(hardsymbols[i]);
                    card[j]=&hc[j];
                    j++;
                    
                }
                myvector<int >indices(size,0);
                for(int i=0;i<size;i++)
                indices[i]=i;
                random_device rd;
                mt19937 g(rd());
             
                 myvector<int>shuffledindices;
          
           for(int i=0;i<size;i++)
           shuffledindices.push(indices[i]);

                shuffle(shuffledindices.begin(),shuffledindices.end(),g);
                Card*temp[16];
                for(int i=0;i<size;i++)
                temp[i]=card[shuffledindices[i]];
                for(int i=0;i<size;i++)
                card[i]=temp[i];
                for(int i=0;i<size;i++)
                card[i]->setmatched(false);
                
      }
      catch(const char *msg){
          logger::getInstance().writeerror(String("exception in setup of hard")+msg);
          throw;
      }
  }
   
     void Board::show(const myvector<bool>&revealed){
        try{
            cout<<"\nboard:\n";
            for(int i=0;i<size;i++){
                if(i%4==0)
                cout<<"\n";
                cout<<"["<<i<<"]";
                if(card[i]->ismatched()){card[i]->display();
                    cout<<" ";
                }
                else if(revealed[i]){card[i]->display();
                cout<<" ";}
                else 
                if(hardmode){
                    cout<<"****";
                }
                else cout<<"*";
            }
            cout<<"\n";
        }
        catch(const char *msg){
            logger::getInstance().writeerror(String("exception in show ")+msg);
        }
    }
    int Board::getsize()const {
       return size;
   }
   bool Board::ishardmode()const {
       return hardmode;
   }
   void Board::showall(){
       try {
           cout<<"\n board previous state :\n";
           for(int i=0;i<size;i++){
               if(i%4==0)
               cout<<"\n";
               cout<<"["<<i<<"]";
               if(card[i]->ismatched()){
                   card[i]->display();
                   cout<<" ";
               }
               else 
               if(hardmode){
               cout<<"**** ";
                   
               }
               else cout<<"* ";
           }
           cout<<"\n";
       }
       catch(const char*msg){
           logger::getInstance().writeerror(String("exception in show all: ")+msg);
           
       }
   }
   Card* Board::getcard (int index){
       return card[index];
   }
   void Board::setmatched(int i ,int j){
       try {
           card[i]->setmatched(true);
           card[j]->setmatched(true);
           
       }
       catch(const char *msg){
           logger::getInstance().writeerror(String("exception in set matched:")+msg);
           
       }
   }
    bool Board::saveboard(const String &filename){
    ofstream ofs(filename.c_str(),ios::binary|ios::trunc);
    if(!ofs)return false;
    ofs.write((char*)&hardmode,sizeof(hardmode));
    for(int i=0;i<size;i++){
        bool matched=card[i]->ismatched();
        ofs.write((char*)&matched,sizeof(matched));
        if(hardmode){
        String s=((hardcard*)card[i])->getsymbol();
        
            int len=s.length();
            ofs.write((char*)&len,sizeof(len));
            ofs.write(s.c_str(),len);
        }else{
          char s=((simplecard*)card[i])->getsymbol()[0];
          ofs.write(&s,sizeof(s));
        }
    }
    return true;
}
    bool Board::loadboard(const String &filename){
    ifstream ifs(filename.c_str(),ios::binary);
    if(!ifs)return false;
    bool mode;
    ifs.read((char*)&mode,sizeof(mode));
    hardmode=mode;
    if(hardmode){
        for(int i =0;i<size;i++){
            bool matched;
            ifs.read((char*)&matched,sizeof(matched));
            int len;
            ifs.read((char*)&len,sizeof(len));
            char *buffer=new char [len+1];
            ifs.read(buffer,len);
            buffer[len]='\0';
            hc[i]=hardcard(String(buffer));
            hc[i].setmatched(matched);
            card[i]=&hc[i];
            delete []buffer;
        }
    }
    else{
        for(int i=0;i<size;i++){
            bool matched;
            ifs.read((char*)&matched,sizeof(matched));
            char s;
            ifs.read(&s,sizeof(s));
            sc[i]=simplecard(s);
            sc[i].setmatched(matched);
            card[i]=&sc[i];
            
        }
    }
    return true;
}
Board *Board::instance=nullptr;

