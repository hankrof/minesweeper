#ifndef GAMESTATEWINNINGCONTROLLER_H
#define GAMESTATEWINNINGCONTROLLER_H
#include "gamestatectrl.h"
namespace ms
{
    class GameStateWinningController : public GameStateController
    {
    public:
        GameStateWinningController(GameStateController& ctrl);
        void processMouseMoveEvent   (QMouseEvent* event)
            { GameStateController::processMouseMoveEvent(event); }
        void processMousePressEvent  (QMouseEvent* event)
            { GameStateController::processMousePressEvent(event); }
        void processMouseDoubleClickEvent(QMouseEvent* event)
            { GameStateController::processMouseDoubleClickEvent(event); }
        void processMouseReleaseEvent(QMouseEvent* event)
            { GameStateController::processMouseReleaseEvent(event); }
        void processPaintEvent()
            { GameStateController::processPaintEvent(); }
    };
}




#endif // GAMESTATEWINNINGCONTROLLER_H
