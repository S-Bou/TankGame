#include <QApplication>
#include "mainwindow.h"
#include "windowstart.h"
#include "game.h"

Game *game;
WindowStart *s;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}

