#ifndef PLAYTHREAD_H
#define PLAYTHREAD_H

#include <QThread>
#include <QString>
#include <QDebug>
#include <QImage>

extern "C"
{
    #include "libavcodec/avcodec.h"            //编解码库，最重要的模块之一
    #include "libavdevice/avdevice.h"            //输入输出设备库；读取摄像头的
    #include "libavfilter/avfilter.h"            //音视频滤镜库；进行音视频处理与编辑
    #include "libavformat/avformat.h"            //文件格式和协议库
    #include "libavutil/avutil.h"                //音视频处理
    #include "libswresample/swresample.h"    //音频重采样
    #include "libswscale/swscale.h"            //图像进行格式转换
}

class PlayThread : public QThread
{
    Q_OBJECT;

public:
    PlayThread(QString videoPath);       //类型
    ~PlayThread(); // 释放资源
    //1.打开视频
    int openVideo();
    //2.查找视频流
    int findVideoStream();
    //3.打开解码器
    int openDecoder();
    //4.数据准备
    void prepareData();
    //5.解码
    void decodeRGB32();

    QString getVideoPath() const;
    void setVideoPath(const QString &value);

    bool getIsPlay() const;
    void setIsPlay(bool value);

    float getPlaySpeed() const;
    void setPlaySpeed(double value);

    int transPlaySpeed();

    bool getIsClose() const;
    void setIsClose(bool value);

private:
    QString videoPath;        //解码视频路径
    AVFormatContext* pFormatContext;    //封装格式上下文结构体
    int videoIndex;           //视频流下标
    AVCodecContext* pCodecContext;      //编解码器上下文结构体
    AVCodec*decoder;          //解码器
    AVPacket*pkt;             //压缩的一帧码流数据
    AVFrame*frame, *RGBFrame; //frame 完整的像素数据 RGBFr
    SwsContext *pSwsContext;  //转置格式结构体指针
    QImage img;
    uint8_t* bufferRGB;

    bool isPlay;
    bool isClose;

    double playSpeed;

    qint64 totalDuration; // 视频总时长（单位：微秒）
    qint64 currentTime;  // 当前播放时间（单位：微秒）

protected:
    void run();


signals:
    void sendImg(QImage img);
    void sendTotalDuration(qint64 totalSec); // 发送总时长（秒）
    void sendCurrentProgress(qint64 currentSec); // 发送当前进度（秒）
};

#endif // PLAYTHREAD_H
