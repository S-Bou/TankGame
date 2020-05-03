#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "windowstart.h"
#include <QDialog>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //Game *game;
};

#endif // MAINWINDOW_H
