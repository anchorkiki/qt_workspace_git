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
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *MainWideget)
    {
        if (MainWideget->objectName().isEmpty())
            MainWideget->setObjectName("MainWideget");
        MainWideget->resize(800, 600);
        verticalLayout = new QVBoxLayout(MainWideget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(MainWideget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(MainWideget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(MainWideget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


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
        pushButton->setText(QCoreApplication::translate("MainWideget", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("MainWideget", "\345\214\273\351\231\242\350\257\212\347\226\227\347\263\273\347\273\237\347\224\250\346\210\267\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWideget", "\346\263\250\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWideget: public Ui_MainWideget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDEGET_H
