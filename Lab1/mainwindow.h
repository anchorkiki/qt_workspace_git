#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QStack>
#include <QKeyEvent>
#include <QPushButton>
#include <QMap>
#include <QDebug>
#include <QFile>

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

    QString operand;
    QString opcode;
    QList<QString> operands;
    QList<QString> opcodes;
    QMap <int,QPushButton*> digitBTNs;

    QString calculation(bool * ok = NULL);

private slots:

    void btnNumClicked();
    void btnBinaryOperatorClicked();
    void btnUnaryOperatorClicked();
    void on_btnPeriod_clicked();
    void on_btnDel_clicked();
    void on_btnClear_clicked();
    void on_btnEqual_clicked();
    void on_btnSign_clicked();
    void on_btnClearAll_clicked();
    virtual void keyPressEvent(QKeyEvent *event);


private:
    Ui::MainWindow *ui;
    QLabel *statusMsgLabel;
};
#endif // MAINWINDOW_H
