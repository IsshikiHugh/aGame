#ifndef __Logger__
#define __Logger__

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class Logger{
public:
    Logger(){};
    ~Logger(){};
    //Initialize logger with the default log file name("latest.log").
    int init();

    //Initialize logger with the customized log file name.
    int init(string filename);

    void trace(string msg);

    void debug(string msg);

    void info(string msg);

    void warn(string msg);

    void error(string msg);

    //Inform the message and exit the program with code 0.
    void fatal(string msg);

    //Inform the message and exit the program with the customized code.
    void fatal(string msg , int code);

    //Close the file stream.
    void close();

private:
    ofstream log;

    //Return a string in the format of "YYYY-MM-hour-min-sec"
    string getTimeStr();

    //Print a message with the format of the type.
    //Type:
    //1 : Trace
    //2 : Debug
    //3 : Info
    //4 : Warn
    //5 : Error
    //6 : Fatal
    void printWithColor(int type,string msg);
    
    //Write the message to the log file.
    void writetoLog(string msg);
};

#endif
