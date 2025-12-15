#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private:
    Ui::LoginWidget *ui;

signals:
    // 登录按钮点击：切换到选择界面
    void sigLoginSuccess();
    // 注册按钮点击：切换到注册界面（如果有注册页）
    void sigRegisterClicked();
};

#endif // LOGINWIDGET_H
