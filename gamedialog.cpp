#include "gamedialog.h"
#include "gamestatectrlctx.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
namespace ms
{
    GameDialog::GameDialog(GameStateControllerContext &ctrl)
        : _textLabel(nullptr), _allLayout(nullptr)
        , _buttonsLayout(nullptr), _yesButton(nullptr)
        , _noButton(nullptr), _ctrl(ctrl)
    {
        _textLabel = new QLabel("", this);
        _yesButton = new QPushButton("Yes", this);
        _noButton  = new QPushButton ("No", this);
        _buttonsLayout = new QHBoxLayout();
        _buttonsLayout->addWidget(_yesButton);
        _buttonsLayout->addSpacing(5);
        _buttonsLayout->addWidget(_noButton);
        _allLayout = new QVBoxLayout();
        _allLayout->addWidget(_textLabel);
        _allLayout->addItem(_buttonsLayout);
        setLayout(_allLayout);
        connect(_yesButton, SIGNAL(clicked(bool)), this, SLOT(accept()));
        connect(_noButton,  SIGNAL(clicked(bool)), this, SLOT(reject()));
        connect(this, SIGNAL(finished(int)), this, SLOT(onGameDialogFinish(int)));
    }

    GameDialog& GameDialog::setMessage(QString message)
    {
        _textLabel->setText(message);
        return *this;
    }

    void GameDialog::onGameDialogFinish(int choice)
    {
        _ctrl.processRestartGame(choice);
    }
}
