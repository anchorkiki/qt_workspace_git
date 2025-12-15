#include "choosewidget.h"
#include "ui_choosewidget.h"

ChooseWidget::ChooseWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChooseWidget)
{
    ui->setupUi(this);

    // 科室管理按钮 -> 发射切换信号
    connect(ui->subBtn, &QPushButton::clicked, this, &ChooseWidget::sigSwitchToSub);
    // 医生管理按钮 -> 发射切换信号
    connect(ui->docBtn, &QPushButton::clicked, this, &ChooseWidget::sigSwitchToDoc);
    // 患者管理按钮 -> 发射切换信号
    connect(ui->patientBtn, &QPushButton::clicked, this, &ChooseWidget::sigSwitchToPatient);
}

ChooseWidget::~ChooseWidget()
{
    delete ui;
}
