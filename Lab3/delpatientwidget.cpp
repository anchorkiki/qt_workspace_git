#include "delpatientwidget.h"
#include "ui_delpatientwidget.h"

DelPatientWidget::DelPatientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DelPatientWidget)
{
    ui->setupUi(this);
}

DelPatientWidget::~DelPatientWidget()
{
    qDebug()<<"析构 DelPatientWidget";
    delete ui;
}
