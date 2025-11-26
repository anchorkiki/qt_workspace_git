#ifndef VEDIOPLAYER_H
#define VEDIOPLAYER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QLineEdit>
#include <QListWidget>
#include <QMap>
#include <QTimer>
#include <QSlider>
#include <QComboBox>
#include <QString>
#include <QThread>
#include "THREAD/playthread.h"
#include "TOOL/trancecode.h"
#include <QImage>
#include <QFileDialog>   // 文件对话框类
#include <QFile>         // 文件操作类
#include <QMessageBox>   // 消息提示框
#include <QCloseEvent>

class VedioPlayer:public QWidget
{
    Q_OBJECT
public:
    explicit VedioPlayer(QWidget *parent = nullptr);
    ~VedioPlayer();
    void initWin();
    void initUI();
    void initConnect();
    void initQss();
    void initData(QString videoPath);

    // 启动视频线程
    void startVideoThread();

    // 成员函数
    void setTitle(QString title);


public slots:
    // 接受到视频线程解码得到的RGB图片
    void reciveImg(QImage img);

    // 点击 播放/暂停按钮
    void playBtn_clicked();

    // 下拉框
    void chooseSpeedCombox();

    // ==========================
    void updateProgress(qint64 currentSec); // 更新进度条
    void setTotalDuration(qint64 totalSec); // 设置总时长
//    void onSliderMoved(int value);       // 处理进度条拖动
    // ==========================

    void downloadBtn_clicked();

protected:
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    /*
     * 总体是垂直布局，又分为4部分
     * 1.最上面是水平布局，有一个标题和返回按钮
     * 2.中间是一个视频，先用图片代替
     * 3.中间下面是一个进度条
     * 4.最下面是水平布局，有“暂停播放”按钮，倍数下拉框，下载按钮，前进按钮，后退按钮
    */

    // 总布局
    QVBoxLayout *totalLayout;

    // 顶部布局
    QWidget *topView;
    QHBoxLayout *topViewLayout;
    QLabel *title;
    QPushButton *returnBtn;

    // 中上布局
    QLabel *vedio;

    // 中下布局
    QSlider *slider;

    // 底部布局
    QWidget *buttomView;
    QHBoxLayout *buttomViewLayout;
    QPushButton *playBtn;
    QPushButton *downloadBtn;
    QPushButton *forwardBtn;
    QPushButton *rewindBtn;
    QComboBox* speedCombox;

    // 非UI成员
    QString videoPath; // 视频路径
    QImage img;
    PlayThread* videoThread; // 视频线程
    bool isPlay;
    bool isFirstPlay;

signals:
    void showMainWidget();


};

#endif // VEDIOPLAYER_H
