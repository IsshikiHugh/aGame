#include "game.h"
#include "./utils/models.h"
#include "./utils/data_reader/dataReader.h"

QWQReader r;
Game g;
Model model;



int main(){
    r.init("./data/index.qwq");
    g.init(r);
    g.gameOpener();
    return 0;
}