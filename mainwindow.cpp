#include "mainwindow.h"
#include "gamescreen.h"
#include "gamedialog.h"
#include "gamestatectrlctx.h"
#include <QMouseEvent>
#include <QToolBar>
#include <QAction>
namespace ms
{
    MainWindow::MainWindow(GameStateControllerContext &ctrl)
        : QMainWindow(nullptr)
        , _gameScreen(new GameScreen(ctrl, this))
        , _gameResultDialog(new GameResultDialog(ctrl))
        , _gameSettingsDialog(new GameSettingsDialog(ctrl))
        , _ctrl(ctrl)
    {
        setCentralWidget(_gameScreen.get());
        createToolBars();
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
        _gameResultDialog->setMessage("Congradulations! You won the game. Try again?");
        _gameResultDialog->open();
    }

    void MainWindow::execLosingResult()
    {
        _gameResultDialog->setMessage("Sorry! You lost the game. Try again?");
        _gameResultDialog->open();
    }

    void MainWindow::processNewGameButton()
    {
        _ctrl.processRestartGame(true);
    }

    void MainWindow::processSettingsButton()
    {
        _gameSettingsDialog->exec();
    }

    void MainWindow::createToolBars()
    {
        QToolBar* toolbar = addToolBar("toolbar");
        QAction *newGameAction  = new QAction("New Game", toolbar);
        QAction *settingsAction = new QAction("Settings", toolbar);
        toolbar->addAction(newGameAction);
        toolbar->addAction(settingsAction);
        connect(newGameAction,  SIGNAL(triggered()), this, SLOT(processNewGameButton()));
        connect(settingsAction, SIGNAL(triggered()), this, SLOT(processSettingsButton()));
    }
}
