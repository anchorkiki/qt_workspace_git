#include "addsubwidget.h"
#include "ui_addsubwidget.h"

AddSubWidget::AddSubWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddSubWidget)
{
    ui->setupUi(this);
}

AddSubWidget::~AddSubWidget()
{
    delete ui;
}
