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
        GameStateInitController(GameStateController& ctrl);
        void processMouseMoveEvent(QMouseEvent* event)
            { GameStateController::processMouseMoveEvent(event);}
        void processMousePressEvent(QMouseEvent* event)
            { GameStateController::processMousePressEvent(event);}
        void processMouseDoubleClickEvent(QMouseEvent* event)
            { GameStateController::processMouseDoubleClickEvent(event);}
        void processMouseReleaseEvent(QMouseEvent*);
        void processPaintEvent()
            { GameStateController::processPaintEvent();}
    };
}

#endif // GAMESTATEINITCONTROLLER_H
