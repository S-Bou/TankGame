#include "mainwindow.h"
#include "ui_mainwindow.h"

extern Game *game;
extern WindowStart *s;

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);

    game = new Game(this);
    game->setGeometry(0,0,800,600);
    game->show();

    s = new WindowStart(this);
    s->setGeometry(400-(285/2),300-(390/2),285,390);
    s->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
