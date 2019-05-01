#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <memory>
class QMouseEvent;
namespace ms
{
    class GameWorld;
    class GameScreen;
    class Environment;
    class GameStateControllerContext;
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        MainWindow(GameStateControllerContext &ctrl);
        ~MainWindow();
        void initGameEnvir(Environment *envir);
        void paintGameWorld(GameWorld*);
    private:
        std::unique_ptr<GameScreen> _gameScreen;
        GameStateControllerContext& _ctrl;
    };
}
#endif // MAINWINDOW_H
