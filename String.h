#include <iostream>
#ifndef STRING_H
#define STRING_H
using namespace std;
class String {
    private :
    int len;
    int cap;
    char *cs;
    int slength(const char *str)
    const ;
    void scopy(char *dest,const char *scr )
    const ;
    void sfill(char *str ,char c,int s);
    bool isspace(char c);
    bool ischar(char c,const char *ch)const ;
public:
    String ();
    String (const char *p);
    String (int s, char c);
    void replacef(char c);
     
    String (int num);
String itos(int num);
    

    String shallowc();
    String (const String &other);
    int stoi()
    const ;
    String &trim ();
    
    char operator[](int i)
    const ;
    char &operator[](int i);
    int findf(char ch)
    const;
 int findl(char ch)
    const;

   int *findall(char ch, int &count )
    const ;
    void removef(char c);
        
        void removel(char c);
    void removeall(char c);
    void print ()
    const ;
    void insertat(int i,char c);
        
    void insertat (int i,const String sub);
    bool isequal (const String &m);
    bool isless(const String &m);

    bool isgreat(const String &m);
    String *split(char ch ,int &count)
    const;
    String *tokenize(const char *ch,int &count)const;
    int * allsub(const char *sub,int &count)const;
    String concat(const String &s2) const ;
        String & append(const String &s2);
    void clear();
    void toupper();

       void tolower();

       String upper() const ;

       String lower()const ;

  
String &operator =(const String&other);
    ~String ();
const char*c_str()const;
int length()const;
};
istream& operator>>(istream &in, String &s);
ostream& operator<<(ostream& out ,const String &s);
bool operator==(const String &s,const char *cstr);
bool operator==(const char *cstr,const String &s);
bool operator!=(const String &s,const char *cstr);
bool operator!=(const char *cstr,const String &s);
String operator+(const String &s1 ,const String &s2);
String operator+(const String &s1,const char *s2);
String operator+(const char* s1,const String &s2);
bool operator==(const String&a,const String &b);
#endif
