#ifndef __Room_Class__
#define __Room_Class__

#include <string>
#include <map>
#include <vector>
using std::string;
using std::map;
using std::vector;
#include "./utils/logger/logger.h"

extern Logger logs;

class Room{
public:
    Room(){}
    ~Room(){}

    virtual void set(string uid,map< string , vector<string> > r);

    // 0 North
    // 1 East                0
    // 2 Sourth           4     1
    // 3 West                3
    // return the uid of the next room in certain direction
    string &getNextRoomUID(int dir);

    string &getRoomUID(){ return roomUID; }

    bool isBegin(){ return isBeginRoom; }
private:
    // set the next room of thisRoom in certain direction as thatRoom
    void linkToRoom(string thatUID,int dir);

    bool isBeginRoom = false;

    string roomName;
    string roomUID;

    // 0 North
    // 1 East                0
    // 2 Sourth           4     1
    // 3 West                3
    string exitUID[4];
    string type;
};










#endif