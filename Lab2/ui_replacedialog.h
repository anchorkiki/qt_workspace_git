/********************************************************************************
** Form generated from reading UI file 'replacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEDIALOG_H
#define UI_REPLACEDIALOG_H

#include <QtCore/QVariant>
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

class Ui_ReplaceDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *search_edit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *replace_edit;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QGroupBox *gb_direction;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbUp;
    QRadioButton *rbDown;
    QVBoxLayout *verticalLayout;
    QPushButton *bt_next;
    QPushButton *bt_replace;
    QPushButton *bt_replaceAll;
    QPushButton *bt_cancel;

    void setupUi(QDialog *ReplaceDialog)
    {
        if (ReplaceDialog->objectName().isEmpty())
            ReplaceDialog->setObjectName(QStringLiteral("ReplaceDialog"));
        ReplaceDialog->resize(418, 159);
        horizontalLayout_4 = new QHBoxLayout(ReplaceDialog);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(ReplaceDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 20));

        horizontalLayout_2->addWidget(label);

        search_edit = new QLineEdit(ReplaceDialog);
        search_edit->setObjectName(QStringLiteral("search_edit"));

        horizontalLayout_2->addWidget(search_edit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(ReplaceDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 20));

        horizontalLayout->addWidget(label_2);

        replace_edit = new QLineEdit(ReplaceDialog);
        replace_edit->setObjectName(QStringLiteral("replace_edit"));

        horizontalLayout->addWidget(replace_edit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioButton = new QRadioButton(ReplaceDialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_3->addWidget(radioButton);

        gb_direction = new QGroupBox(ReplaceDialog);
        gb_direction->setObjectName(QStringLiteral("gb_direction"));
        verticalLayout_2 = new QVBoxLayout(gb_direction);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        rbUp = new QRadioButton(gb_direction);
        rbUp->setObjectName(QStringLiteral("rbUp"));

        verticalLayout_2->addWidget(rbUp);

        rbDown = new QRadioButton(gb_direction);
        rbDown->setObjectName(QStringLiteral("rbDown"));

        verticalLayout_2->addWidget(rbDown);


        horizontalLayout_3->addWidget(gb_direction);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        bt_next = new QPushButton(ReplaceDialog);
        bt_next->setObjectName(QStringLiteral("bt_next"));

        verticalLayout->addWidget(bt_next);

        bt_replace = new QPushButton(ReplaceDialog);
        bt_replace->setObjectName(QStringLiteral("bt_replace"));

        verticalLayout->addWidget(bt_replace);

        bt_replaceAll = new QPushButton(ReplaceDialog);
        bt_replaceAll->setObjectName(QStringLiteral("bt_replaceAll"));

        verticalLayout->addWidget(bt_replaceAll);

        bt_cancel = new QPushButton(ReplaceDialog);
        bt_cancel->setObjectName(QStringLiteral("bt_cancel"));

        verticalLayout->addWidget(bt_cancel);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(ReplaceDialog);

        QMetaObject::connectSlotsByName(ReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplaceDialog)
    {
        ReplaceDialog->setWindowTitle(QApplication::translate("ReplaceDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\347\233\256\346\240\207:", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReplaceDialog", "\346\233\277\346\215\242\344\270\272:", Q_NULLPTR));
        radioButton->setText(QApplication::translate("ReplaceDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", Q_NULLPTR));
        gb_direction->setTitle(QApplication::translate("ReplaceDialog", "\346\226\271\345\220\221", Q_NULLPTR));
        rbUp->setText(QApplication::translate("ReplaceDialog", "\345\220\221\344\270\212(&U)", Q_NULLPTR));
        rbDown->setText(QApplication::translate("ReplaceDialog", "\345\220\221\344\270\213(&D)", Q_NULLPTR));
        bt_next->setText(QApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252(&F)", Q_NULLPTR));
        bt_replace->setText(QApplication::translate("ReplaceDialog", "\346\233\277\346\215\242(&R)", Q_NULLPTR));
        bt_replaceAll->setText(QApplication::translate("ReplaceDialog", "\345\205\250\351\203\250\346\233\277\346\215\242(&A)", Q_NULLPTR));
        bt_cancel->setText(QApplication::translate("ReplaceDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReplaceDialog: public Ui_ReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
