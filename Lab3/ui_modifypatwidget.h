/********************************************************************************
** Form generated from reading UI file 'modifypatwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYPATWIDGET_H
#define UI_MODIFYPATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyPatWidget
{
public:

    void setupUi(QWidget *ModifyPatWidget)
    {
        if (ModifyPatWidget->objectName().isEmpty())
            ModifyPatWidget->setObjectName("ModifyPatWidget");
        ModifyPatWidget->resize(400, 300);

        retranslateUi(ModifyPatWidget);

        QMetaObject::connectSlotsByName(ModifyPatWidget);
    } // setupUi

    void retranslateUi(QWidget *ModifyPatWidget)
    {
        ModifyPatWidget->setWindowTitle(QCoreApplication::translate("ModifyPatWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyPatWidget: public Ui_ModifyPatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYPATWIDGET_H
