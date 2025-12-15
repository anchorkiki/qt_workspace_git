#ifndef DelDocWidget_H
#define DelDocWidget_H

#include <QWidget>
#include "ui_deldocwidget.h"

namespace Ui {
class DelDocWidget;
}

class DelDocWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DelDocWidget(QWidget *parent = nullptr);
    ~DelDocWidget();

private:
    Ui::DelDocWidget *ui;
};

#endif // DelDocWidget_H
