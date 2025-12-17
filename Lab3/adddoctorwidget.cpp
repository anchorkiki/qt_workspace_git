#include "adddoctorwidget.h"
#include "ui_adddoctorwidget.h"

AddDoctorWidget::AddDoctorWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddDoctorWidget)
{
    ui->setupUi(this);
}

AddDoctorWidget::~AddDoctorWidget()
{
    delete ui;
}
