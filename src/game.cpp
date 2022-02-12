#include "game.h"

Game::Game(){
}

Game::~Game(){}

void Game::init(QWQReader r){
    auto t = ( ( r.getRecorder("static") ).getTag("Base") );
    this->lang = t["language"].front();
    this->gameVersion = t["game_version"].front();
    this->authors = t["author"];
    this->lastUpdateTime = t["update_time"].front();
    this->githubLink = t["github"].front();
    this->description = t["description"];

    

    logs.info("Game object initialized sucessfully.");
}

vector<string> Game::fillBlanks(string str){
    logs.info("fill blanks begin");
    vector<string> ret{"NULL"};

    // pre 
    if(str[0] != '{'){
        logs.info("fill blanks end because no need");
        return ret;
    }

    string pre,suf;
    stringstream st;
    st << str;
    st >> pre >> suf;
    suf = suf.substr(1,suf.size()-2);

    // special
    if(pre == "{.game_version}"){
        ret.push_back(gameVersion);
    } else if(pre == "{.update_time}"){
        ret.push_back(lastUpdateTime);
    } else if(pre == "{.github}"){
        ret.push_back(githubLink);
    } else if(pre == "{.space}"){
        ret.push_back(" ");
    } else if(pre == "{.authors}"){
        for(auto it = authors.begin();it != authors.end();++it){
            string ss{""};
            if(it != authors.begin()){
                ss.append(suf).append(*it);
            } else {
                ss.append(*it);
            }
            ret.push_back(ss);
        }
    } else if(pre == "{.description}"){
        for(auto it = description.begin();it != description.end();++it){
            string ss{""};
            if(it != description.begin()){
                ss.append(suf).append(*it);
            } else {
                ss.append(*it);
            }
            ret.push_back(ss);
        }
    } else if(pre == "{.players}"){
        ifstream ist;
        ist.open("./data/players/tot.lst"); 
        bool isFirst = true;
        string ss;
        ist >> ss;
        while(!ist.eof()){
            if(!isFirst){
                ss = suf + ss;
            } 
            isFirst = false;
            ret.push_back(ss);
            ist >> ss;
        }
        ist.close();
    }else {
        ret.front() = "NULL";
    }
    logs.info("fill blanks end with size = " + IntToStr(ret.size()) );
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

    printAll(msg);
    return;
}

string Game::showPage(const string &target){
    logs.info("show page");
    string targetOption;
    vector<string> msg_ori;
    const vector<pageLineModel> &curPage = (r.getPage(target)).getPage();
    targetOption = (r.getPage(target)).getOptions();
    for(auto it = curPage.begin();it != curPage.end();++it){
        vector<string> oriLine;
        if(lang == "zh"){
            oriLine = (*it).desZh;
        } else {
            oriLine = (*it).desEn;
        }

        string newLine{""};
        for(auto ll = oriLine.begin();ll != oriLine.end();++ll){
            vector<string> fillMsg = fillBlanks(*ll);
            if(fillMsg.size() == 1){
                newLine.append(*ll);
            } else {
                for(auto f = fillMsg.begin()+1;f != fillMsg.end();++f){
                    newLine.append(*f);
                }
            }
        }
        if(!newLine.empty()) msg_ori.push_back(newLine);
    }
    vector<string> msg = generateIntoFrame(msg_ori);
    printAll(msg);
    return targetOption;
}

void Game::gotoPage(const string &target){
    string targetName;
    clearScreen();
    targetName = showPage(target);
    logs.debug("page target = " + targetName);
    showOption( targetName );
    dealOption( targetName );
    return;
}

void Game::showOption(const string &target){
    vector<string> msg_ori;
    const vector<optionModel> &curOptions = (r.getOptions(target)).getOptions();
    logs.info("find cur " + target + " 's size = " + IntToStr(curOptions.size()));
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

void Game::dealOption(const string &target){
    logs.info("dealOption begin");
    string str{""};
    string nextType{""};
    string nextPath{""};
    bool valid=false;
    cout << "请输入目标选项关键字：\n";
    cin >> str;
    logs.debug("str:"+str);
    const vector<optionModel> &curOptions = (r.getOptions(target)).getOptions();
    for(auto it = curOptions.begin();it != curOptions.end();++it){
        if((*it).button.compare(str)==0){
            nextType = (*it).type;
            nextPath = (*it).targetPage;
            valid = true;
            break;
        }
    }
    if(!valid){
        if(lang=="zh") cout << "这是个无效的选项！请重试！\n";
        else cout << "Invalid option! Please try again.\n";
        dealOption(target);
        return;
    }


    if(nextType == "page"){
        logs.debug("now goto page " + target);
        gotoPage(nextPath);
    } else if(nextType == "exit"){
        exit(0);
    } else if(nextType == "options"){
        showOption(nextPath);
    } else if(nextType == "initialMenuPage"){
        gameOpener();
    } else if(nextType == "createCharacter"){
        string name;
        cin >> name;
        bool ex = p.checkExit(name);
        if(ex){
            if(lang == "zh"){
                cout << "你不能创建一个已有的角色！请重试！" << endl;
            } else {
                cout << "You can't create a existed character!Please try again!" << endl;
            }
            dealOption(target);
        }
        p.set_(name);
        p.load();
        mapRunner();
    } else if(nextType == "loadCharacter"){
        string name;
        cin >> name;
        bool ex = p.checkExit(name);
        if(!ex){
            if(lang == "zh"){
                cout << "你不能载入一个不存在的角色！请重试！" << endl;
            } else {
                cout << "You can't load a unexisted character!Please try again!" << endl;
            }
            dealOption(target);
        }
        p.set_(name);
        p.load();
        mapRunner();
    }

    cin.clear();
    cin.sync();

    logs.info("dealOption end");
}

void Game::gameOpener(){
    clearScreen();
    showTitle();
    showOption( "initial_menu" );
    dealOption( "initial_menu" );
}

void Game::mapRunner(){
    showMap();
    vector<string> msg_ori;
    string ele = "「go」";
    if(lang == "zh"){
        ele += "移动";
    } else {
        ele += "move";
    }
    msg_ori.push_back(ele);
    ele = "「quit」";
    if(lang == "zh"){
        ele += "退出";
    } else {
        ele += "exit";
    }
    msg_ori.push_back(ele);
    vector<string> msg = generateIntoFrame(msg_ori);
    printAll(msg);

_goto_mapDealOption:

    string readin;
    cin >> readin;
    if(readin == "go"){
        string dir;
        cin >> dir;
        int dirN;
        if(dir == "North" || dir == "north" || dir == "n"){
            dirN = 0;
        } else if(dir == "East" || dir == "east" || dir == "e"){
            dirN = 1;
        } else if(dir == "South" || dir == "south" || dir == "s"){
            dirN = 2;
        } else if(dir == "West" || dir == "west" || dir == "w"){
            dirN = 3;
        } else {
            goto _goto_mapErrorGo_;
        }
        PlayerModel updataP;
        updataP.tmpRoom = m.getNextRoom( p.getTmpRoom() , dirN ).getRoomUID();
        if(updataP.tmpRoom.empty()){
            goto _goto_mapErrorGo_;
        }
        p.update(updataP);
        logs.debug("ok!");
        mapRunner();
        return;
    } else if(readin == "quit") {
        exit(0);
    } else {
_goto_mapErrorGo_:
        if(lang=="zh") cout << "这是个无效的选项！请重试！\n";
        else cout << "Invalid option! Please try again.\n";
        cin.clear();
        cin.sync();
        goto _goto_mapDealOption;
    }

}

void Game::showMap(){
    vector< string > msg_ori;
    string ele;
    if(lang == "zh"){
        ele = "您当前所在的房间为：";
    } else {
        ele = "You are at: ";
    }
    string tmpID = p.getTmpRoom();
    msg_ori.push_back(ele + m.getRoomNameByID(tmpID));
    for(int i = 0;i < 4;++i){
        if(!m.haveNextRoom(tmpID,i)){
            continue;
        }
        Room &nextRoom = m.getNextRoom(tmpID,i);
        switch(i){
            case 0: ele = " [North] : " + nextRoom.getRoomName();
                break;
            case 1: ele = "  [East] : " + nextRoom.getRoomName();
                break;
            case 2: ele = " [South] : " + nextRoom.getRoomName();
                break;
            case 3: ele = "  [West] : " + nextRoom.getRoomName();
                break;
        }
        msg_ori.push_back(ele);
    }
    if(lang == "zh"){
        ele = "使用[ go <方向> ]来移动。";
    } else {
        ele = "Use[ go <direction> ]to move.";
    }
    msg_ori.push_back(ele);
    ele = "eg: go n";
    msg_ori.push_back(ele);
    ele = "eg: go north";
    msg_ori.push_back(ele);
    ele = "eg: go North";
    msg_ori.push_back(ele);
    vector<string> msg = generateIntoFrame(msg_ori);
    printAll(msg);
}
