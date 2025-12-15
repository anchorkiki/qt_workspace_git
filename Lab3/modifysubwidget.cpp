#include "modifysubwidget.h"
#include "ui_modifysubwidget.h"

ModifySubWidget::ModifySubWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModifySubWidget)
{
    ui->setupUi(this);
}

ModifySubWidget::~ModifySubWidget()
{
    delete ui;
}
