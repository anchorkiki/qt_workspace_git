#include "DelDocWidget.h"
#include "ui_DelDocWidget.h"

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
