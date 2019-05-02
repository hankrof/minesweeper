#include "gamestatectrl.h"
#include "gamestatectrlctx.h"
#include "gamestateinitctrl.h"
#include "gameworld.h"
#include "gameblock.h"
#include "bccvtqtutils.h"
#include "mainwindow.h"
#include "gamemap.h"
#include "envir.h"
#include <QMouseEvent>
namespace ms
{
    GameStateController::GameStateController()
        : _pImpl(nullptr)
    {

    }

    GameStateController::~GameStateController()
    {

    }

    GameStateController::GameStateController
        (const GameStateController &ctrl)
        : _pImpl(ctrl._pImpl)
    {

    }

    void GameStateController::setGameCtrl(GameStateController* ctrl)
    {
        _pImpl->_ctx->setGameCtrl(ctrl);
    }

    void GameStateController::processRestartGame(bool choice)
    {
        setGameCtrl(new GameStateInitController(*this));
    }

    void GameStateController::processMouseMoveEvent(QMouseEvent* event)
    {
        Point p(normalizeToButtonCoordinate(event->x(), event->y()));
        if(p != _lastSelectedPos)
            getGameMap()->at(_lastSelectedPos.y(),
                _lastSelectedPos.x())->unselect();
        getGameMap()->at(p.y(), p.x())->select();
        QRect unSelectedButtonRect = cvtQRect(calButtonRect(_lastSelectedPos));
        QRect selectedButtonRect   = cvtQRect(calButtonRect(p));
        getMainWindow()->repaint(unSelectedButtonRect);
        getMainWindow()->repaint(selectedButtonRect);
        _lastSelectedPos = p;
    }

    void GameStateController::processMousePressEvent(QMouseEvent*)
    {

    }

    void GameStateController::processMouseDoubleClickEvent(QMouseEvent*)
    {

    }

    void GameStateController::processMouseReleaseEvent(QMouseEvent*)
    {

    }

    void GameStateController::processPaintEvent()
    {
        getMainWindow()->paintGameWorld(getGameWorld().get());
    }

    Point GameStateController::normalizeToButtonCoordinate(std::size_t x, std::size_t y)
    {
        const Size blockSize = getEnvironment()->getBlockSize();
        return Point(static_cast<int>(x) / blockSize.width(),
            static_cast<int>(y) / blockSize.height());
    }

    Rectangle GameStateController::calButtonRect(const Point &p)
    {
        const Size blockSize = getEnvironment()->getBlockSize();
        return Rectangle(Point(p.x() * blockSize.width(),
            p.y() * blockSize.height()),
            Size(blockSize.width(), blockSize.height()));
    }


    std::shared_ptr<GameMap> GameStateController::getGameMap() const
    {
        return getGameWorld()->getMap();
    }
}

