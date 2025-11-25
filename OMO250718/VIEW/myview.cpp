#include "myview.h"


MyView::MyView()
{
    // 1.窗口大小，背景
    this->setFixedSize(1600, 1200);
    this->setWindowTitle("开机动画");
    this->setBackgroundBrush(QBrush(QPixmap(":/img/myView_Bg.jpg")));

    // 在视图中设置场景
    this->scene = new QGraphicsScene();
    this->setScene(this->scene);
    // 坐标轴匹配
    this->setSceneRect(0, 0, this->width() - 2, this->height() - 2);

    // 创建图元
    this->item1 = new MyItem(":/img/oringe.png", 1, 200, 200);
    this->item2 = new MyItem(":/img/knife.png", -1, 200, 200);
    this->item3 = new MyItem(":/img/oringes.png", 0, 200, 200);
    // 把图元添加到场景中
    this->scene->addItem(this->item1);
    this->scene->addItem(this->item2);
    // 设置图元站位
    this->item1->setPos(100, this->height()/2);
    this->item2->setPos(this->width() - 200, this->height()/2);

    // 创建定时器
    this->myTimer = new QTimer(this);
    this->myTimer->setInterval(35); // 定时器倒计时
    this->myTimer->start(); // 启动定时器

    this->delayHideTimer = new QTimer(this);
    this->delayHideTimer->setInterval(2000); // 定时器倒计时

    /*
        这个SLOT(advance())是场景scene的advance，而这个SLOT(advance())会调用场景下全部的
        item图元的advance（），所以有两个advance，一个是场景的，一个是图元的
    */
    connect(this->myTimer, SIGNAL(timeout()), this->scene, SLOT(advance()));
    connect(this->delayHideTimer, SIGNAL(timeout()), this, SLOT(delayHideWin()));
    connect(this->item1, SIGNAL(boom(QPointF)), this, SLOT(stopTimer(QPointF)));
}

void MyView::stopTimer(QPointF collidePos)
{
    this->myTimer->stop();

    this->item1->setVisible(false);
    this->item2->setVisible(false);

    this->scene->addItem(this->item3);
    this->item3->setPos(collidePos);
//    qDebug()<<"停止图元移动定时器";

    delayHideTimer->start();
//    qDebug()<<"开启延时关闭窗口定时器";
}

void MyView::delayHideWin()
{
    this->hide();
    this->delayHideTimer->stop();
//    qDebug()<<"关闭延时关闭窗口定时器";

    // 发送结束信号
    emit animationFinished();
}
