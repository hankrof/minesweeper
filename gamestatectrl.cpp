#include "gamestatectrl.h"
#include "gamestatectrlctx.h"
namespace ms
{
    GameStateController::GameStateController()
        : _pImpl(nullptr)
    {

    }

    GameStateController::~GameStateController()
    {

    }

    GameStateController::GameStateController
        (const GameStateController &ctrl)
        : _pImpl(ctrl._pImpl)
    {

    }

    void GameStateController::setGameCtrl(GameStateController* ctrl)
    {
        _pImpl->_ctx->setGameCtrl(ctrl);
    }

    void GameStateController::processMouseMoveEvent(QMouseEvent*)
    {

    }

    void GameStateController::processMousePressEvent(QMouseEvent*)
    {

    }

    void GameStateController::processMouseReleaseEvent(QMouseEvent*)
    {

    }

    void GameStateController::processPaintEvent()
    {

    }
}

