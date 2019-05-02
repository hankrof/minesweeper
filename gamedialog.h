#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H
#include <QDialog>
class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
namespace ms
{
    class GameStateControllerContext;
    class GameDialog : public QDialog
    {
        Q_OBJECT
    public:
        GameDialog(GameStateControllerContext& ctrl);
        GameDialog& setMessage(QString message);
    private slots:
        void onGameDialogFinish(int);
    private:
        QLabel*      _textLabel;
        QVBoxLayout* _allLayout;
        QHBoxLayout* _buttonsLayout;
        QPushButton* _yesButton;
        QPushButton* _noButton;
    private:
        GameStateControllerContext& _ctrl;
    };
}

#endif // GAMEDIALOG_H
