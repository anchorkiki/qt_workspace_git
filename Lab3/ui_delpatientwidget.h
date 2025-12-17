/********************************************************************************
** Form generated from reading UI file 'delpatientwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELPATIENTWIDGET_H
#define UI_DELPATIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DelPatientWidget
{
public:

    void setupUi(QWidget *DelPatientWidget)
    {
        if (DelPatientWidget->objectName().isEmpty())
            DelPatientWidget->setObjectName("DelPatientWidget");
        DelPatientWidget->resize(400, 300);

        retranslateUi(DelPatientWidget);

        QMetaObject::connectSlotsByName(DelPatientWidget);
    } // setupUi

    void retranslateUi(QWidget *DelPatientWidget)
    {
        DelPatientWidget->setWindowTitle(QCoreApplication::translate("DelPatientWidget", "\345\210\240\351\231\244\346\202\243\350\200\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DelPatientWidget: public Ui_DelPatientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELPATIENTWIDGET_H
