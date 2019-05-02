#ifndef GAMERULER_H
#define GAMERULER_H
namespace ms
{
    class Point;
    class GameMap;
    class GameRuler
    {
    public:
        GameRuler(GameMap& map);
        bool isAlive();
        bool isWinning();
        bool openSingleBlock(const Point& p);
        bool open3x3Blocks(const Point& center);
        void toggleFlagToBlock(const Point& p);
    private:
        int count3x3Flag(const Point& p);
        int open(const Point& center);
        void init();
        GameMap& _map;
        bool _alive;
        int _openableBlocks;
    };
}
#endif // GAMERULER_H
