#include "barchart.h"
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

BarChart::BarChart(QWidget *parent) : QWidget(parent)
{
    // 1. 初始化图表组件
    m_chart = new QChart();
    m_chart->setTitle("近7日温度极值统计");

    m_series = new QBarSeries(m_chart); // 父对象设为 m_chart

    m_chartView = new QChartView(m_chart, this); // 父对象为当前窗口
    m_chartView->setRenderHint(QPainter::Antialiasing);

    // 2. 初始化布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_chartView);
    setLayout(layout);
}

void BarChart::updateData(const QList<QString>& dates,
                         const QList<double>& maxTemps,
                         const QList<double>& minTemps)
{
    // 清空旧数据（通过父对象自动管理内存，避免手动删除导致的野指针）
    m_series->clear(); // QBarSeries::clear() 会自动删除其包含的 QBarSet
    m_chart->removeAllSeries(); // 先移除旧系列
    m_chart->addSeries(m_series); // 重新添加系列

    // 移除旧坐标轴（避免重复添加导致冲突）
    QList<QAbstractAxis*> axes = m_chart->axes();
    for (QAbstractAxis *axis : axes) {
        m_chart->removeAxis(axis);
    }

    // 添加新数据
    QBarSet *maxSet = new QBarSet("最高温度", m_series); // 父对象设为 m_series
    QBarSet *minSet = new QBarSet("最低温度", m_series);
    for (double temp : maxTemps) {
        *maxSet << temp;
    }
    for (double temp : minTemps) {
        *minSet << temp;
    }
    m_series->append(maxSet);
    m_series->append(minSet);

    // 设置X轴
    QCategoryAxis *axisX = new QCategoryAxis(m_chart); // 父对象设为 m_chart
    for (int i = 0; i < dates.size(); ++i) {
        axisX->append(dates[i], i);
    }
    axisX->setRange(0, dates.size() - 1);

    // 设置Y轴
    QValueAxis *axisY = new QValueAxis(m_chart); // 父对象设为 m_chart
    axisY->setTitleText("温度 (°C)");
    axisY->setMin(0);
    axisY->setMax(40);

    m_chart->setAxisX(axisX, m_series);
    m_chart->setAxisY(axisY, m_series);
}
