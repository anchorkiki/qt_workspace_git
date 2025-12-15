/********************************************************************************
** Form generated from reading UI file 'addpatientwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPATIENTWIDGET_H
#define UI_ADDPATIENTWIDGET_H

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

class Ui_AddPatientWidget
{
public:
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *idEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *identityEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QComboBox *genderComb;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDateEdit *bornSpinB;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *heighSpinB;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QSpinBox *weightSpinB;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *phoneEdit;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *saveBtn;
    QPushButton *backBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *AddPatientWidget)
    {
        if (AddPatientWidget->objectName().isEmpty())
            AddPatientWidget->setObjectName("AddPatientWidget");
        AddPatientWidget->resize(400, 300);
        horizontalLayout_11 = new QHBoxLayout(AddPatientWidget);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalSpacer = new QSpacerItem(82, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(AddPatientWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        idEdit = new QLineEdit(AddPatientWidget);
        idEdit->setObjectName("idEdit");

        horizontalLayout->addWidget(idEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(AddPatientWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        nameEdit = new QLineEdit(AddPatientWidget);
        nameEdit->setObjectName("nameEdit");

        horizontalLayout_2->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(AddPatientWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        identityEdit = new QLineEdit(AddPatientWidget);
        identityEdit->setObjectName("identityEdit");

        horizontalLayout_3->addWidget(identityEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_9 = new QLabel(AddPatientWidget);
        label_9->setObjectName("label_9");

        horizontalLayout_4->addWidget(label_9);

        genderComb = new QComboBox(AddPatientWidget);
        genderComb->setObjectName("genderComb");

        horizontalLayout_4->addWidget(genderComb);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(AddPatientWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        bornSpinB = new QDateEdit(AddPatientWidget);
        bornSpinB->setObjectName("bornSpinB");

        horizontalLayout_5->addWidget(bornSpinB);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        label_6 = new QLabel(AddPatientWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        heighSpinB = new QSpinBox(AddPatientWidget);
        heighSpinB->setObjectName("heighSpinB");

        horizontalLayout_6->addWidget(heighSpinB);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_5 = new QLabel(AddPatientWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_7->addWidget(label_5);

        weightSpinB = new QSpinBox(AddPatientWidget);
        weightSpinB->setObjectName("weightSpinB");

        horizontalLayout_7->addWidget(weightSpinB);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_7 = new QLabel(AddPatientWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_8->addWidget(label_7);

        phoneEdit = new QLineEdit(AddPatientWidget);
        phoneEdit->setObjectName("phoneEdit");

        horizontalLayout_8->addWidget(phoneEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        saveBtn = new QPushButton(AddPatientWidget);
        saveBtn->setObjectName("saveBtn");

        horizontalLayout_10->addWidget(saveBtn);

        backBtn = new QPushButton(AddPatientWidget);
        backBtn->setObjectName("backBtn");

        horizontalLayout_10->addWidget(backBtn);


        verticalLayout->addLayout(horizontalLayout_10);


        horizontalLayout_11->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(81, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        retranslateUi(AddPatientWidget);

        QMetaObject::connectSlotsByName(AddPatientWidget);
    } // setupUi

    void retranslateUi(QWidget *AddPatientWidget)
    {
        AddPatientWidget->setWindowTitle(QCoreApplication::translate("AddPatientWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddPatientWidget", "ID\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("AddPatientWidget", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("AddPatientWidget", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("AddPatientWidget", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("AddPatientWidget", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("AddPatientWidget", "\350\272\253\351\253\230\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("AddPatientWidget", "\344\275\223\351\207\215\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("AddPatientWidget", "\346\211\213\346\234\272\345\217\267\347\240\201\357\274\232", nullptr));
        saveBtn->setText(QCoreApplication::translate("AddPatientWidget", "\344\277\235\345\255\230", nullptr));
        backBtn->setText(QCoreApplication::translate("AddPatientWidget", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPatientWidget: public Ui_AddPatientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPATIENTWIDGET_H
