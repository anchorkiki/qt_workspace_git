#ifndef EncodeToH264_H
#define EncodeToH264_H

#include <QString>
#include <QDebug>
#include <QImage>
#include <QDateTime>

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

class EncodeToH264
{
public:
    EncodeToH264();
    void prepareEncode(); // 编码准备
    void encodeFrame(AVFrame* yuvFrame); // 编码
    void writeTailer(); // 写尾帧

    int getWid() const;
    void setWid(int value);

    int getHig() const;
    void setHig(int value);

    QString getVideoPath() const;
    void setVideoPath(const QString &value);

private:
    QString videoPath;        //编码视频路径

    AVFormatContext* pFormatContext;    //封装格式上下文结构体
    AVOutputFormat* outFormat;
    AVStream* newStream;
    AVCodecContext* pCodecContext;      //编解码器上下文结构体
    AVCodec* encoder;          //解码器
    AVPacket* pkt;             //压缩的一帧码流数据
    int pkt_index;
    int wid, hig;
};

#endif // EncodeToH264_H
