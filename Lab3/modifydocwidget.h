#ifndef MODIFYDOCWIDGET_H
#define MODIFYDOCWIDGET_H
#include <QDebug>
#include <QWidget>

namespace Ui {
class ModifyDocWidget;
}

class ModifyDocWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyDocWidget(QWidget *parent = nullptr);
    ~ModifyDocWidget();

private:
    Ui::ModifyDocWidget *ui;
};

#endif // MODIFYDOCWIDGET_H
