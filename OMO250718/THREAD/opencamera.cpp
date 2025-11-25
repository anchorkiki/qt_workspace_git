#include "opencamera.h"

OpenCamera::OpenCamera(QString cameraName)
{
    this->videoPath = videoPath;
    this->videoIndex = 1;
    this->isPlay = false;  // 初始化为播放状态
    this->isClose = false;
    this->cameraName = cameraName;
    this->encoder = new EncodeToH264();

    // 注册组件
    av_register_all();
    // 注册外部设备（摄像头）
    avdevice_register_all();

    this->openVideo();
    this->findVideoStream();
    this->openDecoder();
    this->prepareData();
}

OpenCamera::~OpenCamera() {
    qDebug()<<"OpenCamera 析构函数被调用";

//    // 释放FFmpeg资源
//    if (pFormatContext) {
//        avformat_close_input(&pFormatContext);
//        avformat_free_context(pFormatContext);
//    }
//    if (pCodecContext) {
//        avcodec_close(pCodecContext);
//        avcodec_free_context(&pCodecContext);
//    }
//    if (pkt) {
//        av_packet_free(&pkt);
//    }
//    if (frame) av_frame_free(&frame);
//    if (RGBFrame) av_frame_free(&RGBFrame);
//    if (YUVFrame) av_frame_free(&YUVFrame);
//    if (bufferRGB) av_free(bufferRGB);
//    if (bufferYUV) av_free(bufferYUV);
//    if (pSwsContext) sws_freeContext(pSwsContext);
//    if (pSwsContextYUV) sws_freeContext(pSwsContextYUV);
//    // 释放编码器
//    if (encoder) delete encoder;
    qDebug()<<"OpenCamera 析构函数结束";
}

// 打开视频
int OpenCamera::openVideo()
{

    this->pFormatContext = avformat_alloc_context();

    /*
         * windows上打开摄像头
         * dshow：推流方式
     */
    AVInputFormat *fmt=av_find_input_format("dshow");
    QString camera = QString("video=%1").arg(this->cameraName);
    int res=avformat_open_input(&this->pFormatContext,camera.toUtf8(),fmt,nullptr);

    if(res != 0){
        qDebug()<<"avformat_open_input error"<<this->cameraName;
        return -1;
    }
    qDebug()<<"直播解码器 openVideo success 40";
    return 0;
}

// 查找流媒体数据，获取视频流下标
int OpenCamera::findVideoStream()
{
    // 读取了 “封装头”，并填充到 pFormatContext->streams 数组中
    int res = avformat_find_stream_info(this->pFormatContext, nullptr);
    if(res < 0){
        qDebug()<<"avformat_find_stream_info error";
        return -1;
    }
    qDebug()<<"直播解码器 findVideoStream success 53";

    // 获取视频流下标
    this->videoIndex = -1;
    for(int i = 0; i < this->pFormatContext->nb_streams; i++){
        if(this->pFormatContext->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO){
            videoIndex = i;
            break;
        }
    }
    if(this->videoIndex == -1){
        qDebug()<<"findVideoStream error";
        return -1;
    }
    qDebug()<<"直播解码器 findVideoStream success 67";
    return 0;
}

// 找到解码器,打开解码器
int OpenCamera::openDecoder()
{
    // 找到解码器
    // 获取编解码器上下文结构体
    this->pCodecContext = this->pFormatContext->streams[this->videoIndex]->codec;
    // 根据编解码器ID（codec_id）找到对应的解码器
    this->decoder = avcodec_find_decoder(this->pCodecContext->codec_id);
    if(this->decoder == nullptr){
        qDebug()<<"avcodec_find_decoder error";
        return -1;
    }
    qDebug()<<"直播解码器 avcodec_find_decoder success 83";

    // 打开解码器
    int res = avcodec_open2(this->pCodecContext, this->decoder, nullptr);
    if(res != 0){
        qDebug()<<"avcodec_open2 error";
        return -1;
    }
    qDebug()<<"直播解码器 avcodec_open2 success 91";
    return 0;
}

void OpenCamera::prepareData()
{
    this->pkt = (AVPacket*)malloc(sizeof (AVPacket));

    this->frame = av_frame_alloc();
    this->frame->width = this->pCodecContext->width;
    this->frame->height = this->pCodecContext->height;
    this->frame->format = this->pCodecContext->pix_fmt;

    this->RGBFrame = av_frame_alloc();
    this->RGBFrame->width = this->pCodecContext->width;
    this->RGBFrame->height = this->pCodecContext->height;
    this->RGBFrame->format = this->pCodecContext->pix_fmt;

    // 计算一帧RGB32
    int numbyteRGB = avpicture_get_size(AV_PIX_FMT_RGB32,
                                        this->pCodecContext->width, this->pCodecContext->height);

    this->bufferRGB = (uint8_t*)av_malloc(numbyteRGB * sizeof (uint8_t));

    avpicture_fill((AVPicture*)this->RGBFrame, this->bufferRGB, AV_PIX_FMT_RGB32,
                   this->pCodecContext->width, this->pCodecContext->height);

    this->pSwsContext = sws_getContext(this->pCodecContext->width, this->pCodecContext->height,
                                       this->pCodecContext->pix_fmt,
                                       this->pCodecContext->width, this->pCodecContext->height,
                                       AV_PIX_FMT_RGB32, SWS_BICUBIC,
                                       nullptr, nullptr, nullptr);

    this->YUVFrame = av_frame_alloc();
    this->YUVFrame->width = this->pCodecContext->width;
    this->YUVFrame->height = this->pCodecContext->height;
//    this->YUVFrame->format = this->pCodecContext->pix_fmt;
    this->YUVFrame->format = AV_PIX_FMT_YUV420P;

    // 计算一帧YUV
    int numbyteYUV = avpicture_get_size(AV_PIX_FMT_YUV420P,
                                        this->pCodecContext->width, this->pCodecContext->height);

    this->bufferYUV = (uint8_t*)av_malloc(numbyteYUV * sizeof (uint8_t));

    avpicture_fill((AVPicture*)this->YUVFrame, this->bufferYUV, AV_PIX_FMT_YUV420P,
                   this->pCodecContext->width, this->pCodecContext->height);

    this->pSwsContextYUV = sws_getContext(this->pCodecContext->width, this->pCodecContext->height,
                                       this->pCodecContext->pix_fmt,
                                       this->pCodecContext->width, this->pCodecContext->height,
                                       AV_PIX_FMT_YUV420P, SWS_BICUBIC,
                                       nullptr, nullptr, nullptr);

    qDebug()<<"直播解码器 prepareData success 145";
}

void OpenCamera::decodeRGB32()
{
    int got_picture_ptr = -1;
    int count = 0;

    // 设置encode
    this->encoder->setHig(this->pCodecContext->height);
    this->encoder->setWid(this->pCodecContext->width);
    this->encoder->prepareEncode();

    //读取码流数据,不知道循环的次数
    while(1){

        qDebug()<<"直播线程执行中";

        if(this->isClose){
            qDebug()<<"isClose 为真, 跳出循环";
            break;
        }

        if(!this->isPlay){
            qDebug()<<"暂停解码";
            msleep(100);
            continue;
        }

        if(av_read_frame(this->pFormatContext, this->pkt) == 0)
        {
            //视频码流
            if(this->pkt->stream_index == this->videoIndex)
            {
                //解码
                avcodec_decode_video2(this->pCodecContext, this->frame, &got_picture_ptr, this->pkt);
                if(got_picture_ptr != 0)  //解码成功
                {

                    //转置格式  frame 剔除掉无效数据 -->this->RGBFrame
                    sws_scale(pSwsContext, this->frame->data, this->frame->linesize, 0, this->frame->height,
                              this->RGBFrame->data, this->RGBFrame->linesize);

                    // 转存为YUV420P
                    sws_scale(pSwsContextYUV, this->frame->data, this->frame->linesize, 0, this->frame->height,
                              this->YUVFrame->data, this->YUVFrame->linesize);

//                    this->encoder->encodeFrame(this->YUVFrame);
                    img = QImage((uchar*)bufferRGB, this->RGBFrame->width, this->RGBFrame->height, QImage::Format_RGB32);
                    count++;
                    qDebug()<<"count: "<<count;
                    emit sendImg(this->img);
                    qDebug()<<"直播线程发送 QImage";

//                    if(count >= 200){
//                        this->encoder->writeTailer();
//                        this->encoder->prepareEncode();
//                        count = 0;
//                    }
                }
                av_packet_unref(this->pkt);
            }
        }
        else{
            qDebug()<<"读取帧失败，等待后重试";
            msleep(100);
        }
    }

    avformat_close_input(&this->pFormatContext);
    qDebug()<<"decodeToRGB32 最后一行代码";
}


QString OpenCamera::getVideoPath() const
{
    return videoPath;
}

void OpenCamera::setVideoPath(const QString &value)
{
    videoPath = value;
}

bool OpenCamera::getIsPlay() const
{
    return isPlay;
}

void OpenCamera::setIsPlay(bool value)
{
    isPlay = value;
}

void OpenCamera::run()
{
    this->decodeRGB32();
    qDebug()<<"跳出decodeRGB32函数";
    qDebug()<<"直播线程退出";
}

QString OpenCamera::getCameraName() const
{
    return cameraName;
}

void OpenCamera::setCameraName(const QString &value)
{
    cameraName = value;
}

bool OpenCamera::getIsClose() const
{
    return isClose;
}

void OpenCamera::setIsClose(bool value)
{
    isClose = value;
}

