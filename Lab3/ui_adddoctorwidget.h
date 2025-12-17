/********************************************************************************
** Form generated from reading UI file 'adddoctorwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDOCTORWIDGET_H
#define UI_ADDDOCTORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDoctorWidget
{
public:

    void setupUi(QWidget *AddDoctorWidget)
    {
        if (AddDoctorWidget->objectName().isEmpty())
            AddDoctorWidget->setObjectName("AddDoctorWidget");
        AddDoctorWidget->resize(400, 300);

        retranslateUi(AddDoctorWidget);

        QMetaObject::connectSlotsByName(AddDoctorWidget);
    } // setupUi

    void retranslateUi(QWidget *AddDoctorWidget)
    {
        AddDoctorWidget->setWindowTitle(QCoreApplication::translate("AddDoctorWidget", "\346\267\273\345\212\240\345\214\273\347\224\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDoctorWidget: public Ui_AddDoctorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDOCTORWIDGET_H
