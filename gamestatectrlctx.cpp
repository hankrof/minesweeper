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

    void GameStateControllerContext::processSaveSettings(std::size_t rows, std::size_t cols, std::size_t mines)
    {
        _ctrl->processSaveSettings(rows, cols, mines);
    }

    void GameStateControllerContext::processRestartGame(bool choice)
    {
        _ctrl->processRestartGame(choice);
    }

    void GameStateControllerContext::processMouseMoveEvent(QMouseEvent* event)
    {
        _ctrl->processMouseMoveEvent(event);
    }

    void GameStateControllerContext::processMousePressEvent(QMouseEvent* event)
    {
        _ctrl->processMousePressEvent(event);
    }

    void GameStateControllerContext::processMouseDoubleClickEvent(QMouseEvent* event)
    {
        _ctrl->processMouseDoubleClickEvent(event);
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
