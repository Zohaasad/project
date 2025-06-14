#include<iostream>
#include"logger.h"
#include"String.h"
#include<ctime>
#include<fstream>
using namespace std;

     logger & logger::getInstance(){
        static logger instance;
        return instance;
    }
    void logger::initialize(const String & filename ){
        if(log_file_.is_open()){
            cout<<"logger is already initialized "<<endl;
            return ;
        }
        log_file_.open(filename.c_str(),ios::out );
        if(!log_file_){
            cout<<"failed to open "<<filename<<endl;
            exit(EXIT_FAILURE);
        }
    }
    void logger::cleanup(){
        if(log_file_.is_open()){
            log_file_.close();
        }
    }
    void logger::writeerror(const String & error_message){
        if(!log_file_.is_open()){
            cout<<"logger is not initialized"<<endl;
           exit(EXIT_FAILURE);
        }
        time_t now =time(nullptr);
        tm* local_time=localtime(&now);
        char timestamp[20];
        strftime(timestamp,sizeof(timestamp),"%Y-%m-%d %H:%M:%S",local_time);
        
        log_file_<<"["<<timestamp<<"] error" <<error_message<<endl;
    }
    

   
     

logger::logger(){}
logger::~logger(){}
