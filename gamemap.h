#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <vector>
#include "geometry.h"
namespace ms
{
    class GameBlock;
    class GameMap
    {
    public:
        GameMap();
        GameMap(std::size_t rows, std::size_t cols, std::size_t mines);
        ~GameMap();
        GameMap& setup(std::size_t rows, std::size_t cols, std::size_t mines);
        std::size_t rows() const;
        std::size_t cols() const;
        std::size_t mines() const;
        std::vector<GameBlock*>& operator[](std::size_t row);
        const std::vector<GameBlock*>& operator[](std::size_t row) const;
        GameBlock* at(std::size_t row, std::size_t col);
        const GameBlock* at(std::size_t row, std::size_t col) const;
    private:
        GameMap& resize(std::size_t rows, std::size_t cols);
        GameMap& setupMines(std::size_t mines);
        GameMap& determineNumbersByMines();
        std::vector<Point> getNeighboringPoints(const Point& p) const;
        std::vector<Point> generateMines(std::size_t mines) const;
        std::vector<std::vector<GameBlock*>> _elements;
        std::vector<Point> _mines;
    };
}
#endif // GAMEMAP_H
