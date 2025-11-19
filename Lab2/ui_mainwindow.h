/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <codeeditor.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveTo;
    QAction *actionBack;
    QAction *actionRecover;
    QAction *actionCut;
    QAction *actionPasta;
    QAction *actionCover;
    QAction *actionFind;
    QAction *actionStand;
    QAction *actionAll;
    QAction *actionAutoChangeLine;
    QAction *actionShowLineNo;
    QAction *actionLetter;
    QAction *actionLetterColor;
    QAction *actionLetterBackgroundColor;
    QAction *actionEditBackgroundColor;
    QAction *actionToolBar;
    QAction *actionStatus;
    QAction *actionExit;
    QAction *action_A;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    CodeEditor *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNew->setIcon(icon);
        actionNew->setMenuRole(QAction::MenuRole::NoRole);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionOpen->setIcon(icon1);
        actionOpen->setMenuRole(QAction::MenuRole::NoRole);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSave->setIcon(icon2);
        actionSave->setMenuRole(QAction::MenuRole::NoRole);
        actionSaveTo = new QAction(MainWindow);
        actionSaveTo->setObjectName("actionSaveTo");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/saveTo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSaveTo->setIcon(icon3);
        actionSaveTo->setMenuRole(QAction::MenuRole::NoRole);
        actionBack = new QAction(MainWindow);
        actionBack->setObjectName("actionBack");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/upStep.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionBack->setIcon(icon4);
        actionBack->setMenuRole(QAction::MenuRole::NoRole);
        actionRecover = new QAction(MainWindow);
        actionRecover->setObjectName("actionRecover");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/nextStep.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionRecover->setIcon(icon5);
        actionRecover->setMenuRole(QAction::MenuRole::NoRole);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/cut.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCut->setIcon(icon6);
        actionCut->setMenuRole(QAction::MenuRole::NoRole);
        actionPasta = new QAction(MainWindow);
        actionPasta->setObjectName("actionPasta");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/pasta.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPasta->setIcon(icon7);
        actionPasta->setMenuRole(QAction::MenuRole::NoRole);
        actionCover = new QAction(MainWindow);
        actionCover->setObjectName("actionCover");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/cover.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCover->setIcon(icon8);
        actionCover->setMenuRole(QAction::MenuRole::NoRole);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName("actionFind");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionFind->setIcon(icon9);
        actionFind->setMenuRole(QAction::MenuRole::NoRole);
        actionStand = new QAction(MainWindow);
        actionStand->setObjectName("actionStand");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/stand.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionStand->setIcon(icon10);
        actionStand->setMenuRole(QAction::MenuRole::NoRole);
        actionAll = new QAction(MainWindow);
        actionAll->setObjectName("actionAll");
        actionAll->setMenuRole(QAction::MenuRole::NoRole);
        actionAutoChangeLine = new QAction(MainWindow);
        actionAutoChangeLine->setObjectName("actionAutoChangeLine");
        actionAutoChangeLine->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/multi-line-text.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAutoChangeLine->setIcon(icon11);
        actionAutoChangeLine->setMenuRole(QAction::MenuRole::NoRole);
        actionShowLineNo = new QAction(MainWindow);
        actionShowLineNo->setObjectName("actionShowLineNo");
        actionShowLineNo->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/showLineCount.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionShowLineNo->setIcon(icon12);
        actionShowLineNo->setMenuRole(QAction::MenuRole::NoRole);
        actionLetter = new QAction(MainWindow);
        actionLetter->setObjectName("actionLetter");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/letter.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionLetter->setIcon(icon13);
        actionLetter->setMenuRole(QAction::MenuRole::NoRole);
        actionLetterColor = new QAction(MainWindow);
        actionLetterColor->setObjectName("actionLetterColor");
        actionLetterColor->setMenuRole(QAction::MenuRole::NoRole);
        actionLetterBackgroundColor = new QAction(MainWindow);
        actionLetterBackgroundColor->setObjectName("actionLetterBackgroundColor");
        actionLetterBackgroundColor->setMenuRole(QAction::MenuRole::NoRole);
        actionEditBackgroundColor = new QAction(MainWindow);
        actionEditBackgroundColor->setObjectName("actionEditBackgroundColor");
        actionEditBackgroundColor->setMenuRole(QAction::MenuRole::NoRole);
        actionToolBar = new QAction(MainWindow);
        actionToolBar->setObjectName("actionToolBar");
        actionToolBar->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/toolBar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionToolBar->setIcon(icon14);
        actionToolBar->setMenuRole(QAction::MenuRole::NoRole);
        actionStatus = new QAction(MainWindow);
        actionStatus->setObjectName("actionStatus");
        actionStatus->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/statusBar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionStatus->setIcon(icon15);
        actionStatus->setMenuRole(QAction::MenuRole::NoRole);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionExit->setMenuRole(QAction::MenuRole::NoRole);
        action_A = new QAction(MainWindow);
        action_A->setObjectName("action_A");
        action_A->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        textEdit = new CodeEditor(centralwidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName("menu_5");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addAction(actionSaveTo);
        menu->addSeparator();
        menu->addAction(actionExit);
        menu_2->addAction(actionBack);
        menu_2->addAction(actionRecover);
        menu_2->addAction(actionCut);
        menu_2->addAction(actionPasta);
        menu_2->addAction(actionCover);
        menu_2->addSeparator();
        menu_2->addAction(actionFind);
        menu_2->addAction(actionStand);
        menu_2->addSeparator();
        menu_2->addAction(actionAll);
        menu_3->addAction(actionAutoChangeLine);
        menu_3->addAction(actionShowLineNo);
        menu_3->addAction(actionLetter);
        menu_3->addAction(actionLetterColor);
        menu_3->addSeparator();
        menu_3->addAction(actionLetterBackgroundColor);
        menu_3->addAction(actionEditBackgroundColor);
        menu_4->addAction(actionToolBar);
        menu_4->addAction(actionStatus);
        menu_5->addAction(action_A);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSaveTo);
        toolBar->addSeparator();
        toolBar->addAction(actionBack);
        toolBar->addAction(actionRecover);
        toolBar->addAction(actionCut);
        toolBar->addAction(actionPasta);
        toolBar->addAction(actionCover);
        toolBar->addSeparator();
        toolBar->addAction(actionFind);
        toolBar->addAction(actionStand);
        toolBar->addSeparator();
        toolBar->addAction(actionLetter);
        toolBar->addAction(actionShowLineNo);
        toolBar->addAction(actionAutoChangeLine);
        toolBar->addSeparator();
        toolBar->addAction(actionToolBar);
        toolBar->addAction(actionStatus);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\224\241\344\277\212\346\235\260\347\232\204\346\226\207\346\234\254\347\274\226\350\276\221\345\231\250", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", nullptr));
#if QT_CONFIG(tooltip)
        actionNew->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveTo->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", nullptr));
#if QT_CONFIG(tooltip)
        actionSaveTo->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actionBack->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200(&U)", nullptr));
#if QT_CONFIG(tooltip)
        actionBack->setToolTip(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionBack->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRecover->setText(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215", nullptr));
#if QT_CONFIG(tooltip)
        actionRecover->setToolTip(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionRecover->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207(&T)", nullptr));
#if QT_CONFIG(tooltip)
        actionCut->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPasta->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264(&C)", nullptr));
#if QT_CONFIG(tooltip)
        actionPasta->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPasta->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCover->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266(&V)", nullptr));
#if QT_CONFIG(tooltip)
        actionCover->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCover->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276(&F)", nullptr));
#if QT_CONFIG(tooltip)
        actionFind->setToolTip(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStand->setText(QCoreApplication::translate("MainWindow", "\346\233\277\346\215\242(&R)", nullptr));
#if QT_CONFIG(tooltip)
        actionStand->setToolTip(QCoreApplication::translate("MainWindow", "\346\233\277\346\215\242", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionStand->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211(&A)", nullptr));
#if QT_CONFIG(tooltip)
        actionAll->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAll->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAutoChangeLine->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214(&W)", nullptr));
#if QT_CONFIG(tooltip)
        actionAutoChangeLine->setToolTip(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
#endif // QT_CONFIG(tooltip)
        actionShowLineNo->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\241\214\345\217\267(&L)", nullptr));
#if QT_CONFIG(tooltip)
        actionShowLineNo->setToolTip(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\241\214\345\217\267", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionShowLineNo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLetter->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223(&F)", nullptr));
#if QT_CONFIG(tooltip)
        actionLetter->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        actionLetterColor->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#if QT_CONFIG(tooltip)
        actionLetterColor->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionLetterBackgroundColor->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\203\214\346\231\257\350\211\262", nullptr));
#if QT_CONFIG(tooltip)
        actionLetterBackgroundColor->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\203\214\346\231\257\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionEditBackgroundColor->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\345\231\250\350\203\214\346\231\257\350\211\262", nullptr));
#if QT_CONFIG(tooltip)
        actionEditBackgroundColor->setToolTip(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\345\231\250\350\203\214\346\231\257\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionToolBar->setText(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217(&T)", nullptr));
#if QT_CONFIG(tooltip)
        actionToolBar->setToolTip(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionStatus->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217(&S)", nullptr));
#if QT_CONFIG(tooltip)
        actionStatus->setToolTip(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        action_A->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", nullptr));
#if QT_CONFIG(tooltip)
        action_A->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(tooltip)
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217(&O)", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213(&V)", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
