#ifndef PATIENTWIDGET_H
#define PATIENTWIDGET_H

#include <QWidget>

namespace Ui {
class PatientWidget;
}

class PatientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PatientWidget(QWidget *parent = nullptr);
    ~PatientWidget();

private:
    Ui::PatientWidget *ui;

signals:
    // 切换到添加患者页面
    void sigSwitchToAddPatient();
    // 切换到修改患者页面
    void sigSwitchToModifyPatient();
    // 切换到删除患者页面
    void sigSwitchToDelPatient();
};

#endif // PATIENTWIDGET_H
