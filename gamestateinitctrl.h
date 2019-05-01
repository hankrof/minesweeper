#ifndef GAMESTATEINITCONTROLLER_H
#define GAMESTATEINITCONTROLLER_H
#include "gamestatectrl.h"
#include <memory>
namespace ms
{
    class GameStateControllerContext;
    class GameStateInitController : public GameStateController
    {
    public:
        GameStateInitController(GameStateControllerContext* ctrl);
        void processMouseMoveEvent(QMouseEvent* event)
            { GameStateController::processMouseMoveEvent(event);}
        void processMousePressEvent(QMouseEvent* event)
            { GameStateController::processMousePressEvent(event);}
        void processMouseReleaseEvent(QMouseEvent* event)
            { GameStateController::processMouseReleaseEvent(event);}
        void processPaintEvent();
    };
}

#endif // GAMESTATEINITCONTROLLER_H
