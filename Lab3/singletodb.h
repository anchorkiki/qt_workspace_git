#ifndef SINGLETODB_H
#define SINGLETODB_H

#include <QObject>
#include <QSqlDatabase>   // 数据库连接
#include <QSqlQuery>      // 执行 SQL 语句
#include <QSqlError>      // 错误处理
#include <QDebug>         // 输出调试信息
#include <QString>

class SingleToDB : public QObject
{
    Q_OBJECT
public:
    static SingleToDB* getInstance();

    // 登录
    int login(QString userName, QString userPwd);

    // 注册
    void userRegister(QString fullName, QString userName, QString userPwd);

private:
    explicit SingleToDB(QObject *parent = nullptr);
    ~SingleToDB();
    static SingleToDB *instance;

signals:
    // 传递登录结果文本
    void loginMsg(const QString& msg);
};

#endif // SINGLETODB_H
