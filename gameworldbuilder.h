#ifndef GAMEWORLDBUILDER_H
#define GAMEWORLDBUILDER_H
#include <memory>
namespace ms
{
    class GameWorld;
    class GameWorldBuilder
    {
    public:
        GameWorldBuilder();
        virtual ~GameWorldBuilder();
        virtual GameWorldBuilder& buildMap() = 0;
        virtual std::shared_ptr<GameWorld> getResult() const final;
    private:
        std::shared_ptr<GameWorld> _product;
    };

    class GameWorldEasyModeBuilder : public GameWorldBuilder
    {
    public:
        GameWorldEasyModeBuilder();
        GameWorldBuilder& buildMap();
    };

    class GameWorldNormalModeBuilder : public GameWorldBuilder
    {
    public:
        GameWorldNormalModeBuilder();
        GameWorldBuilder& buildMap();
    };

    class GameWorldHardModeBuilder : public GameWorldBuilder
    {
    public:
        GameWorldHardModeBuilder();
        GameWorldBuilder& buildMap();
    };
}
#endif // GAMEWORLDBUILDER_H
