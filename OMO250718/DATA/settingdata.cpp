#include "settingdata.h"

SettingData* SettingData::instance = nullptr;

SettingData* SettingData::getInstance(){
    if(SettingData::instance == nullptr){
        SettingData::instance = new SettingData();
    }
    else{
        qDebug()<<"SettingData::instance exists";
    }
    return SettingData::instance;
}

void SettingData::loadIniData()
{
    QSettings settings("../config.ini", QSettings::IniFormat);

    // 1. 串口配置
    setSerialPortName(settings.value("SerialPort/PortName").toString());

    // 2. 摄像头配置
    setCameraName(settings.value("Camera/Name", "Integrated Camera").toString());

    // 3. 视频存储配置
    setVideoStoragePath(settings.value("Video/StoragePath").toString());
    setVideoSegmentDuration(settings.value("Video/SegmentDuration", "1min").toString());

    // 4. 温度告警阈值
    setTempNormal(settings.value("Alarm/TempNormal", 30.0).toDouble());
    setTempSevere(settings.value("Alarm/TempSevere", 35.0).toDouble());

    // 5. 湿度告警阈值
    setHumidityNormal(settings.value("Alarm/HumidityNormal", 60.0).toDouble());
    setHumiditySevere(settings.value("Alarm/HumiditySevere", 80.0).toDouble());

    // 6. 光照告警阈值
    setLightNormal(settings.value("Alarm/LightNormal", 500).toInt());
    setLightSevere(settings.value("Alarm/LightSevere", 1000).toInt());

    qDebug() << "配置数据加载完成";
}

void SettingData::saveIniData()
{
    QSettings settings("../config.ini", QSettings::IniFormat);

    // 串口配置
    settings.setValue("SerialPort/PortName", serialPortName);

    // 摄像头配置
    settings.setValue("Camera/Name", cameraName);

    // 视频存储配置
    settings.setValue("Video/StoragePath", videoStoragePath);
    settings.setValue("Video/SegmentDuration", videoSegmentDuration);

    // 温度告警阈值
    settings.setValue("Alarm/TempNormal", tempNormal);
    settings.setValue("Alarm/TempSevere", tempSevere);

    // 湿度告警阈值
    settings.setValue("Alarm/HumidityNormal", humidityNormal);
    settings.setValue("Alarm/HumiditySevere", humiditySevere);

    // 光照告警阈值
    settings.setValue("Alarm/LightNormal", lightNormal);
    settings.setValue("Alarm/LightSevere", lightSevere);

    qDebug() << "配置数据保存完成";
}

SettingData::SettingData()
{

}

int SettingData::getLightSevere() const
{
    return lightSevere;
}

void SettingData::setLightSevere(int value)
{
    lightSevere = value;
}

int SettingData::getLightNormal() const
{
    return lightNormal;
}

void SettingData::setLightNormal(int value)
{
    lightNormal = value;
}

double SettingData::getHumiditySevere() const
{
    return humiditySevere;
}

void SettingData::setHumiditySevere(double value)
{
    humiditySevere = value;
}

double SettingData::getHumidityNormal() const
{
    return humidityNormal;
}

void SettingData::setHumidityNormal(double value)
{
    humidityNormal = value;
}

double SettingData::getTempSevere() const
{
    return tempSevere;
}

void SettingData::setTempSevere(double value)
{
    tempSevere = value;
}

double SettingData::getTempNormal() const
{
    return tempNormal;
}

void SettingData::setTempNormal(double value)
{
    tempNormal = value;
}

QString SettingData::getVideoSegmentDuration() const
{
    return videoSegmentDuration;
}

void SettingData::setVideoSegmentDuration(const QString &value)
{
    videoSegmentDuration = value;
}

QString SettingData::getVideoStoragePath() const
{
    return videoStoragePath;
}

void SettingData::setVideoStoragePath(const QString &value)
{
    videoStoragePath = value;
}

QString SettingData::getCameraName() const
{
    return cameraName;
}

void SettingData::setCameraName(const QString &value)
{
    cameraName = value;
}

QString SettingData::getSerialPortName() const
{
    return serialPortName;
}

void SettingData::setSerialPortName(const QString &value)
{
    serialPortName = value;
}
