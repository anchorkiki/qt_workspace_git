#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->oprand = "0";

    connect(ui->but0, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    connect(ui->but1, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    connect(ui->but2, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    connect(ui->but3, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    connect(ui->but4, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    connect(ui->but5, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    connect(ui->but6, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    connect(ui->but7, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    connect(ui->but8, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    connect(ui->but9, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    connect(ui->butMultiply, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->butDivide, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->butPlus, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->butSubtract, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnNumClicked(){
    QString digit = qobject_cast<QPushButton*>(sender())->text();

    if(digit == "0" && this->oprand == "0"){
        digit = "";
    }

    if(this->oprand == "0" && digit != "0" ){
        this->oprand = "";
    }

    this->oprand += digit;
    ui->display->setText(this->oprand);
}

void MainWindow::on_butPoint_clicked()
{
    if (this->oprand.isEmpty()) {
        this->oprand = "0";
    }

    if(!this->oprand.contains(".")){
        this->oprand += qobject_cast<QPushButton*>(sender())->text();
    }
    ui->display->setText(this->oprand);
}


void MainWindow::on_butDelete_clicked()
{
    this->oprand = this->oprand.left(this->oprand.length() - 1);
    ui->display->setText(this->oprand);
}


void MainWindow::on_butC_clicked()
{
    this->oprand.clear();
    ui->display->setText(this->oprand);
    this->oprand = "0";
}

QString MainWindow::calculation(){
    ui->statusbar->showMessage("calculation is in progress");
    return "";
}

void MainWindow::btnBinaryOperatorClicked(){
    this->opcode = qobject_cast<QPushButton*>(sender())->text();
    this->operands.push_back(this->oprand);
    this->oprand = "";
    this->opercodes.push_back(this->opcode);

    QString res = this->calculation();
    ui->display->setText(res);

}

void MainWindow::on_butEqual_clicked()
{
    this->operands.push_back(this->oprand);
    this->oprand = "";

    QString res = this->calculation();
    ui->display->setText(res);
}

