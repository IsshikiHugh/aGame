#ifndef __Map_Class__
#define __Map_Class__

#include <vector>
using std::vector;

#include "room.h"

class Map {
public:
    Map(){};
    ~Map(){};

    // push Room into map
    void pushGrid(Room r){ grid[r.getRoomUID()] = r; }
    // get the beginRoom
    Room &getBeginRoom(){ return grid[beginRoomUID]; }
    // get the nextRoom
    Room &getNextRoom(string currentUID,int dir){
        return grid[ grid[currentUID].getNextRoomUID(dir) ];
    }
    
private:
    string beginRoomUID;
    map< string , Room > grid;
};

#endif