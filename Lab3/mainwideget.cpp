#include "mainwideget.h"
#include "ui_mainwideget.h"
#include "singletodb.h"

MainWideget::MainWideget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWideget)
{
    this->ui->setupUi(this);

    // 设置窗口界面（没有顶层的隐藏，最小化，关闭）
    this->setWindowFlag(Qt::FramelessWindowHint);

    // 返回
    connect(this->ui->returnBtn, &QPushButton::clicked, this, &MainWideget::onSwitchToLast);
    // 注销
    connect(this->ui->exitBtn, &QPushButton::clicked, this, &MainWideget::onExit);

    // 首个界面是登录界面
    this->onSwitchToLogin();

    // 数据库初始化
    SingleToDB::getInstance();

    // 初始化所有页面

    // this->chooseWidget = new ChooseWidget(this);

    // this->subWidget = new SubWidget(this);
    // this->docWidget = new DocWidget(this);
    // this->patientWidget = new PatientWidget(this);

    // this->addSubWidget = new AddSubWidget(this);
    // this->modifySubWidget = new ModifySubWidget(this);
    // this->delSubWidget = new DelSubWidget(this);

    // this->addDoctorWidget = new AddDoctorWidget(this);
    // this->modifyDocWidget = new ModifyDocWidget(this);
    // this->delDocWidget = new DelDocWidget(this);


    // this->modifyPatWidget = new ModifyPatWidget(this);
    // this->delPatientWidget = new DelPatientWidget(this);

    // 将页面添加到栈控件

    // this->ui->stackedWidget->addWidget(this->chooseWidget);

    // this->ui->stackedWidget->addWidget(this->subWidget);
    // this->ui->stackedWidget->addWidget(this->docWidget);
    // this->ui->stackedWidget->addWidget(this->patientWidget);

    // this->ui->stackedWidget->addWidget(this->addSubWidget);
    // this->ui->stackedWidget->addWidget(this->modifySubWidget);
    // this->ui->stackedWidget->addWidget(this->delSubWidget);

    // this->ui->stackedWidget->addWidget(this->addDoctorWidget);
    // this->ui->stackedWidget->addWidget(this->modifyDocWidget);
    // this->ui->stackedWidget->addWidget(this->delDocWidget);


    // this->ui->stackedWidget->addWidget(this->modifyPatWidget);
    // this->ui->stackedWidget->addWidget(this->delPatientWidget);



    // ===================== 连接信号与槽 =====================

    // // 3. 科室管理页面 -> 各操作页面
    // connect(subWidget, &SubWidget::sigSwitchToAddSub, this, &MainWideget::onSwitchToAddSub);
    // connect(subWidget, &SubWidget::sigSwitchToModifySub, this, &MainWideget::onSwitchToModifySub);
    // connect(subWidget, &SubWidget::sigSwitchToDelSub, this, &MainWideget::onSwitchToDelSub);

    // // 4. 医生管理页面 -> 各操作页面
    // connect(docWidget, &DocWidget::sigSwitchToAddDoctor, this, &MainWideget::onSwitchToAddDoctor);
    // connect(docWidget, &DocWidget::sigSwitchToModifyDoc, this, &MainWideget::onSwitchToModifyDoc);
    // connect(docWidget, &DocWidget::sigSwitchToDelDoc, this, &MainWideget::onSwitchToDelDoc);



    // // 6. 操作页面 -> 返回管理页面（以患者相关为例，其他同理）
    // connect(addPatientWidget, &AddPatientWidget::sigBackToPatient, this, &MainWideget::onSwitchToPatient);
    // connect(modifyPatWidget, &ModifyPatWidget::sigBackToPatient, this, &MainWideget::onSwitchToPatient);
    // connect(delPatientWidget, &DelPatientWidget::sigBackToPatient, this, &MainWideget::onSwitchToPatient);
}

MainWideget::~MainWideget()
{
    delete this->ui;
}

void MainWideget::pushWidgetToTop(QWidget *newWidget)
{
    this->ui->stackedWidget->addWidget(newWidget);
    int count = ui->stackedWidget->count();
    // 设置初始页面为登录页
    this->ui->stackedWidget->setCurrentIndex(count - 1);
    this->ui->titleLabel->setText(newWidget->windowTitle());
}

// 切换到登录页
void MainWideget::onSwitchToLogin() {
    this->loginWidget = new LoginWidget(this);
    this->pushWidgetToTop(this->loginWidget);

    // 登录页面 -> 选择页面
    connect(loginWidget, &LoginWidget::sigLoginSuccess, this, &MainWideget::onSwitchToChoose);
}

// 切换到选择页
void MainWideget::onSwitchToChoose() {
    this->chooseWidget = new ChooseWidget(this);
    this->pushWidgetToTop(this->chooseWidget);

    // 选择页面 -> 各管理页面
    connect(chooseWidget, &ChooseWidget::sigSwitchToSub, this, &MainWideget::onSwitchToSub);
    connect(chooseWidget, &ChooseWidget::sigSwitchToDoc, this, &MainWideget::onSwitchToDoc);
    connect(chooseWidget, &ChooseWidget::sigSwitchToPatient, this, &MainWideget::onSwitchToPatient);
}

// 切换到科室管理页
void MainWideget::onSwitchToSub() {
    this->subWidget = new SubWidget(this);
    this->pushWidgetToTop(this->subWidget);
}

// 切换到医生管理页
void MainWideget::onSwitchToDoc() {
    this->docWidget = new DocWidget(this);
    this->pushWidgetToTop(this->docWidget);
}

// 切换到患者管理页
void MainWideget::onSwitchToPatient() {
    this->patientWidget = new PatientWidget(this);
    this->pushWidgetToTop(this->patientWidget);

    // 患者管理页面 -> 各操作页面
    connect(patientWidget, &PatientWidget::sigSwitchToAddPatient, this, &MainWideget::onSwitchToAddPatient);
    connect(patientWidget, &PatientWidget::sigSwitchToModifyPatient, this, &MainWideget::onSwitchToModifyPatient);
    // connect(patientWidget, &PatientWidget::sigSwitchToDelPatient, this, &MainWideget::onSwitchToDelPatient);
}

// 切换到添加科室页
void MainWideget::onSwitchToAddSub() {
    ui->stackedWidget->setCurrentWidget(addSubWidget);
}

// 切换到修改科室页
void MainWideget::onSwitchToModifySub() {
    ui->stackedWidget->setCurrentWidget(modifySubWidget);
}

// 切换到删除科室页
void MainWideget::onSwitchToDelSub() {
    ui->stackedWidget->setCurrentWidget(delSubWidget);
}

// 切换到添加医生页
void MainWideget::onSwitchToAddDoctor() {
    ui->stackedWidget->setCurrentWidget(addDoctorWidget);
}

// 切换到修改医生页
void MainWideget::onSwitchToModifyDoc() {
    ui->stackedWidget->setCurrentWidget(modifyDocWidget);
}

// 切换到删除医生页
void MainWideget::onSwitchToDelDoc() {
    ui->stackedWidget->setCurrentWidget(delDocWidget);
}

// 切换到添加患者页
void MainWideget::onSwitchToAddPatient(int rowIndex) {
    this->addPatientWidget = new AddPatientWidget(this, rowIndex);
    this->pushWidgetToTop(this->addPatientWidget);

    connect(addPatientWidget, &AddPatientWidget::goLastWidget, this, &MainWideget::onSwitchToLast);

}

// 切换到修改患者页
void MainWideget::onSwitchToModifyPatient(int rowNo) {
    this->modifyPatWidget = new ModifyPatWidget(this, rowNo);
    this->pushWidgetToTop(this->modifyPatWidget);

    connect(modifyPatWidget, &ModifyPatWidget::goLastWidget, this, &MainWideget::onSwitchToLast);
}

// 切换到删除患者页
void MainWideget::onSwitchToDelPatient() {
    ui->stackedWidget->setCurrentWidget(delPatientWidget);
}

void MainWideget::onSwitchToLast()
{
    int count = this->ui->stackedWidget->count();

    if(count > 1){
        this->ui->stackedWidget->setCurrentIndex(count - 2);
        this->ui->titleLabel->setText(this->ui->stackedWidget->currentWidget()->windowTitle());

        QWidget *tempWidget = this->ui->stackedWidget->widget(count - 1);
        // 弹出返回前的窗口出队列
        this->ui->stackedWidget->removeWidget(tempWidget);
        delete tempWidget;
    }
}

void MainWideget::onExit()
{
    onSwitchToLogin();


}

void MainWideget::on_stackedWidget_currentChanged(int arg1)
{
    int count = this->ui->stackedWidget->count();
    if(count <= 1){
        this->ui->returnBtn->setEnabled(false);
    }
    else{
        this->ui->returnBtn->setEnabled(true);
    }

    QString title = this->ui->stackedWidget->currentWidget()->windowTitle();
    if(title == "选择"){
        this->ui->returnBtn->setEnabled(false);
        this->ui->exitBtn->setEnabled(true);
    }
    else{
        this->ui->exitBtn->setEnabled(false);
    }
}

