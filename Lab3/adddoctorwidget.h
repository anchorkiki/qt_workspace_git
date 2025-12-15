#ifndef AddDoctorWidget_H
#define AddDoctorWidget_H

#include <QWidget>

namespace Ui {
class AddDoctorWidget;
}

class AddDoctorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddDoctorWidget(QWidget *parent = nullptr);
    ~AddDoctorWidget();

private:
    Ui::AddDoctorWidget *ui;
};

#endif // AddDoctorWidget_H
