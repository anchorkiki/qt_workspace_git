/********************************************************************************
** Form generated from reading UI file 'docwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCWIDGET_H
#define UI_DOCWIDGET_H

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

class Ui_DocWidget
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

    void setupUi(QWidget *DocWidget)
    {
        if (DocWidget->objectName().isEmpty())
            DocWidget->setObjectName("DocWidget");
        DocWidget->resize(490, 300);
        verticalLayout = new QVBoxLayout(DocWidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lineEdit = new QLineEdit(DocWidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        searchBtn = new QPushButton(DocWidget);
        searchBtn->setObjectName("searchBtn");

        horizontalLayout->addWidget(searchBtn);

        addBtn = new QPushButton(DocWidget);
        addBtn->setObjectName("addBtn");

        horizontalLayout->addWidget(addBtn);

        delBtn = new QPushButton(DocWidget);
        delBtn->setObjectName("delBtn");

        horizontalLayout->addWidget(delBtn);

        editBtn = new QPushButton(DocWidget);
        editBtn->setObjectName("editBtn");

        horizontalLayout->addWidget(editBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(DocWidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);


        retranslateUi(DocWidget);

        QMetaObject::connectSlotsByName(DocWidget);
    } // setupUi

    void retranslateUi(QWidget *DocWidget)
    {
        DocWidget->setWindowTitle(QCoreApplication::translate("DocWidget", "\345\214\273\347\224\237\347\256\241\347\220\206", nullptr));
        searchBtn->setText(QCoreApplication::translate("DocWidget", "\346\237\245\346\211\276", nullptr));
        addBtn->setText(QCoreApplication::translate("DocWidget", "\346\267\273\345\212\240", nullptr));
        delBtn->setText(QCoreApplication::translate("DocWidget", "\345\210\240\351\231\244", nullptr));
        editBtn->setText(QCoreApplication::translate("DocWidget", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DocWidget: public Ui_DocWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCWIDGET_H
