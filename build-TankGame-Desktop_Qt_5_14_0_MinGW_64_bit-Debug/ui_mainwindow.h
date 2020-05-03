/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *label_lose;
    QLabel *label_Win;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 630);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        label_lose = new QLabel(MainWindow);
        label_lose->setObjectName(QString::fromUtf8("label_lose"));
        label_lose->setEnabled(false);
        label_lose->setGeometry(QRect(270, 50, 250, 60));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        label_lose->setFont(font);
        label_Win = new QLabel(MainWindow);
        label_Win->setObjectName(QString::fromUtf8("label_Win"));
        label_Win->setEnabled(false);
        label_Win->setGeometry(QRect(270, 50, 250, 60));
        label_Win->setFont(font);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TankGame", nullptr));
        label_lose->setText(QCoreApplication::translate("MainWindow", "YOU LOSE", nullptr));
        label_Win->setText(QCoreApplication::translate("MainWindow", "YOU WIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
