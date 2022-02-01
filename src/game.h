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
#include "./utils/logger.h"
#include "./utils/data_reader/dataReader.h"

using namespace printController;

extern Logger log;
extern Model model;
// extern QWQReader r;

class Game {
public:
    // C'tor
    Game();
    // D'tor
    ~Game();
    
    // Be used to initialized Game object with reader r.
    void init(QWQReader r);

    // Be used to deal the begin of the game.
    void gameOpener();

    // Be used to show title scenes.
    void showTitle();

    // Print usable options according to optionModel m    
    void showOption(const OptionModel m);
    // Deal options according to optionModel m    
    bool dealOption(const OptionModel m);
private:
    string gameVersion{"0.1"};
    vector<string> authors;
    string lastUpdateTime{"2077.1.1"};
    string githubLink{"404 NOT FOUND"};
    vector<string> discription;
};


#endif