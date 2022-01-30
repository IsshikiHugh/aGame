#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "game.h"
#include "utils/printController.h"

void Game::gameOpener(){
    vector<string> title{
        "##================================================================##",
        "[]     __        __   _                            _____          []",
        "[]     \\ \\      / /__| | ___ ___  _ __ ___   ___  |_   _|__       []",
        "[]      \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\   | |/ _ \\      []",
        "[]       \\ V  V /  __/ | (_| (_) | | | | | |  __/   | | (_) |     []",
        "[]        \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|   |_|\\___/      []",
        "[]                       ____                                     []",
        "[]                 __ _ / ___| __ _ _ __ ___   ___                []",
        "[]                / _` | |  _ / _` | '_ ` _ \\ / _ \\               []",
        "[]               | (_| | |_| | (_| | | | | | |  __/               []",
        "[]                \\__,_|\\____|\\__,_|_| |_| |_|\\___|     v0.1      []",
        "##================================================================##",
        " 〔Ė〕 It's a game named \"aGame\".",
        " 〔Ẕ〕 这是一个叫做\"aGame\"的游戏。",
        " 〔Ė〕 I made it only for fun. (lol)",
        " 〔Ė〕 写它可能只是因为......这很有趣？ (乐)",
        ""
    };
    for(int i = 0;i < title.size();++i){
        cout << tab << title[i] << "\n";
    }
}