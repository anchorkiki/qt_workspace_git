#include "patientwidget.h"
#include "ui_patientwidget.h"

PatientWidget::PatientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PatientWidget)
{
    ui->setupUi(this);

    // 增加按钮 -> 切换到添加页面
    connect(ui->addBtn, &QPushButton::clicked, this, &PatientWidget::sigSwitchToAddPatient);
    // 修改按钮 -> 切换到修改页面
    connect(ui->editBtn, &QPushButton::clicked, this, &PatientWidget::sigSwitchToModifyPatient);
    // 删除按钮 -> 切换到删除页面
    connect(ui->delBtn, &QPushButton::clicked, this, &PatientWidget::sigSwitchToDelPatient);
}

PatientWidget::~PatientWidget()
{
    qDebug()<<"析构 PatientWidget";
    delete ui;
}
