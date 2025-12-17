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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyPatWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *dbEditID;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLineEdit *dbEditName;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QLineEdit *dbEditIDCard;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    QComboBox *dbComboSex;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_13;
    QDateEdit *dbDateEditDOB;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QSpinBox *dbSpinHeight;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_15;
    QSpinBox *dbSpinWeight;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_16;
    QLineEdit *dbEditMobile;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *dbCreatedTimestamp;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *saveBtn_2;
    QPushButton *backBtn_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ModifyPatWidget)
    {
        if (ModifyPatWidget->objectName().isEmpty())
            ModifyPatWidget->setObjectName("ModifyPatWidget");
        ModifyPatWidget->resize(360, 300);
        horizontalLayout_2 = new QHBoxLayout(ModifyPatWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(82, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_8 = new QLabel(ModifyPatWidget);
        label_8->setObjectName("label_8");

        horizontalLayout_9->addWidget(label_8);

        dbEditID = new QLineEdit(ModifyPatWidget);
        dbEditID->setObjectName("dbEditID");

        horizontalLayout_9->addWidget(dbEditID);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_10 = new QLabel(ModifyPatWidget);
        label_10->setObjectName("label_10");

        horizontalLayout_11->addWidget(label_10);

        dbEditName = new QLineEdit(ModifyPatWidget);
        dbEditName->setObjectName("dbEditName");

        horizontalLayout_11->addWidget(dbEditName);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_11 = new QLabel(ModifyPatWidget);
        label_11->setObjectName("label_11");

        horizontalLayout_12->addWidget(label_11);

        dbEditIDCard = new QLineEdit(ModifyPatWidget);
        dbEditIDCard->setObjectName("dbEditIDCard");

        horizontalLayout_12->addWidget(dbEditIDCard);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_12 = new QLabel(ModifyPatWidget);
        label_12->setObjectName("label_12");

        horizontalLayout_13->addWidget(label_12);

        dbComboSex = new QComboBox(ModifyPatWidget);
        dbComboSex->setObjectName("dbComboSex");

        horizontalLayout_13->addWidget(dbComboSex);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_13 = new QLabel(ModifyPatWidget);
        label_13->setObjectName("label_13");

        horizontalLayout_14->addWidget(label_13);

        dbDateEditDOB = new QDateEdit(ModifyPatWidget);
        dbDateEditDOB->setObjectName("dbDateEditDOB");

        horizontalLayout_14->addWidget(dbDateEditDOB);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        label_14 = new QLabel(ModifyPatWidget);
        label_14->setObjectName("label_14");

        horizontalLayout_15->addWidget(label_14);

        dbSpinHeight = new QSpinBox(ModifyPatWidget);
        dbSpinHeight->setObjectName("dbSpinHeight");

        horizontalLayout_15->addWidget(dbSpinHeight);


        verticalLayout_2->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_15 = new QLabel(ModifyPatWidget);
        label_15->setObjectName("label_15");

        horizontalLayout_16->addWidget(label_15);

        dbSpinWeight = new QSpinBox(ModifyPatWidget);
        dbSpinWeight->setObjectName("dbSpinWeight");

        horizontalLayout_16->addWidget(dbSpinWeight);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        label_16 = new QLabel(ModifyPatWidget);
        label_16->setObjectName("label_16");

        horizontalLayout_17->addWidget(label_16);

        dbEditMobile = new QLineEdit(ModifyPatWidget);
        dbEditMobile->setObjectName("dbEditMobile");

        horizontalLayout_17->addWidget(dbEditMobile);


        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(ModifyPatWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        dbCreatedTimestamp = new QLineEdit(ModifyPatWidget);
        dbCreatedTimestamp->setObjectName("dbCreatedTimestamp");

        horizontalLayout->addWidget(dbCreatedTimestamp);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        saveBtn_2 = new QPushButton(ModifyPatWidget);
        saveBtn_2->setObjectName("saveBtn_2");

        horizontalLayout_18->addWidget(saveBtn_2);

        backBtn_2 = new QPushButton(ModifyPatWidget);
        backBtn_2->setObjectName("backBtn_2");

        horizontalLayout_18->addWidget(backBtn_2);


        verticalLayout_2->addLayout(horizontalLayout_18);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(81, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        retranslateUi(ModifyPatWidget);

        QMetaObject::connectSlotsByName(ModifyPatWidget);
    } // setupUi

    void retranslateUi(QWidget *ModifyPatWidget)
    {
        ModifyPatWidget->setWindowTitle(QCoreApplication::translate("ModifyPatWidget", "\344\277\256\346\224\271\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        label_8->setText(QCoreApplication::translate("ModifyPatWidget", "ID\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("ModifyPatWidget", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("ModifyPatWidget", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("ModifyPatWidget", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("ModifyPatWidget", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("ModifyPatWidget", "\350\272\253\351\253\230\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("ModifyPatWidget", "\344\275\223\351\207\215\357\274\232", nullptr));
        label_16->setText(QCoreApplication::translate("ModifyPatWidget", "\346\211\213\346\234\272\345\217\267\347\240\201\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("ModifyPatWidget", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        saveBtn_2->setText(QCoreApplication::translate("ModifyPatWidget", "\344\277\235\345\255\230", nullptr));
        backBtn_2->setText(QCoreApplication::translate("ModifyPatWidget", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyPatWidget: public Ui_ModifyPatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYPATWIDGET_H
