#ifndef AddPatientWidget_H
#define AddPatientWidget_H
#include <QDebug>
#include <QWidget>
#include "singletodb.h"
#include <qdatawidgetmapper.h>
namespace Ui {
class AddPatientWidget;
}

class AddPatientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddPatientWidget(QWidget *parent = nullptr, int rowIndex = 0);
    ~AddPatientWidget();

private:
    Ui::AddPatientWidget *ui;
    int m_rowIndex; // 用于保存要添加的行索引
    QDataWidgetMapper *dataMapper;

signals:
    // 返回患者管理页面
    void goLastWidget();

private slots:
    void on_saveBtn_clicked();
    void on_backBtn_clicked();
};

#endif // AddPatientWidget_H
