#include "gamestatectrlctx.h"
#include "gamestateinitctrl.h"
#include "gamestatectrl.h"
namespace ms
{
    GameStateControllerContext::GameStateControllerContext()
    {
        setGameCtrl(new GameStateInitController(this));
    }

    void GameStateControllerContext::setGameCtrl(GameStateController* ctrl)
    {
        _ctrl.reset(ctrl);
    }

    void GameStateControllerContext::processMouseMoveEvent(QMouseEvent* event)
    {
        _ctrl->processMouseMoveEvent(event);
    }

    void GameStateControllerContext::processMousePressEvent(QMouseEvent* event)
    {
        _ctrl->processMousePressEvent(event);
    }

    void GameStateControllerContext::processMouseReleaseEvent(QMouseEvent* event)
    {
        _ctrl->processMouseReleaseEvent(event);
    }

    void GameStateControllerContext::processPaintEvent()
    {
        _ctrl->processPaintEvent();
    }

}
