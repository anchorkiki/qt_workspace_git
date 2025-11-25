#ifndef ENVIDATACONTROLLER_H
#define ENVIDATACONTROLLER_H

#include <QString>
#include <QDebug>
#include "MODEL/envidatamodel.h"

class EnviDataController
{
public:
    static EnviDataController* getInstance();

    int insertDataToDB(double temperature, double humidity, double light);

    void getLast7DaysTempData(QList<QString> &dates, QList<double> &maxTemps, QList<double> &minTemps);

private:
    EnviDataController();
    static EnviDataController* instance;
};

#endif // ENVIDATACONTROLLER_H
