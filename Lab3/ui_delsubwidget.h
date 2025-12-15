/********************************************************************************
** Form generated from reading UI file 'delsubwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELSUBWIDGET_H
#define UI_DELSUBWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DelSubWidget
{
public:

    void setupUi(QWidget *DelSubWidget)
    {
        if (DelSubWidget->objectName().isEmpty())
            DelSubWidget->setObjectName("DelSubWidget");
        DelSubWidget->resize(400, 300);

        retranslateUi(DelSubWidget);

        QMetaObject::connectSlotsByName(DelSubWidget);
    } // setupUi

    void retranslateUi(QWidget *DelSubWidget)
    {
        DelSubWidget->setWindowTitle(QCoreApplication::translate("DelSubWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DelSubWidget: public Ui_DelSubWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELSUBWIDGET_H
