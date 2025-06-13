#include <iostream>
#include "String.h"
using namespace std;

 int  String::  slength(const char *str)
    const {
        int length=0;
        while (str[length]!='\0'){
            length++;
        }
        return length;
    }
    void String::scopy(char *dest,const char *scr )
    const {
        int i=0;
        while (scr[i]!=0){
            dest [i]=scr[i];
            i++;
            
        }
        dest[i]='\0';
    }
    void String::sfill(char *str ,char c,int s){
        for(int i=0;i<s;i++){
            str[i]=c;
        }
        str[s]='\0';
    }
    bool String::isspace(char c){
        return (c==' '||c=='\t'||c=='\n');
    }
    bool String::ischar(char c,const char *ch)const {
        for(int i=0;ch[i]!='\0';i++){
            if(c==ch[i])return true;
        }
        return false;
    }

   String:: String (): len(0),cap(1){
        cs=new char [cap];
        cs[0]='\0';
    }
   String:: String (const char *p){
        len =slength(p);
        cap=len+1;
        cs=new char [cap];
        scopy(cs,p);
    }
   String:: String (int s, char c): len(s),cap(s+1){
        cs=new char[cap];
        sfill(cs,c,len);
    }
    void String::replacef(char c){
        if(len>0){
            cs[0]=c;
        }
    }
     
   String:: String (int num){
        *this=itos(num);
        
    }
String String::itos(int num){
    int tempnum=num;
    int digit =0;
    do {
        digit++;
        tempnum/=10;
        
    }
    while(tempnum!=0);
    len=digit;
    cap=len+1;
    cs=new char [cap];
    cs[len]='\0';
    for(int i=len-1;i>=0;i--){
        cs[i]=(num%10)+'0';
        num/=10;
    }
    return *this;
}
    

    String String::shallowc(){
        String temp;
        temp.len=this->len;
        temp.cap=this->cap;
        temp.cs=this->cs;
        return temp;
    }
   String:: String (const String &other){
        len=other.len;
        cap=other.cap;
        cs=new char[cap];
        scopy(cs,other.cs);
    }
    int String::stoi()
    const {
        int num=0;
        for (int i=0;i<len;i++){
            if(cs[i]>='0'&&cs[i]<='9'){
                num=num*10+(cs[i]-'0');
            }
            else return -1;
        }
        return num;
    }
    String &String::trim (){
         int start =0;
         while (start<len&& isspace(cs[start])){
             start++;
         }
         int end=len-1;
         while(end>=start && isspace( cs[end])){
             end--;
         }
         int newlen=end-start+1;
         if(newlen<0){
             newlen=0;
         }
         char *newcs=new char[newlen+1];
         for(int i=0;i<newlen;i++){
             newcs[i]=cs[start+i];
         }
         newcs[newlen]='\0';
         delete[]cs;
         cs=newcs;
         len=newlen;
         cap=newlen+1;
         return *this;
     }
    
    char String::operator[](int i)
    const {
        if(i<0||i>=len){
            cout<<"error"<<endl;
            return'\0';
        }
        return cs[i];
    }
    char &String::operator[](int i){
           if(i<0||i>=len){
               cout<<"error"<<endl;
              throw;
           }
           return cs[i];
       }
    int String::findf(char ch)
    const{
        for(int i=0;i<len;i++){
            if(cs[i]==ch)
                return i;
        }
        return -1;
    }
 int String::findl(char ch)
    const{
        for(int i=len-1;i>=0;i--){
            if(cs[i]==ch)
                return i;
        }
        return -1;
    }

   int *String::findall(char ch, int &count )
    const {
        count =0;
        int *ind=new int [len];
        for(int i=0;i<len;i++){
            if(cs[i]==ch){
                ind[count++]=i;
            }
        }
        int *result =new int [count];
        for(int i=0;i<count;i++){
            result[i]=ind[i];
        }
        delete[]ind;
        return result;
    }

    void String::removef(char c){
            int index=findf(c);
            if(index==-1)
                return;
            char *newcs=new char[len];
            int j=0;
            for(int i=0;i<len;i++){
                if(i!=index){
                    newcs[j]=cs[i];
                    j++;
                }
            }
            newcs[len-1]='\0';
            delete[]cs;
            cs=newcs;
            len--;
        }
        
        void String::removel(char c){
            int index=findl(c);
            if(index==-1)
                return;
            char *newcs=new char[len];
            int j=0;
            for(int i=0;i<len;i++){
                if(i!=index){
                    newcs[j]=cs[i];
                    j++;
                }
            }
            newcs[len-1]='\0';
            delete[]cs;
            cs=newcs;
            len--;
        }
    void String::removeall(char c){
        int count=0;
        for(int i=0;i<len;i++){
            if(cs[i]==c){
                count++;
            }
        }
        if(count==0)
            return;
        char *newcs=new char [len-count+1];
        int j=0;
        for(int i=0;i<len;i++){
            if(cs[i]!=c){
                newcs[j]=cs[i];
                j++;
            }
        }
        newcs[len-count]='\0';
        delete[]cs;
        cs=newcs;
        len-=count;}
    void String::print ()
    const {
        cout<<'"'<<cs<<'"'<<endl;
    }
    void String::insertat(int i,char c){
        if(i<0||i>len){
            cout<<"index out of bound"<<endl;
            return;
        }
        if(len +1>=cap){
            cap*=2;
            char *newcs=new char[cap];
            for (int j=0;j<i;j++){
                newcs[j]=cs[j];
            }
            for(int j=i;j<len;j++){
                newcs[j+1]=cs[j];
            }
            newcs[len+1]='\0';
            delete[]cs;
            cs=newcs;
            
        }
        else{
            for(int j=len;j>=i;j--){
                cs[j+1]=cs[j];
            }
            cs[i]=c;
        }
        len++;
    }
    void String::insertat (int i,const String sub){
        if(i<0||i>len){
            cout<<"out of bound"<<endl;
            return;
        }
        int newlen=cap*2;
        char *newcs= new char [newlen];
        for(int j=0;j<i;j++){
            newcs[j]=cs[j];
        }
        for(int j=0;j<sub.len;j++){
            newcs[i+j]=sub.cs[j];
        }
        for(int j=i;j<len;j++){
            newcs[sub.len+j]=cs[j];
        }
        newcs[newlen]='\0';
        delete[]cs;
        cs=newcs;
        len=newlen;
        cap=newlen+1;
    }
    bool String::isequal (const String &m){
        if(len !=m.len )return false;
        for(int i=0;i<len;i++){
            if(cs[i]!=m.cs [i])
                return false;
        }
        return true ;
    }
    bool String::isless(const String &m){
        for(int i=0;i<len &&i<m.len ;i++){
            if(cs[i]<m.cs[i])return true;
            if(cs[i]>m.cs[i])
                return false;
        }
        return len<m.len;
    }

    bool String::isgreat(const String &m){
        return !isless(m)&&!isequal(m);
    }
    String *String::split(char ch ,int &count)
    const{
        count=1;
        for(int i=0;i<len;i++){
            if(cs[i]==ch){
                count++;
            }
        }
        String *result =new String[count];
        int start=0;
        int part =0;
        for(int i=0;i<=len;i++){
            if(cs[i]==ch||cs[i]=='\0'){
                int sublen=i-start;
                char *temp=new char[sublen+1];
                for(int j=0;j<sublen;j++){
                    temp[j]=cs[start+j];
                }
                temp[sublen]='\0';
                result[part++]=String(temp);
                delete[] temp;
                start=i+1;
            }
        }
        return result ;
    }
    String *String::tokenize(const char *ch,int &count)
    const {
        count=1;
        for(int i=0;i<len;i++){
            if(ischar(cs[i],ch)){
                count++;
            }
        }
        String *result=new String[count];
        int start=0;
        int part=0;
        for(int i=0;i<=len;i++){
            if(ischar(cs[i],ch)||cs[i]=='\0'){
                int sublen=i-start;
                if(sublen>0){
                    char *temp=new char[sublen+1];
                    for(int j=0;j<sublen;j++){
                        temp[j]=cs[start+j];
                    }
                    temp[sublen]='\0';
                    result[part++]=String (temp);
                    delete[]temp;
                }
                start=i+1;
            }
        }
        count=part;
        return result;
    }
    int * String::allsub(const char *sub,int &count)
    const{
        count=0;
        int sublen=slength(sub);
        if(sublen==0||sublen>len)
            return nullptr;
        int *ind=new int [len];
        for(int i=0;i<=len-sublen;i++){
            bool match=true;
            for(int j=0;j<sublen;j++){
                if(cs[i+j]!=sub[j]){
                    match=false;
                    break;
                }
            }
            if(match){
                ind[count++]=i;
            }}
        int * result =new int[count];
        for(int i=0;i<count;i++){
            result[i]=ind[i];
        }
        delete[]ind;
        return result;
    }
    String String::concat(const String &s2)
        const {
            int newlen=len+s2.len;
            char*newcs= new char[newlen+1];
            scopy(newcs,cs);
            for(int i=0;i<s2.len;i++){
                newcs[len+i]=s2.cs[i];
                
            }
            newcs[newlen]='\0';
            String result(newcs);
            delete[]newcs;
            return result;
        }
        String &String:: append(const String &s2){
            int newlen =len +s2.len;
            char*newcs= new char[newlen+1];
            scopy(newcs,cs);
            for(int i=0;i<s2.len;i++){
                newcs[len+i]=s2.cs[i];
                
            }
            newcs[newlen]='\0';
            delete[]cs;
            cs=newcs;
            len=newlen;
            cap=newlen+1;
            return *this ;
        }
    void String::clear(){
        delete []cs;
        cap=1;
        len=0;
        cs=new char[cap];
        cs[0]='\0';
    }
    void String::toupper(){

           for(int i=0;i<len;i++){

               if(cs[i]>='a'&&cs[i]<='z'){

                   cs[i]-=32;

               }

           }

       }

       void String::tolower(){

           for(int i=0;i<len;i++){

               if(cs[i]>='A'&&cs[i]<='Z'){

                   cs[i]+=32;

               }

           }

       }

       String String::upper() const {

           String result(cs);

           result.toupper();

           return result;

       }

       String String::lower()const {

           String result(cs);

           result.tolower();

           return result;

       }

  
String &String::operator =(const String&other){
    if(this!=&other){
        delete[]cs;
        len=other.len;
        cap=other.cap;
        cs=new char[cap];
        scopy(cs,other.cs);
        
    }
    return *this ;
}
    String::~String (){
        delete[]cs;
    }
bool operator==(const String&a,const String &b){
    if(a.length()!=b.length())return false;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}
const char*String::c_str()const{
    return cs;
}
int String::length()const{
    return len;
}
