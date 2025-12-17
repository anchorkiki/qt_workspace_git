#ifndef SINGLETODB_H
#define SINGLETODB_H

#include <QObject>
#include <QSqlDatabase>   // 数据库连接
#include <QSqlQuery>      // 执行 SQL 语句
#include <QSqlError>      // 错误处理
#include <QDebug>         // 输出调试信息
#include <QString>
#include <QSqlTableModel>
#include <qitemselectionmodel.h>
#include <QModelIndex>

class SingleToDB : public QObject
{
    Q_OBJECT
public:
    static SingleToDB* getInstance();

    // 初始化数据库模型
    bool initPatientModel();

    // 登录
    int login(QString userName, QString userPwd);

    // 注册
    void userRegister(QString fullName, QString userName, QString userPwd);

    // 查询
    bool searchPatient(QString filter);

    // 删除
    bool deleteCurrentPatient();

    // 提交修改
    bool submitPatientEdit();

    // 取消操作
    void revertPatientEdit();

    // 增加患者
    int addNewPatient();

    // 获取UID
    int getMaxPatientID();

public:
    // 数据模型
    QSqlTableModel *patienTabModel;
    // 选择模型
    QItemSelectionModel *patientSelection;

private:
    explicit SingleToDB(QObject *parent = nullptr);
    ~SingleToDB();
    static SingleToDB *instance;

    QSqlDatabase db; // 数据库连接


signals:
    // 传递登录结果文本
    void loginMsg(const QString& msg);
};

#endif // SINGLETODB_H
