#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <memory>
class QMouseEvent;
namespace ms
{
    class GameWorld;
    class GameDialog;
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
        void execWinningResult();
        void execLosingResult();
    private:
        std::unique_ptr<GameScreen> _gameScreen;
        std::unique_ptr<GameDialog> _gameDialog;
        GameStateControllerContext& _ctrl;
    };
}
#endif // MAINWINDOW_H
