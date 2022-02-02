#include "logger.h"

using namespace std;

int Logger::init(){
    return init(getTimeStr()+".log");
}

int Logger::init(string filename){
    this->log.open("./logs/"+filename,ios::out);
    if(!this->log.is_open()){
        printWithColor(5,"Error when opening the log file. Please check if the ./logs dir has been created.");
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
    printWithColor(1,msg);
    writetoLog("[TRACE] "+msg);
}

void Logger::debug(string msg){
    printWithColor(2,msg);
    writetoLog("[DEBUG] "+msg);
}

void Logger::info(string msg){
    printWithColor(3,msg);
    writetoLog("[INFO] "+msg);
} 

void Logger::warn(string msg){
    printWithColor(4,msg);
    writetoLog("[WARN] "+msg);
}

void Logger::error(string msg){
    printWithColor(5,msg);
    writetoLog("[ERROR] "+msg);
}

void Logger::fatal(string msg){
    fatal(msg,0);
}

void Logger::fatal(string msg,int code){
    printWithColor(6,msg);
    writetoLog("[FATAL] "+msg);
    this->log.close();
    exit(code);
}

void Logger::printWithColor(int type,string msg){
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
            s1="\e[37;1m[TRACE]";break;
        case 2://Debug
            s1="\e[35;40m[DEBUG]";break;
        case 3://Info
            s1="\e[36;40m[INFO]";break;
        case 4://Warn
            s1="\e[33;40m[WARN]";break;
        case 5://Error
            s1="\e[31;40m[ERROR]";break;
        case 6://Fatal
            s1="\e[37;41m[FATAL]";break;
        default:
            break;
    }
    s1.append("\e[0m");
    cout<<s1;
    cout<<" "<<msg<<endl; 
}

void Logger::writetoLog(string msg){
    this->log << msg <<endl;
}

void Logger::close(){
    this->log.close();
}