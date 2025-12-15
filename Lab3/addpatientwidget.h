#ifndef AddPatientWidget_H
#define AddPatientWidget_H

#include <QWidget>

namespace Ui {
class AddPatientWidget;
}

class AddPatientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddPatientWidget(QWidget *parent = nullptr);
    ~AddPatientWidget();

private:
    Ui::AddPatientWidget *ui;

signals:
    // 返回患者管理页面
    void sigBackToPatient();
};

#endif // AddPatientWidget_H
