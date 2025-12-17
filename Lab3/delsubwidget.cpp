#include "delsubwidget.h"
#include "ui_delsubwidget.h"

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
