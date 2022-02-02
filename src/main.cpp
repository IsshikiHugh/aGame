#include "game.h"
#include "./utils/models.h"
#include "./utils/data_reader/dataReader.h"
#include "./utils/logger/logger.h"
#include "./utils/printController.h"

QWQReader r;
Game g;
Logger log{};
Model model;

int main(){
    printController::zhInit();
    log.init();
    r.init("./data/index.qwq");
    g.init(r);
    g.gameOpener();
    log.close();
    return 0;
}