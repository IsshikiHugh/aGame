#include "player.h"

void Player::init(){
    string path = "./data/players/tot.lst";
    ifstream ist(path,std::ios::in);
    while(!ist.eof()){
        string newPlayer;
        ist >> newPlayer;
        if(!newPlayer.empty()){
            st.insert(newPlayer);
        }
    }
    ist.close();
}

void Player::save(){
    string path = "./data/players/";
    path += nickName;
    path += ".qwq";
    ofstream ost;
    ost.open(path,std::ios::out);
    ost << uid << endl;
    ost << nickName << endl;
    ost << tmpRoom << endl;
    ost.close();
}

void Player::load(){
    string path = "./data/players/";
    path += nickName;
    path += ".qwq";
    ifstream ist;
    ist.open(path,std::ios::in);
    string uid_S;
    ist >> uid_S >> nickName >> tmpRoom;
    uid = StrToULL(uid_S);
    ist.close();
}

void Player::update(PlayerModel &to){
    if(to.nickName != "Default"){
        nickName = to.nickName;
    }
    if(to.tmpRoom != "Default"){
        tmpRoom = to.tmpRoom;
    }
}

string Player::ULLToStr(unsigned long long x){
    string num;
    while(x){
        num.push_back(x%10);
        x /= 10;
    }
    string ret;
    for(auto it = num.rbegin();it != num.rend();++it){
        ret.push_back(*it);
    }
    return ret;
}

unsigned long long Player::StrToULL(string x){
    unsigned long long ret = 0;
    for(auto it = x.rbegin();it != x.rend();++it){
        ret = ret * 10 + (*it) - '0';
    }
    return ret;
}

bool Player::checkExit(string name){
    if(st.find(name) == st.end()){
        return false;
    } else {
        return true;
    }
}

void Player::set_(string name){
        nickName = name;
        if(st.find(name) == st.end()){
            st.insert(name);
            ofstream ost("./data/players/tot.lst",std::ios::out | std::ios::app);
            ost << name << endl;
            ost.close();
            createPlayer(name,m.getBeginRoomID());
        }
    }