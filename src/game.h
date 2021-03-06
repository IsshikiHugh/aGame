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
#include "./controllers/player.h"

using namespace printController;

extern QWQReader r;
extern Logger logs;
extern Player p;

class Game {
public:
    // C'tor
    Game();
    // D'tor
    ~Game();
    
    // Be used to initialized Game object with reader r.
    void init(QWQReader r);

    // Be used to try to replace {...} in string to certain things.
    vector<string> fillBlanks(string str);

    // Be used to deal the begin of the game.
    void gameOpener();

    // Be used to show title scenes.
    void showTitle();

    // Be used to show certain page in path and return the target option.
    string showPage(const string &target);
    // Be used to goto certain page in path.
    void gotoPage(const string &target);
    // Print usable options according to optionModel m    
    void showOption(const string &target);
    // Deal options according to optionModel m    
    void dealOption(const string &target);
    // deal map page
    void showMap();
    // run the map
    void mapRunner();
private:
    string lang;

    string gameVersion{"0.1"};
    vector<string> authors;
    string lastUpdateTime{"2077.1.1"};
    string githubLink{"404 NOT FOUND"};
    vector<string> description;

    string mainIDX;
    string optionIDX;
    string pagesIDX;

    // string nextType{""};
    // string nextPath{""};
};


#endif