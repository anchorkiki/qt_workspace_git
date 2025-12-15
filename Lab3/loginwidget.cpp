#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    // 登录按钮点击 -> 发射登录成功信号
    connect(ui->loginBtn, &QPushButton::clicked, this, &LoginWidget::sigLoginSuccess);
    // 注册按钮点击 -> 发射注册信号
    connect(ui->registerBtn, &QPushButton::clicked, this, &LoginWidget::sigRegisterClicked);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}
