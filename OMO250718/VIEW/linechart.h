#ifndef LINECHART_H
#define LINECHART_H

#include <QMainWindow>
#include <QWidget>

#include <QPoint>
#include <QtCharts>
#include <QLineSeries> // 折线
#include <QValueAxis> // 坐标系
#include <QChartView> // 展示图
#include <QSplineSeries> // 平滑的折线
#include <QDateTimeAxis> // 时间轴
#include <QDateTime> // 有关系统时间的

using namespace QtCharts;

class LineChart : public QChartView
{
public:
    LineChart();

    // 方法
    void updateTimeAxis();
    void addLuxData(QDateTime x, double y);
    void addTempData(QDateTime x, double y);
    void addHumidData(QDateTime x, double y);

private:
    QChart *chart; // 图表对象
    QDateTimeAxis *axisX; // 时间 x
    QValueAxis *axisY; // 温度 y
    QSplineSeries *tempSeries; // 温度折线图
    QSplineSeries *LuxSeries; // 温度折线图
    QSplineSeries *humidSeries; // 温度折线图
    QDateTime startTime;
    QDateTime curTime;

};

#endif // LINECHART_H
