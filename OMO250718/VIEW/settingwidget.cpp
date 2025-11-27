#include "SettingWidget.h"

SettingWidget::SettingWidget(QWidget *parent) : QWidget(parent)
{
    this->initWin();
    this->initConnect();
    // 加载配置
    this->loadFromSettingData();
}

void SettingWidget::initWin()
{
    this->setFixedSize(800, 600);

    // 串口相关
    lb_serialPort = new QLabel("串口：");
    cb_serialPort = new QComboBox;
    this->fillSerialPortList();

    // 视频存储路径相关
    lb_videoStoragePath = new QLabel("视频存储路径：");
    le_videoStoragePath = new QLineEdit;
    le_videoStoragePath->setPlaceholderText("请选择视频存储文件夹");
    bt_selectStoragePath = new QPushButton("选择路径");

    // 视频分段时长相关
    lb_videoSegmentDuration = new QLabel("视频分段时长：");
    cb_videoSegmentDuration = new QComboBox;
    cb_videoSegmentDuration->addItems({"1min", "5min", "10min", "30min"});
    cb_videoSegmentDuration->setCurrentText("1min"); // 默认1min

    // 摄像头配置组件初始化
    lb_cameraConfig = new QLabel("摄像头配置：");
    cb_cameraConfig = new QComboBox;
    fillCameraList();

    // 温度告警阈值相关
    lb_tempThreshold = new QLabel("温度告警阈值（℃）：");
    lb_tempNormal = new QLabel("一般告警：");
    le_tempNormal = new QLineEdit("30"); // 默认值30℃
    lb_tempSevere = new QLabel("严重告警：");
    le_tempSevere = new QLineEdit("35"); // 默认值35℃
    // 设置温度输入框为数字验证（-50~150℃，保留1位小数）
    le_tempNormal->setValidator(new QDoubleValidator(-50, 150, 1, this));
    le_tempSevere->setValidator(new QDoubleValidator(-50, 150, 1, this));

    // 湿度告警阈值相关
    lb_humidityThreshold = new QLabel("湿度告警阈值（%）：");
    lb_humidityNormal = new QLabel("一般告警：");
    le_humidityNormal = new QLineEdit("60"); // 默认值60%
    lb_humiditySevere = new QLabel("严重告警：");
    le_humiditySevere = new QLineEdit("80"); // 默认值80%
    // 设置湿度输入框为数字验证（0~100%，保留1位小数）
    le_humidityNormal->setValidator(new QDoubleValidator(0, 100, 1, this));
    le_humiditySevere->setValidator(new QDoubleValidator(0, 100, 1, this));

    // 光照告警阈值相关
    lb_lightThreshold = new QLabel("光照告警阈值（lux）：");
    lb_lightNormal = new QLabel("一般告警：");
    le_lightNormal = new QLineEdit("500"); // 默认值500lux
    lb_lightSevere = new QLabel("严重告警：");
    le_lightSevere = new QLineEdit("1000"); // 默认值1000lux
    // 设置光照输入框为非负整数验证
    le_lightNormal->setValidator(new QIntValidator(0, 9999, this));
    le_lightSevere->setValidator(new QIntValidator(0, 9999, this));

    // 功能按钮
    bt_confirm = new QPushButton("确认");
    bt_cancel = new QPushButton("取消");

    // 主布局
    vLayout_main = new QVBoxLayout(this);
    vLayout_main->setSpacing(20); // 组件间距20px
    vLayout_main->setContentsMargins(30, 30, 30, 30); // 内边距30px

    // 串口布局
    QHBoxLayout *hLayout_serial = new QHBoxLayout;
    hLayout_serial->addWidget(lb_serialPort);
    hLayout_serial->addWidget(cb_serialPort);
    hLayout_serial->addStretch(); // 下拉框居左，右侧拉伸填充
    vLayout_main->addLayout(hLayout_serial);

    // 视频存储路径布局（水平）
    QHBoxLayout *hLayout_storage = new QHBoxLayout;
    hLayout_storage->addWidget(lb_videoStoragePath);
    hLayout_storage->addWidget(le_videoStoragePath);
    hLayout_storage->addWidget(bt_selectStoragePath);
    vLayout_main->addLayout(hLayout_storage);

    // 视频分段时长布局
    QHBoxLayout *hLayout_videoDuration = new QHBoxLayout;
    hLayout_videoDuration->addWidget(lb_videoSegmentDuration);
    hLayout_videoDuration->addWidget(cb_videoSegmentDuration);
    hLayout_videoDuration->addStretch(); // 下拉框居左
    vLayout_main->addLayout(hLayout_videoDuration);

    // 摄像头配置布局
    QHBoxLayout *hLayout_camera = new QHBoxLayout;
    hLayout_camera->addWidget(lb_cameraConfig);
    hLayout_camera->addWidget(cb_cameraConfig);
    hLayout_camera->addStretch();
    vLayout_main->addLayout(hLayout_camera);

    // 温度阈值布局
    QHBoxLayout *hLayout_temp = new QHBoxLayout;
    hLayout_temp->addWidget(lb_tempThreshold);
    hLayout_temp->addSpacing(20);
    hLayout_temp->addWidget(lb_tempNormal);
    hLayout_temp->addWidget(le_tempNormal);
    hLayout_temp->addSpacing(30);
    hLayout_temp->addWidget(lb_tempSevere);
    hLayout_temp->addWidget(le_tempSevere);
    hLayout_temp->addStretch();
    vLayout_main->addLayout(hLayout_temp);

    // 湿度阈值布局
    QHBoxLayout *hLayout_humidity = new QHBoxLayout;
    hLayout_humidity->addWidget(lb_humidityThreshold);
    hLayout_humidity->addSpacing(20);
    hLayout_humidity->addWidget(lb_humidityNormal);
    hLayout_humidity->addWidget(le_humidityNormal);
    hLayout_humidity->addSpacing(30);
    hLayout_humidity->addWidget(lb_humiditySevere);
    hLayout_humidity->addWidget(le_humiditySevere);
    hLayout_humidity->addStretch();
    vLayout_main->addLayout(hLayout_humidity);

    // 光照阈值布局
    QHBoxLayout *hLayout_light = new QHBoxLayout;
    hLayout_light->addWidget(lb_lightThreshold);
    hLayout_light->addSpacing(20);
    hLayout_light->addWidget(lb_lightNormal);
    hLayout_light->addWidget(le_lightNormal);
    hLayout_light->addSpacing(30);
    hLayout_light->addWidget(lb_lightSevere);
    hLayout_light->addWidget(le_lightSevere);
    hLayout_light->addStretch();
    vLayout_main->addLayout(hLayout_light);

    // 按钮布局
    QHBoxLayout *hLayout_buttons = new QHBoxLayout;
    hLayout_buttons->addStretch(); // 按钮居右
    hLayout_buttons->addWidget(bt_confirm);
    hLayout_buttons->addSpacing(20);
    hLayout_buttons->addWidget(bt_cancel);
    vLayout_main->addLayout(hLayout_buttons);

}

void SettingWidget::initConnect()
{
    // 槽函数
    connect(bt_selectStoragePath, &QPushButton::clicked, this, &SettingWidget::onSelectStoragePath);
    connect(this->bt_confirm, SIGNAL(clicked()), this, SLOT(saveIni()));
    connect(bt_cancel, &QPushButton::clicked, this, &SettingWidget::close);
}

// 选择视频存储路径槽函数
void SettingWidget::onSelectStoragePath()
{
    QString selectedPath = QFileDialog::getExistingDirectory(this, "选择视频存储文件夹");
    if (!selectedPath.isEmpty()) {
        le_videoStoragePath->setText(selectedPath);
    }
}


// 实现获取系统串口并填充下拉框
void SettingWidget::fillSerialPortList()
{
    // 清空下拉框原有内容（避免重复添加）
    cb_serialPort->clear();

    // 获取系统中所有可用的串口列表
    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

    if (availablePorts.isEmpty()) {
        // 无可用串口时，添加提示项并禁用下拉框
        cb_serialPort->addItem("无可用串口");
        cb_serialPort->setEnabled(false); // 禁用下拉框，防止用户操作
    } else {
        // 有可用串口时，遍历并添加串口名称（跨平台兼容）
        for (const QSerialPortInfo &port : availablePorts) {
            // 添加串口名称（Windows：COMx，Linux：/dev/ttyUSBx，macOS：/dev/tty.usbmodemx）
            cb_serialPort->addItem(port.portName());
            // 若需显示串口详情（如设备描述），可改为：
            // cb_serialPort->addItem(QString("%1 (%2)").arg(port.portName()).arg(port.description()));
        }
        cb_serialPort->setEnabled(true); // 启用下拉框
    }
}

// 填充摄像头列表
void SettingWidget::fillCameraList()
{
    cb_cameraConfig->clear();
    // 获取系统中所有可用摄像头
    QList<QCameraInfo> availableCameras = QCameraInfo::availableCameras();

    if (availableCameras.isEmpty()) {
        // 无可用摄像头时显示提示
        cb_cameraConfig->addItem("无可用摄像头");
        cb_cameraConfig->setEnabled(false);
    } else {
        // 有可用摄像头时，添加摄像头名称（通常为设备名称，如"Integrated Camera"）
        for (const QCameraInfo &camera : availableCameras) {
            cb_cameraConfig->addItem(camera.description()); // 显示摄像头描述（如"集成摄像头"）
        }
        cb_cameraConfig->setEnabled(true);
    }
}

void SettingWidget::loadFromSettingData()
{
    SettingData* settingData = SettingData::getInstance();

    // 1. 串口配置
    QString serialPort = settingData->getSerialPortName();
    if (!serialPort.isEmpty()) {
        int portIndex = cb_serialPort->findText(serialPort);
        if (portIndex != -1) {
            cb_serialPort->setCurrentIndex(portIndex);
        }
    }

    // 2. 视频存储路径
    le_videoStoragePath->setText(settingData->getVideoStoragePath());

    // 3. 视频分段时长
    cb_videoSegmentDuration->setCurrentText(settingData->getVideoSegmentDuration());

    // 4. 摄像头配置
    QString camera = settingData->getCameraName();
    if (!camera.isEmpty()) {
        int cameraIndex = cb_cameraConfig->findText(camera);
        if (cameraIndex != -1) {
            cb_cameraConfig->setCurrentIndex(cameraIndex);
        }
    }

    // 5. 温度阈值
    le_tempNormal->setText(QString::number(settingData->getTempNormal()));
    le_tempSevere->setText(QString::number(settingData->getTempSevere()));

    // 6. 湿度阈值
    le_humidityNormal->setText(QString::number(settingData->getHumidityNormal()));
    le_humiditySevere->setText(QString::number(settingData->getHumiditySevere()));

    // 7. 光照阈值
    le_lightNormal->setText(QString::number(settingData->getLightNormal()));
    le_lightSevere->setText(QString::number(settingData->getLightSevere()));
}

void SettingWidget::saveIni()
{
    SettingData* settingData = SettingData::getInstance();

    // 1. 串口配置
    settingData->setSerialPortName(cb_serialPort->currentText());

    // 2. 视频相关配置
    settingData->setVideoStoragePath(le_videoStoragePath->text());
    settingData->setVideoSegmentDuration(cb_videoSegmentDuration->currentText());

    // 3. 摄像头配置
    settingData->setCameraName(cb_cameraConfig->currentText());

    // 4. 温度告警阈值
    settingData->setTempNormal(le_tempNormal->text().toDouble());
    settingData->setTempSevere(le_tempSevere->text().toDouble());

    // 5. 湿度告警阈值
    settingData->setHumidityNormal(le_humidityNormal->text().toDouble());
    settingData->setHumiditySevere(le_humiditySevere->text().toDouble());

    // 6. 光照告警阈值
    settingData->setLightNormal(le_lightNormal->text().toInt());
    settingData->setLightSevere(le_lightSevere->text().toInt());

    // 保存到INI文件
    settingData->saveIniData();

    // 发送设置完成信号
    emit settingCompleted();

    // 关闭设置页面
    qDebug()<<"设置完毕";
    this->close();
}
