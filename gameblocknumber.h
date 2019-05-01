#ifndef GAMEBLOCKNUMBER_H
#define GAMEBLOCKNUMBER_H
#include "gameblock.h"
namespace ms
{
    class GameBlockNumber : public GameBlock
    {
    public:
        GameBlockNumber();
        GameBlockNumber(int number);
        GameBlockNumber& setNumber(int number);
        int number() const;
        int addNumber(int add);
        std::shared_ptr<GameImage> getOpenedImage() const;
    private:
        void loadImage(int number);
        std::shared_ptr<GameImage> _image;
        int _number;
    };
}
#endif // GAMEBLOCKNUMBER_H
