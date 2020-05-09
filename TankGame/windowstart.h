#ifndef WINDOWSTART_H
#define WINDOWSTART_H

#include <QWidget>
#include "evaded.h"

namespace Ui {
class WindowStart;
}

class WindowStart : public QWidget
{
    Q_OBJECT

public:
    explicit WindowStart(QWidget *parent = nullptr);
    ~WindowStart();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_clicked();

private:
    Ui::WindowStart *ui;
};

#endif // WINDOWSTART_H
