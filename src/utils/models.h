#ifndef __Models__
#define __Models__

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

#include "./printController.h"
#include "./logger/logger.h"

extern Logger logs;

//==============================================================================//

struct optionModel{
    string desZh;
    string desEn;
    string button;
    string level;
    string type;
    string targetPage;
};
struct pageLineModel{
    vector<string> desZh;
    vector<string> desEn;
};

struct recorderModel {
    recorderModel(){}
    virtual ~recorderModel(){}

    map< string , vector<string> > &getTag(string tag);
    vector<string> &getVal(string tag , string key);

    void init(map < string , map < string , vector<string> > > &dic);
    // [tag][key][v:val]
    map< string , map < string , vector<string> > > dic;
    string typeName;
};

class optionsModel {
public:
    optionsModel(){}
    virtual ~optionsModel(){}

    void set(recorderModel aimRecorder);

    const vector< optionModel > &getOptions();
private:
    vector< optionModel > options;
};

class pagesModel{
public:
    pagesModel(){}
    virtual ~pagesModel(){}

    void set(recorderModel aimRecorder);

    const vector< pageLineModel > &getPage();
    const string &getOptions();
private:
    vector< pageLineModel > pageMsgs;
    string optionsName;
};

//==============================================================================//

#endif
