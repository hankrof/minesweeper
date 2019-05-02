#include "gamestateinitctrl.h"
#include "gamestateplayingctrl.h"
#include "gamestatectrlctx.h"
#include "gameworldbuilder.h"
#include "mainwindow.h"
#include "envir.h"
#include <QMouseEvent>
namespace ms
{
    GameStateInitController::GameStateInitController
        (GameStateControllerContext *ctrl)
    {
        ImplStateController *data = new ImplStateController;
        data->_ctx = ctrl;
        data->_gameWorld  = GameWorldEmptyBuilder().buildMap().getResult();
        data->_envir      = std::shared_ptr<Environment>(new Environment());
        data->_mainWindow = std::shared_ptr<MainWindow>(new MainWindow(*ctrl));
        data->_startPosition = nullptr;
        data->_mainWindow->show();
        _pImpl.reset(data);
        data->_mainWindow->initGameEnvir(data->_envir.get());
    }

    GameStateInitController::GameStateInitController(GameStateController& ctrl)
        : GameStateController(ctrl)
    {
        _pImpl->_gameWorld  = GameWorldEmptyBuilder().buildMap().getResult();
        _pImpl->_envir      = std::shared_ptr<Environment>(new Environment());
        _pImpl->_startPosition = nullptr;
        _pImpl->_mainWindow->initGameEnvir(getEnvironment().get());
    }

    void GameStateInitController::processPaintEvent()
    {
        getMainWindow()->paintGameWorld(getGameWorld().get());
    }

    void GameStateInitController::processMouseReleaseEvent(QMouseEvent* event)
    {
        if(event->button() != Qt::LeftButton)
            return;
        Point startPosition    = normalizeToButtonCoordinate(event->x(), event->y());
        _pImpl->_gameWorld     = GameWorldHardModeBuilder(startPosition).buildMap().getResult();
        _pImpl->_startPosition.reset(new Point(startPosition));
        setGameCtrl(new GameStatePlayingController(*this));
    }
}
