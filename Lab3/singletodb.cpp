#include "singletodb.h"

SingleToDB *SingleToDB::instance = nullptr;

SingleToDB *SingleToDB::getInstance()
{
    if(SingleToDB::instance == nullptr){
        SingleToDB::instance = new SingleToDB();
    }

    return SingleToDB::instance;
}

SingleToDB::SingleToDB(QObject *parent)
    : QObject{parent}
{
    // 添加 SQLite 数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    // 设置数据库文件路径（相对路径或绝对路径）
    // 若文件不存在，SQLite 会自动创建
    db.setDatabaseName("./Lab3.db");

    // 打开数据库
    if (!db.open()) {
        qDebug() << "数据库打开失败：" << db.lastError().text();
    } else {
        qDebug() << "数据库打开成功";
    }
}

SingleToDB::~SingleToDB()
{
    if(SingleToDB::instance != nullptr){
        QSqlDatabase::database().close(); // 关闭数据库连接
        qDebug()<<"析构 SingleToDB，数据库已关闭";
        delete SingleToDB::instance;
        SingleToDB::instance = nullptr;
    }
}

int SingleToDB::login(QString userName, QString userPwd)
{
    // 查询用户
    QSqlQuery query;
    query.prepare("SELECT PASSWORD FROM User WHERE USERNAME = ?");
    query.addBindValue(userName);

    if (!query.exec()) {
        qDebug()<<"userName = "<<userName<<"  userPwd = "<<userPwd;
        qDebug()<<QString("查询异常：%1").arg(query.lastError().text());
        return -1;
    }

    // 区分「用户不存在」「密码错误」「登录成功」
    if (!query.next()) {
        return -2; // 无匹配用户
    }
    else if (query.value(0).toString() != userPwd) {
        return -3; // 密码不匹配
    }
    else {
        return 0; // 登录成功
    }
}
