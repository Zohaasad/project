#include<iostream>
#include"aiplayer.h"
#include<fstream>
#include<algorithm>
#include<random>
#include<fstream>
#include<limits>
#include<ctime>
#include"String.h"
#include"myvector.h"
#include"player.h"
 #include"logger.h"
 #include"board.h"
   aiplayer:: aiplayer(String n ):player(n){}
    void aiplayer::cleanupmemory(const myvector <bool>&revealed){
        try{
            int i=0;
            while(i<symbols.size()){
                myvector<int>&index=indices[i];
                int j=0;
                while(j<index.size()){
                    if(revealed[index[j]]||Board::getinstance()->getcard(index[j])->ismatched()){
                        index.deleteat(j);
                    }
                    else{
                        j++;
                    }
                }
                if(index.size()==0){
                    symbols.deleteat(i);
                    indices.deleteat(i);
                }
                else{
                    i++;
                }
            }
        }
        catch(const char*msg){
            logger::getInstance().writeerror(String("there is exception in ai player in clean up part ")+msg);
        }
    }
    
void aiplayer::updatememory (const myvector<bool>&revealed){
    try{
        for(int i =0;i<revealed.size();i++){
            if(revealed[i]&&!Board::getinstance()->getcard(i)->ismatched()){
                String value =Board::getinstance()->getcard(i)->getsymbol();
                int find=-1;
                for(int j=0;j<symbols.size();j++){
                    if(symbols[j]==value){
                        find=j;
                        break;
                    }
                }
                if(find==-1){
                    symbols.push(value);
                    myvector<int> v;
                    v.push(i);
                    indices.push(v);
                }
                else{
                    bool alreadythere =false;
                    for(int k=0;k<indices[find].size();k++){
                        if(indices[find][k]==i)
                        alreadythere=true;
                        
                    }
                    if(!alreadythere)
                    indices[find].push(i);
                }
                
            }
        }
    }
    catch(const char *msg){
        logger::getInstance().writeerror(String("exception in ai player in upadte memory part :")+msg);
    }
}
 void aiplayer::remembercards(const myvector<bool>&revealed){
     updatememory(revealed);
 }

pair<int,int>aiplayer::pick(const myvector<bool>&revealed){
    try{
        cleanupmemory(revealed);
        updatememory(revealed);
        for(int i=0;i<symbols.size();i++){
            if(indices[i].size()>=2){
                return {
                    indices[i][0],indices[i][1]
                };
                
            }
        }
        for(int i =0;i<symbols.size();i++){
            if(indices[i].size()==1){
                int knownindex=indices[i][0];
                myvector<int>unknown;
                for(int j=0;j<revealed.size();j++){
                    if(!revealed[j]&&!Board::getinstance()->getcard(j)->ismatched()&&j!=knownindex){
                        String symbolatj=Board::getinstance()->getcard(j)->getsymbol();
                        int find=-1;
                        for(int k=0;k<symbols.size();k++){
                            if(symbols[k]==symbolatj){
                                for(int m=0;m<indices[i].size();m++){
                                    if(indices[k][m]==j)
                                    find=k;
                                    
                                }
                            }
                        }
                        if(find==-1)
                        unknown.push(j);
                        
                    }
                }
                if (unknown.size()>0){
                    random_device rd ;
                    mt19937 g(rd());
                    myvector<int >temp;
                    for(int p=0;p<unknown.size();p++)
                    temp.push(unknown[p]);
                    shuffle(temp.begin(),temp.end(),g);
                    return{
                        knownindex, temp[0]
                        
                    };
                }
            }
        }
        myvector<int >choices;
        for(int i=0;i<revealed.size();i++){
            if(!revealed[i]&& !Board::getinstance()->getcard(i)->ismatched())
            choices.push(i);
            
        }
            random_device rd;
            mt19937 g(rd());
            myvector<int >temp;
            for(int p=0;p<choices.size();p++)
            temp.push(choices[p]);
            shuffle(temp.begin(),temp.end(),g);
            if(choices.size()==1)
            return{
                choices[0],choices[0]
            };
           return {
               temp[0],temp[1]
           };
        }
        catch(const char *msg){
            logger::getInstance().writeerror(String("exception in ai player in picking ")+msg);
            throw;
        }
    }
    
