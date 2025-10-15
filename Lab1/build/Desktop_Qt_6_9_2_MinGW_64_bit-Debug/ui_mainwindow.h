/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *butInverse;
    QPushButton *but4;
    QPushButton *but3;
    QPushButton *but5;
    QPushButton *but6;
    QPushButton *but9;
    QPushButton *butMultiply;
    QLineEdit *display;
    QPushButton *butDelete;
    QPushButton *butMinus;
    QPushButton *but8;
    QPushButton *butEqual;
    QPushButton *butCE;
    QPushButton *but0;
    QPushButton *butSubtract;
    QPushButton *butDivide;
    QPushButton *butC;
    QPushButton *but7;
    QPushButton *but1;
    QPushButton *butSquare;
    QPushButton *butPercent;
    QPushButton *butSquareRoot;
    QPushButton *butPoint;
    QPushButton *but2;
    QPushButton *butPlus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(698, 451);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        butInverse = new QPushButton(centralwidget);
        butInverse->setObjectName("butInverse");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(butInverse->sizePolicy().hasHeightForWidth());
        butInverse->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butInverse, 2, 0, 1, 1);

        but4 = new QPushButton(centralwidget);
        but4->setObjectName("but4");
        sizePolicy.setHeightForWidth(but4->sizePolicy().hasHeightForWidth());
        but4->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(but4, 4, 0, 1, 1);

        but3 = new QPushButton(centralwidget);
        but3->setObjectName("but3");
        sizePolicy.setHeightForWidth(but3->sizePolicy().hasHeightForWidth());
        but3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(but3, 5, 2, 1, 1);

        but5 = new QPushButton(centralwidget);
        but5->setObjectName("but5");
        sizePolicy.setHeightForWidth(but5->sizePolicy().hasHeightForWidth());
        but5->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(but5, 4, 1, 1, 1);

        but6 = new QPushButton(centralwidget);
        but6->setObjectName("but6");
        sizePolicy.setHeightForWidth(but6->sizePolicy().hasHeightForWidth());
        but6->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(but6, 4, 2, 1, 1);

        but9 = new QPushButton(centralwidget);
        but9->setObjectName("but9");
        sizePolicy.setHeightForWidth(but9->sizePolicy().hasHeightForWidth());
        but9->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(but9, 3, 2, 1, 1);

        butMultiply = new QPushButton(centralwidget);
        butMultiply->setObjectName("butMultiply");
        sizePolicy.setHeightForWidth(butMultiply->sizePolicy().hasHeightForWidth());
        butMultiply->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butMultiply, 3, 3, 1, 1);

        display = new QLineEdit(centralwidget);
        display->setObjectName("display");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(display->sizePolicy().hasHeightForWidth());
        display->setSizePolicy(sizePolicy1);
        display->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(display, 0, 0, 1, 4);

        butDelete = new QPushButton(centralwidget);
        butDelete->setObjectName("butDelete");
        sizePolicy.setHeightForWidth(butDelete->sizePolicy().hasHeightForWidth());
        butDelete->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butDelete, 1, 3, 1, 1);

        butMinus = new QPushButton(centralwidget);
        butMinus->setObjectName("butMinus");
        sizePolicy.setHeightForWidth(butMinus->sizePolicy().hasHeightForWidth());
        butMinus->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butMinus, 6, 0, 1, 1);

        but8 = new QPushButton(centralwidget);
        but8->setObjectName("but8");
        sizePolicy.setHeightForWidth(but8->sizePolicy().hasHeightForWidth());
        but8->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(but8, 3, 1, 1, 1);

        butEqual = new QPushButton(centralwidget);
        butEqual->setObjectName("butEqual");
        sizePolicy.setHeightForWidth(butEqual->sizePolicy().hasHeightForWidth());
        butEqual->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butEqual, 6, 3, 1, 1);

        butCE = new QPushButton(centralwidget);
        butCE->setObjectName("butCE");
        sizePolicy.setHeightForWidth(butCE->sizePolicy().hasHeightForWidth());
        butCE->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butCE, 1, 1, 1, 1);

        but0 = new QPushButton(centralwidget);
        but0->setObjectName("but0");
        sizePolicy.setHeightForWidth(but0->sizePolicy().hasHeightForWidth());
        but0->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(but0, 6, 1, 1, 1);

        butSubtract = new QPushButton(centralwidget);
        butSubtract->setObjectName("butSubtract");
        sizePolicy.setHeightForWidth(butSubtract->sizePolicy().hasHeightForWidth());
        butSubtract->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butSubtract, 4, 3, 1, 1);

        butDivide = new QPushButton(centralwidget);
        butDivide->setObjectName("butDivide");
        sizePolicy.setHeightForWidth(butDivide->sizePolicy().hasHeightForWidth());
        butDivide->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butDivide, 2, 3, 1, 1);

        butC = new QPushButton(centralwidget);
        butC->setObjectName("butC");
        sizePolicy.setHeightForWidth(butC->sizePolicy().hasHeightForWidth());
        butC->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butC, 1, 2, 1, 1);

        but7 = new QPushButton(centralwidget);
        but7->setObjectName("but7");
        sizePolicy.setHeightForWidth(but7->sizePolicy().hasHeightForWidth());
        but7->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(but7, 3, 0, 1, 1);

        but1 = new QPushButton(centralwidget);
        but1->setObjectName("but1");
        sizePolicy.setHeightForWidth(but1->sizePolicy().hasHeightForWidth());
        but1->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(but1, 5, 0, 1, 1);

        butSquare = new QPushButton(centralwidget);
        butSquare->setObjectName("butSquare");
        sizePolicy.setHeightForWidth(butSquare->sizePolicy().hasHeightForWidth());
        butSquare->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butSquare, 2, 1, 1, 1);

        butPercent = new QPushButton(centralwidget);
        butPercent->setObjectName("butPercent");
        sizePolicy.setHeightForWidth(butPercent->sizePolicy().hasHeightForWidth());
        butPercent->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butPercent, 1, 0, 1, 1);

        butSquareRoot = new QPushButton(centralwidget);
        butSquareRoot->setObjectName("butSquareRoot");
        sizePolicy.setHeightForWidth(butSquareRoot->sizePolicy().hasHeightForWidth());
        butSquareRoot->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butSquareRoot, 2, 2, 1, 1);

        butPoint = new QPushButton(centralwidget);
        butPoint->setObjectName("butPoint");
        sizePolicy.setHeightForWidth(butPoint->sizePolicy().hasHeightForWidth());
        butPoint->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butPoint, 6, 2, 1, 1);

        but2 = new QPushButton(centralwidget);
        but2->setObjectName("but2");
        sizePolicy.setHeightForWidth(but2->sizePolicy().hasHeightForWidth());
        but2->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(but2, 5, 1, 1, 1);

        butPlus = new QPushButton(centralwidget);
        butPlus->setObjectName("butPlus");
        sizePolicy.setHeightForWidth(butPlus->sizePolicy().hasHeightForWidth());
        butPlus->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(butPlus, 5, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 698, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        butInverse->setText(QCoreApplication::translate("MainWindow", "1/x", nullptr));
        but4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        but3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        but5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        but6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        but9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        butMultiply->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        display->setPlaceholderText(QCoreApplication::translate("MainWindow", "0", nullptr));
        butDelete->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        butMinus->setText(QCoreApplication::translate("MainWindow", "\302\261", nullptr));
        but8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        butEqual->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        butCE->setText(QCoreApplication::translate("MainWindow", "CE", nullptr));
        but0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        butSubtract->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        butDivide->setText(QCoreApplication::translate("MainWindow", "\342\236\227", nullptr));
        butC->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        but7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        but1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        butSquare->setText(QCoreApplication::translate("MainWindow", "x^2", nullptr));
        butPercent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        butSquareRoot->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        butPoint->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        but2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        butPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
