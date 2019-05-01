#ifndef ENVIR_H
#define ENVIR_H
#include "geometry.h"
#include <string>
namespace ms
{
    class Desktop
    {
    public:
        static int getNumberOfMonitor();
        static Size getScreenSize();
        static Size getScreenSize(int id);
    };

    class Environment
    {
    public:
        Environment();
        Size        getBlockSize             () const;
        Size        getBlockNumberSize       () const;
        Size        getScreenSize            () const;
    private:
        void        init();
        Size        _blockSize;
        Size        _blockNumberSize;
        Size        _screenSize;
    };
}
#endif // ENVIRONMENT_H
