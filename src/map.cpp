#include "map.h"

bool Map::checkError(){
    if(beginRoomUID.empty()){
        return true;
    }
    return false;
}

void Map::makeMap(vector<Room> rooms){ 
    for(auto it = rooms.begin();it != rooms.end();++it){
        pushGrid(*it);
        if((*it).isBegin()){
            beginRoomUID = (*it).getRoomUID();
        }
    }
}