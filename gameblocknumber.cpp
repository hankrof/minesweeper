#include "gameblocknumber.h"
#include "gameimg.h"
namespace ms
{
    GameBlockNumber::GameBlockNumber()
        : GameBlockNumber(0)
    {

    }

    GameBlockNumber::GameBlockNumber(int number)
        : _number(number)
    {
        loadImage(0);
    }

    GameBlockNumber& GameBlockNumber::setNumber(int number)
    {
        _number = number;
        loadImage(number);
        return *this;
    }

    int GameBlockNumber::number() const
    {
        return _number;
    }

    int GameBlockNumber::addNumber(int add)
    {
        _number++;
        loadImage(_number);
        return _number;
    }

    std::shared_ptr<GameImage> GameBlockNumber::getOpenedImage() const
    {
        return _image;
    }

    void GameBlockNumber::loadImage(int number)
    {
        std::string base = "pics/";
        base += std::to_string(number) + ".bmp";
        _image.reset(new GameImage(base));
    }
}
