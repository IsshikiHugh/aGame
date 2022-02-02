#include "game.h"
#include "./utils/models.h"
#include "./utils/data_reader/dataReader.h"
#include "./utils/logger/logger.h"

QWQReader r;
Game g;
Logger log{};
Model model;

int main(){
    log.init();
    r.init("./data/index.qwq");
    g.init(r);
    g.gameOpener();
    log.close();
    return 0;
}