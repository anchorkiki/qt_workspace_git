#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    digitBTNs = {{Qt ::Key_0,ui->btnNum0},{Qt ::Key_1,ui->btnNum1},
                {Qt ::Key_2,ui->btnNum2},{Qt ::Key_3,ui->btnNum3},
                {Qt ::Key_4,ui->btnNum4},{Qt ::Key_5,ui->btnNum5},
                {Qt ::Key_6,ui->btnNum6},{Qt ::Key_7,ui->btnNum7},
                {Qt ::Key_8,ui->btnNum8},{Qt ::Key_9,ui->btnNum9},};

    foreach(auto btn,digitBTNs){
        connect(btn,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    }

    connect(ui->btnPoint, SIGNAL(clicked()), this, SLOT(on_btnPeriod_clicked()));
    connect(ui->btnPlus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMultiple,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnPercentage,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result = 0;
    bool calculationOk = true;

    if(operands.size() >= 2 && opcodes.size() > 0)
    {
        //取操作数
        double operand2 = operands.last().toDouble();
        operands.removeLast();
        double operand1 = operands.last().toDouble();
        operands.removeLast();

        //取操作符
        QString op = opcodes.first();
        opcodes.removeFirst();

        if(op == "+"){
            result = operand1 + operand2;
        }
        else if(op == "-"){
            result = operand1 - operand2;
        }
        else if(op == "×"){
            result = operand1 * operand2;
        }
        else if(op == "÷q"){
            if(operand2 == 0){
                calculationOk = false;
                if(ok) *ok = false;
                return "Error: Division by zero";
            }
            result = operand1 / operand2;
        }


        operands.push_back(QString::number(result));

        ui->statusbar->showMessage(QString("result: %1").arg(result));
    }
    else
        ui->statusbar->showMessage(QString("operands is %1, opcode is %2").arg(operands.size()).arg(opcodes.size()));

    if(ok) *ok = calculationOk;
    qDebug()<<result<<'\n';
    return QString::number(result);
}

void MainWindow::btnNumClicked()
{
    QString digit = qobject_cast<QPushButton*>(sender())->text();

    if(digit == "0" && operand == "0")
        digit = "";

    if(operand == "0" && digit != "0" )
        operand = "" ;

    operand += digit;

    ui->display->setText(operand);
}



void MainWindow::on_btnPeriod_clicked()
{
    if (this->operand.isEmpty()) {
        this->operand = "0";
    }

    if(!this->operand.contains(".")){
        this->operand += qobject_cast<QPushButton*>(sender())->text();
    }
    ui->display->setText(this->operand);
}


void MainWindow::on_btnDel_clicked()
{
    operand = operand.left(operand.length()-1);
    ui->display->setText(operand);
}


void MainWindow::on_btnClear_clicked()
{
    operand.clear();
    operands.clear();
    opcodes.clear();
    ui->display->setText("0");
}


void MainWindow::btnBinaryOperatorClicked()
{
    ui->statusbar->showMessage("last operand " + operand);

    QString opcode = qobject_cast<QPushButton*>(sender())->text();

    qDebug() << opcode;

    if(operand != "")
    {
        operands.push_back(operand);
        operand = "";

        if(operands.size() >= 2 && opcodes.size() >= 1) {
            QString result = calculation();
            ui->display->setText(result);
            operand.clear(); // 清空operand，准备接收新操作数
        }


        opcodes.push_back(opcode);
    }
    else if(operands.size() == 1 && opcodes.size() == 0)
    {
        opcodes.push_back(opcode);
    }
    else if(operands.size() >= 1 && opcodes.size() >= 1)
    {
        opcodes.removeLast();
        opcodes.push_back(opcode);
    }
}

void MainWindow::btnUnaryOperatorClicked()
{
    if(operand != "")
    {
        double result = operand.toDouble();

        QString op = qobject_cast<QPushButton*>(sender())->text();

        if(op == "%")
            result /= 100.0;
        else if(op == "1/x")
            result = 1/result;
        else if(op == "x^2")
            result *= result;
        else if(op == "√")
            result = sqrt(result);

        operand = QString::number(result);
        ui->display->setText(operand);
    }
}

void MainWindow::on_btnEqual_clicked()
{
    if(operand != "")
    {
        operands.push_back(operand);
    }

    if(operands.size() >= 2 && opcodes.size() >= 1) {
        QString result = calculation();
        ui->display->setText(result);

        operand = result;

        operands.clear();
        opcodes.clear();
        operands.push_back(result);
    }
    else if(operands.size() == 1 && opcodes.size() == 0)
    {
        ui->display->setText(operands.first());
        operand = operands.first();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    foreach(auto btnKey , digitBTNs.keys())
    {
        if(event->key() == btnKey)
            digitBTNs[btnKey]->animateClick();
    }
}

void MainWindow::on_btnSign_clicked()
{
    if(operand != "" && operand != "0")
    {
        if(operand.startsWith("-"))
        {
            operand = operand.mid(1);
        }
        else
        {
            operand = "-" + operand;
        }
        ui->display->setText(operand);
    }
}

void MainWindow::on_btnClearAll_clicked()
{
    operand.clear();
    ui->display->setText("0");
}

