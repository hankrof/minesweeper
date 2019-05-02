#ifndef GAMESTATEPLAYINGCONTROLLER_H
#define GAMESTATEPLAYINGCONTROLLER_H
#include "gamestatectrl.h"
#include "gameruler.h"
#include <QRect>
namespace ms
{
    class GameStatePlayingController : public GameStateController
    {
    public:
        GameStatePlayingController(GameStateController& ctrl);
        void processMouseMoveEvent   (QMouseEvent* event)
            { GameStateController::processMouseMoveEvent(event);  }
        void processMousePressEvent  (QMouseEvent* event)
            { GameStateController::processMousePressEvent(event); }
        void processMouseDoubleClickEvent(QMouseEvent*);
        void processMouseReleaseEvent(QMouseEvent*);
        void processPaintEvent()
            { GameStateController::processPaintEvent();}
    private:
        void processGameState();
        Point _lastSelectedPos;
        GameRuler _ruler;
    };
}

#endif // GAMESTATEPLAYINGCONTROLLER_H
