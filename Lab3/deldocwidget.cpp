#include "deldocwidget.h"
#include "ui_deldocwidget.h"

DelDocWidget::DelDocWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DelDocWidget)
{
    ui->setupUi(this);
}

DelDocWidget::~DelDocWidget()
{
    delete ui;
}
