#ifndef GAMESTATEPLAYINGCONTROLLER_H
#define GAMESTATEPLAYINGCONTROLLER_H
#include "gamestatectrl.h"
#include "geometry.h"
namespace ms
{
    class GameStatePlayingController : public GameStateController
    {
    public:
        GameStatePlayingController(GameStateController& ctrl);
        void processMouseMoveEvent   (QMouseEvent*);
        void processMousePressEvent  (QMouseEvent*);
        void processMouseReleaseEvent(QMouseEvent*);
        void processPaintEvent()                   ;
    private:
        Point _lastSelectedPos;
    };
}

#endif // GAMESTATEPLAYINGCONTROLLER_H
