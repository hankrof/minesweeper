#include "gameworldbuilder.h"
#include "gameblocknumber.h"
#include "gameblockmine.h"
#include "gameworld.h"
#include "gamemap.h"
namespace ms
{
    GameWorldBuilder::GameWorldBuilder()
        : _product(new GameWorld())
    {

    }

    std::shared_ptr<GameWorld> GameWorldBuilder::getResult() const
    {
        return _product;
    }

    GameWorldBuilder::~GameWorldBuilder()
    {

    }

    GameWorldEasyModeBuilder::GameWorldEasyModeBuilder()
    {

    }

    GameWorldBuilder& GameWorldEasyModeBuilder::buildMap()
    {
        getResult()->getMap()->setup(8, 8, 10);
        return *this;
    }

    GameWorldNormalModeBuilder::GameWorldNormalModeBuilder()
    {

    }

    GameWorldBuilder& GameWorldNormalModeBuilder::buildMap()
    {
        getResult()->getMap()->setup(16, 16, 40);
        return *this;
    }

    GameWorldHardModeBuilder::GameWorldHardModeBuilder()
    {

    }

    GameWorldBuilder& GameWorldHardModeBuilder::buildMap()
    {
        getResult()->getMap()->setup(16, 30, 99);
        return *this;
    }
}
