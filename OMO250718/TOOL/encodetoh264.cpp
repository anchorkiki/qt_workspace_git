#include "encodeToH264.h"

EncodeToH264::EncodeToH264()
{
    av_register_all();

    this->pkt = av_packet_alloc();

    // 不能写在preparaEncoded()
    this->pkt_index = 0;

}

void EncodeToH264::prepareEncode()
{
    // 存储文件路径（时间）
    this->videoPath = QString("../fileOut/%1.h264").arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));

    // 封装格式上下文结构体开辟空间
    this->pFormatContext = avformat_alloc_context();

    // 猜测合适的封装格式
    this->outFormat = av_guess_format(nullptr, this->videoPath.toUtf8(), nullptr);
    if(this->outFormat == nullptr){
        qDebug()<<"av_guess_format error";
        return;
    }
    qDebug()<<"编码器 av_guess_format success 27";

    //
    this->pFormatContext->oformat = this->outFormat;

    //
    int res = avio_open(&this->pFormatContext->pb, this->videoPath.toUtf8(), AVIO_FLAG_WRITE);
    if(res < 0){
        qDebug()<<"avio_open error";
        return;
    }
    qDebug()<<"编码器 avio_open success 38";

    //
    this->newStream = avformat_new_stream(this->pFormatContext, nullptr);
    if(this->newStream == nullptr){
        qDebug()<<"avformat_new_stream error";
        return;
    }
    qDebug()<<"编码器 avformat_new_stream success 46";

    //
    pCodecContext = newStream->codec;
    pCodecContext->width = this->wid;     //这个宽是解码器获取的宽--变量
    pCodecContext->height = this->hig;
    pCodecContext->time_base = {1,25};  //帧率1s播放25帧
    pCodecContext->bit_rate = 400000;   //码率
    pCodecContext->framerate = {25,1};  //帧率
    pCodecContext->gop_size = 10;       //1组10帧    
    qDebug()<<"编码器 基本参数设置完成 55";

    //-----------影响清晰度-------------
    pCodecContext->qmax = 51;                //
    pCodecContext->qmin = 10;
    pCodecContext->max_b_frames = 0;         //没有B帧  I红  P蓝 B绿
    pCodecContext->pix_fmt = AV_PIX_FMT_YUV420P; //编码器格式
    pCodecContext->codec_type = AVMEDIA_TYPE_VIDEO;  //设置为视频流
    pCodecContext->codec_id = outFormat->video_codec;//编码器id
    qDebug()<<"编码器 高级参数设置完成 64";

    //
    this->encoder = avcodec_find_encoder(this->pCodecContext->codec_id);
    if(encoder == nullptr){
        qDebug()<<"avcodec_find_encoder error";
        return;
    }
    qDebug()<<"编码器 avcodec_find_encoder success 69";

    //
    res = avcodec_open2(this->pCodecContext, this->encoder, nullptr);
    if(res != 0){
        qDebug()<<"avcodec_open2 error";
        return;
    }
    qDebug()<<"编码器 avcodec_open2 success 77";

    res = avformat_write_header(this->pFormatContext, nullptr);
    if(res < 0){
        qDebug()<<"avformat_write_header error";
        return;
    }
    qDebug()<<"编码器 avformat_write_header success 84";
}

void EncodeToH264::encodeFrame(AVFrame* yuvFrame)
{
    int res = avcodec_send_frame(this->pCodecContext, yuvFrame);
    if(res != 0){

    }
    qDebug()<<"";

    while(res >= 0){
        this->pkt->pts = this->pkt_index++;
        res = avcodec_receive_packet(this->pCodecContext, this->pkt);
        if(res == AVERROR(EAGAIN) || res == AVERROR_EOF){
            break;
        }

        res = av_interleaved_write_frame(this->pFormatContext, this->pkt);
        if(res != 0){
            qDebug()<<"编码器 av_interleaved_write_frame error"<<this->pkt_index;
        }
        qDebug()<<"编码器 av_interleaved_write_frame success"<<this->pkt_index;
    }
}

void EncodeToH264::writeTailer()
{
    av_write_trailer(this->pFormatContext);
    avio_close(this->pFormatContext->pb);
    avformat_free_context(this->pFormatContext);
}

int EncodeToH264::getWid() const
{
    return wid;
}

void EncodeToH264::setWid(int value)
{
    wid = value;
}

int EncodeToH264::getHig() const
{
    return hig;
}

void EncodeToH264::setHig(int value)
{
    hig = value;
}

QString EncodeToH264::getVideoPath() const
{
    return videoPath;
}

void EncodeToH264::setVideoPath(const QString &value)
{
    videoPath = value;
}
