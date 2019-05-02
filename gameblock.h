#ifndef GAMEBLOCK_H
#define GAMEBLOCK_H
#include <memory>
namespace ms
{
    class GameImage;
    class GameBlock
    {
    public:
        GameBlock();
        virtual ~GameBlock();
        GameBlock& open();
        GameBlock& select();
        GameBlock& unselect();
        GameBlock& toggleFlag();
        std::shared_ptr<GameImage> getImage() const;
        bool isOpen() const;
        bool openable() const;
        bool flag() const;
        virtual bool nearMines() const = 0;
        virtual bool isMine() const = 0;
        virtual int addNumber(int add) = 0;
        virtual std::shared_ptr<GameImage> getOpenedImage() const = 0;
    private:
        std::shared_ptr<GameImage> _coveredImage;
        std::shared_ptr<GameImage> _flagImage;
        std::shared_ptr<GameImage> _coveredSelectedImage;
        std::shared_ptr<GameImage> _flagSelectedImage;
        bool _flag;
        bool _open;
        bool _select;
    };
}



#endif // GAMEBLOCK_H
