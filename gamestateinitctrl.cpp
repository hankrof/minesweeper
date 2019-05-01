#include "gamestateinitctrl.h"
#include "gamestateplayingctrl.h"
#include "gamestatectrlctx.h"
#include "gameworldbuilder.h"
#include "mainwindow.h"
#include "envir.h"
namespace ms
{
    GameStateInitController::GameStateInitController
        (GameStateControllerContext *ctrl)
    {
        ImplStateController *data = new ImplStateController;
        data->_ctx = ctrl;
        data->_gameWorld  = GameWorldHardModeBuilder().buildMap().getResult();
        data->_envir      = std::shared_ptr<Environment>(new Environment());
        data->_mainWindow = std::shared_ptr<MainWindow>(new MainWindow(*ctrl));
        data->_mainWindow->show();
        _pImpl.reset(data);
        data->_mainWindow->initGameEnvir(data->_envir.get());
    }

    void GameStateInitController::processPaintEvent()
    {
        getMainWindow()->paintGameWorld(getGameWorld().get());
        setGameCtrl(new GameStatePlayingController(*this));
    }
}
