#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnNumClicked(){
    QString str = ui->display->text();
    str += qobject_cast<QPushButton*>(sender())->text();
    ui->display->setText(str);
    ui->statusbar->showMessage(qobject_cast<QPushButton*>(sender())->text() + "btn clicked");
}

void MainWindow::on_butPoint_clicked()
{
    QString str = ui->display->text();
    if(!str.contains(".")){
        str += qobject_cast<QPushButton*>(sender())->text();
    }
    ui->display->setText(str);
}


void MainWindow::on_butDelete_clicked()
{
    QString str = ui->display->text();
    str = str.left(str.length() - 1);
    ui->display->setText(str);
}

