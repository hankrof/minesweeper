#ifndef GAMESTATECONTROLLERCONTEXT_H
#define GAMESTATECONTROLLERCONTEXT_H
#include <memory>
class QMouseEvent;
namespace ms
{
    class GameStateController;
    class GameStateControllerContext
    {
    public:
        GameStateControllerContext();
        void setGameCtrl(GameStateController* ctrl);
        void processSaveSettings(std::size_t rows, std::size_t cols, std::size_t mines);
        void processRestartGame(bool choice);
        void processMouseMoveEvent(QMouseEvent* event);
        void processMousePressEvent(QMouseEvent* event);
        void processMouseDoubleClickEvent(QMouseEvent* event);
        void processMouseReleaseEvent(QMouseEvent* event);
        void processPaintEvent();
    private:
        std::shared_ptr<GameStateController> _ctrl;
    };
}


#endif // GAMESTATECONTROLLERCONTEXT_H
