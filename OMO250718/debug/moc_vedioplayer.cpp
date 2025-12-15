/****************************************************************************
** Meta object code from reading C++ file 'vedioplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VIEW/vedioplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vedioplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VedioPlayer_t {
    QByteArrayData data[12];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VedioPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VedioPlayer_t qt_meta_stringdata_VedioPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VedioPlayer"
QT_MOC_LITERAL(1, 12, 14), // "showMainWidget"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "reciveImg"
QT_MOC_LITERAL(4, 38, 3), // "img"
QT_MOC_LITERAL(5, 42, 15), // "playBtn_clicked"
QT_MOC_LITERAL(6, 58, 17), // "chooseSpeedCombox"
QT_MOC_LITERAL(7, 76, 14), // "updateProgress"
QT_MOC_LITERAL(8, 91, 10), // "currentSec"
QT_MOC_LITERAL(9, 102, 16), // "setTotalDuration"
QT_MOC_LITERAL(10, 119, 8), // "totalSec"
QT_MOC_LITERAL(11, 128, 19) // "downloadBtn_clicked"

    },
    "VedioPlayer\0showMainWidget\0\0reciveImg\0"
    "img\0playBtn_clicked\0chooseSpeedCombox\0"
    "updateProgress\0currentSec\0setTotalDuration\0"
    "totalSec\0downloadBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VedioPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   50,    2, 0x0a /* Public */,
       5,    0,   53,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x0a /* Public */,
       9,    1,   58,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    8,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void,

       0        // eod
};

void VedioPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VedioPlayer *_t = static_cast<VedioPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showMainWidget(); break;
        case 1: _t->reciveImg((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->playBtn_clicked(); break;
        case 3: _t->chooseSpeedCombox(); break;
        case 4: _t->updateProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->setTotalDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->downloadBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (VedioPlayer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VedioPlayer::showMainWidget)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject VedioPlayer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VedioPlayer.data,
      qt_meta_data_VedioPlayer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VedioPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VedioPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VedioPlayer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VedioPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void VedioPlayer::showMainWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
