/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets>
#include <QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton;
    QGroupBox *gb_direction;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbUp;
    QRadioButton *rbDown;
    QVBoxLayout *verticalLayout;
    QPushButton *bt_next;
    QPushButton *bt_cancel;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName(QStringLiteral("SearchDialog"));
        SearchDialog->resize(439, 174);
        horizontalLayout_3 = new QHBoxLayout(SearchDialog);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SearchDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(SearchDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButton = new QRadioButton(SearchDialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        gb_direction = new QGroupBox(SearchDialog);
        gb_direction->setObjectName(QStringLiteral("gb_direction"));
        verticalLayout_2 = new QVBoxLayout(gb_direction);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        rbUp = new QRadioButton(gb_direction);
        rbUp->setObjectName(QStringLiteral("rbUp"));

        verticalLayout_2->addWidget(rbUp);

        rbDown = new QRadioButton(gb_direction);
        rbDown->setObjectName(QStringLiteral("rbDown"));

        verticalLayout_2->addWidget(rbDown);


        horizontalLayout_2->addWidget(gb_direction);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        bt_next = new QPushButton(SearchDialog);
        bt_next->setObjectName(QStringLiteral("bt_next"));

        verticalLayout->addWidget(bt_next);

        bt_cancel = new QPushButton(SearchDialog);
        bt_cancel->setObjectName(QStringLiteral("bt_cancel"));

        verticalLayout->addWidget(bt_cancel);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QApplication::translate("SearchDialog", "\346\237\245\346\211\276", Q_NULLPTR));
        label->setText(QApplication::translate("SearchDialog", "\346\237\245\346\211\276\347\233\256\346\240\207:", Q_NULLPTR));
        radioButton->setText(QApplication::translate("SearchDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", Q_NULLPTR));
        gb_direction->setTitle(QApplication::translate("SearchDialog", "\346\226\271\345\220\221", Q_NULLPTR));
        rbUp->setText(QApplication::translate("SearchDialog", "\345\220\221\344\270\212(&U)", Q_NULLPTR));
        rbDown->setText(QApplication::translate("SearchDialog", "\345\220\221\344\270\213(&D)", Q_NULLPTR));
        bt_next->setText(QApplication::translate("SearchDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", Q_NULLPTR));
        bt_cancel->setText(QApplication::translate("SearchDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
