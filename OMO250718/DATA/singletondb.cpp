#include "singletondb.h"

// 数据类型 类名::静态成员 = val
SingletonDB* SingletonDB::instance = nullptr;
SingletonDB::GC SingletonDB::GC::gc; // GC的类外初始化

SingletonDB* SingletonDB::getInstance()
{
    if(SingletonDB::instance == nullptr){
        SingletonDB::instance = new SingletonDB();
//        qDebug()<<"SingletonDB instance creates";
    }
    else{
//        qDebug()<<"SingletonDB instance exists";
    }
    return SingletonDB::instance;
}

void SingletonDB::releaseInstance()
{
//    if(SingletonDB::instance != NULL){
//        delete  SingletonDB::instance;
//        SingletonDB::instance = nullptr;
//          qDebug()<<"releaseInstance()";
    //    }
}

int SingletonDB::execSql(QString sql)
{
    char *errmsg = nullptr;
    int res = sqlite3_exec(this->pdb, sql.toUtf8(), nullptr, nullptr, &errmsg);
    if(res != SQLITE_OK){
        qDebug()<<sqlite3_errcode(this->pdb);
        qDebug()<<sqlite3_errmsg(this->pdb);
    }
    return res;
}

int SingletonDB::selectSql(QString sql, char **&qres, int &row, int &col)
{
    char *errmsg = nullptr;
    int res = sqlite3_get_table(this->pdb, sql.toUtf8(), &qres, &row, &col, &errmsg);
    if(res != SQLITE_OK){
        qDebug()<<sqlite3_errcode(this->pdb);
        qDebug()<<sqlite3_errmsg(this->pdb);
    }
    return res;
}

SingletonDB::SingletonDB()
{
    // 打开数据库
    //1.打开数据库，不存在就新建
    int res = sqlite3_open("OMO250718.db", &pdb);
    if(res == SQLITE_OK)
    {
//        qDebug()<<"CREATE OR OPEN SUCCESS"<<pdb;
    }
    else {
        qDebug()<<sqlite3_errcode(pdb);
        qDebug()<<sqlite3_errmsg(pdb);
    }
}

SingletonDB::~SingletonDB()
{
    // 释放类内的指针成员
    // 关闭数据库
    sqlite3_close(pdb);
    qDebug()<<"qlite3 close";
}
