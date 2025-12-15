#include "trancecode.h"

TranceCode::TranceCode(QString srcPath, QString destPtah)
{
    this->srcPath = srcPath;
    this->destPtah = destPtah;
}

void TranceCode::initDecode()
{
    this->srcFormatContext = avformat_alloc_context();

    // 1.打开封装格式
    int res = avformat_open_input(&this->srcFormatContext, this->srcPath.toUtf8(), nullptr, nullptr);
    if(res != 0){
        qDebug()<<"解码 avformat_open_input error";
    }
    qDebug()<<"解码 avformat_open_input success";

    // 2.找到流
    res = avformat_find_stream_info(this->srcFormatContext, nullptr);
    if(res < 0){
        qDebug()<<"解码 avformat_find_stream_info error";
    }
    qDebug()<<"解码 avformat_find_stream_info success";

    // 3.遍历流找到视频流
    this->videoIndex = -1;
    for(int i = 0; i < this->srcFormatContext->nb_streams; i++){
        if(this->srcFormatContext->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO){
            this->videoIndex = i;
            break;
        }
    }

    if(this->videoIndex == -1){
        qDebug()<<"解码 find video stream error";
    }
    qDebug()<<"解码 find video stream success";
}



void TranceCode::initEncode()
{
    this->destFormatContext = avformat_alloc_context();
    // 1.猜猜封装格式
    AVOutputFormat *outFormat = av_guess_format(nullptr, this->destPtah.toUtf8(), nullptr);
    this->destFormatContext->oformat = outFormat;

    // 2.写入模式打开文件
    int res = avio_open(&this->destFormatContext->pb, this->destPtah.toUtf8(), AVIO_FLAG_WRITE);
    if(res < 0){
        qDebug()<<"编码 avio_open error";
        return;
    }
    qDebug()<<"编码 avio_open success";

    // 3.创建视频流
    this->newStream = avformat_new_stream(this->destFormatContext, nullptr);
    if(this->newStream == nullptr){
        qDebug()<<"编码 avformat_new_stream error";
        return;
    }
    qDebug()<<"编码 avformat_new_stream success";

    // 4.参数拷贝
    res = avcodec_parameters_copy(this->newStream->codecpar, this->srcFormatContext->streams[this->videoIndex]->codecpar);
    if(res < 0){
        qDebug()<<"编码 avcodec_parameters_copy error";
        return;
    }
    // 额外的参数设置
    this->newStream->codecpar->codec_type = AVMEDIA_TYPE_VIDEO;
    this->newStream->codecpar->codec_tag = 0;
    qDebug()<<"编码 avcodec_parameters_copy success";

    // 5.写入头部信息
    res = avformat_write_header(this->destFormatContext, nullptr);
    if(res < 0){
        qDebug()<<"编码 avformat_write_header error";
        return;
    }
    qDebug()<<"编码 avformat_write_header success";
}

void TranceCode::tranceCode()
{
    int frameCount = 0;
    this->pkt = (AVPacket*)malloc(sizeof(AVPacket));
    int res = 0;
    // 转码，有源数据读取AVPacket，设置pts dts
    while (av_read_frame(this->srcFormatContext, this->pkt) == 0){
        if(this->pkt->stream_index == this->videoIndex){
            frameCount++;
            // 显示时间基 解码时间
            // 显示时间基公式：当前是第几帧*2帧之间的长度 / 输入时间基 * AV_TIME_BASE
            // 1.在没有时间基的情况下进行计算
            if(this->pkt->pts == AV_NOPTS_VALUE){
                AVRational time_base1 = this->srcFormatContext->streams[this->videoIndex]->time_base;
                // 2 帧之间长度
                int64_t duration = (double)AV_TIME_BASE /
                        av_q2d(this->srcFormatContext->streams[this->videoIndex]->r_frame_rate);

                this->pkt->pts = (double)frameCount * duration /
                        double(av_q2d(time_base1) * AV_TIME_BASE);

                // 无B帧
                this->pkt->dts = this->pkt->pts;
                this->pkt->duration = duration / double(av_q2d(time_base1) * AV_TIME_BASE);
            }
            else if(this->pkt->pts < this->pkt->dts){
                continue;
            }

            // 计算公式
            // 解码时间基转换：参数1：要换算的值（待转换时间）     参数2：原来的时间基（待转换时间依赖的时间基）
            //              参数3：现在的时间基（目标时间基）    参数4：换算规则
            this->pkt->pts = av_rescale_q_rnd(this->pkt->pts, this->srcFormatContext->streams[this->videoIndex]->time_base,
                    this->newStream->time_base, (AVRounding)(AV_ROUND_INF | AV_ROUND_PASS_MINMAX));
            this->pkt->dts = av_rescale_q_rnd(this->pkt->dts, this->srcFormatContext->streams[this->videoIndex]->time_base,
                    this->newStream->time_base, (AVRounding)(AV_ROUND_INF | AV_ROUND_PASS_MINMAX));
            this->pkt->duration = av_rescale_q(this->pkt->duration, this->srcFormatContext->streams[this->videoIndex]->time_base,
                    this->newStream->time_base);
            this->pkt->stream_index = 0;
            this->pkt->pos = -1;
            this->pkt->flags |= AV_PKT_FLAG_KEY;

            // 写入文件
            res = av_interleaved_write_frame(this->destFormatContext, this->pkt);
            if(res != 0){
                qDebug()<<"转码 av_interleaved_write_frame error";
            }
            qDebug()<<"转码 av_interleaved_write_frame success"<<frameCount;
        }
        av_packet_unref(this->pkt);
    }

    qDebug()<<"准备写尾帧 和 释放流";
    // 写尾帧
    av_write_trailer(this->destFormatContext);
    // 释放输出流
    avio_close(this->srcFormatContext->pb);
    av_free(this->destFormatContext->pb);
    // 释放视频流
    avformat_close_input(&this->srcFormatContext);
    av_free(this->srcFormatContext);
    qDebug()<<"trance code end "<<frameCount;
}
