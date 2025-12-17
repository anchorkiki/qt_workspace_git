#include "AddPatientWidget.h"
#include "ui_AddPatientWidget.h"

AddPatientWidget::AddPatientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddPatientWidget)
{
    ui->setupUi(this);

    // 返回按钮 -> 发射返回信号
    connect(ui->backBtn, &QPushButton::clicked, this, &AddPatientWidget::sigBackToPatient);
}

AddPatientWidget::~AddPatientWidget()
{
    qDebug()<<"析构 AddPatientWidget";
    delete ui;
}
