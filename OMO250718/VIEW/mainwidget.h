#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QLineEdit>
#include <QTimer>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMessageBox>
#include <QStringList>
#include <QComboBox>
#include <QList>
#include <QFile>
#include <QImage>

#include "VIEW/linechart.h"
#include "VIEW/settingwidget.h"
#include "CONTROLLER/envidatacontroller.h"
#include "VIEW/barchart.h"
#include "THREAD/opencamera.h"
#include "VIEW/vedioplayer.h"
#include "DATA/settingdata.h"


class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    // 成员函数
    void initWindow();
    void initUi();
    void initConnect();
    void initData();
    void initQss();
    void initSerial();
    void openSerial();

    // 检查设备是否完整
    int checkSetting();

    // 启动直播线程
    void startCameraAuto();

    // 重启直播线程
    void restartCamera(QString newCameraName);

    // 更新摄像头布局
   void updateCameraLayout();

   // 启动所有任务
   void startAllMission();

   // 关闭所有任务
   void closeAllMission();

   // 加载ini数据
   void loadIniData();

protected:
    void showEvent(QShowEvent *event);

public slots:
    // 接收设置界面的数据
    void onSettingCompleted();

    // 读取串口数据
    void readSerialData();

    // 打开设置界面
    void showSettingWidget();

    // 接收直播图片
    void onReceiveCameraImage(QImage img);

    // 单通道/四通道切换
    void onSingleClicked();
    void onFourClicked();

    // 打开回放界面
    void showVideoPlayerWidget();

    // 显示当前界面
    void showMyMainWidget();

private:
    QHBoxLayout *layoutMain; // 总水平布局
    QVBoxLayout *layoutA;    // 垂直布局A
    QVBoxLayout *layoutB;    // 垂直布局B
    QVBoxLayout *layoutC;    // 垂直布局C


    // 成员变量（控件）
    // A
    QWidget *dataWidget; // 数据窗口
    QLabel *temperatureLabel;
    QLabel *temperatureNameLabel;
    QLabel *humidityLabel;
    QLabel *humidityNameLabel;
    QLabel *lightLabel;
    QLabel *lightNameLabel;

    LineChart *lineChart;    // 折线图

    BarChart *m_barChart; // 柱状图

    // B
    QPushButton *bt_settingWidget;
    OpenCamera* cameraThread; // 摄像头线程

    QLabel* lb_camera;        // 田字格左上角
    QLabel* lb_camera2;       // 田字格右上角
    QLabel* lb_camera3;       // 田字格左下角
    QLabel* lb_camera4;       // 田字格右下角

    bool isCameraInitialized;

    QLabel* lb_title;
    QPushButton* lb_single;
    QPushButton* lb_four;
    QPushButton* lb_setting;
    QPushButton* lb_extend;

    bool isFourCameraMode; // 标记当前是否为四摄像头模式
    int currentSingleCameraIndex; // 当前单个摄像头索引(0-3)

    // 串口
    QSerialPort *serial;

    // 定时器
    QTimer *readDataTimer;

    // 串口数据
    double lux, temperature, humidity;

    // 底下的窗口
    SettingWidget *settingWidget; // 设置窗口
    VedioPlayer *videoPlayWidget;

};

#endif // MAINWIDGET_H
