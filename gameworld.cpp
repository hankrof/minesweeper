#include "gameworld.h"
#include "gamemap.h"
namespace ms
{
    GameWorld::GameWorld()
        : _map(new GameMap())
    {

    }

    std::shared_ptr<GameMap> GameWorld::getMap()
    {
        return _map;
    }
}
