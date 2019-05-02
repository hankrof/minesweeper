#ifndef GAMEBLOCKMINE_H
#define GAMEBLOCKMINE_H
#include "gameblock.h"
namespace ms
{
    class GameBlockMine : public GameBlock
    {
    public:
        GameBlockMine();
        bool nearMines() const;
        int addNumber(int);
        bool isMine() const;
        std::shared_ptr<GameImage> getOpenedImage() const;
    private:
        std::shared_ptr<GameImage> _image;
    };
}



#endif // GAMEBLOCKMINE_H
