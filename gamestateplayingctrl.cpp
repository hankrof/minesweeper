#include "gamestateplayingctrl.h"
#include "mainwindow.h"
#include "gameworld.h"
#include "gamemap.h"
#include "gameblock.h"
#include "envir.h"
#include <QMouseEvent>
#include <QDebug>
namespace ms
{
    GameStatePlayingController::GameStatePlayingController(GameStateController& ctrl)
        : GameStateController (ctrl)
    {

    }

    void GameStatePlayingController::processMouseMoveEvent(QMouseEvent* event)
    {
        Size blockSize = getEnvironment()->getBlockSize();
        Point p(event->x() / blockSize.width(),
                event->y() / blockSize.height());
        if(p != _lastSelectedPos)
            getGameWorld()->getMap()->
                at(_lastSelectedPos.y(), _lastSelectedPos.x())->unselect();
        getGameWorld()->getMap()->at(p.y(), p.x())->select();
        QRect unSelectedButtonRect(_lastSelectedPos.x() * blockSize.width(),
            _lastSelectedPos.y() * blockSize.height(),
            blockSize.width(), blockSize.height());

        QRect selectedButtonRect(p.x() * blockSize.width(),
            p.y() * blockSize.height(),
            blockSize.width(), blockSize.height());

        getMainWindow()->repaint(unSelectedButtonRect);
        getMainWindow()->repaint(selectedButtonRect);
        _lastSelectedPos = p;
    }

    void GameStatePlayingController::processMousePressEvent(QMouseEvent*)
    {

    }

    void GameStatePlayingController::processMouseReleaseEvent(QMouseEvent* event)
    {
        Size blockSize = getEnvironment()->getBlockSize();
        Point p(event->x() / blockSize.width(),
                event->y() / blockSize.height());
        QRect openedButtonRect(p.x() * blockSize.width(),
            p.y() * blockSize.height(),
            blockSize.width(), blockSize.height());
        getGameWorld()->getMap()->at(p.y(), p.x())->open();
        getMainWindow()->repaint(openedButtonRect);
    }

    void GameStatePlayingController::processPaintEvent()
    {
        getMainWindow()->paintGameWorld(getGameWorld().get());
    }
}
