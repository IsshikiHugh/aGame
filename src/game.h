#ifndef __Game_Class__
#define __Game_Class__

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "./utils/printController.h"
#include "./utils/models.h"
#include "./utils/logger/logger.h"
#include "./utils/data_reader/dataReader.h"

using namespace printController;

extern QWQReader r;
extern Logger logs;

class Game {
public:
    // C'tor
    Game();
    // D'tor
    ~Game();
    
    // Be used to initialized Game object with reader r.
    void init(QWQReader r);

    // Be used to try to replace {...} in string to certain things.
    string fillBlank(string str);

    // Be used to deal the begin of the game.
    void gameOpener();

    // Be used to show title scenes.
    void showTitle();

    // Be used to show certain page in path.
    void showPage(string path);
    // Print usable options according to optionModel m    
    void showOption(const string &target);
    // Deal options according to optionModel m    
    void dealOption(const string &target);
private:
    string lang;

    string gameVersion{"0.1"};
    vector<string> authors;
    string lastUpdateTime{"2077.1.1"};
    string githubLink{"404 NOT FOUND"};
    vector<string> discription;

    string mainIDX;
    string optionIDX;
    string pagesIDX;

    string nextType{""};
    string nextPath{""};
};


#endif