/********************************************************************************
** Form generated from reading UI file 'subwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWIDGET_H
#define UI_SUBWIDGET_H

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

class Ui_SubWidget
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

    void setupUi(QWidget *SubWidget)
    {
        if (SubWidget->objectName().isEmpty())
            SubWidget->setObjectName("SubWidget");
        SubWidget->resize(466, 300);
        verticalLayout = new QVBoxLayout(SubWidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lineEdit = new QLineEdit(SubWidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        searchBtn = new QPushButton(SubWidget);
        searchBtn->setObjectName("searchBtn");

        horizontalLayout->addWidget(searchBtn);

        addBtn = new QPushButton(SubWidget);
        addBtn->setObjectName("addBtn");

        horizontalLayout->addWidget(addBtn);

        delBtn = new QPushButton(SubWidget);
        delBtn->setObjectName("delBtn");

        horizontalLayout->addWidget(delBtn);

        editBtn = new QPushButton(SubWidget);
        editBtn->setObjectName("editBtn");

        horizontalLayout->addWidget(editBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(SubWidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);


        retranslateUi(SubWidget);

        QMetaObject::connectSlotsByName(SubWidget);
    } // setupUi

    void retranslateUi(QWidget *SubWidget)
    {
        SubWidget->setWindowTitle(QCoreApplication::translate("SubWidget", "\347\247\221\345\256\244\347\256\241\347\220\206", nullptr));
        searchBtn->setText(QCoreApplication::translate("SubWidget", "\346\237\245\346\211\276", nullptr));
        addBtn->setText(QCoreApplication::translate("SubWidget", "\346\267\273\345\212\240", nullptr));
        delBtn->setText(QCoreApplication::translate("SubWidget", "\345\210\240\351\231\244", nullptr));
        editBtn->setText(QCoreApplication::translate("SubWidget", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubWidget: public Ui_SubWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWIDGET_H
