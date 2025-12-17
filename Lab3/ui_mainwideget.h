/********************************************************************************
** Form generated from reading UI file 'mainwideget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDEGET_H
#define UI_MAINWIDEGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWideget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *returnBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exitBtn;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *MainWideget)
    {
        if (MainWideget->objectName().isEmpty())
            MainWideget->setObjectName("MainWideget");
        MainWideget->resize(660, 426);
        verticalLayout = new QVBoxLayout(MainWideget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        returnBtn = new QPushButton(MainWideget);
        returnBtn->setObjectName("returnBtn");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/return.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        returnBtn->setIcon(icon);

        horizontalLayout->addWidget(returnBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        titleLabel = new QLabel(MainWideget);
        titleLabel->setObjectName("titleLabel");

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        exitBtn = new QPushButton(MainWideget);
        exitBtn->setObjectName("exitBtn");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/exit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exitBtn->setIcon(icon1);

        horizontalLayout->addWidget(exitBtn);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(MainWideget);
        stackedWidget->setObjectName("stackedWidget");

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(MainWideget);

        QMetaObject::connectSlotsByName(MainWideget);
    } // setupUi

    void retranslateUi(QWidget *MainWideget)
    {
        MainWideget->setWindowTitle(QCoreApplication::translate("MainWideget", "MainWideget", nullptr));
        returnBtn->setText(QString());
        titleLabel->setText(QString());
        exitBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWideget: public Ui_MainWideget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDEGET_H
