#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "singletodb.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    // 登录按钮点击 -> 发射登录成功信号
    connect(ui->loginBtn, &QPushButton::clicked, this, &LoginWidget::onLoginBtn_Clicked);
    // 注册按钮点击 -> 发射注册信号
    connect(ui->registerBtn, &QPushButton::clicked, this, &LoginWidget::sigRegisterClicked);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::onLoginBtn_Clicked()
{
    QString userName = this->ui->userEdit->text();
    QString userPwd = this->ui->pwdEdit->text();

    int loginRes = SingleToDB::getInstance()->login(userName, userPwd);
    if(loginRes == 0){
        qDebug()<<"Login success";
        emit sigLoginSuccess();
    }
    else if(loginRes == -1){
        qDebug()<<"404";
    }
    else if(loginRes == -2){
        qDebug()<<"No this user";
    }
    else if(loginRes == -3){
        qDebug()<<"Password error";
    }
}
