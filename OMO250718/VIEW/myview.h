#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QObject>
#include <QGraphicsScene>
#include <QPixmap>
#include "myitem.h"
#include <QTimer>
#include <QDebug>
#include <QPointF>
#include <windows.h>

class MyView:public QGraphicsView
{
    Q_OBJECT
public:
    MyView();

private:
    QGraphicsScene *scene;
    MyItem *item1;
    MyItem *item2;
    MyItem *item3;
    QTimer *myTimer;
    QTimer *delayHideTimer;

public slots:
    void stopTimer(QPointF collidePos);
    void delayHideWin();

signals:
    // 动画结束信号
    void animationFinished();
};

#endif // MYVIEW_H
