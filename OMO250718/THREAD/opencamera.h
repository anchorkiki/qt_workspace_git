#ifndef OPENCAMERA_H
#define OPENCAMERA_H

#include <QString>
#include <QDebug>
#include <QImage>
#include <QThread>
#include "TOOL/encodetoh264.h"

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

//封装格式（avi/mp4/flv）解封装获 AVPacket，解码生成 AVFrame 像素数据，转 RGB32 后存储为本地图片。

class OpenCamera : public QThread
{
    Q_OBJECT;
public:
    explicit OpenCamera(QString cameraName);
    ~OpenCamera();
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

    bool getIsClose() const;
    void setIsClose(bool value);

    QString getCameraName() const;
    void setCameraName(const QString &value);

protected:
    void run();

private:
    QString videoPath;        //解码视频路径
    AVFormatContext* pFormatContext;    //封装格式上下文结构体
    int videoIndex;           //视频流下标
    AVCodecContext* pCodecContext;      //编解码器上下文结构体
    AVCodec*decoder;          //解码器
    AVPacket*pkt;             //压缩的一帧码流数据
    AVFrame*frame, *RGBFrame, *YUVFrame; //frame 完整的像素数据 RGBFr
    SwsContext *pSwsContext, *pSwsContextYUV;  //转置格式结构体指针
    QImage img;
    uint8_t* bufferRGB, *bufferYUV;

    bool isPlay;
    bool isClose;

    EncodeToH264 *encoder;
    QString cameraName;

signals:
    void sendImg(QImage img);  // 发送图像信号
};

#endif // OPENCAMERA_H
