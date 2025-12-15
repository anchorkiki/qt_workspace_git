#ifndef CHOOSEWIDGET_H
#define CHOOSEWIDGET_H

#include <QWidget>

namespace Ui {
class ChooseWidget;
}

class ChooseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseWidget(QWidget *parent = nullptr);
    ~ChooseWidget();

private:
    Ui::ChooseWidget *ui;

signals:
    // 切换到科室管理页面
    void sigSwitchToSub();
    // 切换到医生管理页面
    void sigSwitchToDoc();
    // 切换到患者管理页面
    void sigSwitchToPatient();
};

#endif // CHOOSEWIDGET_H
