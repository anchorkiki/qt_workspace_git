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
    qDebug()<<"析构 ModifyPatWidget";
    delete ui;
}
