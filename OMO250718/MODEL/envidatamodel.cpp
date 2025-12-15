#include "envidatamodel.h"

EnviDataModel* EnviDataModel::instance = nullptr;

EnviDataModel *EnviDataModel::getInstance()
{
    if(EnviDataModel::instance == nullptr){
        EnviDataModel::instance = new EnviDataModel();
    }
    else{
        qDebug()<<"EnviDataModel::instance exists";
    }
    return EnviDataModel::instance;
}

int EnviDataModel::insertEnvirDataToDB(double temperature, double humidity, double light)
{
    // 获取系统当前时间
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeStr = currentTime.toString("yyyy-MM-dd HH:mm:ss");

    QString sql = QString("INSERT INTO t_environment (collect_time, temperature, humidity, light) "
                          "VALUES ('%1', %2, %3, %4);")
                          .arg(timeStr).arg(temperature).arg(humidity).arg(light);

    int res = SingletonDB::getInstance()->execSql(sql);
    if(res != SQLITE_OK){
        // sql执行错误
        qDebug()<<"EnviDataModel::insertEnvirDataToDB error 29";
        return -1;
    }

    return 1;
}

int EnviDataModel::selectLast7DaysTempData(int &row, int &col, char **&qres)
{
    // 计算近7天日期范围
    QDate today = QDate::currentDate(); // 今天
    QDate startDate = today.addDays(-6); // 7天前
    QDate endDate = today.addDays(1); // 明天


    // SQL
    QString sql = QString("SELECT DATE(collect_time), "
                          "MAX(temperature) AS max_temp, "
                          "MIN(temperature) AS min_temp "
                          "FROM t_environment "
                          "WHERE collect_time BETWEEN '%1' AND '%2' "
                          "GROUP BY DATE(collect_time) "
                          "ORDER BY DATE(collect_time)")
                          .arg(startDate.toString("yyyy-MM-dd"))  // 开始：7天前的00:00
                          .arg(endDate.toString("yyyy-MM-dd"));    // 结束：明天的00:00

//    qDebug()<<"查询近7天温度SQL:"<<sql;

    int res = SingletonDB::getInstance()->selectSql(sql, qres, row, col);
    if(res != SQLITE_OK){
        qDebug() << "EnviDataModel::selectLast7DaysTempData error";
        return -1;
    }
    return 1;
}


EnviDataModel::EnviDataModel()
{

}
