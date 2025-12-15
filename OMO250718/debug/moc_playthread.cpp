/****************************************************************************
** Meta object code from reading C++ file 'playthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../THREAD/playthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayThread_t {
    QByteArrayData data[8];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayThread_t qt_meta_stringdata_PlayThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PlayThread"
QT_MOC_LITERAL(1, 11, 7), // "sendImg"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "img"
QT_MOC_LITERAL(4, 24, 17), // "sendTotalDuration"
QT_MOC_LITERAL(5, 42, 8), // "totalSec"
QT_MOC_LITERAL(6, 51, 19), // "sendCurrentProgress"
QT_MOC_LITERAL(7, 71, 10) // "currentSec"

    },
    "PlayThread\0sendImg\0\0img\0sendTotalDuration\0"
    "totalSec\0sendCurrentProgress\0currentSec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       6,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void, QMetaType::LongLong,    7,

       0        // eod
};

void PlayThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayThread *_t = static_cast<PlayThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->sendTotalDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->sendCurrentProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PlayThread::*_t)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayThread::sendImg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PlayThread::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayThread::sendTotalDuration)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PlayThread::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayThread::sendCurrentProgress)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject PlayThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_PlayThread.data,
      qt_meta_data_PlayThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlayThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PlayThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PlayThread::sendImg(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlayThread::sendTotalDuration(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlayThread::sendCurrentProgress(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
