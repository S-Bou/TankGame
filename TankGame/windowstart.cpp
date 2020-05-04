#include "windowstart.h"
#include "ui_windowstart.h"
#include "game.h"

extern Game *game;

WindowStart::WindowStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowStart)
{
    ui->setupUi(this);
}

WindowStart::~WindowStart()
{
    delete ui;
}

void WindowStart::on_pushButton_clicked()
{
    game->StartGame();
    game->ResetLevels();
    close();
}

