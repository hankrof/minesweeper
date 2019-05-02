#ifndef GAMESTATELOSINGCONTROLLER_H
#define GAMESTATELOSINGCONTROLLER_H
#include "gamestatectrl.h"
namespace ms
{
    class GameStateLosingController : public GameStateController
    {
    public:
        GameStateLosingController(GameStateController &ctrl);
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
#endif // GAMESTATELOSINGCONTROLLER_H
