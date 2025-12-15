#include "AddDoctorWidget.h"
#include "ui_AddDoctorWidget.h"

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
