#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>

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

    QString oprand; // 操作数
    QString opcode; // 操作符
    QStack<QString> operands; // 操作数
    QStack<QString> opercodes; // 操作符
    QString calculation();

private:
    Ui::MainWindow *ui;

private slots:
    void btnNumClicked();
    void btnBinaryOperatorClicked();

    void on_butPoint_clicked();
    void on_butDelete_clicked();
    void on_butC_clicked();
    void on_butEqual_clicked();
};
#endif // MAINWINDOW_H
