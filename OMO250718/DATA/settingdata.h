#ifndef SETTINGDATA_H
#define SETTINGDATA_H

#include <QString>
#include <QDebug>
#include <QSettings>

class SettingData
{
public:
    static SettingData* getInstance();

    // 加载ini数据
    void loadIniData();

    // 写入ini数据
    void saveIniData();

    QString getSerialPortName() const;
    void setSerialPortName(const QString &value);

    QString getCameraName() const;
    void setCameraName(const QString &value);

    QString getVideoStoragePath() const;
    void setVideoStoragePath(const QString &value);

    QString getVideoSegmentDuration() const;
    void setVideoSegmentDuration(const QString &value);

    double getTempNormal() const;
    void setTempNormal(double value);

    double getTempSevere() const;
    void setTempSevere(double value);

    double getHumidityNormal() const;
    void setHumidityNormal(double value);

    double getHumiditySevere() const;
    void setHumiditySevere(double value);

    int getLightNormal() const;
    void setLightNormal(int value);

    int getLightSevere() const;
    void setLightSevere(int value);

private:
    SettingData();
    static SettingData* instance;

    // 串口配置
    QString serialPortName;
    // 摄像头配置
    QString cameraName;
    // 视频存储
    QString videoStoragePath;
    QString videoSegmentDuration;
    // 告警阈值
    double tempNormal;
    double tempSevere;
    double humidityNormal;
    double humiditySevere;
    int lightNormal;
    int lightSevere;
};

#endif // SETTINGDATA_H
