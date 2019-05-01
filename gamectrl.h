#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
class QMouseEvent;
namespace ms
{
    class MainWindow;
    class GameController
    {
    public:
        GameController();
        virtual void processMouseEvent(QMouseEvent*) = 0;
        virtual void processPaintEvent() = 0;
    };
}

#endif // GAMECONTROLLER_H
