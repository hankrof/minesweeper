#include "envir.h"
#include <QApplication>
#include <QScreen>
#include <QDesktopWidget>

namespace ms
{
    int Desktop::getNumberOfMonitor()
    {
        return QApplication::desktop()->numScreens();
    }

    Size Desktop::getScreenSize()
    {
        QRect r = QApplication::primaryScreen()->geometry();
        return Size(r.width(), r.height());
    }

    Size Desktop::getScreenSize(int id)
    {
        QRect r = QApplication::screens()[id]->geometry();
        return Size(r.width(), r.height());
    }

    Environment::Environment()
    {
        init();
    }

    void Environment::init()
    {
        Size monitorSize    = Desktop::getScreenSize();
        _blockSize          = Size(monitorSize.width()  / 64,
                                   monitorSize.width()  / 64);
        _blockNumberSize    = Size(30, 16);
        _screenSize         = Size(_blockSize.width()  * _blockNumberSize.width(),
                                   _blockSize.height() * _blockNumberSize.height());
    }

    Size Environment::getBlockSize() const
    {
        return _blockSize;
    }

    Size Environment::getBlockNumberSize() const
    {
        return _blockNumberSize;
    }

    Size Environment::getScreenSize() const
    {
        return _screenSize;
    }
}
