#include "envidatacontroller.h"

EnviDataController* EnviDataController::instance = nullptr;

EnviDataController *EnviDataController::getInstance()
{
    if(EnviDataController::instance == nullptr){
        EnviDataController::instance = new EnviDataController();
    }
    else{
        qDebug()<<"ChannelController::instance exists";
    }

    return  EnviDataController::instance;
}

int EnviDataController::insertDataToDB(double temperature, double humidity, double light)
{
    int res = EnviDataModel::getInstance()->insertEnvirDataToDB(temperature, humidity, light);
    if(res != 1){
        // sql执行错误
        qDebug()<<"EnviDataController::insertDataToDB error";
        return -1;
    }
    return 1;
}

void EnviDataController::getLast7DaysTempData(QList<QString> &dates, QList<double> &maxTemps, QList<double> &minTemps)
{
    // 清空传入的列表
    dates.clear();
    maxTemps.clear();
    minTemps.clear();

    char** qres = nullptr;
    int row = 0, col = 0;
    // 调用Model
    int res = EnviDataModel::getInstance()->selectLast7DaysTempData(row, col, qres);
    if(res == -1){
        qDebug() << "EnviDataController::getLast7DaysTempData sql error";
        return; // 直接返回空列表
    }

    if(res == -1 || row == 0){ // 处理查询失败或无数据的情况
        qDebug() << "无查询结果或查询失败";
        sqlite3_free_table(qres); // 即使无数据也需释放
        return;
    }

    // 解析结果集（跳过表头i=0）
    if(col == 3){ // 3列数据（日期、最高温、最低温）
        for(int i = 1; i <= row; i++){
            // 填充日期
            dates.append(QString(qres[i * col]));
            // 填充最高温
            maxTemps.append(atof(qres[i * col + 1]));
            // 填充最低温
            minTemps.append(atof(qres[i * col + 2]));

            qDebug()<<"解析数据: "<<dates.last()<<"最高温: "<<maxTemps.last()<<"最低温: "<<minTemps.last();
        }
    }

    // 释放结果集内存
    sqlite3_free_table(qres);
}

EnviDataController::EnviDataController()
{

}


