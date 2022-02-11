#include "room.h"

void Room::set(string uid,map< string , vector<string> > r){
    roomUID = uid;
    roomName = r["name"].front();
    logs.debug("here!" + roomName);
    for(int d = 0;d <= 3;++d){
        exitUID[d] = r["exit"][d];
    }
    type = r["type"].front();
    if(type == "beginRoom"){
        isBeginRoom = true;
    }
}


string &Room::getNextRoomUID(int dir){
    return exitUID[dir];
}

void Room::linkToRoom(string thatUID,int dir){
    exitUID[dir] = thatUID;
}
