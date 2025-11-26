#include "vedioplayer.h"


VedioPlayer::VedioPlayer(QWidget *parent):QWidget (parent)
{
    qDebug()<<"initData";
    this->initData("../FILEIN/save.h264");
    qDebug()<<"initWin";
    this->initWin();
    this->initUI();
    this->initConnect();
    qDebug()<<"initQss";
    this->initQss();
}

VedioPlayer::~VedioPlayer()
{
    qDebug() << "VedioPlayer 析构函数调用";

       if (videoThread) {
           // 先停止线程
           videoThread->setIsClose(true);

           // 等待线程结束
           if (videoThread->isRunning()) {
               qDebug()<<"VedioPlayer析构 线程还在运行";
               videoThread->wait(2000); // 最多等待2秒
           }

           // 删除线程对象
           delete videoThread;
           videoThread = nullptr;
       }

       qDebug() << "VedioPlayer 完全销毁";
}

void VedioPlayer::initWin()
{
    this->resize(1920, 1080);
    this->setWindowTitle("视频回放");
}

void VedioPlayer::initUI()
{
    // 创建总布局
    this->totalLayout = new QVBoxLayout(this);

    // ========== 顶部布局 ==========
    this->topView = new QWidget();
    this->topViewLayout = new QHBoxLayout(this->topView);

    this->title = new QLabel("视频播放");
    this->title->setObjectName("videoTitle");
    this->title->setStyleSheet("font-size: 24px; font-weight: bold;");

    this->returnBtn = new QPushButton("返回");
    this->returnBtn->setObjectName("returnBtn");
    this->returnBtn->setFixedSize(80, 40);

    this->topViewLayout->addWidget(this->title);
    this->topViewLayout->addStretch(1);
    this->topViewLayout->addWidget(this->returnBtn);
    this->topView->setLayout(this->topViewLayout);

    // ========== 视频显示区域 ==========
    this->vedio = new QLabel();
    this->vedio->setObjectName("videoDisplay");
    this->vedio->setAlignment(Qt::AlignCenter);
    this->vedio->setScaledContents(true);
    this->vedio->setMinimumSize(1600, 900);
    this->vedio->setStyleSheet("background-color: black; border: 2px solid #ccc;");
    this->vedio->setText("视频播放区域\n(实际播放器实现)");

    // ========== 进度条 ==========
    this->slider = new QSlider(Qt::Horizontal);
    this->slider->setObjectName("progressSlider");
    this->slider->setRange(0, 100);
    this->slider->setValue(0);
    this->slider->setFixedHeight(20);

    // ========== 底部控制栏 ==========
    this->buttomView = new QWidget();
    this->buttomViewLayout = new QHBoxLayout(this->buttomView);

    this->playBtn = new QPushButton("播放");
    this->playBtn->setObjectName("playBtn");
    this->playBtn->setFixedSize(80, 40);

    this->rewindBtn = new QPushButton("后退");
    this->rewindBtn->setObjectName("rewindBtn");
    this->rewindBtn->setFixedSize(80, 40);

    this->forwardBtn = new QPushButton("前进");
    this->forwardBtn->setObjectName("forwardBtn");
    this->forwardBtn->setFixedSize(80, 40);

    this->speedCombox = new QComboBox();
    this->speedCombox->setObjectName("speedCombox");
    this->speedCombox->addItems({"0.5x", "1.0x", "1.5x", "2.0x", "5.0x"});
    this->speedCombox->setCurrentIndex(1); // 默认1.0x
    this->speedCombox->setFixedSize(80, 40);

    this->downloadBtn = new QPushButton("下载");
    this->downloadBtn->setObjectName("downloadBtn");
    this->downloadBtn->setFixedSize(80, 40);

    this->buttomViewLayout->addWidget(this->playBtn);
    this->buttomViewLayout->addWidget(this->rewindBtn);
    this->buttomViewLayout->addWidget(this->forwardBtn);
    this->buttomViewLayout->addWidget(this->speedCombox);
    this->buttomViewLayout->addStretch(1);
    this->buttomViewLayout->addWidget(this->downloadBtn);
    this->buttomView->setLayout(this->buttomViewLayout);

    // ========== 添加到总布局 ==========
    this->totalLayout->addWidget(this->topView, 1);
    this->totalLayout->addWidget(this->vedio, 8);
    this->totalLayout->addWidget(this->slider, 1);
    this->totalLayout->addWidget(this->buttomView, 1);

    this->setLayout(this->totalLayout);
}

void VedioPlayer::initConnect()
{
    connect(this->videoThread, SIGNAL(sendImg(QImage)), this, SLOT(reciveImg(QImage)));
    connect(this->playBtn, SIGNAL(clicked()), this, SLOT(playBtn_clicked()));
    connect(this->speedCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(chooseSpeedCombox()));

    connect(this->videoThread, SIGNAL(sendTotalDuration(qint64)), this, SLOT(setTotalDuration(qint64)));
    connect(this->videoThread, SIGNAL(sendCurrentProgress(qint64)), this, SLOT(updateProgress(qint64)));

    connect(this->downloadBtn, SIGNAL(clicked()), this, SLOT(downloadBtn_clicked()));
}

void VedioPlayer::initQss()
{

}

void VedioPlayer::initData(QString videoPath)
{
    this->videoPath = videoPath;
    this->videoThread = new PlayThread(videoPath);
    this->isPlay = false;
    // 标记为是第一次播放，如果是第一次播放，则启动线程
    this->isFirstPlay = true;
}

void VedioPlayer::startVideoThread()
{
    this->videoThread->start();
}

void VedioPlayer::setTitle(QString title)
{
    this->title->setText(title);
}

void VedioPlayer::paintEvent(QPaintEvent *event)
{
    if (!this->img.isNull()) {
        this->vedio->setPixmap(QPixmap::fromImage(this->img));
    }
}

void VedioPlayer::closeEvent(QCloseEvent *event)
{
    this->videoThread->setIsClose(true);
    emit showMainWidget();
    event->accept();
}

void VedioPlayer::reciveImg(QImage img)
{
    if(img.isNull()){
        qDebug()<<"播放器收到图片为空";
        return;
    }
    this->img = img;
    this->vedio->update();
}

void VedioPlayer::playBtn_clicked()
{
    if(this->isFirstPlay){
        this->isFirstPlay = false;
        this->isPlay = true;
        this->playBtn->setText("暂停");
        this->videoThread->setIsPlay(this->isPlay);
        qDebug()<<"第一次播放视频，启动线程";
        this->startVideoThread();
        return;
    }

    if(this->isPlay){
        qDebug("暂停视频");
        this->isPlay = false;
        this->playBtn->setText("播放");
        this->videoThread->setIsPlay(this->isPlay);
    }
    else if(!this->isPlay){
        qDebug("播放视频");
        this->isPlay = true;
        this->playBtn->setText("暂停");
        this->videoThread->setIsPlay(this->isPlay);
    }
}

void VedioPlayer::chooseSpeedCombox()
{
    QString speedText = this->speedCombox->currentText();
    qDebug()<<"当前选中的倍数文本:"<<speedText;

    double speed = speedText.remove("x").toDouble();
    this->videoThread->setPlaySpeed(speed);
}

// ===============================
// 新增：设置进度条最大值（总时长）
void VedioPlayer::setTotalDuration(qint64 totalSec)
{
    slider->setRange(0, totalSec); // 进度条范围：0到总秒数
}

void VedioPlayer::downloadBtn_clicked()
{
    // 步骤1：弹出保存对话框，限制为MP4格式
    QString defaultFileName = QFileInfo(videoPath).baseName() + ".mp4"; // 用原视频名作为默认名
    QString savePath = QFileDialog::getSaveFileName(
        this,
        "保存视频",
        defaultFileName,
        "MP4 视频文件 (*.mp4)" // 仅允许MP4格式
    );

    // 步骤2：判断用户是否取消操作
    if (savePath.isEmpty()) {
        QMessageBox::information(this, "提示", "已取消保存");
        return;
    }

    // 步骤3：检查源文件是否存在
    if (!QFile::exists(videoPath)) {
        QMessageBox::warning(this, "错误", "源视频文件不存在：" + videoPath);
        return;
    }

    // 步骤4：使用TranceCode类进行转码保存（注意：转码耗时，建议放后台线程）
    // 临时使用同步方式（实际项目需改为异步线程，避免UI卡顿）
    TranceCode tranceCode(videoPath, savePath);
    tranceCode.initDecode();   // 初始化解码（打开源文件）
    tranceCode.initEncode();   // 初始化编码（创建目标文件）
    tranceCode.tranceCode();   // 执行转码

    // 步骤5：提示结果（实际需根据转码返回值判断，这里简化处理）
    if (QFile::exists(savePath) && QFileInfo(savePath).size() > 0) {
        QMessageBox::information(this, "成功", "视频已保存至：\n" + savePath);
    } else {
        QMessageBox::warning(this, "失败", "保存视频失败，请检查转码逻辑");
    }
}

// 新增：更新进度条当前值
void VedioPlayer::updateProgress(qint64 currentSec)
{
    // 避免滑块拖动时被实时更新覆盖（仅在非拖动状态更新）
    if (!slider->isSliderDown()) {
        slider->setValue(currentSec);
    }
}
// =================================
