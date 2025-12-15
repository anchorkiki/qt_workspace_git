#include "modifydocwidget.h"
#include "ui_modifydocwidget.h"

ModifyDocWidget::ModifyDocWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModifyDocWidget)
{
    ui->setupUi(this);
}

ModifyDocWidget::~ModifyDocWidget()
{
    delete ui;
}
