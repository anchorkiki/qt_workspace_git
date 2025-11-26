#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    this->readDataTimer = new QTimer(this);
    this->readDataTimer->setInterval(1000);

    this->serial = new QSerialPort(this);

    this->settingWidget = new SettingWidget();

    this->lux = 0;
    this->temperature = 0;
    this->humidity = 0;

    this->isFourCameraMode = true; // 默认是四摄像头模式
    this->currentSingleCameraIndex = 0; // 默认显示第一个摄像头

    this->videoPlayWidget = nullptr;

    qDebug()<<"initWindow";
    this->initWindow();
    qDebug()<<"initUi";
    this->initUi();
    qDebug()<<"initConnect";
    this->initConnect();
    qDebug()<<"initData";
    this->initData();
    qDebug()<<"initQss";
    this->initQss();
}

MainWidget::~MainWidget()
{
    qDebug()<<"MainWidget析构";
    if(cameraThread){
        cameraThread->setIsClose(true);
        cameraThread->wait();
        delete cameraThread;
    }
}

void MainWidget::initWindow()
{
    this->resize(1920, 1080);
    this->setWindowTitle("智能监控系统");
}

void MainWidget::initUi()
{
    // 主布局
    layoutMain = new QHBoxLayout(this);
    layoutMain->setContentsMargins(10, 10, 10, 10); // 外边框
    layoutMain->setSpacing(15); // 总布局间距

    // ===================================================
    // 垂直布局A
    layoutA = new QVBoxLayout();
    layoutA->setSpacing(10);
    layoutA->setContentsMargins(5, 5, 5, 5);

    // --------------------------
    // 上部分：数据Widget（包含温度湿度光照）
    QWidget *cardsContainer = new QWidget(this);
    cardsContainer->setProperty("class", "CardsContainer");
    QVBoxLayout *cardsLayout = new QVBoxLayout(cardsContainer);
    cardsLayout->setSpacing(8);
    cardsLayout->setContentsMargins(10, 10, 10, 10); // 数据Widgett的内边距（与小卡片间隔）

    // 温度
    QWidget *tempCard = new QWidget(cardsContainer);
    tempCard->setProperty("class", "Card");
    QHBoxLayout *tempCardLayout = new QHBoxLayout(tempCard);
    tempCardLayout->setContentsMargins(5, 5, 5, 5);
    tempCardLayout->setSpacing(10);
    this->temperatureNameLabel = new QLabel("温度：", tempCard);
    this->temperatureLabel = new QLabel("0.00°C", tempCard);
    tempCardLayout->addWidget(temperatureNameLabel);
    tempCardLayout->addStretch();
    tempCardLayout->addWidget(temperatureLabel);

    // 湿度
    QWidget *humidCard = new QWidget(cardsContainer);
    humidCard->setProperty("class", "Card");
    QHBoxLayout *humidCardLayout = new QHBoxLayout(humidCard);
    humidCardLayout->setContentsMargins(5, 5, 5, 5);
    humidCardLayout->setSpacing(10);
    this->humidityNameLabel = new QLabel("湿度：", humidCard);
    this->humidityLabel = new QLabel("0.00%", humidCard);
    humidCardLayout->addWidget(humidityNameLabel);
    humidCardLayout->addStretch();
    humidCardLayout->addWidget(humidityLabel);

    // 光照
    QWidget *lightCard = new QWidget(cardsContainer);
    lightCard->setProperty("class", "Card");
    QHBoxLayout *lightCardLayout = new QHBoxLayout(lightCard);
    lightCardLayout->setContentsMargins(5, 5, 5, 5);
    lightCardLayout->setSpacing(10);
    this->lightNameLabel = new QLabel("光照：", lightCard);
    this->lightLabel = new QLabel("0.00", lightCard);
    lightCardLayout->addWidget(lightNameLabel);
    lightCardLayout->addStretch();
    lightCardLayout->addWidget(lightLabel);

    // 添加到数据Widget的布局
    cardsLayout->addWidget(tempCard);
    cardsLayout->addWidget(humidCard);
    cardsLayout->addWidget(lightCard);

    // --------------------------
    // 中部：折线图
    this->lineChart = new LineChart();
    this->lineChart->setProperty("class", "ChartContainer");
    this->lineChart->setParent(this);

    // --------------------------
    // 下部：柱状图
    this->m_barChart = new BarChart(this);
    this->m_barChart->setProperty("class", "ChartContainer");

    // 添加到布局A
    layoutA->addWidget(cardsContainer, 1);
    layoutA->addWidget(this->lineChart, 3);
    layoutA->addWidget(m_barChart, 3);

    // ===================================================
    // 垂直布局B
    layoutB = new QVBoxLayout();
    layoutB->setContentsMargins(5, 5, 5, 5);
    layoutB->setSpacing(5);

    // --------------------------
    // 上部：标题标签
    this->lb_title = new QLabel("小蔡监控系统", this);
    lb_title->setProperty("class", "LayoutBTitle");
    lb_title->setAlignment(Qt::AlignCenter); // 居中

    // --------------------------
    // 中部：四个摄像头
    QWidget* cameraContainer = new QWidget(this);
    cameraContainer->setProperty("class", "CameraContainer");
    QGridLayout* cameraGrid = new QGridLayout(cameraContainer);
    cameraGrid->setSpacing(2);
    cameraGrid->setContentsMargins(0, 0, 0, 0);

    // 四个摄像头
    this->lb_camera = new QLabel(cameraContainer);
    this->lb_camera2 = new QLabel(cameraContainer);
    this->lb_camera3 = new QLabel(cameraContainer);
    this->lb_camera4 = new QLabel(cameraContainer);

    // 设置摄像头标签样式
    auto setCameraLabelStyle = [this](QLabel* label) {
        label->setProperty("class", "CameraDisplay");
        label->setStyleSheet("background-color: black; color: white; text-align: center;");
        label->setAlignment(Qt::AlignCenter);
        label->setMinimumSize(320, 240);
    };
    setCameraLabelStyle(lb_camera);
    setCameraLabelStyle(lb_camera2);
    setCameraLabelStyle(lb_camera3);
    setCameraLabelStyle(lb_camera4);

    // 添加到田字布局布局
    cameraGrid->addWidget(lb_camera, 0, 0);
    cameraGrid->addWidget(lb_camera2, 0, 1);
    cameraGrid->addWidget(lb_camera3, 1, 0);
    cameraGrid->addWidget(lb_camera4, 1, 1);

    // 设置网格拉伸比例
    cameraGrid->setRowStretch(0, 1);
    cameraGrid->setRowStretch(1, 1);
    cameraGrid->setColumnStretch(0, 1);
    cameraGrid->setColumnStretch(1, 1);

    // --------------------------
    // 下部：单/四通道切换，设置界面按钮，回放（登录）按钮
    QWidget* bottomContainer = new QWidget(this);
    bottomContainer->setProperty("class", "LayoutBBottom");
    QHBoxLayout* bottomLayout = new QHBoxLayout(bottomContainer);
    bottomLayout->setContentsMargins(5, 5, 5, 5);
    bottomLayout->setSpacing(10);

    // 下部左侧
    this->lb_single = new QPushButton(this);
    this->lb_four = new QPushButton(this);
    this->lb_setting = new QPushButton(this);
    // 下部右侧
    this->lb_extend = new QPushButton(this);

    lb_single->setProperty("class", "BottomImageButton");
    lb_four->setProperty("class", "BottomImageButton");
    lb_setting->setProperty("class", "BottomImageButton");
    lb_extend->setProperty("class", "BottomExtendButton");


    // 加载图片到标签
    lb_single->setMinimumSize(60, 60);
    lb_four->setMinimumSize(60, 60);
    lb_setting->setMinimumSize(60, 60);
    lb_extend->setMinimumSize(60, 60);

    // 加载图片
    QPixmap singlePix(":/img/single.png");
    QPixmap fourPix(":/img/four.png");
    QPixmap settingPix(":/img/setting.png");
    QPixmap extendPix(":/img/extend.png");

    // 图片设置为按钮图标（自动缩放）
    if (!singlePix.isNull()) {
        lb_single->setIcon(QIcon(singlePix));
        lb_single->setIconSize(lb_single->size());  // 图标大小适应按钮大小
    }
    if (!fourPix.isNull()) {
        lb_four->setIcon(QIcon(fourPix));
        lb_four->setIconSize(lb_four->size());
    }
    if (!settingPix.isNull()) {
        lb_setting->setIcon(QIcon(settingPix));
        lb_setting->setIconSize(lb_setting->size());
    }
    if (!extendPix.isNull()) {
        lb_extend->setIcon(QIcon(extendPix));
        lb_extend->setIconSize(lb_extend->size());
    }

    // 按钮样式设置（去掉边框、背景，使其看起来像标签）
    auto setButtonStyle = [](QPushButton* btn) {
        btn->setStyleSheet("border: none; background: transparent;");  // 无边框、透明背景
        btn->setCursor(Qt::PointingHandCursor);  // 鼠标悬停显示手型
    };
    setButtonStyle(lb_single);
    setButtonStyle(lb_four);
    setButtonStyle(lb_setting);
    setButtonStyle(lb_extend);

    // 添加到水平布局
    bottomLayout->addWidget(lb_single);
    bottomLayout->addWidget(lb_four);
    bottomLayout->addWidget(lb_setting);
    bottomLayout->addStretch(); // 中间空白
    bottomLayout->addWidget(lb_extend);

    // --------------------------
    // 布局B组装：标题，摄像头，下部按钮
    layoutB->addWidget(lb_title, 1);
    layoutB->addWidget(cameraContainer, 8);
    layoutB->addWidget(bottomContainer, 1);

    // ===================================================
    // 垂直布局C
    layoutC = new QVBoxLayout();
    layoutC->setContentsMargins(5, 5, 5, 5);
    layoutC->setSpacing(10);

    // 总布局添加三个垂直布局
    layoutMain->addLayout(layoutA, 2);
    layoutMain->addLayout(layoutB, 5);
    layoutMain->addLayout(layoutC, 2);

    this->setLayout(layoutMain);
}

void MainWidget::initConnect()
{
    // 设置界面设置完成，发送设置参数
    connect(settingWidget, &SettingWidget::settingCompleted, this, &MainWidget::onSettingCompleted);
    // 读取温湿度数据，绘制折线图
    connect(readDataTimer, SIGNAL(timeout()), this, SLOT(readSerialData()));
    // 单/四通道
    connect(lb_single, &QPushButton::clicked, this, &MainWidget::onSingleClicked);
    connect(lb_four, &QPushButton::clicked, this, &MainWidget::onFourClicked);
    // 打开设置界面
    connect(lb_setting, &QPushButton::clicked, this, &MainWidget::showSettingWidget);
    // 打开回放视频界面
    connect(lb_extend, SIGNAL(clicked()), this, SLOT(showVideoPlayerWidget()));
}

void MainWidget::initData()
{
    QList<QString> dates;       // 日期列表
    QList<double> maxTemps;     // 最高温列表
    QList<double> minTemps;     // 最低温列表

    // 填充数据
    EnviDataController::getInstance()->getLast7DaysTempData(dates, maxTemps, minTemps);

    // 更新柱状图
    m_barChart->updateData(dates, maxTemps, minTemps);
}

void MainWidget::initQss()
{
    QFile file(":/mainWidget.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
        file.close();
    } else {
        qDebug()<<"无法加载QSS文件：";
    }
}

void MainWidget::initSerial()
{
    // 如果串口已打开，先关闭
    if(serial->isOpen()){
        serial->close();
    }

    // 配置串口参数
    serial->setPortName(this->serialName);
    serial->setDataBits(QSerialPort::Data8);
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}

void MainWidget::openSerial()
{
    // 打开串口
    bool isOpen = serial->open(QIODevice::ReadWrite);
    if(!isOpen){
        // 打开失败
        QMessageBox::critical(this, "串口错误", QString("无法打开串口 %1：%2").arg(this->serialName));
    }
    else{
        // 打开成功
        // 开始读取数据
        serial->write("CONNECT");
        // 启动定时器读取串口数据
        readDataTimer->start();
    }
}

int MainWidget::checkSetting()
{
    // 检查摄像头
    QSettings settings("../config.ini", QSettings::IniFormat);
    QString cameraName = settings.value("Camera/Name").toString();
    qDebug()<<"摄像头:"<<cameraName;

    // 获取所有可用摄像头
    QList<QCameraInfo> availableCameras = QCameraInfo::availableCameras();
    if (availableCameras.isEmpty()) {
        QMessageBox::warning(this, "设备错误", "未检测到任何可用摄像头，请检查设备后重新配置");
        return -1;
    }

    // 检查配置的摄像头是否存在
    bool isCameraValid = false;
    foreach (const QCameraInfo& cam, availableCameras) {
        if (cam.description() == cameraName) {
            isCameraValid = true;
            break;
        }
    }

    // 摄像头不存在时返回错误状态
    if (!isCameraValid) {
        QMessageBox::warning(this, "配置错误",
            QString("配置的摄像头「%1」不存在，请重新选择").arg(cameraName));
        return -1;
    }

    // 检查串口
    QString serialPort = settings.value("SerialPort/PortName").toString();
    qDebug()<<"摄像头:"<<serialPort;
    if (!serialPort.isEmpty()) {
        bool isSerialValid = false;
        foreach (const QSerialPortInfo& port, QSerialPortInfo::availablePorts()) {
            if (port.portName() == serialPort) {
                isSerialValid = true;
                break;
            }
        }
        if (!isSerialValid) {
            QMessageBox::warning(this, "配置错误", QString("配置的串口「%1」不存在，请重新选择").arg(serialPort));
            return -1;
        }
    }

    return 1;
}

void MainWidget::startCameraAuto()
{
    // 检查摄像头是否有效
    QSettings settings("../config.ini", QSettings::IniFormat);
    QString cameraName = settings.value("Camera/Name", "Integrated Camera").toString();

//    bool isCameraValid = false;
//    foreach (const QCameraInfo& cam, QCameraInfo::availableCameras()) {
//        if (cam.description() == cameraName) {
//            isCameraValid = true;
//            break;
//        }
//    }

//    if (!isCameraValid) {
//        qDebug() << "摄像头无效，不启动线程";
//        return;
//    }

    // 初始化摄像头线程
    cameraThread = new OpenCamera(cameraName);
    isCameraInitialized = true;
    connect(cameraThread, &OpenCamera::sendImg, this, &MainWidget::onReceiveCameraImage);
    cameraThread->setIsPlay(true);
    cameraThread->start();
}

void MainWidget::onSettingCompleted(QString serialPortName, QString cameraName)
{
    this->serialName = serialPortName.trimmed().remove("\"");
    qDebug()<<"收到串口名称:"<<this->serialName;

    this->initSerial();
    this->openSerial();

    // 更新摄像头配置（重启摄像头线程）
    qDebug()<<"收到摄像头名称:"<<cameraName;
    restartCamera(cameraName);

    this->show(); // 重新显示主界面
}

void MainWidget::readSerialData()
{
    if(!this->serial || !this->serial->isOpen()){
        QMessageBox::information(this, "提示", "串口未打开");
        qDebug()<<"readSerialData():串口未打开\n";
        return;
    }
    QString readBuf = QString(this->serial->readAll());
    QString cleanedBuf = readBuf.trimmed();
    qDebug()<<"全部读取内容："<<readBuf<<"\n";

    QStringList allBuf = readBuf.split(",");
    QStringList splitBuf;
    // 过滤空的
    for(int i = 0; i < allBuf.size(); i++){
        QString buf = allBuf[i];
        if(!buf.isEmpty()){
            qDebug()<<i<<":"<<buf<<"\n";
            splitBuf.append(buf);
        }
    }

    if(splitBuf.size() == 3){
        this->lux = splitBuf[0].split(":")[1].toDouble();

        // 解析温度,去除末尾"C"
        QString tempStr = splitBuf[1].split(":")[1].trimmed(); // 先去除空格
        tempStr.remove("C"); // 移除温度单位
        this->temperature = tempStr.toDouble();

        // 解析湿度,去除末尾"%"
        QString humidStr = splitBuf[2].split(":")[1].trimmed();
        humidStr.remove("%"); // 移除湿度单位
        this->humidity = humidStr.toDouble();

        qDebug()<<"光照:"<<lux;
        qDebug()<<"温度:"<<temperature;
        qDebug()<<"湿度:"<<humidity;

        this->lightLabel->setText(QString::number(this->lux, 'f', 2));
        this->temperatureLabel->setText(QString::number(this->temperature, 'f', 2) + "C");
        this->humidityLabel->setText(QString::number(this->humidity, 'f', 2) + "%");

        // 获取当前时间
        QDateTime currentTime = QDateTime::currentDateTime();
        // 调用折线图方法添加数据
        this->lineChart->addTempData(currentTime, this->temperature);
        this->lineChart->addLuxData(currentTime, this->lux);
        this->lineChart->addHumidData(currentTime, this->humidity);

        // 调用控制器写入数据
        int res = EnviDataController::getInstance()->insertDataToDB(this->temperature, this->humidity, this->lux);
        if(res == 1){
            qDebug() << "数据成功写入数据库";
        }
        else{
            qDebug() << "数据写入数据库失败";
        }
    }
    else{
        qDebug()<<"readSerialData():splitBuf长度不为3\n";
    }

}

void MainWidget::showSettingWidget()
{
    qDebug()<<"进入showSettingWidget()";

    if(cameraThread){
        qDebug()<<"线程在运行";
        disconnect(cameraThread, &OpenCamera::sendImg, this, &MainWidget::onReceiveCameraImage);
        qDebug()<<"断开直播线程的连接";
        cameraThread->setIsClose(true); // 触发线程退出
        qDebug()<<"线程在运行";
        if(!cameraThread->wait(3000)) { // 等待3秒
            qDebug() << "线程没有正常结束，强制终止";
            cameraThread->terminate();
            cameraThread->wait();
        }
        delete cameraThread;
        cameraThread = nullptr;
        qDebug()<<"结束已经启动的摄像头线程";
    }
    else{
        qDebug()<<"线程没有在运行";
    }

    qDebug()<<"重新创建或显示设置界面检查";
    // 重新创建或显示设置界面
    if(settingWidget){
        qDebug()<<"准备释放设置界面";
        disconnect(settingWidget, &SettingWidget::settingCompleted, this, &MainWidget::onSettingCompleted);
        settingWidget->close();
        delete settingWidget;
        settingWidget = nullptr;
    }

    qDebug()<<"创建设置界面";
    settingWidget = new SettingWidget();
    connect(settingWidget, &SettingWidget::settingCompleted, this, &MainWidget::onSettingCompleted);
    settingWidget->show();
    this->hide(); // 隐藏主界面
}

void MainWidget::onReceiveCameraImage(QImage img)
{
    if (img.isNull()){
        qDebug()<<"直播收到图片为空";
        return;
    }

    // 缩放图像以适应标签大小
    QImage scaledImg = img.scaled(
        this->lb_camera->size(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
    );
    this->lb_camera->setPixmap(QPixmap::fromImage(scaledImg));
}

void MainWidget::restartCamera(QString newCameraName){
    // 停止旧线程
    if (cameraThread && cameraThread->isRunning()) {
        cameraThread->setIsClose(true); // 触发线程退出循环
        cameraThread->wait(); // 等待线程结束
        delete cameraThread;
        cameraThread = nullptr;
    }
    // 用新摄像头名称启动线程
    cameraThread = new OpenCamera(newCameraName);
    connect(cameraThread, &OpenCamera::sendImg, this, &MainWidget::onReceiveCameraImage);
    cameraThread->setIsPlay(true);
    cameraThread->start();
}

void MainWidget::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    static bool isFirstShow = true;
    if (isFirstShow) {
        isFirstShow = false;
        // 首次显示时检查配置
        qDebug()<<"472";
        int checkResult = checkSetting();

        if(checkResult != 1){
            qDebug() << "配置异常，显示设置界面";
            // 使用单次定时器延迟显示设置界面
            QTimer::singleShot(100, this, &MainWidget::showSettingWidget);
        }
        else{
            // 配置正常，初始化串口和摄像头
            QSettings settings("../config.ini", QSettings::IniFormat);
            QString serialPort = settings.value("SerialPort/PortName").toString();
            if (!serialPort.isEmpty()) {
                this->serialName = serialPort;
                this->initSerial();
                this->openSerial();
            }
            this->startCameraAuto();
        }
    }
}

void MainWidget::updateCameraLayout()
{
    // 获取摄像头容器的布局
    QGridLayout* cameraGrid = qobject_cast<QGridLayout*>(lb_camera->parentWidget()->layout());
    if (!cameraGrid) return;

    // 先隐藏所有摄像头标签
    lb_camera->hide();
    lb_camera2->hide();
    lb_camera3->hide();
    lb_camera4->hide();

    if (isFourCameraMode) {
        // 田字布局
        // 重新添加所有摄像头到网格并显示
        cameraGrid->addWidget(lb_camera, 0, 0);
        cameraGrid->addWidget(lb_camera2, 0, 1);
        cameraGrid->addWidget(lb_camera3, 1, 0);
        cameraGrid->addWidget(lb_camera4, 1, 1);

        // 显示所有摄像头
        lb_camera->show();
        lb_camera2->show();
        lb_camera3->show();
        lb_camera4->show();

        // 恢复网格比例
        cameraGrid->setRowStretch(0, 1);
        cameraGrid->setRowStretch(1, 1);
        cameraGrid->setColumnStretch(0, 1);
        cameraGrid->setColumnStretch(1, 1);
    }
    else {
        // 单摄像头模式
        // 根据当前索引显示对应的摄像头
        QLabel* currentCamera = nullptr;
        switch (currentSingleCameraIndex) {
            case 0:
                currentCamera = lb_camera;
                break;
            case 1:
                currentCamera = lb_camera2;
                break;
            case 2:
                currentCamera = lb_camera3;
                break;
            case 3:
                currentCamera = lb_camera4;
                break;
            default:
                currentCamera = lb_camera;
        }

        // 将当前摄像头添加到网格并占据整个空间
        cameraGrid->addWidget(currentCamera, 0, 0, 2, 2); // 跨2行2列
        currentCamera->show();

        // 设置网格比例
        cameraGrid->setRowStretch(0, 1);
        cameraGrid->setRowStretch(1, 1);
        cameraGrid->setColumnStretch(0, 1);
        cameraGrid->setColumnStretch(1, 1);
    }
}

void MainWidget::onSingleClicked()
{
    if (isFourCameraMode) {
        // 从四摄像头模式切换到单摄像头模式
        isFourCameraMode = false;
        currentSingleCameraIndex = 0; // 从第一个摄像头开始
    } else {
        // 已经是单摄像头模式，切换到下一个摄像头
        currentSingleCameraIndex = (currentSingleCameraIndex + 1) % 4;
    }
    updateCameraLayout();
}

void MainWidget::onFourClicked()
{
    if (!isFourCameraMode) {
        // 从单摄像头模式切换到四摄像头模式
        isFourCameraMode = true;
        updateCameraLayout();
    }
    // 如果已经是四摄像头模式，不做处理
}

void MainWidget::showVideoPlayerWidget()
{
    qDebug()<<"showVideoPlayerWidget()";

    if(cameraThread){
        qDebug()<<"线程在运行";
        disconnect(cameraThread, &OpenCamera::sendImg, this, &MainWidget::onReceiveCameraImage);
        qDebug()<<"断开直播线程的连接";
        cameraThread->setIsClose(true); // 触发线程退出
        qDebug()<<"线程在运行";
        if(!cameraThread->wait(3000)) { // 等待3秒
            qDebug() << "线程没有正常结束，强制终止";
            cameraThread->terminate();
            cameraThread->wait();
        }
        delete cameraThread;
        cameraThread = nullptr;
        qDebug()<<"结束已经启动的摄像头线程";
    }
    else{
        qDebug()<<"线程没有在运行";
    }

    this->hide();

    if(this->videoPlayWidget){
        qDebug()<<"videoPlayer 已经存在，先释放";
        delete this->videoPlayWidget;

        this->videoPlayWidget = new VedioPlayer();
        connect(this->videoPlayWidget, SIGNAL(showMainWidget()), this, SLOT(showMyMainWidget()));
        qDebug()<<"new 一个新的 videoPlayer";
    }
    else{
        qDebug()<<"videoPlayer 不存在，先new";
        this->videoPlayWidget = new VedioPlayer();
        connect(this->videoPlayWidget, SIGNAL(showMainWidget()), this, SLOT(showMyMainWidget()));
    }

//    this->videoPlayWidget->setTitle(item->text());
    this->videoPlayWidget->show();
}

void MainWidget::showMyMainWidget()
{
    this->show();
}
