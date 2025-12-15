#ifndef TRANCECODE_H
#define TRANCECODE_H

#include <QThread>
#include <QString>
#include <QDebug>
#include <QImage>
#include <QObject>
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

class TranceCode : public QObject
{
    Q_OBJECT;
public:
    TranceCode(QString srcPath, QString destPtah);

    void initDecode();
    void initEncode();
    void tranceCode();

private:
    QString srcPath;
    QString destPtah;
    AVFormatContext *srcFormatContext, *destFormatContext;
    AVPacket *pkt;
    int videoIndex;
    AVStream *newStream;
};

#endif // TRANCECODE_H
