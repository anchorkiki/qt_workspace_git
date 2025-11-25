#ifndef SINGLETONDB_H
#define SINGLETONDB_H

#include <QDebug>
#include "sqlite3.h"
#include <QString>

class SingletonDB
{
public:
    static SingletonDB* getInstance();
    static void releaseInstance(); // 释放单例的方法一

    /**
     * @brief execSql 执行sql语句中的增删改
     * @param sql 参数是sql语句
     * @return 0：成功 else：error
     */
    int execSql(QString sql);

    /**
     * @brief selectSql 执行sql的查询语句
     * @param sql
     * @param qres 查询到的结果集
     * @param row 查询到的数据的行数（不包括表头）
     * @param col 查询到的数据的列数
     * @return 0：成功 else：error
     */
    int selectSql(QString sql, char**&qres, int &row, int &col);

private:
    SingletonDB();
    ~SingletonDB();

    static SingletonDB* instance;
    // GC 机制(释放单例的方法二，GC机制, 需要在.cpp 文件进行类外的初始化:SingletonDB::GC SingletonDB::GC::gc;)
        class GC
        {
            public:~GC()
            {
                // 可以在这里销毁所有的资源，例如：db 连接、文件句柄等
                if (instance != nullptr) {
                    qDebug() << "Here destroy the m_pSingleton...";
                    delete instance;
                    instance = nullptr;
                }
            }
            static GC gc; // 用于释放单例
        };

    sqlite3 *pdb; // 数据库操作指针
};

#endif // SINGLETONDB_H
