#include "gamescreen.h"
#include "gamestatectrlctx.h"
#include "gameworld.h"
#include "gamemap.h"
#include "gameimg.h"
#include "gameblocknumber.h"
#include "bccvtqtutils.h"
#include "envir.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
namespace ms
{
    GameScreen::GameScreen(GameStateControllerContext& ctrl, QWidget *parent)
        : QWidget(parent)
        , _ctrl(ctrl)
        , _painter(nullptr)
    {
        setMouseTracking(true);
    }

    void GameScreen::initGameEnvir(Environment* envir)
    {
        _envir = envir;
        setFixedSize(cvtQSize(envir->getScreenSize()));
    }

    void GameScreen::paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        _painter = &painter;
        _ctrl.processPaintEvent();
    }

    void GameScreen::mousePressEvent(QMouseEvent *event)
    {
        _ctrl.processMousePressEvent(event);
    }

    void GameScreen::mouseDoubleClickEvent(QMouseEvent *event)
    {
        _ctrl.processMouseDoubleClickEvent(event);
    }

    void GameScreen::mouseReleaseEvent(QMouseEvent *event)
    {
        _ctrl.processMouseReleaseEvent(event);
    }

    void GameScreen::mouseMoveEvent(QMouseEvent *event)
    {
        _ctrl.processMouseMoveEvent(event);
    }

    void GameScreen::paintGameWorld(GameWorld* world)
    {
        if(!_painter)
            return;
        std::shared_ptr<GameMap> map = world->getMap();
        Size blockSize = _envir->getBlockSize();
        for(std::size_t y = 0; y < map->rows(); y++)
        {
            for(std::size_t x = 0; x < map->cols(); x++)
            {
                auto image = map->at(y, x)->getImage();
                QImage qimage = cvtQImage(*image.get()).scaled(cvtQSize(blockSize));
                _painter->drawImage(x * blockSize.width(),
                    y * blockSize.height(), qimage);
            }
        }
    }
}
