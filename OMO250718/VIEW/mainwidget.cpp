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

    this->initWindow();
    this->initUi();
    this->initConnect();
    this->initData();
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
    // 垂直布局A（上方数据卡片容器，中间折线图，下方柱状图）
    layoutA = new QVBoxLayout();
    layoutA->setSpacing(10);  // 布局A间距
    layoutA->setContentsMargins(5, 5, 5, 5); // 布局A内边距

    // --------------------------
    // 新增：数据卡片大容器（包含三个小卡片）
    QWidget *cardsContainer = new QWidget(this);
    cardsContainer->setProperty("class", "CardsContainer"); // 可在QSS中定义容器样式
    QVBoxLayout *cardsLayout = new QVBoxLayout(cardsContainer); // 容器内用垂直布局
    cardsLayout->setSpacing(8); // 三个小卡片之间的间距
    cardsLayout->setContentsMargins(10, 10, 10, 10); // 大容器的内边距（与小卡片间隔）

    // 温度卡片（放入大容器）
    QWidget *tempCard = new QWidget(cardsContainer); // 父对象设为大容器
    tempCard->setProperty("class", "Card");
    QHBoxLayout *tempCardLayout = new QHBoxLayout(tempCard);
    tempCardLayout->setContentsMargins(5, 5, 5, 5);
    tempCardLayout->setSpacing(10);
    this->temperatureNameLabel = new QLabel("温度：", tempCard);
    this->temperatureLabel = new QLabel("0.00°C", tempCard);
    tempCardLayout->addWidget(temperatureNameLabel);
    tempCardLayout->addStretch();
    tempCardLayout->addWidget(temperatureLabel);

    // 湿度卡片（放入大容器）
    QWidget *humidCard = new QWidget(cardsContainer); // 父对象设为大容器
    humidCard->setProperty("class", "Card");
    QHBoxLayout *humidCardLayout = new QHBoxLayout(humidCard);
    humidCardLayout->setContentsMargins(5, 5, 5, 5);
    humidCardLayout->setSpacing(10);
    this->humidityNameLabel = new QLabel("湿度：", humidCard);
    this->humidityLabel = new QLabel("0.00%", humidCard);
    humidCardLayout->addWidget(humidityNameLabel);
    humidCardLayout->addStretch();
    humidCardLayout->addWidget(humidityLabel);

    // 光照卡片（放入大容器）
    QWidget *lightCard = new QWidget(cardsContainer); // 父对象设为大容器
    lightCard->setProperty("class", "Card");
    QHBoxLayout *lightCardLayout = new QHBoxLayout(lightCard);
    lightCardLayout->setContentsMargins(5, 5, 5, 5);
    lightCardLayout->setSpacing(10);
    this->lightNameLabel = new QLabel("光照：", lightCard);
    this->lightLabel = new QLabel("0.00", lightCard);
    lightCardLayout->addWidget(lightNameLabel);
    lightCardLayout->addStretch();
    lightCardLayout->addWidget(lightLabel);

    // 将三个小卡片添加到大容器的布局中
    cardsLayout->addWidget(tempCard);
    cardsLayout->addWidget(humidCard);
    cardsLayout->addWidget(lightCard);

    // --------------------------
    // 折线图（使用QSS的.ChartContainer样式）
    this->lineChart = new LineChart();
    this->lineChart->setProperty("class", "ChartContainer");
    this->lineChart->setParent(this);

    // 柱状图（使用QSS的.ChartContainer样式）
    this->m_barChart = new BarChart(this);
    this->m_barChart->setProperty("class", "ChartContainer");

    // 布局A添加：大容器、折线图、柱状图
    layoutA->addWidget(cardsContainer, 1);
    layoutA->addWidget(this->lineChart, 3);
    layoutA->addWidget(m_barChart, 3);

    // ===================================================
    // 垂直布局B
    layoutB = new QVBoxLayout();
    layoutB->setContentsMargins(5, 5, 5, 5);
    layoutB->setSpacing(5);

    // 摄像头画面
    this->lb_camera = new QLabel(this);
    this->lb_camera->setProperty("class", "CameraDisplay");
    this->lb_camera->setStyleSheet("background-color: black; color: white; text-align: center;");
    this->lb_camera->setAlignment(Qt::AlignCenter);
    this->lb_camera->setMinimumSize(640, 480);

    // 设置按钮
    this->bt_settingWidget = new QPushButton("设置", this);

    layoutB->addWidget(bt_settingWidget);
    layoutB->addWidget(this->lb_camera);

    // ===================================================
    // 垂直布局C（预留布局）
    layoutC = new QVBoxLayout();
    layoutC->setContentsMargins(5, 5, 5, 5);
    layoutC->setSpacing(10);

    // 总布局添加三个垂直布局
    layoutMain->addLayout(layoutA, 3);
    layoutMain->addLayout(layoutB, 4);
    layoutMain->addLayout(layoutC, 3);

    this->setLayout(layoutMain);
}

void MainWidget::initConnect()
{
    connect(this->bt_settingWidget, SIGNAL(clicked()), this, SLOT(showSettingWidget()));
    connect(settingWidget, &SettingWidget::settingCompleted, this, &MainWidget::onSettingCompleted);
    connect(readDataTimer, SIGNAL(timeout()), this, SLOT(readSerialData()));
}

void MainWidget::initData()
{
    // 视图层定义三个空容器，用于接收数据
    QList<QString> dates;       // 日期列表
    QList<double> maxTemps;     // 最高温列表
    QList<double> minTemps;     // 最低温列表

    // 调用Controller，通过引用填充数据
    EnviDataController::getInstance()->getLast7DaysTempData(dates, maxTemps, minTemps);

    // 直接使用填充好的数据更新柱状图
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
            // 使用单次定时器延迟显示设置界面，避免递归问题
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
