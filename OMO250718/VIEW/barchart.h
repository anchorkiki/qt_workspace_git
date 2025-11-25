#ifndef BARCHART_H
#define BARCHART_H

#include <QWidget>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

class BarChart : public QWidget
{
    Q_OBJECT
public:
    explicit BarChart(QWidget *parent = nullptr);

    // 更新柱状图数据
    void updateData(const QList<QString>& dates,
                   const QList<double>& maxTemps,
                   const QList<double>& minTemps);

private:
    QChart *m_chart;
    QBarSeries *m_series;
    QChartView *m_chartView;
};

#endif // BARCHART_H
