#include "linechart.h"

LineChart::LineChart()
{
    // 创建图表
    this->chart = new QChart();

    // 创建折线
    this->tempSeries = new QSplineSeries();
    this->tempSeries->setName("TEMP");

    this->LuxSeries = new QSplineSeries();
    this->LuxSeries->setName("LUX");

    this->humidSeries = new QSplineSeries();
    this->humidSeries->setName("HUMID");

    // 将折线添加进图表
    this->chart->addSeries(this->tempSeries);
    this->chart->addSeries(this->LuxSeries);
    this->chart->addSeries(this->humidSeries);

    // 创建坐标轴
    // x
    this->axisX = new QDateTimeAxis();
    this->axisX->setFormat("hh:mm:ss"); // 分秒
    this->axisX->setTitleText("时间"); // 设置坐标轴标题
    this->axisX->setTickCount(6); // 设置坐标轴格子间隔
    // y
    this->axisY = new QValueAxis();
    this->axisY->setRange(0, 100);
    this->axisY->setTitleText("光照/温度℃/湿度"); // 设置坐标轴标题
    this->axisY->setTickCount(5); // 设置坐标轴格子间隔

    // 将坐标轴添加进图标
    this->chart->addAxis(this->axisX, Qt::AlignBottom); // 添加并设置x在底部
    this->chart->addAxis(this->axisY, Qt::AlignLeft); // 添加并设置x在底部

    // 折线图合坐标轴关联
    this->tempSeries->attachAxis(this->axisX);
    this->tempSeries->attachAxis(this->axisY);
    this->LuxSeries->attachAxis(this->axisX);
    this->LuxSeries->attachAxis(this->axisY);
    this->humidSeries->attachAxis(this->axisX);
    this->humidSeries->attachAxis(this->axisY);

    // 新建图表的显示
    this->setChart(this->chart); // 自身作为视图设置图表
    this->setRenderHint(QPainter::Antialiasing); // 开启抗锯齿
    this->move(500, 100); // 设置自身位置
    this->resize(1000, 800); // 设置自身大小

}

void LineChart::updateTimeAxis()
{
    this->curTime = QDateTime::currentDateTime();
    this->startTime = this->curTime.addSecs(-60); // 60秒前
    axisX->setRange(this->startTime, this->curTime);
}

void LineChart::addLuxData(QDateTime x, double y)
{
    this->LuxSeries->append(x.toMSecsSinceEpoch(), y);
    // 移除60秒前的旧数据
    while (!this->LuxSeries->points().isEmpty() &&
           QDateTime::fromMSecsSinceEpoch(this->LuxSeries->points().first().x()) < x.addSecs(-60)) {
        this->LuxSeries->remove(0);
    }
    // 更新x轴
    updateTimeAxis();
}

void LineChart::addTempData(QDateTime x, double y)
{
    this->tempSeries->append(x.toMSecsSinceEpoch(), y);
    // 移除60秒前的旧数据
    while (!this->tempSeries->points().isEmpty() &&
           QDateTime::fromMSecsSinceEpoch(this->tempSeries->points().first().x()) < x.addSecs(-60)) {
        this->tempSeries->remove(0);
    }
    // 更新x轴
    updateTimeAxis();
}

void LineChart::addHumidData(QDateTime x, double y)
{
    this->humidSeries->append(x.toMSecsSinceEpoch(), y);
    // 移除60秒前的旧数据
    while (!this->humidSeries->points().isEmpty() &&
           QDateTime::fromMSecsSinceEpoch(this->humidSeries->points().first().x()) < x.addSecs(-60)) {
        this->humidSeries->remove(0);
    }
    // 更新x轴
    updateTimeAxis();
}
