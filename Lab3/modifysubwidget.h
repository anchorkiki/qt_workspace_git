#ifndef MODIFYSUBWIDGET_H
#define MODIFYSUBWIDGET_H
#include <QDebug>
#include <QWidget>

namespace Ui {
class ModifySubWidget;
}

class ModifySubWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifySubWidget(QWidget *parent = nullptr);
    ~ModifySubWidget();

private:
    Ui::ModifySubWidget *ui;
};

#endif // MODIFYSUBWIDGET_H
