#ifndef GAMEIMG_H
#define GAMEIMG_H
#include <string>
#include <memory>
#include <QImage>
#include "geometry.h"
namespace ms
{
    class ImplImage
    {
    public:
        ImplImage(const QImage& image)
            : _image(image)
        {

        }
        QImage _image;
    };
    class GameImage
    {
    public:
        GameImage();
        GameImage(const std::string filename);
        GameImage(const std::string filename, const Size& scaledSize);
        bool open(const std::string& filename);
        bool open(const std::string& filename, const Size& scaledSize);
        bool scale(const Size& size);
        void *getData() const;
    private:
        std::unique_ptr<ImplImage> pImplImg;
    };
}

#endif // GAMEIMG_H
