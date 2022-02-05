#ifndef __QWQ_Reader__
#define __QWQ_Reader__

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "./../logger/logger.h"

extern Logger logs;

using namespace std;

// Base class for other recorder.
struct QWQRecorder {
    QWQRecorder(){}
    virtual ~QWQRecorder(){}

    map< string , vector<string> > &getTag(string tag);
    vector<string> &getVal(string tag , string key);

    void init(map < string , map < string , vector<string> > > &dic);
    // [tag][key][v:val]
    map< string , map < string , vector<string> > > dic;
    string typeName;
};


#include "./../models.h"

// Be used to analyze the data in the .qwq file.
class QWQAnalyzer : public QWQRecorder {
public:
    QWQAnalyzer(){}
    QWQAnalyzer(string p) : path(p){}
    virtual ~QWQAnalyzer(){}

    // Return 1 while nothing wrong.
    // Return 0 while there is something wrong with file.
    // Return -1 while file doesn't exist. 
    int analyze();
private:
    string path;
};

// Be used to manage the data read in.
class QWQReader {
public:
    QWQReader(){};
    ~QWQReader(){};

    // Initialize reader with index file in the path.
    // Return 1 while nothing wrong.
    // Return 0 while there is something wrong with file.
    // Return -1 while file doesn't exist.  
    int init(string path);

    // Be used to deal Error Code.
    void dealReader(int code);

    QWQRecorder &getRecorder(string name);
    optionsModel &getOptions(string name);
    pagesModel &getPage(string name);
private:
    // TODO: Make it more "OOP\n".
    // QWQRecorder staticData;                 // Basic information of game.
    // QWQRecorder archiveData;                // Data of player.
    // QWQRecorder itemDictionary;             // Dictionary of items.
    // QWQRecorder monsterDictionary;          // Dictionary of monster.
    // QWQRecorder npcDictionary;              // Dictionary of npc.
    // QWQRecorder roomDictionary;             // Dictionary of room.
    map< string , QWQRecorder > data;
    map< string , optionsModel > options;
    map< string , pagesModel > page;

    string mainIDX;
    string optionsIDX;
    string pagesIDX;
    string playersIDX;
};

#endif