/********************************************************************************
** Form generated from reading UI file 'addsubwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSUBWIDGET_H
#define UI_ADDSUBWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddSubWidget
{
public:

    void setupUi(QWidget *AddSubWidget)
    {
        if (AddSubWidget->objectName().isEmpty())
            AddSubWidget->setObjectName("AddSubWidget");
        AddSubWidget->resize(400, 300);

        retranslateUi(AddSubWidget);

        QMetaObject::connectSlotsByName(AddSubWidget);
    } // setupUi

    void retranslateUi(QWidget *AddSubWidget)
    {
        AddSubWidget->setWindowTitle(QCoreApplication::translate("AddSubWidget", "\346\267\273\345\212\240\347\247\221\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSubWidget: public Ui_AddSubWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSUBWIDGET_H
