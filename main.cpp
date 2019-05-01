#include "gamestatectrlctx.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::unique_ptr<ms::GameStateControllerContext> controller
            (new ms::GameStateControllerContext());
    return a.exec();
}
