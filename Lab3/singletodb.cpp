#include "singletodb.h"

SingleToDB *SingleToDB::instance = nullptr;

SingleToDB *SingleToDB::getInstance()
{
    if(SingleToDB::instance == nullptr){
        SingleToDB::instance = new SingleToDB();
    }

    return SingleToDB::instance;
}

bool SingleToDB::initPatientModel()
{
    this->patienTabModel = new QSqlTableModel(this, this->db);
    this->patienTabModel->setTable("Patient");
    this->patienTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit); //数据保存方式，OnManualSubmit , OnRowChange
    this->patienTabModel->setSort(this->patienTabModel->fieldIndex("NAME"), Qt::AscendingOrder); //按第0列（"name"）的升序排列

    // 查询数据
    if(!(this->patienTabModel->select())){
        qDebug()<<"this->patienTabModel->select() error";
        return false;
    }

    this->patientSelection = new QItemSelectionModel(this->patienTabModel);
    return true;
}

SingleToDB::SingleToDB(QObject *parent)
    : QObject{parent}
{
    // 添加 SQLite 数据库驱动
    this->db = QSqlDatabase::addDatabase("QSQLITE");

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

bool SingleToDB::searchPatient(QString filter)
{
    this->patienTabModel->setFilter(filter);
    return this->patienTabModel->select();
}

// 修改后
bool SingleToDB::deleteCurrentPatient()
{
    QModelIndex curIndex = this->patientSelection->currentIndex();
    if (!curIndex.isValid()) { // 检查索引是否有效
        qDebug() << "未选中任何行，无法删除";
        return false;
    }
    this->patienTabModel->removeRow(curIndex.row());
    bool success = this->patienTabModel->submitAll(); // 使用submitAll()提交所有更改
    if (success) {
        this->patienTabModel->select(); // 刷新数据
    } else {
        qDebug() << "删除失败：" << this->patienTabModel->lastError().text();
    }
    return success;
}

bool SingleToDB::submitPatientEdit()
{
    return this->patienTabModel->submitAll();
}

void SingleToDB::revertPatientEdit()
{
    this->patienTabModel->revertAll();
}

int SingleToDB::addNewPatient()
{
    this->patienTabModel->insertRow(this->patienTabModel->rowCount(), QModelIndex()); // 在末尾添加一个记录
    QModelIndex curIndex = this->patienTabModel->index(this->patienTabModel->rowCount() - 1, 1);
    return curIndex.row();
}

int SingleToDB::getMaxPatientID()
{
    QSqlQuery query;
    // 查询最大的ID字符串
    if (!query.exec("SELECT MAX(ID) FROM Patient")) {
        qDebug() << "查询最大ID失败：" << query.lastError().text();
        return 0;
    }

    if (query.next()) {
        QString maxIdStr = query.value(0).toString();
        if (maxIdStr.isEmpty()) { // 表中无数据时，返回0
            return 0;
        }
        // 解析ID
        if (maxIdStr.startsWith("P")) {
            // 截取前缀P后的部分 P005
            QString numStr = maxIdStr.mid(1);
            bool ok;
            int maxNum = numStr.toInt(&ok); // 转为整数
            if (ok) {
                return maxNum; // 返回解析后的数字
            } else {
                qDebug() << "ID格式错误（数字部分无效）：" << maxIdStr;
                return 0;
            }
        } else {
            qDebug() << "ID格式错误（未以P开头）：" << maxIdStr;
            return 0;
        }
    }
    return 0;
}
