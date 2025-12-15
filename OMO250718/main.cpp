#include "mainwindow.h"
#include "VIEW/settingwidget.h"
#include "VIEW/myview.h"
#include "VIEW/mainwidget.h"
#include <QApplication>
#include <QObject>
#include "sqlite3.h"

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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 验证ffmpeg环境配置是否成功
//    const char* version = av_version_info();
//    if(version){
//        qDebug() << "FFmpeg版本信息：" << version;
//    }
//    else{
//        qDebug() << "获取FFmpeg版本失败！";
//    }

    // 验证sqlite3环境配置是否成功
//    sqlite3 *db = nullptr;
//    int ret = sqlite3_open("OMO250718.db", &db);
//    if (ret == SQLITE_OK) {
//        qDebug()<<"成功！sqlite3 库可正常调用";
//        sqlite3_close(db);  // 关闭数据库
//    }
//    else{
//        qCritical()<<"失败！sqlite3 库调用异常：";
//        sqlite3_close(db);
//    }



    // 设置界面
//    SettingWidget w;
//    w.show();

//    MainWidget mainWidget;
//    mainWidget.show();

    // ini单例
    SettingData::getInstance()->loadIniData();

    // 开机动画
    MyView myView;
    myView.show();

    // 连接动画结束信号到lambda
    QObject::connect(&myView, &MyView::animationFinished, [&](){
        // 检查是否是第一次启动（通过判断配置文件是否存在）
        QFile configFile("../config.ini");
        bool isFirstStart = !configFile.exists();

        if (isFirstStart) {
            // 第一次启动，先显示设置界面
            SettingWidget *settingWidget = new SettingWidget();
            // 连接设置完成信号到创建主界面的槽函数
            QObject::connect(settingWidget, &SettingWidget::settingCompleted, [&](){
                MainWidget *mainWidget = new MainWidget();
                // 传递串口参数
//                mainWidget->onSettingCompleted(serialPortName, cameraName);
                mainWidget->show();
                settingWidget->deleteLater(); // 释放设置界面
            });
            settingWidget->show();
        }
        else{
            // 非第一次启动，直接显示主界面
            MainWidget *mainWidget = new MainWidget();
            qDebug()<<"80";
            mainWidget->show();
        }
    });

    return a.exec();
}
