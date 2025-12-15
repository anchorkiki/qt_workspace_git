#ifndef MODIFYPATWIDGET_H
#define MODIFYPATWIDGET_H

#include <QWidget>

namespace Ui {
class ModifyPatWidget;
}

class ModifyPatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyPatWidget(QWidget *parent = nullptr);
    ~ModifyPatWidget();

private:
    Ui::ModifyPatWidget *ui;
};

#endif // MODIFYPATWIDGET_H
