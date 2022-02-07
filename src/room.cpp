#include "room.h"

void Room::set(string uid,map< string , vector<string> > r){
    roomUID = uid;
    roomName = r["name"].front();
    for(int d = 0;d <= 3;++d){
        exitUID[d] = r["room"][d];
    }
    type = r["type"].front();
}


string &Room::getNextRoomUID(int dir){
    return exitUID[dir];
}

void Room::linkToRoom(string thatUID,int dir){
    exitUID[dir] = thatUID;
}
