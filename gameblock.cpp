#include "gameblock.h"
#include "gameimg.h"
namespace ms
{
    GameBlock::GameBlock()
        : _coveredImage(new GameImage("pics/btnNor.bmp"))
        , _flagImage(new GameImage("pics/flagNor.bmp"))
        , _coveredSelectedImage(new GameImage("pics/btnSlt.bmp"))
        , _flagSelectedImage(new GameImage("pics/flagSlt.bmp"))
        , _flag(false)
        , _open(false)
        , _select(false)
    {

    }

    GameBlock::~GameBlock()
    {

    }

    GameBlock& GameBlock::open()
    {
        _open = true;
        return *this;
    }

    GameBlock& GameBlock::select()
    {
        _select = true;
        return *this;
    }

    GameBlock& GameBlock::unselect()
    {
        _select = false;
        return *this;
    }

    GameBlock& GameBlock::toggleFlag()
    {
        if(!_open)
            _flag = !_flag;
        return *this;
    }

    std::shared_ptr<GameImage> GameBlock::getImage() const
    {
        if(_open)
            return getOpenedImage();
        else if(_flag)
            if(_select)
                return _flagSelectedImage;
            else
                return _flagImage;
        else
            if(_select)
                return _coveredSelectedImage;
            else
                return _coveredImage;
    }

    bool GameBlock::isOpen() const
    {
        return _open;
    }

    bool GameBlock::openable() const
    {
        return !_flag;
    }

    bool GameBlock::flag() const
    {
        return _flag;
    }
}
