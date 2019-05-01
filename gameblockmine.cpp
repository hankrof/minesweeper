#include "gameblockmine.h"
#include "gameimg.h"
namespace ms
{
    GameBlockMine::GameBlockMine()
        : _image(new GameImage("pics/mine.bmp"))
    {

    }

    int GameBlockMine::addNumber(int)
    {
        return -1;
    }

    std::shared_ptr<GameImage> GameBlockMine::getOpenedImage() const
    {
       return _image;
    }
}
