#include "mainwindow.h"
#include "gamescreen.h"
#include <QMouseEvent>
namespace ms
{
    MainWindow::MainWindow(GameStateControllerContext &ctrl)
        : QMainWindow(nullptr)
        , _gameScreen(new GameScreen(ctrl, this))
        , _ctrl(ctrl)
    {
        setCentralWidget(_gameScreen.get());
    }

    MainWindow::~MainWindow()
    {

    }

    void MainWindow::initGameEnvir(Environment *envir)
    {
        _gameScreen->initGameEnvir(envir);
    }

    void MainWindow::paintGameWorld(GameWorld *world)
    {
        _gameScreen->paintGameWorld(world);
    }
}
