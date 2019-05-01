#include "gameimg.h"
namespace ms
{
    GameImage::GameImage()
        : pImplImg(nullptr)
    {

    }

    GameImage::GameImage(const std::string filename)
        : pImplImg(nullptr)
    {
        if(!open(filename))
            throw std::logic_error(std::string("Could not load image from [")
                + filename + "]");
    }

    GameImage::GameImage(const std::string filename, const Size& scaledSize)
    {
        if(!open(filename, scaledSize))
            throw std::logic_error(std::string("Could not load image from [")
                + filename + "]");
    }

    bool GameImage::open(const std::string& filename)
    {
        QImage image(QString::fromStdString(filename));
        if(!image.isNull())
            pImplImg.reset(new ImplImage(image));
        return !image.isNull();
    }

    bool GameImage::open(const std::string& filename, const Size& scaledSize)
    {
        return open(filename) && scale(scaledSize);
    }

    bool GameImage::scale(const Size& size)
    {
        ImplImage* pImpl = pImplImg.get();
        QImage image = pImpl->_image.scaled(static_cast<int>(size.width()),
            static_cast<int>(size.height()));
        pImplImg.reset(new ImplImage(image));
        return !image.isNull();
    }

    void *GameImage::getData() const
    {
        ImplImage* pImpl = pImplImg.get();
        return &pImpl->_image;
    }
}
