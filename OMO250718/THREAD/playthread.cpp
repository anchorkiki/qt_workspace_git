#include "playthread.h"

PlayThread::PlayThread(QString videoPath)
{
    this->videoPath = videoPath;
    this->videoIndex = 1;
    this->isPlay = false;
    this->isClose = false;
    this->playSpeed = 1;
    // 注册组件
    av_register_all();

    if (openVideo() != 0) {
        qDebug() << "打开视频失败，终止初始化";
        return;
    }
    if (findVideoStream() != 0) {
        qDebug() << "查找视频流失败，终止初始化";
        avformat_close_input(&pFormatContext); // 释放已分配资源
        return;
    }
    if (openDecoder() != 0) {
        qDebug() << "打开解码器失败，终止初始化";
        avformat_close_input(&pFormatContext);
        return;
    }
    prepareData();
}

PlayThread::~PlayThread()
{
    qDebug()<<"~PlayThread 析构函数调用";

    // 确保线程已经停止
    if (this->isRunning()) {
        qDebug()<<"析构 线程还在运行";
        this->setIsClose(true);
        this->wait(1000); // 等待线程结束
    }

//    // 释放FFmpeg资源
//    if (pSwsContext) {
//        sws_freeContext(pSwsContext);
//        pSwsContext = nullptr;
//    }

//    if (bufferRGB) {
//        av_free(bufferRGB);
//        bufferRGB = nullptr;
//    }

//    if (RGBFrame) {
//        av_frame_free(&RGBFrame);
//    }

//    if (frame) {
//        av_frame_free(&frame);
//    }
//    qDebug()<<"析构 av_frame_free success";

//    if (pkt) {
//        av_packet_free(&pkt);
//    }
//    qDebug()<<"析构 av_packet_free success";

//    if (pCodecContext) {
//        avcodec_close(pCodecContext);
//        avcodec_free_context(&pCodecContext);
//    }
//    qDebug()<<"析构 avcodec_free_context success";

//    if (pFormatContext) {
//        avformat_close_input(&pFormatContext);
//        avformat_free_context(pFormatContext);
//    }

    qDebug() << "PlayThread 资源完全释放";
}

// 打开视频
int PlayThread::openVideo()
{

    this->pFormatContext = avformat_alloc_context();

    int res = avformat_open_input(&this->pFormatContext, this->videoPath.toUtf8(),
                                  nullptr, nullptr);
    if(res != 0){
        qDebug()<<"avformat_open_input error";
        return -1;
    }
    qDebug()<<"openVideo success";
    return 0;
}

// 查找流媒体数据，获取视频流下标
int PlayThread::findVideoStream()
{
    // 读取了 “封装头”，并填充到 pFormatContext->streams 数组中
    int res = avformat_find_stream_info(this->pFormatContext, nullptr);
    if(res < 0){
        qDebug()<<"avformat_find_stream_info error";
        return -1;
    }
    qDebug()<<"avformat_find_stream_info success";

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
    qDebug()<<"findVideoStream success";

    // 获取视频总时间
    if(pFormatContext->duration != AV_NOPTS_VALUE){
        this->totalDuration = pFormatContext->duration;
        qDebug()<<"视频总时长（秒）："<<totalDuration / 1000000.0;
    }

    return 0;
}

// 找到解码器,打开解码器
int PlayThread::openDecoder()
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
    qDebug()<<"avcodec_find_decoder success";

    // 打开解码器
    int res = avcodec_open2(this->pCodecContext, this->decoder, nullptr);
    if(res != 0){
        qDebug()<<"avcodec_open2 error";
        return -1;
    }
    qDebug()<<"avcodec_open2 success";
    return 0;
}

//void PlayThread::prepareData()
//{
//    this->pkt = (AVPacket*)malloc(sizeof (AVPacket));

//    this->frame = av_frame_alloc();
//    this->frame->width = this->pCodecContext->width;
//    this->frame->height = this->pCodecContext->height;
//    this->frame->format = this->pCodecContext->pix_fmt;

//    this->RGBFrame = av_frame_alloc();
//    this->RGBFrame->width = this->pCodecContext->width;
//    this->RGBFrame->height = this->pCodecContext->height;
//    this->RGBFrame->format = this->pCodecContext->pix_fmt;
//    // this->RGBFrame->format = AV_PIX_FMT_RGB32;

//    // 计算一帧RGB32
//    int numbyteRGB = avpicture_get_size(AV_PIX_FMT_RGB32,
//                                        this->pCodecContext->width, this->pCodecContext->height);

//    this->bufferRGB = (uint8_t*)av_malloc(numbyteRGB * sizeof (uint8_t));

//    // 添加 bufferRGB 检查
//    if (!this->bufferRGB) {
//        qDebug() << "bufferRGB 内存分配失败!";
//        return;
//    }
//    qDebug() << "bufferRGB 分配成功，大小:" << numbyteRGB;

//    avpicture_fill((AVPicture*)this->RGBFrame, this->bufferRGB, AV_PIX_FMT_RGB32,
//                   this->pCodecContext->width, this->pCodecContext->height);

//    this->pSwsContext = sws_getContext(this->pCodecContext->width, this->pCodecContext->height,
//                                       this->pCodecContext->pix_fmt,
//                                       this->pCodecContext->width, this->pCodecContext->height,
//                                       AV_PIX_FMT_RGB32, SWS_BICUBIC,
//                                       nullptr, nullptr, nullptr);
//    // 添加 SwsContext 检查
//    if (!this->pSwsContext) {
//        qDebug() << "sws_getContext 失败!";
//        return;
//    }
//    qDebug() << "SwsContext 创建成功";



//    qDebug()<<"PlayThread prepareData success";
//}


void PlayThread::prepareData()
{
    this->pkt = (AVPacket*)malloc(sizeof (AVPacket));

    this->frame = av_frame_alloc();
    this->frame->width = this->pCodecContext->width;
    this->frame->height = this->pCodecContext->height;
    this->frame->format = this->pCodecContext->pix_fmt;

    // 强制使用标准分辨率（16的倍数）
    int target_width = (this->pCodecContext->width + 15) & ~15;  // 对齐到16的倍数
    int target_height = (this->pCodecContext->height + 15) & ~15;

    qDebug() << "原始分辨率:" << this->pCodecContext->width << "x" << this->pCodecContext->height;
    qDebug() << "目标分辨率:" << target_width << "x" << target_height;

    this->RGBFrame = av_frame_alloc();
    this->RGBFrame->width = target_width;  // 使用调整后的宽度
    this->RGBFrame->height = target_height; // 使用调整后的高度
    this->RGBFrame->format = AV_PIX_FMT_RGB32;  // 明确设置为目标格式

    // 使用调整后的分辨率计算缓冲区大小
    int numbyteRGB = avpicture_get_size(AV_PIX_FMT_RGB32, target_width, target_height);

    this->bufferRGB = (uint8_t*)av_malloc(numbyteRGB * sizeof (uint8_t));

    // 添加 bufferRGB 检查
    if (!this->bufferRGB) {
        qDebug() << "bufferRGB 内存分配失败!";
        return;
    }
    qDebug() << "bufferRGB 分配成功，大小:" << numbyteRGB;

    avpicture_fill((AVPicture*)this->RGBFrame, this->bufferRGB, AV_PIX_FMT_RGB32,
                   target_width, target_height);  // 使用调整后的分辨率

    // 使用调整后的分辨率创建SwsContext
    this->pSwsContext = sws_getContext(this->pCodecContext->width, this->pCodecContext->height,
                                       this->pCodecContext->pix_fmt,
                                       target_width, target_height,  // 使用调整后的分辨率
                                       AV_PIX_FMT_RGB32, SWS_BILINEAR,  // 使用更简单的算法
                                       nullptr, nullptr, nullptr);

    // 添加 SwsContext 检查
    if (!this->pSwsContext) {
        qDebug() << "sws_getContext 失败!";
        return;
    }
    qDebug() << "SwsContext 创建成功";

    qDebug()<<"PlayThread prepareData success";
}


void PlayThread::decodeRGB32()
{
    qDebug()<<"进入 decodeRGB32()";
    QString img_path;
    int got_picture_ptr = -1;
    int count = 0;

    qint64 totalSec = this->totalDuration / 1000000; // 总时长（秒）
    emit sendTotalDuration(totalSec); // 发送总时长

    qDebug()<<"准备进入 decodeRGB32()的 while循环";
    //读取码流数据,不知道循环的次数
    while(1){
        if(this->isClose){
            qDebug()<<"isClose 为真";
            break;
        }

        if(!this->isPlay){
            qDebug()<<"暂停解码";
            msleep(100);
            continue;
        }

//        qDebug()<<"准备 av_read_frame";
        if(av_read_frame(this->pFormatContext, this->pkt) == 0)
        {
            //视频码流
            if(this->pkt->stream_index == this->videoIndex)
            {
//                qDebug()<<"准备解码 avcodec_decode_video2";
                //解码
                avcodec_decode_video2(this->pCodecContext, this->frame, &got_picture_ptr, this->pkt);
                if(got_picture_ptr != 0)  //解码成功
                {
//                    qDebug()<<"解码成功";
                    // ==============
                    // 计算当前播放时间（PTS转换为微秒）
                    if (pkt->pts != AV_NOPTS_VALUE) {
                        this->currentTime = av_rescale_q(pkt->pts,
                                                  pFormatContext->streams[videoIndex]->time_base,
                                                  {1, AV_TIME_BASE}); // 转换为微秒
                    }
                    else if (pkt->dts != AV_NOPTS_VALUE) {
                        this->currentTime = av_rescale_q(pkt->dts,
                                                  pFormatContext->streams[videoIndex]->time_base,
                                                  {1, AV_TIME_BASE});
                    }
//                    qDebug()<<"计算完播放时间";

                    // 发送当前进度（转换为秒）
                    qint64 currentSec = this->currentTime / 1000000;
                    emit sendCurrentProgress(currentSec);
//                    qDebug()<<"发送完播放当前进度";
                    // ===============

                    // 添加帧数据检查
//                    qDebug() << "帧数据检查 - 宽度:" << this->frame->width << "高度:" << this->frame->height;
//                    qDebug() << "帧数据检查 - 格式:" << this->frame->format;
//                    qDebug() << "帧数据检查 - data[0]:" << (void*)this->frame->data[0];
//                    qDebug() << "帧数据检查 - linesize[0]:" << this->frame->linesize[0];

//                    qDebug() << "RGBFrame linesize[0]:" << this->RGBFrame->linesize[0];
//                    qDebug() << "RGBFrame data[0]:" << (void*)this->RGBFrame->data[0];

                    //转置格式  frame 剔除掉无效数据 -->this->RGBFrame
                    int result = sws_scale(pSwsContext, this->frame->data, this->frame->linesize, 0, this->frame->height,
                              this->RGBFrame->data, this->RGBFrame->linesize);

//                    qDebug() << "sws_scale 返回值:" << result;

//                    if (result <= 0) {
//                        qDebug() << "sws_scale 失败!";
//                        break;
//                    }

//                    qDebug()<<"格式转置完成";
                    img = QImage((uchar*)bufferRGB, this->RGBFrame->width, this->RGBFrame->height, QImage::Format_RGB32);
//                    qDebug()<<"图片生成完成";
                    count++;
                    qDebug()<<"count: "<<count;
                    emit sendImg(this->img);
                }
//                qDebug()<<"处理完一帧";
                av_packet_unref(this->pkt);
            }
            msleep(this->transPlaySpeed());

        }
        else{
            break;
        }
    }

    avformat_close_input(&this->pFormatContext);
    qDebug()<<"视频播放线程已经跳出循环";
}

QString PlayThread::getVideoPath() const
{
    return videoPath;
}

void PlayThread::setVideoPath(const QString &value)
{
    videoPath = value;
}

bool PlayThread::getIsPlay() const
{
    return isPlay;
}

void PlayThread::setIsPlay(bool value)
{
    isPlay = value;
}

float PlayThread::getPlaySpeed() const
{
    return playSpeed;
}

void PlayThread::setPlaySpeed(double value)
{
    playSpeed = value;
}

int PlayThread::transPlaySpeed()
{
    if (this->playSpeed <= 0){
        return 40;  // 防止除以0
    }
    return qRound(40.0 / this->playSpeed);
}

bool PlayThread::getIsClose() const
{
    return isClose;
}

void PlayThread::setIsClose(bool value)
{
    isClose = value;
}

void PlayThread::run()
{
    this->decodeRGB32();
    qDebug()<<"视频播放线程退出";
}
