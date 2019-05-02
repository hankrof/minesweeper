#include "gamestatewinningctrl.h"
#include "mainwindow.h"
namespace ms
{
    GameStateWinningController::GameStateWinningController(GameStateController &ctrl)
        : GameStateController(ctrl)
    {
        getMainWindow()->execWinningResult();
    }
}
