#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QSerialPortInfo>
#include <QCameraInfo>
#include <QSettings>
#include <QDebug>
#include <QDir>

#include "DATA/settingdata.h"

class SettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingWidget(QWidget *parent = nullptr);

    // =================
    // 窗口初始化
    void initWin();
    // 初始化基础控件槽函数
    void initConnect();

    // 获取系统串口并填充下拉框
    void fillSerialPortList();

    // 填充摄像头列表
    void fillCameraList();

    //  获取ini数据填充页面
    void loadFromSettingData();

signals:
    // 设置完成信号
    void settingCompleted();

private slots:
    // 选择视频存储路径槽函数
    void onSelectStoragePath();

    // 保存ini文件
    void saveIni();

private:
    // 串口相关组件
    QLabel *lb_serialPort;       // 串口标签
    QComboBox *cb_serialPort;    // 串口下拉框

    // 视频存储相关组件
    QLabel *lb_videoStoragePath; // 视频存储路径标签
    QLineEdit *le_videoStoragePath; // 存储路径显示框
    QPushButton *bt_selectStoragePath; // 选择路径按钮

    // 视频分段时长组件
    QLabel *lb_videoSegmentDuration; // 视频分段时长标签
    QComboBox *cb_videoSegmentDuration; // 分段时长下拉框

    // 摄像头配置组件
    QLabel *lb_cameraConfig;      // 摄像头配置标签
    QComboBox *cb_cameraConfig;   // 摄像头选择下拉框

    // 温度告警阈值组件
    QLabel *lb_tempThreshold;    // 温度阈值总标签
    QLabel *lb_tempNormal;       // 一般告警标签
    QLineEdit *le_tempNormal;    // 一般告警输入框
    QLabel *lb_tempSevere;       // 严重告警标签
    QLineEdit *le_tempSevere;    // 严重告警输入框

    // 湿度告警阈值组件
    QLabel *lb_humidityThreshold; // 湿度阈值总标签
    QLabel *lb_humidityNormal;    // 一般告警标签
    QLineEdit *le_humidityNormal; // 一般告警输入框
    QLabel *lb_humiditySevere;    // 严重告警标签
    QLineEdit *le_humiditySevere; // 严重告警输入框

    // 光照告警阈值组件
    QLabel *lb_lightThreshold;   // 光照阈值总标签
    QLabel *lb_lightNormal;      // 一般告警标签
    QLineEdit *le_lightNormal;   // 一般告警输入框
    QLabel *lb_lightSevere;      // 严重告警标签
    QLineEdit *le_lightSevere;   // 严重告警输入框

    // 功能按钮
    QPushButton *bt_confirm;     // 确认按钮
    QPushButton *bt_cancel;      // 取消按钮

    // 布局管理器
    QVBoxLayout *vLayout_main;   // 主垂直布局

};

#endif // SETTINGWIDGET_H
