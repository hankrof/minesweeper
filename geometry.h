#ifndef BC_GEOMETRY_H
#define BC_GEOMETRY_H

namespace ms
{
    const double g_pi = 3.141592653589793238462643;
    class Color
    {
    public:
        Color();
        Color(int r, int g, int b);
        unsigned char &r();
        unsigned char r() const;
        unsigned char& g();
        unsigned char g() const;
        unsigned char& b();
        unsigned char b() const;
    private:
        unsigned char _r;
        unsigned char _g;
        unsigned char _b;
    };

    class Point
    {
    public:
        Point();
        explicit Point(int x,int y);
        int& x();
        int& y();
        int x() const;
        int y() const;
        const Point& operator+=(const Point& pt);
        const Point& operator-=(const Point& pt);
        bool operator==(const Point& pt);
        bool operator!=(const Point& pt);
        static unsigned int distance(const Point& pt1, const Point& pt2);
    private:
        int _x, _y;
    };

    Point operator+(const Point& pt1, const Point& pt2);
    Point operator-(const Point& pt1, const Point& pt2);

    class Size
    {
    public:
        Size();
        explicit Size(unsigned int  width, unsigned int  height);
        unsigned int & width();
        unsigned int & height();
        unsigned int width() const;
        unsigned int height() const;
        unsigned int area() const;
        const Size& operator+=(const Size& s);
        const Size& operator-=(const Size& s);
    private:
        unsigned int  _width, _height;
    };

    Size operator+(const Size& s1, const Size& s2);
    Size operator-(const Size& s1, const Size& s2);

    class Shape
    {
    public:
        virtual ~Shape() = 0;
        virtual double area() const = 0;
        virtual Point  position() const = 0;
        virtual Point& position() = 0;
        virtual  Size  boundingBoxSize() const = 0;
        virtual Shape& moveX(int offset) = 0;
        virtual Shape& moveY(int offset) = 0;
    };

    class Rectangle : public Shape
    {
    public:
        Rectangle();
        Rectangle(const Rectangle& rect);
        Rectangle(const Point& p, Size size);
        double area() const;
        Point  position() const;
        Point& position();
        Size   boundingBoxSize() const;
        Shape& moveX(int offset);
        Shape& moveY(int offset);
    private:
        Point _position;
        Size  _size;
    };

    class Circle : public Shape
    {
    public:
        Circle();
        Circle(const Circle& circle);
        Circle(const Point& position, double radius);
        double area() const;
        Point position() const;
        Point& position();
        Size  boundingBoxSize() const;
        Shape& moveX(int offset);
        Shape& moveY(int offset);
        double radius() const;
    private:
        Point _centre;
        double _radius;
    };
}
#endif // BC_GEOMETRY_H
