/********************************************************************************
** Form generated from reading UI file 'modifysubwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYSUBWIDGET_H
#define UI_MODIFYSUBWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifySubWidget
{
public:

    void setupUi(QWidget *ModifySubWidget)
    {
        if (ModifySubWidget->objectName().isEmpty())
            ModifySubWidget->setObjectName("ModifySubWidget");
        ModifySubWidget->resize(400, 300);

        retranslateUi(ModifySubWidget);

        QMetaObject::connectSlotsByName(ModifySubWidget);
    } // setupUi

    void retranslateUi(QWidget *ModifySubWidget)
    {
        ModifySubWidget->setWindowTitle(QCoreApplication::translate("ModifySubWidget", "\344\277\256\346\224\271\347\247\221\345\256\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifySubWidget: public Ui_ModifySubWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYSUBWIDGET_H
