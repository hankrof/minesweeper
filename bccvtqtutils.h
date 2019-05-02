#ifndef MS_CVTQTUTILS
#define MS_CVTQTUTILS
#include "geometry.h"
#include "gameimg.h"
#include <QPoint>
#include <QImage>
#include <QSize>
#include <QRect>
#include <QColor>
namespace ms
{
    inline QPoint cvtQPoint(const Point &p)
    {
        return QPoint(p.x(), p.y());
    }

    inline QSize cvtQSize(const Size &s)
    {
        return QSize(static_cast<int>(s.width()),
            static_cast<int>(s.height()));
    }

    inline QRect cvtQRect(const Point& p, const Size& s)
    {
        return QRect(p.x(), p.y(),
            static_cast<int>(s.width()),
            static_cast<int>(s.height())) ;
    }

    inline QRect cvtQRect(const Rectangle &rect)
    {
        return QRect(rect.position().x(), rect.position().y(),
            static_cast<int>(rect.boundingBoxSize().width()),
            static_cast<int>(rect.boundingBoxSize().height()));
    }

    inline QColor cvtQColor(const Color& c)
    {
        return QColor(c.r(), c.g(), c.b());
    }

    inline QImage cvtQImage(const GameImage& img)
    {
        return *static_cast<QImage*>(img.getData());
    }
}
#endif // BC_CVTQTUTILS
