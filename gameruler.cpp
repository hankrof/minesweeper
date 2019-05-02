#include "gameruler.h"
#include "gamemap.h"
#include "gameblock.h"
#include "gameblocknumber.h"
#include <stack>
namespace ms
{
    GameRuler::GameRuler(GameMap& map)
        : _map(map), _alive(true)
    {
        init();
        _openableBlocks = _map.rows() * _map.cols() - _map.mines();
    }

    bool GameRuler::isAlive()
    {
        return _alive;
    }

    bool GameRuler::isWinning()
    {
        int opened = 0;
        for(std::size_t y = 0; y < _map.rows(); y++)
            for(std::size_t x = 0; x < _map.cols(); x++)
                if(_map.at(y, x)->isOpen() && !_map.at(y, x)->isMine())
                    opened++;
        return opened == _openableBlocks;
    }

    bool GameRuler::openSingleBlock(const Point& p)
    {
        if(_map.at(p)->openable())
        {
            _map.at(p)->open();
            open(p);
            if(_map.at(p)->isMine())
                _alive = false;
        }
        return _alive;
    }

    bool GameRuler::open3x3Blocks(const Point& p)
    {
        int number;
        int opened = 0;
        if(!_map.at(p)->isMine())
            number = (static_cast<GameBlockNumber*>(_map.at(p)))->number();
        if(count3x3Flag(p) == number)
            for(int y = p.y() - 1; y <= p.y() + 1; y++)
            {
                if(y < 0 || y >= static_cast<int>(_map.rows()))
                    continue;
                for(int x = p.x() - 1; x <= p.x() + 1; x++)
                {
                    if( x < 0 || x >= static_cast<int>(_map.cols()))
                        continue;
                    openSingleBlock(Point(x, y));
                }
            }
        return _alive;
    }

    void GameRuler::toggleFlagToBlock(const Point& p)
    {
        _map.at(p)->toggleFlag();
    }

    void GameRuler::openAllMines()
    {
        for(std::size_t y = 0; y < _map.rows(); y++)
            for(std::size_t x = 0; x < _map.cols(); x++)
                if(_map.at(y, x)->isMine())
                    _map.at(y, x)->open();
    }

    int GameRuler::count3x3Flag(const Point& p)
    {
        int nbFlag = 0;
        for(int y = p.y() - 1; y <= p.y() + 1; y++)
        {
            if(y < 0 || y >= static_cast<int>(_map.rows()))
                continue;
            for(int x = p.x() - 1; x <= p.x() + 1; x++)
            {
                if( x < 0 || x >= static_cast<int>(_map.cols()))
                    continue;
                if(_map.at(Point(x, y))->flag())
                    nbFlag++;
            }
        }
        return nbFlag;
    }

    int GameRuler::open(const Point& center)
    {
        std::stack<Point> candidates;
        int openedNumberBlocks = 0;
        candidates.push(center);
        while(!candidates.empty())
        {
            Point p(candidates.top());
            candidates.pop();
            if(_map.at(p)->nearMines())
                continue;
            for(int y = p.y() - 1; y <= p.y() + 1; y++)
            {
                if(y < 0 || y >= static_cast<int>(_map.rows()))
                    continue;
                for(int x = p.x() - 1; x <= p.x() + 1; x++)
                {
                    if( x < 0 || x >= static_cast<int>(_map.cols()))
                        continue;
                    if( _map.at(y, x)->openable() &&
                       !_map.at(y, x)->isOpen())
                    {
                        _map.at(y, x)->open();
                        candidates.push(Point(x, y));
                        openedNumberBlocks++;
                    }
                }
            }
        }
        return openedNumberBlocks;
    }

    void GameRuler::init()
    {
        for(std::size_t y = 0; y < _map.rows(); y++)
            for(std::size_t x = 0; x < _map.cols(); x++)
                if(!_map.at(y, x)->openable() && _map.at(y, x)->isOpen())
                {
                    _alive = false;
                    return;
                }
    }
}
