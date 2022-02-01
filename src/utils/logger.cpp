#include "logger.h"

using namespace std;

int Logger::init(){
    return init("latest.log");
}

int Logger::init(string filename){
    this->hout = GetStdHandle(STD_OUTPUT_HANDLE);
    this->log.open(filename,ios::out | ios::trunc);
    if(!this->log.is_open()){
        printWithColor(5,"[ERROR]","Error when opening the log file.");
        return -1;
    }
    return 0;
}

void Logger::trace(string msg){
    string str="[TRACE]";
    printWithColor(1,str,msg);
    str.append(msg);
    writetoLog(str);
}

void Logger::debug(string msg){
    string str="[DEBUG]";
    printWithColor(2,str,msg);
    str.append(msg);
    writetoLog(str);
}

void Logger::info(string msg){
    string str="[INFO]";
    printWithColor(3,str,msg);
    str.append(msg);
    writetoLog(str);
} 

void Logger::warn(string msg){
    string str="[WARNING]";
    printWithColor(4,str,msg);
    str.append(msg);
    writetoLog(str);
}

void Logger::error(string msg){
    string str="[ERROR]";
    printWithColor(5,str,msg);
    str.append(msg);
    writetoLog(str);
}

void Logger::fatal(string msg){
    fatal(msg,0);
}

void Logger::fatal(string msg,int code){
    string str="[FATAL]";
    printWithColor(6,str,msg);
    str.append(msg);
    writetoLog(str);
    this->log.close();
    exit(code);
}

void Logger::printWithColor(int type,string prefix,string msg){
    switch(type){
        case 1://Trace
            SetConsoleTextAttribute(this->hout,FOREGROUND_WHITE);break;
        case 2://Debug
            SetConsoleTextAttribute(this->hout,FOREGROUND_PINK | FOREGROUND_INTENSITY);break;
        case 3://Info
            SetConsoleTextAttribute(this->hout,FOREGROUND_INDIGO | FOREGROUND_INTENSITY);break;
        case 4://Warn
            SetConsoleTextAttribute(this->hout,FOREGROUND_YELLOW | FOREGROUND_INTENSITY);break;
        case 5://Error
            SetConsoleTextAttribute(this->hout,FOREGROUND_RED | FOREGROUND_INTENSITY);break;
        case 6://Fatal
            SetConsoleTextAttribute(this->hout,FOREGROUND_WHITE | BACKGROUND_RED | FOREGROUND_INTENSITY);break;
        default:
            break;
    }
    cout<<prefix;
    SetConsoleTextAttribute(this->hout,FOREGROUND_WHITE | FOREGROUND_INTENSITY);
    cout<<" "<<msg<<endl; 
}

void Logger::writetoLog(string msg){
    this->log << msg <<endl;
}

void Logger::close(){
    this->log.close();
}