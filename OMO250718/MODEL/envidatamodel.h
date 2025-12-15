#ifndef ENVIDATAMODEL_H
#define ENVIDATAMODEL_H

#include <QString>
#include <QDebug>
#include "DATA/singletondb.h"
#include <QDateTime>
#include <QList>

class EnviDataModel
{
public:
    static EnviDataModel* getInstance();

    // 在数据库中插入串口数据
    int insertEnvirDataToDB(double temperature, double humidity, double light);

    // 从数据库中读取最近7天串口数据
    int selectLast7DaysTempData(int &row, int &col, char **&qres);

private:
    EnviDataModel();
    static EnviDataModel* instance;
};

#endif // ENVIDATAMODEL_H
