#include "mainwindow.h"
#include "gamescreen.h"
#include "gamedialog.h"
#include <QMouseEvent>
#include <QDebug>
namespace ms
{
    MainWindow::MainWindow(GameStateControllerContext &ctrl)
        : QMainWindow(nullptr)
        , _gameScreen(new GameScreen(ctrl, this))
        , _gameDialog(new GameDialog(ctrl))
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

    void MainWindow::execWinningResult()
    {
        _gameDialog->setMessage("Congradulations! You won the game. Try again?");
        _gameDialog->open();
    }

    void MainWindow::execLosingResult()
    {
        _gameDialog->setMessage("Sorry! You lost the game. Try again?");
        _gameDialog->open();
    }
}
