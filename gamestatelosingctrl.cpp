#include "gamestatelosingctrl.h"
#include "mainwindow.h"
namespace ms
{
    GameStateLosingController::GameStateLosingController(GameStateController& ctrl)
        : GameStateController(ctrl)
    {
        getMainWindow()->execLosingResult();
    }
}
