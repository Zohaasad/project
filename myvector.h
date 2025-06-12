#include <iostream>
using namespace std;
#ifndef MYVECTOR_H
#define MYVECTOR_H
template<typename T>
class myvector{
    private:
    T *arr;
    int len;
    int cap;
    void doublecap(){
        if(cap==0){
         cap=1;   
        }
        else{
            cap*=2;
        }
        T *newarr=new T[cap];
        for(int i=0;i<len;i++){
            newarr[i]=arr[i];
        }
        delete[]arr;
        arr=newarr;
    }
    bool isvalid(int index)const{
        return index>=0 &&index<len;
        
    }
    public:
    myvector():arr(nullptr),len(0),cap(0){}
    myvector(int count,const T &value):len(count),cap(count){
        arr=new T[cap];
        for(int i=0;i<len;i++){
            arr[i]=value;
        }
    }
    myvector(int capacity):len(0),cap(capacity){
        arr= new T[cap];
    }
    myvector(const myvector &other):len(other.len),cap(other.cap){
        arr=new T[cap];
        for(int i=0;i<len;i++){
            arr[i]=other.arr[i];
        }
    }
    ~myvector(){
        delete[]arr;
    }
    void push(const T&value){
        if(len==cap){
            doublecap();
        }
        arr[len++]=value;
    }
    void pop(){
        if (len>0){
            len--;
        }
    }
    void insertat(int index,const T &value){
        if(!isvalid(index)&& index!=len){
            cout<<"index out of bound"<<endl;
            return;
        }
        if(len==cap){
            doublecap();
        }
        for(int i=len;i>index;i--){
            arr[i]=arr[i-1];
        }
        arr[index]=value;
        len++;
    }
    void deleteat(int index){
        if(!isvalid(index)){
            cout<<"index out of bound"<<endl;
            return ;
        }
        for(int i=index;i<len-1;i++){
            arr[i]=arr[i+1];
        }
        len--;
    }
    void display()const{
        for(int i=0;i<len;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void clear(){
        len=0;
    }
    void reverse(){
        int start=0;
        int end=len-1;
        while(start<end){
            T temp =arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }
    void shrinktofit(){
        if(len<cap){
            T *newarr=new T[len];
            for(int i=0;i<len;i++){
                newarr[i]=arr[i];
            }
            delete[]arr;
            arr=newarr;
            cap=len;
        }
    }
    void reserve(int newcap){
        if(newcap>cap){
            T * newarr=new T[newcap];
            for(int i=0;i<len;i++){
                newarr[i]=arr[i];
            }
            delete[]arr;
            arr=newarr;
            cap=newcap;
        }
    }
    const T &at(int index)const{
        if(!isvalid(index)){
            cout<<"out of bound"<<endl;
            
            return arr[0];
        }
        return arr[index];
    }
    T &at (int index){
        if(!isvalid(index)){
             cout<<"out of bound"<<endl;
           return arr[0];
        }
        return arr[index];
    }
    T &front(){
        return arr[0];
    }
    const T &front()const{
        return arr[0];
    }
    T &back(){
        return arr[len-1];
    }
    const T &back()const {
        return arr[len-1];
    }
    myvector&operator=(const myvector&other){
        if(this==&other){
            return *this;
        }
        delete[]arr;
        len=other.len;
        cap=other.cap;
        arr=new T[cap];
        for(int i=0;i<len;i++){
            arr[i]=other.arr[i];
        }
        return *this;
    }
    T &operator [](int index){
        if(!isvalid(index)){
             cout<<"out of bound"<<endl;
           return arr[0];
        }
        return arr[index];
    }
    const T &operator[](int index)const{
        if(!isvalid(index)){
             cout<<"out of bound"<<endl;
           return arr[0];
        }
        return arr[index];
    }
   bool operator==(const myvector&other)const{
       if(len!=other.len){
           return false;
       }
       for(int i=0;i<len;i++){
           if(arr[i]!=other.arr[i]){
               return false;
           }
       }
       return true;
   } 
   bool operator !=(const myvector &other)const{
       return !(*this==other);
   }
   myvector operator+(const myvector &other)const{
       myvector<T> newarr(len+other.len);
       for(int i=0;i<len;i++){
           newarr.push(arr[i]);
       }
       for(int i=0;i<other.len;i++){
           newarr.push(other.arr[i]);
       }
       return newarr;
   }
   myvector &operator+=(const myvector &other ){
       for(int i=0;i<other.len;i++){
           push(other.arr[i]);
       }
       return *this;
   }
   int size() const{
       return len;
   }
   int capacity()const{
       return cap;
   }
   bool empty()const{
       return len==0;
   }
   int find (const T &value)const{
       for(int i=0;i<len;i++){
           if(arr[i]==value){
               return i;
           }
       }
       return -1;
   }
   void swap (myvector &other ){
       T * temparr=arr;
       arr=other.arr;
       other.arr=temparr;
       int templen=len;
       len=other.len;
       other.len=templen;
       int tempcap=cap;
       cap=other.cap;
       other.cap=tempcap;
   }
     T* begin(){
        return arr;
    }
    T*end(){
        return arr+len;
    }
    const T *begin()const {
        return arr;
    }
    const T *end()const {
        return arr+len;
    }

   
};
#endif
