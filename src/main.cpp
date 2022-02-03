#include "./game.h"
#include "./utils/logger/logger.h"
#include "./utils/printController.h"
#include "./utils/data_reader/dataReader.h"

QWQReader r;
Game g;
Logger logs;

int main(){
    // printController::zhInit(); // Not necessarrily.
    logs.init();
    r.init("./data/index.qwq");
    g.init(r);
    g.gameOpener();
    logs.close();
    return 0;
}