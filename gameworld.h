#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include <memory>
namespace ms
{
    class GameMap;
    class GameWorld
    {
    public:
        GameWorld();
        std::shared_ptr<GameMap> getMap();
    private:
        std::shared_ptr<GameMap> _map;
    };
}
#endif // GAMEWORLD_H
