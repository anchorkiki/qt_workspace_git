#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <QPointF>

class MyItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MyItem(QString path, int status, int width, int height);

    // 重写，返回图元所在位置
    QRectF boundingRect() const;
    // 重写，重绘图元
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    // 重写，移动图元
    void advance(int phase);

private:
    QPixmap img;
    int status; // 是否移动， -1左移，1右移，0不动
signals:
    // 携带碰撞的坐标
    void boom(QPointF pos);
public slots:
};

#endif // MYITEM_H
