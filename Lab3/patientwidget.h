#ifndef PATIENTWIDGET_H
#define PATIENTWIDGET_H
#include <QDebug>
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
    void sigSwitchToAddPatient(int index);
    // 切换到修改患者页面
    void sigSwitchToModifyPatient(int index);

private slots:
    void on_searchBtn_clicked();
    void on_delBtn_clicked();
    void on_addBtn_clicked();
    void on_editBtn_clicked();
};

#endif // PATIENTWIDGET_H
