#include "game.h"

Game::Game(){
    // TODO: read config file

}

Game::~Game(){}

void Game::init(QWQReader r){
    auto t = ( ( r.getStaticData() ).getTag("Base") );
    this->gameVersion = t["game_version"].front();
    this->authors = t["author"];
    this->lastUpdateTime = t["update_time"].front();
    this->githubLink = t["github"].front();
    this->discription = t["discription"];

    logs.info("Game object initialized sucessfully.");
}

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
    
    // TODO: Make things below more tiddy.
    string moreMsg("  #  Version : ");
    moreMsg.append(this->gameVersion);
    msg.push_back(moreMsg);
    
    moreMsg = "  #  Last Update : ";
    moreMsg.append(this->lastUpdateTime);
    msg.push_back(moreMsg);


    // TODO: move it into option.
    moreMsg = "  #  Authors : ";
    for(auto it = this->authors.begin();it != this->authors.end();++it){
        if(it != this->authors.begin()){
            moreMsg = "               ";
        }
        moreMsg.append(*it);
        msg.push_back(moreMsg);
    }

    printAll(msg);

    //logger example
    logs.trace("trace");
    logs.debug("debug");
    logs.warn("warn");
    logs.info("info");
    logs.error("error");
    logs.fatal("fatal");
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