#include "AddSubWidget.h"
#include "ui_AddSubWidget.h"

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
