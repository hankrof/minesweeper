#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include <QWidget>
class QPaintEvent;
class QMouseEvent;
namespace ms
{
    class GameWorld;
    class Environment;
    class GameStateControllerContext;
    class GameScreen : public QWidget
    {
        Q_OBJECT
    public:
        explicit GameScreen(GameStateControllerContext& ctrl, QWidget *parent = 0);
        void initGameEnvir(Environment* envir);
        void paintEvent(QPaintEvent *);
        void mousePressEvent(QMouseEvent *);
        void mouseReleaseEvent(QMouseEvent *);
        void mouseMoveEvent(QMouseEvent*);
        void paintGameWorld(GameWorld* world);
    private:
        GameStateControllerContext &_ctrl;
        QPainter* _painter;
        Environment *_envir;
    };
}
#endif // GAMESCREEN_H
