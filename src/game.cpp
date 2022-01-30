#include "game.h"

Game::Game(){
    // TODO: read config file

}

Game::~Game(){}

void Game::showTitle(){
    vector<string> msg{
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
        "[]                \\__,_|\\____|\\__,_|_| |_| |_|\\___|               []",
        "##================================================================##",
        " 〔Ė〕 It's a game named \"aGame\".",
        " 〔Ẕ〕 这是一个叫做\"aGame\"的游戏。",
        " 〔Ė〕 I made it only for fun. (lol)",
        " 〔Ẕ〕 写它可能只是因为......这很有趣？ (乐)",
        ""
    };
    string versionMsg("  #  Version : ");
    versionMsg.append(this->gameVersion);
    msg.push_back(versionMsg);
    printAll(msg);
    return;
}

void Game::showOption(OptionModel m){

} 

bool Game::dealOption(OptionModel m){
    bool ret = false;


    return ret;
}

void Game::gameOpener(){

    showTitle();
    while(true){
        showOption( model.openerOption() );
        if( dealOption( model.openerOption() ) ) break;
    }

}