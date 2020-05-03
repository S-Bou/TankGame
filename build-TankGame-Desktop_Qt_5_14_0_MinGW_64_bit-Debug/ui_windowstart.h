/********************************************************************************
** Form generated from reading UI file 'windowstart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSTART_H
#define UI_WINDOWSTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowStart
{
public:
    QPushButton *pushButton;
    QLabel *label_Welcome;
    QLabel *label_Instructions;
    QLabel *label_Start;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *WindowStart)
    {
        if (WindowStart->objectName().isEmpty())
            WindowStart->setObjectName(QString::fromUtf8("WindowStart"));
        WindowStart->resize(285, 390);
        WindowStart->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(WindowStart);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 170, 111, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));
        label_Welcome = new QLabel(WindowStart);
        label_Welcome->setObjectName(QString::fromUtf8("label_Welcome"));
        label_Welcome->setGeometry(QRect(40, 10, 231, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI Black"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setKerning(true);
        label_Welcome->setFont(font1);
        label_Welcome->setAutoFillBackground(false);
        label_Instructions = new QLabel(WindowStart);
        label_Instructions->setObjectName(QString::fromUtf8("label_Instructions"));
        label_Instructions->setGeometry(QRect(20, 220, 251, 151));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI Black"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_Instructions->setFont(font2);
        label_Start = new QLabel(WindowStart);
        label_Start->setObjectName(QString::fromUtf8("label_Start"));
        label_Start->setGeometry(QRect(60, 50, 171, 91));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI Black"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        label_Start->setFont(font3);
        label_Start->setAlignment(Qt::AlignCenter);
        graphicsView = new QGraphicsView(WindowStart);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 285, 390));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/greencamouflage.jpg);"));
        graphicsView->raise();
        pushButton->raise();
        label_Welcome->raise();
        label_Instructions->raise();
        label_Start->raise();

        retranslateUi(WindowStart);

        QMetaObject::connectSlotsByName(WindowStart);
    } // setupUi

    void retranslateUi(QWidget *WindowStart)
    {
        WindowStart->setWindowTitle(QCoreApplication::translate("WindowStart", "TankGame", nullptr));
        pushButton->setText(QCoreApplication::translate("WindowStart", "START", nullptr));
        label_Welcome->setText(QCoreApplication::translate("WindowStart", "Welcome to TankGame", nullptr));
        label_Instructions->setText(QCoreApplication::translate("WindowStart", "Instructions: only you have kill\n"
"ten enemies before four scape.\n"
"W -> Front\n"
"S  ->  Back\n"
"A -> Turn left\n"
"D -> Turn right\n"
"Space -> Shot", nullptr));
        label_Start->setText(QCoreApplication::translate("WindowStart", "For play press\n"
"start\n"
"and enjoy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowStart: public Ui_WindowStart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSTART_H
