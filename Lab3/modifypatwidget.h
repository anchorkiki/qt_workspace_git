#ifndef MODIFYPATWIDGET_H
#define MODIFYPATWIDGET_H
#include <QDebug>
#include <QWidget>
#include <qdatawidgetmapper.h>
#include "singletodb.h"

namespace Ui {
class ModifyPatWidget;
}

class ModifyPatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyPatWidget(QWidget *parent = nullptr, int index = 0);
    ~ModifyPatWidget();

private:
    Ui::ModifyPatWidget *ui;
    QDataWidgetMapper *dataMapper; // 数据映射

signals:
    void goLastWidget();
private slots:
    void on_saveBtn_2_clicked();
    void on_backBtn_2_clicked();
};

#endif // MODIFYPATWIDGET_H
