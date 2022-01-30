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

extern Model model;

class Game {
public:
    // C'tor
    Game();
    // D'tor
    ~Game();
    
    // Be used to deal the begin of the game.
    void gameOpener();

    void showTitle();

    // Print usable options according to optionModel m    
    void showOption(const OptionModel m);
    // Deal options according to optionModel m    
    bool dealOption(const OptionModel m);
private:
    string gameVersion;
};


#endif