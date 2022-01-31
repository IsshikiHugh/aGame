#include "game.h"
#include "./utils/models.h"
#include "./utils/data_reader/dataReader.h"

QWQReader r;
Game g;
Model model;



int main(){
    dealReader(r.init("./data/index.qwq"));
    g.gameOpener();
    return 0;
}