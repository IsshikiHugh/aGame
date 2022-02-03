#ifndef __Models__
#define __Models__

#include <iostream>
#include <string>
#include <map>

using namespace std;

#include "./data_reader/dataReader.h"
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

class optionsModel {
public:
    optionsModel(){}
    virtual ~optionsModel(){}

    void set(QWQRecorder aimRecorder);

    const vector< optionModel > &getOptions();
private:
    vector< optionModel > options;
};


//==============================================================================//

#endif
