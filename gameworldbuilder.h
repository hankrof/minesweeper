#ifndef GAMEWORLDBUILDER_H
#define GAMEWORLDBUILDER_H
#include <memory>
#include "geometry.h"
namespace ms
{
    class GameWorld;
    class GameWorldBuilder
    {
    public:
        GameWorldBuilder();
        GameWorldBuilder(const Point& start);
        virtual ~GameWorldBuilder();
        virtual GameWorldBuilder& buildMap() = 0;
        virtual std::shared_ptr<GameWorld> getResult() const final;
    protected:
        Point getStartPosition() const;
    private:
        std::shared_ptr<GameWorld> _product;
        Point _startPosition;
    };

    class GameWorldEmptyBuilder : public GameWorldBuilder
    {
    public:
        GameWorldEmptyBuilder();
        GameWorldBuilder& buildMap();
    };

    class GameWorldEasyModeBuilder : public GameWorldBuilder
    {
    public:
        GameWorldEasyModeBuilder(const Point& start);
        GameWorldBuilder& buildMap();
    };

    class GameWorldNormalModeBuilder : public GameWorldBuilder
    {
    public:
        GameWorldNormalModeBuilder(const Point& start);
        GameWorldBuilder& buildMap();
    };

    class GameWorldHardModeBuilder : public GameWorldBuilder
    {
    public:
        GameWorldHardModeBuilder(const Point& start);
        GameWorldBuilder& buildMap();
    };

    class GameWorldCustomModeBuilder : public GameWorldBuilder
    {
    public:
        GameWorldCustomModeBuilder(std::size_t rows, std::size_t cols,
            std::size_t mines, const Point& start);
        GameWorldBuilder& buildMap();
    private:
        std::size_t _rows;
        std::size_t _cols;
        std::size_t _mines;
    };
}
#endif // GAMEWORLDBUILDER_H
