#ifndef __Map_Class__
#define __Map_Class__

#include <vector>
using std::vector;

#include "room.h"

class Map {
public:
    Map(){};
    ~Map(){};

    // to make the map
    void makeMap(vector<Room> rooms);
    // push Room into map
    void pushGrid(Room r){ grid[r.getRoomUID()] = r; }
    // chek error
    bool checkError();
    // get the beginRoom
    Room &getBeginRoom(){ return grid[beginRoomUID]; }
    // check have next room
    bool haveNextRoom(string currentUID,int dir){
        logs.debug(grid[currentUID].getNextRoomUID(dir));
        return !(grid[currentUID].getNextRoomUID(dir) == "NULL");
    }
    // get the nextRoom
    Room &getNextRoom(string currentUID,int dir){
        return grid[ grid[currentUID].getNextRoomUID(dir) ];
    }
    string &getBeginRoomID(){
        return beginRoomUID;
    }

    string &getRoomNameByID(string id){
        return grid[id].getRoomName();
    }
    
private:
    string beginRoomUID;
    map< string , Room > grid;
};

#endif