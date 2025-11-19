#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <QColorDialog>
#include <QFontDialog>

#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "searchdialog.h"
#include "replacedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int getTextChange_flag() const;
    void setTextChange_flag(int newTextChange_flag);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_action_A_triggered();

    void on_actionFind_triggered();

    void on_actionStand_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSaveTo_triggered();

    void on_textEdit_textChanged();

    void on_actionPasta_triggered();

    void on_actionCover_triggered();

    void on_actionCut_triggered();

    void on_actionBack_triggered();

    void on_actionRecover_triggered();

    void on_textEdit_undoAvailable(bool b);

    void on_textEdit_copyAvailable(bool b);

    void on_textEdit_redoAvailable(bool b);

    void on_actionLetterColor_triggered();

    void on_actionLetterBackgroundColor_triggered();

    void on_actionEditBackgroundColor_triggered();

    void on_actionAutoChangeLine_triggered();

    void on_actionLetter_triggered();

    void on_actionToolBar_triggered();

    void on_actionStatus_triggered();

    void on_actionAll_triggered();

    void on_actionExit_triggered();

    void on_textEdit_cursorPositionChanged();

private:
    Ui::MainWindow *ui;

    QLabel statusCursorLabel;
    QLabel statusLabel;

    QString filePath;

    int textChange_flag; // false 没变，ture 变了
};
#endif // MAINWINDOW_H
