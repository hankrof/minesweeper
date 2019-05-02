#include "gameblockmine.h"
#include "gameimg.h"
namespace ms
{
    GameBlockMine::GameBlockMine()
        : _image(new GameImage("pics/mine.bmp"))
    {

    }

    bool GameBlockMine::nearMines() const
    {
        return true;
    }

    int GameBlockMine::addNumber(int)
    {
        return -1;
    }

    bool GameBlockMine::isMine() const
    {
        return true;
    }

    std::shared_ptr<GameImage> GameBlockMine::getOpenedImage() const
    {
       return _image;
    }
}
