#ifndef DELPATIENTWIDGET_H
#define DELPATIENTWIDGET_H

#include <QWidget>

namespace Ui {
class DelPatientWidget;
}

class DelPatientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DelPatientWidget(QWidget *parent = nullptr);
    ~DelPatientWidget();

private:
    Ui::DelPatientWidget *ui;
};

#endif // DELPATIENTWIDGET_H
