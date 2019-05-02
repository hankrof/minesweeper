#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H
#include <QDialog>
class QLabel;
class QSpinBox;
class QLineEdit;
class QVBoxLayout;
class QHBoxLayout;
class QFormLayout;
class QPushButton;
namespace ms
{
    class GameStateControllerContext;
    class GameResultDialog : public QDialog
    {
        Q_OBJECT
    public:
        GameResultDialog(GameStateControllerContext& ctrl);
        GameResultDialog& setMessage(QString message);
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

    class GameSettingsDialog : public QDialog
    {
        Q_OBJECT
    public:
        GameSettingsDialog(GameStateControllerContext& ctrl);
    private slots:
        void valueChangedDensity();
        void onGameDialogFinish();
    private:
        GameStateControllerContext& _ctrl;
        QFormLayout *_allLayout;
        QHBoxLayout *_buttonsLayout;
        QSpinBox    *_rowsSpinBox;
        QSpinBox    *_colsSpinBox;
        QSpinBox    *_minesSpinBox;
        QLineEdit   *_densityEdit;
        QPushButton* _saveButton;
        QPushButton* _cancelButton;
    };
}

#endif // GAMEDIALOG_H
