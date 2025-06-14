#include<iostream>
#ifndef LOGGER_H
#define LOGGER_H
using namespace std;
#include"String.h"
#include<fstream>

class logger{
    public:
    static logger & getInstance();
    void initialize(const String & filename );
      
        
    void cleanup();
    void writeerror(const String & error_message);
    

    logger (const logger &)=delete;
    logger &operator=(const logger &)=delete;
     
private:
logger();
~logger();
ofstream log_file_;
};
#endif
