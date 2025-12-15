/********************************************************************************
** Form generated from reading UI file 'deldocwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELDOCWIDGET_H
#define UI_DELDOCWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DelDocWidget
{
public:

    void setupUi(QWidget *DelDocWidget)
    {
        if (DelDocWidget->objectName().isEmpty())
            DelDocWidget->setObjectName("DelDocWidget");
        DelDocWidget->resize(400, 300);

        retranslateUi(DelDocWidget);

        QMetaObject::connectSlotsByName(DelDocWidget);
    } // setupUi

    void retranslateUi(QWidget *DelDocWidget)
    {
        DelDocWidget->setWindowTitle(QCoreApplication::translate("DelDocWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DelDocWidget: public Ui_DelDocWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELDOCWIDGET_H
