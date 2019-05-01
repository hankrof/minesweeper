#ifndef GAMESTATECONTROLLER_H
#define GAMESTATECONTROLLER_H
#include <memory>
class QMouseEvent;
namespace ms
{
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
    };

    class GameStateController
    {
    public:
        GameStateController();
        virtual ~GameStateController();
        GameStateController(const GameStateController& ctrl);
        void setGameCtrl(GameStateController* ctrl);
        virtual void processMouseMoveEvent   (QMouseEvent*) = 0;
        virtual void processMousePressEvent  (QMouseEvent*) = 0;
        virtual void processMouseReleaseEvent(QMouseEvent*) = 0;
        virtual void processPaintEvent()                    = 0;
    protected:
        std::shared_ptr<MainWindow>  getMainWindow () const {return _pImpl->_mainWindow;}
        std::shared_ptr<GameWorld>   getGameWorld  () const {return _pImpl->_gameWorld; }
        std::shared_ptr<Environment> getEnvironment() const {return _pImpl->_envir;     }
        std::shared_ptr<ImplStateController> _pImpl;
    };
}
#endif // GAMESTATECONTROLLER_H
