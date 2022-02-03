#include "logger.h"

using namespace std;

int Logger::init(){
    return init(getTimeStr()+".log");
    
}

int Logger::init(string filename){
    this->log.open("./logs/"+filename,ios::out);
    if(!this->log.is_open()){
        printWithColor(5,"[ERROR]","Error when opening the log file. Please check if the ./logs dir has been created.");
        return -1;
    }
    return 0;
}

string Logger::getTimeStr(){
    string res="";
    time_t now=time(0);
    tm *ltm=localtime(&now);
    cout<<"year:"<<ltm->tm_year;
    res.append(to_string(1900 + ltm->tm_year)+"-")
        .append(to_string(1 + ltm->tm_mon)+"-")
        .append(to_string(ltm->tm_mday)+"_")
        .append(to_string(ltm->tm_hour)+"-")
        .append(to_string(ltm->tm_min)+"-")
        .append(to_string(ltm->tm_sec));
    return res;
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
    string str="[WARN]";
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

// TODO: Put prefix into the function.
void Logger::printWithColor(int type,string prefix,string msg){
    if(!display) return;
    /*
        F       B
        30      40      黑色
        31      41      红色
        32      42      绿色
        33      43      黄色
        34      44      蓝色
        35      45      紫色
        36      46      青蓝色
        37      47      白色
        几种特殊'颜色'：
        0     OFF
        1     高亮显示
        4     underline
        5     闪烁
        7     反显
        8     消隐（不可见）
    */
    string s1;
    switch(type){
        case 1://Trace
            s1="\e[37;1m";break;
        case 2://Debug
            s1="\e[35;40m";break;
        case 3://Info
            s1="\e[36;40m";break;
        case 4://Warn
            s1="\e[33;40m";break;
        case 5://Error
            s1="\e[31;40m";break;
        case 6://Fatal
            s1="\e[37;41m";break;
        default:
            break;
    }
    s1.append(prefix).append("\e[0m");
    cout << s1;
    cout << " " << msg << endl; 
}

void Logger::writetoLog(string msg){
    this->log << msg <<endl;
}

void Logger::close(){
    this->log.close();
}