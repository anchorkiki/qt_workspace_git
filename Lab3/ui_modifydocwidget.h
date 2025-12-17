/********************************************************************************
** Form generated from reading UI file 'modifydocwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYDOCWIDGET_H
#define UI_MODIFYDOCWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyDocWidget
{
public:

    void setupUi(QWidget *ModifyDocWidget)
    {
        if (ModifyDocWidget->objectName().isEmpty())
            ModifyDocWidget->setObjectName("ModifyDocWidget");
        ModifyDocWidget->resize(400, 300);

        retranslateUi(ModifyDocWidget);

        QMetaObject::connectSlotsByName(ModifyDocWidget);
    } // setupUi

    void retranslateUi(QWidget *ModifyDocWidget)
    {
        ModifyDocWidget->setWindowTitle(QCoreApplication::translate("ModifyDocWidget", "\344\277\256\346\224\271\345\214\273\347\224\237\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyDocWidget: public Ui_ModifyDocWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYDOCWIDGET_H
