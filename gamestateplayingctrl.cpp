#include "gamestateplayingctrl.h"
#include "gamestatewinningctrl.h"
#include "gamestatelosingctrl.h"
#include "mainwindow.h"
#include "gameworld.h"
#include "gamemap.h"
#include "gameblock.h"
#include "envir.h"
#include "bccvtqtutils.h"
#include <QMouseEvent>
namespace ms
{

    GameStatePlayingController::GameStatePlayingController(GameStateController& ctrl)
        : GameStateController (ctrl), _ruler(*getGameMap())
    {
        _ruler.openSingleBlock(_pImpl->_startPosition.get()[0]);
        getMainWindow()->repaint();
    }

    void GameStatePlayingController::processMouseDoubleClickEvent(QMouseEvent* event)
    {
        Point p = normalizeToButtonCoordinate(event->x(), event->y());
        if(event->button() == Qt::LeftButton)
            _ruler.open3x3Blocks(p);
        getMainWindow()->repaint();
        processGameState();
    }

    void GameStatePlayingController::processMouseReleaseEvent(QMouseEvent* event)
    {
        Point p = normalizeToButtonCoordinate(event->x(), event->y());
        switch(event->button())
        {
        case Qt::LeftButton:
            _ruler.openSingleBlock(p);
            break;
        case Qt::MidButton:
            _ruler.open3x3Blocks(p);
            break;
        case Qt::RightButton:
            _ruler.toggleFlagToBlock(p);
            break;
        default:
            break;
        }
        getMainWindow()->repaint();
        processGameState();
    }

    void GameStatePlayingController::processGameState()
    {
        if(!_ruler.isAlive())
        {
            _ruler.openAllMines();
            setGameCtrl(new GameStateLosingController(*this));
        }
        else if(_ruler.isWinning())
            setGameCtrl(new GameStateWinningController(*this));
    }
}
