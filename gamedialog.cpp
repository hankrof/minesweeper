#include "gamedialog.h"
#include "gamestatectrlctx.h"
#include <string>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QValidator>
#include <QDebug>
namespace ms
{
    GameResultDialog::GameResultDialog(GameStateControllerContext &ctrl)
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

    GameResultDialog& GameResultDialog::setMessage(QString message)
    {
        _textLabel->setText(message);
        return *this;
    }

    void GameResultDialog::onGameDialogFinish(int choice)
    {
        _ctrl.processRestartGame(choice);
    }

    GameSettingsDialog::GameSettingsDialog(GameStateControllerContext& ctrl)
        : _ctrl(ctrl)
    {
        _saveButton    = new QPushButton("Save"  , this);
        _cancelButton  = new QPushButton("Cancel", this);
        _rowsSpinBox   = new QSpinBox   (this);
        _colsSpinBox   = new QSpinBox   (this);
        _minesSpinBox  = new QSpinBox   (this);
        _densityEdit   = new QLineEdit  (this);
        _buttonsLayout = new QHBoxLayout(    );
        _allLayout     = new QFormLayout(this);
        _buttonsLayout->addWidget(_saveButton  );
        _buttonsLayout->addWidget(_cancelButton);
        _rowsSpinBox->setRange (8, 255);
        _colsSpinBox->setRange (8, 255);
        _minesSpinBox->setRange(1, 65000);
        _allLayout->addRow(new QLabel("Number of rows:",    this), _rowsSpinBox );
        _allLayout->addRow(new QLabel("Number of columns:", this), _colsSpinBox );
        _allLayout->addRow(new QLabel("Number of mines:"  , this), _minesSpinBox);
        _allLayout->addRow(new QLabel("Density of Mines:" , this), _densityEdit );
        _allLayout->addItem(_buttonsLayout);
        connect(_rowsSpinBox,  SIGNAL(valueChanged(int)), this, SLOT(valueChangedDensity()));
        connect(_colsSpinBox,  SIGNAL(valueChanged(int)), this, SLOT(valueChangedDensity()));
        connect(_minesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueChangedDensity()));
        connect(_saveButton,   SIGNAL(clicked(bool)), this, SLOT(accept()));
        connect(_cancelButton, SIGNAL(clicked(bool)), this, SLOT(reject()));
        connect(this, SIGNAL(finished(int)), this, SLOT(onGameDialogFinish()));
        _densityEdit->setDisabled(true);
        setWindowTitle("Game Settings");
        valueChangedDensity();
    }

    void GameSettingsDialog::onGameDialogFinish()
    {
        _ctrl.processSaveSettings(_rowsSpinBox->value(), _colsSpinBox->value(), _minesSpinBox->value());
    }

    void GameSettingsDialog::valueChangedDensity()
    {
        int rows  = _rowsSpinBox->value();
        int cols  = _colsSpinBox->value();
        int mines = _minesSpinBox->value();
        if(mines > (rows * cols - 1))
        {
            mines = rows * cols - 1;
            _minesSpinBox->setValue(mines);
        }
        double density = static_cast<double>(mines) / (rows * cols);
        _densityEdit->setText(QString::fromStdString(std::to_string(density)));
    }
}
