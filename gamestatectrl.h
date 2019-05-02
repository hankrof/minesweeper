#ifndef GAMESTATECONTROLLER_H
#define GAMESTATECONTROLLER_H
#include <memory>
#include "geometry.h"
class QMouseEvent;
namespace ms
{
    class Point;
    class GameStateControllerContext;
    class MainWindow;
    class GameWorld;
    class Environment;
    class GameMap;
    struct ImplStateController
    {
        GameStateControllerContext*  _ctx;
        std::shared_ptr<MainWindow>  _mainWindow;
        std::shared_ptr<GameWorld>   _gameWorld;
        std::shared_ptr<Environment> _envir;
        std::shared_ptr<Point>       _startPosition;
        std::size_t                  _rows;
        std::size_t                  _cols;
        std::size_t                  _mines;
    };

    class GameStateController
    {
    public:
        GameStateController();
        virtual ~GameStateController();
        GameStateController(const GameStateController& ctrl);
        void setGameCtrl(GameStateController* ctrl);
        void processSaveSettings(std::size_t rows, std::size_t cols, std::size_t mines);
        void processRestartGame(bool choice);
        virtual void processMouseMoveEvent   (QMouseEvent*) = 0;
        virtual void processMousePressEvent  (QMouseEvent*) = 0;
        virtual void processMouseDoubleClickEvent(QMouseEvent*) = 0;
        virtual void processMouseReleaseEvent(QMouseEvent*) = 0;
        virtual void processPaintEvent()                    = 0;
    protected:
        Point normalizeToButtonCoordinate (std::size_t x, std::size_t y);
        Rectangle calButtonRect(const Point &p);
        std::shared_ptr<MainWindow>  getMainWindow () const {return _pImpl->_mainWindow;}
        std::shared_ptr<GameWorld>   getGameWorld  () const {return _pImpl->_gameWorld; }
        std::shared_ptr<Environment> getEnvironment() const {return _pImpl->_envir;     }
        std::shared_ptr<GameMap>     getGameMap    () const;
        std::shared_ptr<ImplStateController> _pImpl;
    private:
        Point _lastSelectedPos;
    };
}
#endif // GAMESTATECONTROLLER_H
