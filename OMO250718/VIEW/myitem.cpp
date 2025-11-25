#include "myitem.h"

MyItem::MyItem(QString path, int status, int width, int height)
{
    // 加载图片并缩放到指定尺寸
    this->img = QPixmap(path).scaled(
        width, height,
        Qt::KeepAspectRatio,  // 保持宽高比
        Qt::SmoothTransformation  // 平滑缩放，避免锯齿
    );
//    qDebug() << "图片实际尺寸：" << this->img.width() << "x" << this->img.height();
    this->status = status;
}

QRectF MyItem::boundingRect() const
{
    return QRect(-(this->img.width()/2), -(this->img.height()/2), this->img.width(), this->img.height());
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-(this->img.width()/2), -(this->img.height()/2), this->img.width(), this->img.height(), this->img);
}

void MyItem::advance(int phase)
{
    if(this->status != 0){
        if(this->collidingItems().size() > 0){ // 碰撞检测
            this->status = 0;
            emit boom(this->pos()); //  发送碰撞信号
            return;
        }
        if(this->status == -1){
            // 每次x方向移动-5个像素，y方向移动+0
            this->setPos(mapToScene(-5, 0));
        }
        else if(this->status == 1){
            // 每次x方向移动+5个像素，y方向移动+0
            this->setPos(mapToScene(5, 0));
        }

    }
}
