#include "modifypatwidget.h"
#include "ui_modifypatwidget.h"

ModifyPatWidget::ModifyPatWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModifyPatWidget)
{
    ui->setupUi(this);
}

ModifyPatWidget::~ModifyPatWidget()
{
    delete ui;
}
