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
        ModifyDocWidget->setWindowTitle(QCoreApplication::translate("ModifyDocWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyDocWidget: public Ui_ModifyDocWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYDOCWIDGET_H
