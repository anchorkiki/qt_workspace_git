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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *subBtn;
    QPushButton *docBtn;
    QPushButton *patientBtn;

    void setupUi(QWidget *ChooseWidget)
    {
        if (ChooseWidget->objectName().isEmpty())
            ChooseWidget->setObjectName("ChooseWidget");
        ChooseWidget->resize(400, 299);
        horizontalLayout = new QHBoxLayout(ChooseWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        subBtn = new QPushButton(ChooseWidget);
        subBtn->setObjectName("subBtn");

        horizontalLayout->addWidget(subBtn);

        docBtn = new QPushButton(ChooseWidget);
        docBtn->setObjectName("docBtn");

        horizontalLayout->addWidget(docBtn);

        patientBtn = new QPushButton(ChooseWidget);
        patientBtn->setObjectName("patientBtn");

        horizontalLayout->addWidget(patientBtn);


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
