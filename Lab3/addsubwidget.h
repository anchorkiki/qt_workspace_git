#ifndef AddSubWidget_H
#define AddSubWidget_H

#include <QWidget>

namespace Ui {
class AddSubWidget;
}

class AddSubWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddSubWidget(QWidget *parent = nullptr);
    ~AddSubWidget();

private:
    Ui::AddSubWidget *ui;
};

#endif // AddSubWidget_H
