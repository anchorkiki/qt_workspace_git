/********************************************************************************
** Form generated from reading UI file 'patientwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTWIDGET_H
#define UI_PATIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QPushButton *searchBtn;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QPushButton *editBtn;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;

    void setupUi(QWidget *PatientWidget)
    {
        if (PatientWidget->objectName().isEmpty())
            PatientWidget->setObjectName("PatientWidget");
        PatientWidget->resize(461, 300);
        verticalLayout = new QVBoxLayout(PatientWidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lineEdit = new QLineEdit(PatientWidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        searchBtn = new QPushButton(PatientWidget);
        searchBtn->setObjectName("searchBtn");

        horizontalLayout->addWidget(searchBtn);

        addBtn = new QPushButton(PatientWidget);
        addBtn->setObjectName("addBtn");

        horizontalLayout->addWidget(addBtn);

        delBtn = new QPushButton(PatientWidget);
        delBtn->setObjectName("delBtn");

        horizontalLayout->addWidget(delBtn);

        editBtn = new QPushButton(PatientWidget);
        editBtn->setObjectName("editBtn");

        horizontalLayout->addWidget(editBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(PatientWidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);


        retranslateUi(PatientWidget);

        QMetaObject::connectSlotsByName(PatientWidget);
    } // setupUi

    void retranslateUi(QWidget *PatientWidget)
    {
        PatientWidget->setWindowTitle(QCoreApplication::translate("PatientWidget", "\346\202\243\350\200\205\347\256\241\347\220\206", nullptr));
        searchBtn->setText(QCoreApplication::translate("PatientWidget", "\346\237\245\346\211\276", nullptr));
        addBtn->setText(QCoreApplication::translate("PatientWidget", "\346\267\273\345\212\240", nullptr));
        delBtn->setText(QCoreApplication::translate("PatientWidget", "\345\210\240\351\231\244", nullptr));
        editBtn->setText(QCoreApplication::translate("PatientWidget", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientWidget: public Ui_PatientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTWIDGET_H
