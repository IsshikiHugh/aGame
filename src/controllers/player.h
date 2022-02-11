#ifndef __Player_Class__
#define __Player_Class__

#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

#include "./../map.h"

extern Map m;

struct PlayerModel{
    string nickName = "Default";
    string tmpRoom = "Default";
};

class Player{
public:
    Player(){}
    ~Player(){}

    void init();
    // write data
    void save();
    // read data
    void load();
    // update data
    void update(PlayerModel &to);

    bool checkExit(string name){
        if(st.find(name) == st.end()){
            return false;
        } else {
            return true;
        }
    }

    void set_(string name){
        nickName = name;
        if(st.find(name) == st.end()){
            st.insert(name);
            ofstream ost("./data/players/tot.lst",std::ios::out | std::ios::app);
            ost << name << endl;
            ost.close();
            createPlayer(name,m.getBeginRoomID());
        }
    }

private:
    unsigned long long uid;
    string nickName;
    string tmpRoom;
    std::set<string> st;
    unsigned long long nextUID = 0;

    string ULLToStr(unsigned long long x);
    unsigned long long StrToULL(string x);

    // create a player
    unsigned long long createPlayer(string nickName,string tmpRoom){
        this->nickName = nickName;
        this->tmpRoom = tmpRoom;
        save();
        return nextUID++;
    }

};


#endif