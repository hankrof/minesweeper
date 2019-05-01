#ifndef BC_CVTQTUTILS
#define BC_CVTQTUTILS
#include "geometry.h"
#include "gameimg.h"
#include <QPoint>
#include <QImage>
#include <QSize>
#include <QRect>
#include <QColor>
namespace ms
{
    QPoint cvtQPoint(const Point &p)
    {
        return QPoint(p.x(), p.y());
    }

    QSize cvtQSize(const Size &s)
    {
        return QSize(static_cast<int>(s.width()),
            static_cast<int>(s.height()));
    }

    QRect cvtQRect(const Point& p, const Size& s)
    {
        return QRect(p.x(), p.y(),
            static_cast<int>(s.width()),
            static_cast<int>(s.height())) ;
    }

    QColor cvtQColor(const Color& c)
    {
        return QColor(c.r(), c.g(), c.b());
    }

    QImage cvtQImage(const GameImage& img)
    {
        return *static_cast<QImage*>(img.getData());
    }
}
#endif // BC_CVTQTUTILS
