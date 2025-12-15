#include "DelSubWidget.h"
#include "ui_DelSubWidget.h"

DelSubWidget::DelSubWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DelSubWidget)
{
    ui->setupUi(this);
}

DelSubWidget::~DelSubWidget()
{
    delete ui;
}
