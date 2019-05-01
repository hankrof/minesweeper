#include "geometry.h"
#include <cmath>
#include <algorithm>
namespace ms
{
    Color::Color()
        : _r(0), _g(0), _b(0)
    {


    }

    Color::Color(int r, int g, int b)
        : _r(r), _g(g), _b(b)
    {

    }

    unsigned char& Color::r()
    {
        return _r;
    }

    unsigned char Color::r() const
    {
        return _r;
    }

    unsigned char &Color::g()
    {
        return _g;
    }

    unsigned char Color::g() const
    {
        return _g;
    }

    unsigned char &Color::b()
    {
        return _b;
    }

    unsigned char Color::b() const
    {
        return _b;
    }

    Point::Point()
        : Point(0, 0)
    {

    }

    Point::Point(int x,int y)
        : _x(x), _y(y)
    {

    }

    int& Point::x()
    {
        return _x;
    }

    int& Point::y()
    {
        return _y;
    }

    int Point::x() const
    {
        return _x;
    }

    int Point::y() const
    {
        return _y;
    }

    const Point& Point::operator+=(const Point& pt)
    {
        x() += pt.x();
        y() += pt.y();
        return *this;
    }

    const Point& Point::operator-=(const Point& pt)
    {
        x() -= pt.x();
        y() -= pt.y();
        return *this;
    }

    bool Point::operator==(const Point& pt)
    {
        return x() == pt.x() && y() == pt.y();
    }

    bool Point::operator!=(const Point& pt)
    {
        return x() != pt.x() || y() != pt.y();
    }


    unsigned int Point::distance(const Point& pt1, const Point& pt2)
    {
        int euclid = (pt1.x() - pt2.x()) * (pt1.x() - pt2.x()) +
               (pt2.y() - pt2.x()) * (pt2.y() - pt2.x());
        return static_cast<unsigned int>(std::sqrt(euclid));
    }

    Point operator+(const Point& pt1, const Point& pt2)
    {
        return Point(pt1.x() + pt2.x(), pt2.y() + pt2.y());
    }

    Point operator-(const Point& pt1, const Point& pt2)
    {
        return Point(pt1.x() - pt2.x(), pt2.y() - pt2.y());
    }

    Size::Size()
        : Size(1, 1)
    {

    }

    Size::Size(unsigned int  width, unsigned int  height)
        : _width(width), _height(height)
    {

    }

    unsigned int & Size::width()
    {
        return _width;
    }

    unsigned int & Size::height()
    {
        return _height;
    }

    unsigned int Size::width() const
    {
        return _width;
    }

    unsigned int Size::height() const
    {
        return _height;
    }

    unsigned int Size::area() const
    {
        return _width * _height;
    }

    const Size& Size::operator+=(const Size& s)
    {
        width()  += s.width();
        height() += s.height();
        return *this;
    }

    const Size& Size::operator-=(const Size& s)
    {
        width()  -= s.width();
        height() -= s.height();
        return *this;
    }

    Size operator+(const Size& s1, const Size& s2)
    {
        return Size(s1.width() + s2.width(),
                    s1.height() + s2.height());
    }

    Size operator-(const Size& s1, const Size& s2)
    {
        return Size(s1.width() - s2.width(),
                    s1.height() - s2.height());
    }

    Shape::~Shape()
    {
        //dummy code just for linking.
    }

    Rectangle::Rectangle(const Rectangle &rect)
        : _position(rect._position), _size(rect._size)
    {

    }

    Rectangle::Rectangle()
        : Rectangle(Point(0, 0), Size(1, 1))
    {

    }

    Rectangle::Rectangle(const Point& p, Size size)
        : _position(p), _size(size)
    {

    }

    double Rectangle::area() const
    {
        return _size.area();
    }

    Point Rectangle::position() const
    {
        return _position;
    }

    Point& Rectangle::position()
    {
        return _position;
    }

    Size Rectangle::boundingBoxSize() const
    {
        return _size;
    }

    Shape& Rectangle::moveX(int offset)
    {
        _position.x() += offset;
        return *this;
    }

    Shape& Rectangle::moveY(int offset)
    {
        _position.y() += offset;
        return *this;
    }

    Circle::Circle()
        : Circle(Point(0, 0), 1.0)
    {

    }

    Circle::Circle(const Circle& circle)
        : _centre(circle._centre), _radius(circle._radius)
    {

    }

    Circle::Circle(const Point& centre, double radius)
        : _centre(centre), _radius(radius)
    {

    }

    double Circle::area() const
    {
        return g_pi * _radius * _radius;
    }

    Point Circle::position() const
    {
        return _centre;
    }

    Point& Circle::position()
    {
        return _centre;
    }

    Size Circle::boundingBoxSize() const
    {
        return Size( std::ceil(_radius * 2), std::ceil(_radius * 2));
    }

    Shape& Circle::moveX(int offset)
    {
        _centre.x() += offset;
        return *this;
    }

    Shape& Circle::moveY(int offset)
    {
        _centre.y() += offset;
        return *this;
    }

    double Circle::radius() const
    {
        return _radius;
    }
}
