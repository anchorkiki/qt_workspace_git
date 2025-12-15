#ifndef DelSubWidget_H
#define DelSubWidget_H

#include <QWidget>

namespace Ui {
class DelSubWidget;
}

class DelSubWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DelSubWidget(QWidget *parent = nullptr);
    ~DelSubWidget();

private:
    Ui::DelSubWidget *ui;
};

#endif // DelSubWidget_H
