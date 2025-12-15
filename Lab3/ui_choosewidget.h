/********************************************************************************
** Form generated from reading UI file 'choosewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEWIDGET_H
#define UI_CHOOSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *subBtn;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *docBtn;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *patientBtn;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *ChooseWidget)
    {
        if (ChooseWidget->objectName().isEmpty())
            ChooseWidget->setObjectName("ChooseWidget");
        ChooseWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(ChooseWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        subBtn = new QPushButton(ChooseWidget);
        subBtn->setObjectName("subBtn");

        horizontalLayout->addWidget(subBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        docBtn = new QPushButton(ChooseWidget);
        docBtn->setObjectName("docBtn");

        horizontalLayout_2->addWidget(docBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        patientBtn = new QPushButton(ChooseWidget);
        patientBtn->setObjectName("patientBtn");

        horizontalLayout_3->addWidget(patientBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(ChooseWidget);

        QMetaObject::connectSlotsByName(ChooseWidget);
    } // setupUi

    void retranslateUi(QWidget *ChooseWidget)
    {
        ChooseWidget->setWindowTitle(QCoreApplication::translate("ChooseWidget", "\351\200\211\346\213\251", nullptr));
        subBtn->setText(QCoreApplication::translate("ChooseWidget", "\347\247\221\345\256\244\347\256\241\347\220\206", nullptr));
        docBtn->setText(QCoreApplication::translate("ChooseWidget", "\345\214\273\347\224\237\347\256\241\347\220\206", nullptr));
        patientBtn->setText(QCoreApplication::translate("ChooseWidget", "\346\202\243\350\200\205\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseWidget: public Ui_ChooseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEWIDGET_H
