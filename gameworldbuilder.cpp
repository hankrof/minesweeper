#include "gameworldbuilder.h"
#include "gameblocknumber.h"
#include "gameblockmine.h"
#include "gameworld.h"
#include "gamemap.h"
namespace ms
{
    GameWorldBuilder::GameWorldBuilder()
        : _product(new GameWorld()), _startPosition(Point())
    {

    }


    GameWorldBuilder::GameWorldBuilder(const Point &start)
        : _product(new GameWorld()), _startPosition(start)
    {

    }

    Point GameWorldBuilder::getStartPosition() const
    {
        return _startPosition;
    }

    std::shared_ptr<GameWorld> GameWorldBuilder::getResult() const
    {
        return _product;
    }

    GameWorldBuilder::~GameWorldBuilder()
    {

    }


    GameWorldEmptyBuilder::GameWorldEmptyBuilder()
    {

    }

    GameWorldBuilder& GameWorldEmptyBuilder::buildMap()
    {
        getResult()->getMap()->setup(16, 30, 0);
        return *this;
    }

    GameWorldEasyModeBuilder::GameWorldEasyModeBuilder(const Point &start)
        : GameWorldBuilder(start)
    {

    }

    GameWorldBuilder& GameWorldEasyModeBuilder::buildMap()
    {
        getResult()->getMap()->setup(8, 8, 10, getStartPosition());
        return *this;
    }

    GameWorldNormalModeBuilder::GameWorldNormalModeBuilder(const Point &start)
        : GameWorldBuilder(start)
    {

    }

    GameWorldBuilder& GameWorldNormalModeBuilder::buildMap()
    {
        getResult()->getMap()->setup(16, 16, 40, getStartPosition());
        return *this;
    }

    GameWorldHardModeBuilder::GameWorldHardModeBuilder(const Point& start)
        : GameWorldBuilder(start)
    {

    }

    GameWorldBuilder& GameWorldHardModeBuilder::buildMap()
    {
        getResult()->getMap()->setup(16, 30, 99, getStartPosition());
        return *this;
    }
}
