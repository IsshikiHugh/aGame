#include "game.h"

Game::Game(){
    // TODO: read config file

}

Game::~Game(){}

void Game::init(QWQReader r){
    auto t = ( ( r.getRecorder("static") ).getTag("Base") );
    this->lang = t["language"].front();
    this->gameVersion = t["game_version"].front();
    this->authors = t["author"];
    this->lastUpdateTime = t["update_time"].front();
    this->githubLink = t["github"].front();
    this->discription = t["discription"];


    logs.info("Game object initialized sucessfully.");
}

string Game::fillBlank(string str){
    string ret{"NULL"};

    // pre 
    if(str[0] != '{'){
        return ret;
    }

    // special
    if(str == "{.game_version}"){
        ret = gameVersion;
    } else if(str == "{.update_time}"){
        ret = lastUpdateTime;
    } else if(str == "{.github}"){
        ret = githubLink;
    } else {
        ret = "NULL";
    }
    return ret;
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
    
    /*
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
    }*/

    printAll(msg);
    return;
}

void showPage(string path){

}

void Game::showOption(const string &target){
    vector<string> msg_ori;
    const vector<optionModel> &curOptions = (r.getOptions(target)).getOptions();
    for(auto it = curOptions.begin();it != curOptions.end();++it){
        string newMsg{"「"};
        newMsg.append( (*it).button ).append("」");
        if(lang == "zh"){
            newMsg.append( (*it).desZh );
        } else {
            newMsg.append( (*it).desEn );
        }
        msg_ori.push_back(newMsg);
    }
    vector<string> msg = generateIntoFrame(msg_ori);
    printAll(msg);  
} 

bool Game::dealOption(const string &target){
    bool ret = false;
    string str;
    cin >> str;
    // remember to deal the 

    return ret;
}

void Game::gameOpener(){

    showTitle();
    while(true){
        showOption( "initial_menu" );
        if( dealOption( "initial_menu" ) ) break;
    }

}