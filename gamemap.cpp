#include "gamemap.h"
#include "gameblocknumber.h"
#include "gameblockmine.h"
#include <algorithm>
#include <ctime>
#include <set>
namespace ms
{
    GameMap::GameMap()
    {

    }

    GameMap::GameMap(std::size_t rows, std::size_t cols, std::size_t mines, const Point &startPosition)
        : _startPosition(startPosition)
    {
        setup(rows, cols, mines, startPosition);
    }

    GameMap::~GameMap()
    {
        for(auto row : _elements)
            for(auto cell : row)
                delete cell;
    }

    GameMap& GameMap::resize(std::size_t rows, std::size_t cols)
    {
        for(auto row : _elements)
            for(auto& cell : row)
                delete cell;
        _elements.resize(rows);
        for(auto& row : _elements)
            row.resize(cols);
        for(std::size_t y = 0; y < rows; y++)
            for(std::size_t x = 0; x < cols; x++)
                _elements[y][x] = new GameBlockNumber(0);
        return *this;
    }

    GameMap& GameMap::setupMines(std::size_t mines)
    {
        _mines = generateMines(mines);
        for(const Point& p : _mines)
        {
            delete _elements[p.y()][p.x()];
            _elements[p.y()][p.x()] = new GameBlockMine();
        }
        return *this;
    }

    GameMap& GameMap::determineNumbersByMines()
    {
        for(const Point& p : _mines)
        {
            std::vector<Point> pts = getNeighboringPoints(p);
            for(const Point& neighbor : pts)
                _elements[neighbor.y()][neighbor.x()]->addNumber(1);
        }
        return *this;
    }

    GameMap& GameMap::setup(std::size_t rows, std::size_t cols, std::size_t mines, const Point& startPosition)
    {
        _startPosition = startPosition;
        return resize(rows, cols)
            .setupMines(mines)
            .determineNumbersByMines();
    }

    std::size_t GameMap::rows() const
    {
        return _elements.size();
    }

    std::size_t GameMap::cols() const
    {
        return _elements[0].size();
    }

    std::size_t GameMap::mines() const
    {
        return _mines.size();
    }

    std::vector<GameBlock*>& GameMap::operator[](std::size_t row)
    {
        return _elements[row];
    }

    const std::vector<GameBlock*>& GameMap::operator[](std::size_t row) const
    {
        return _elements[row];
    }

    GameBlock* GameMap::at(std::size_t row, std::size_t col)
    {
        return _elements[row][col];
    }

    const GameBlock* GameMap::at(std::size_t row, std::size_t col) const
    {
        return _elements[row][col];
    }

    GameBlock* GameMap::at(const Point& p)
    {
        return _elements[p.y()][p.x()];
    }

    const GameBlock* GameMap::at(const Point& p) const
    {

        return _elements[p.y()][p.x()];
    }

    std::vector<std::size_t> GameMap::convertPointTo1DIndex(const std::vector<Point> &pts) const
    {
        std::vector<std::size_t> output(pts.size());
        for(std::size_t i = 0; i < pts.size(); i++)
            output[i] = pts[i].y() * cols() + pts[i].x();
        return output;
    }

    std::vector<Point> GameMap::convert1DIndexToPoint(const std::vector<std::size_t> &pts) const
    {
        std::vector<Point> output;
        output.reserve(1);
        for(std::size_t i = 0; i < pts.size(); i++)
        {
            int y = pts[i] / static_cast<int>(cols());
            int x = pts[i] % static_cast<int>(cols());
            output.push_back(Point(x, y));
        }
        return output;
    }

    std::vector<Point> GameMap::getNeighboringPoints(const Point& p) const
    {
        std::vector<Point> output;
        output.reserve(9);
        for(int x = p.x() - 1; x <= p.x() + 1; x++)
        {
            if(x < 0 || x > static_cast<int>(cols()) - 1)
                continue;
            for(int y = p.y() - 1; y <= p.y() + 1; y++)
            {
                if(y < 0 || y > static_cast<int>(rows()) - 1)
                    continue;
                output.push_back(Point(x, y));
            }
        }
        return output;
    }

    std::vector<Point> GameMap::generateMines(std::size_t mines) const
    {
        const std::vector<std::size_t> emptyNeighbors =
            convertPointTo1DIndex(getNeighboringPoints(_startPosition));
        srand(static_cast<unsigned int>(time(nullptr)));
        const std::size_t n = cols() * rows();
        std::set<std::size_t> unique_randoms;
        for(std::size_t i = 0; i < n; i++)
            unique_randoms.insert(i);
        for(std::size_t i = 0; i < emptyNeighbors.size(); i++)
            unique_randoms.erase(emptyNeighbors[i]);
        std::vector<std::size_t> randoms(unique_randoms.begin(), unique_randoms.end());
        for(std::size_t i = 0; i < randoms.size(); i++)
            for(std::size_t j = 0; j < 10; j++)
                std::swap(randoms[rand() % randoms.size()], randoms[rand() % randoms.size()]);
        if(mines > randoms.size())
            throw std::logic_error("No enough spaces to fill mines");
        std::vector<Point> output = convert1DIndexToPoint(randoms);
        return std::vector<Point>(output.begin(), output.begin() + mines);
    }
}
