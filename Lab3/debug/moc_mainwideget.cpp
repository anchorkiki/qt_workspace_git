/****************************************************************************
** Meta object code from reading C++ file 'mainwideget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwideget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwideget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11MainWidegetE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWideget::qt_create_metaobjectdata<qt_meta_tag_ZN11MainWidegetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWideget",
        "onSwitchToLogin",
        "",
        "onSwitchToChoose",
        "onSwitchToSub",
        "onSwitchToDoc",
        "onSwitchToPatient",
        "onSwitchToAddSub",
        "onSwitchToModifySub",
        "onSwitchToDelSub",
        "onSwitchToAddDoctor",
        "onSwitchToModifyDoc",
        "onSwitchToDelDoc",
        "onSwitchToAddPatient",
        "onSwitchToModifyPatient",
        "onSwitchToDelPatient"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'onSwitchToLogin'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToChoose'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToSub'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToDoc'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToPatient'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToAddSub'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToModifySub'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToDelSub'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToAddDoctor'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToModifyDoc'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToDelDoc'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToAddPatient'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToModifyPatient'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSwitchToDelPatient'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWideget, qt_meta_tag_ZN11MainWidegetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWideget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11MainWidegetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11MainWidegetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11MainWidegetE_t>.metaTypes,
    nullptr
} };

void MainWideget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWideget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onSwitchToLogin(); break;
        case 1: _t->onSwitchToChoose(); break;
        case 2: _t->onSwitchToSub(); break;
        case 3: _t->onSwitchToDoc(); break;
        case 4: _t->onSwitchToPatient(); break;
        case 5: _t->onSwitchToAddSub(); break;
        case 6: _t->onSwitchToModifySub(); break;
        case 7: _t->onSwitchToDelSub(); break;
        case 8: _t->onSwitchToAddDoctor(); break;
        case 9: _t->onSwitchToModifyDoc(); break;
        case 10: _t->onSwitchToDelDoc(); break;
        case 11: _t->onSwitchToAddPatient(); break;
        case 12: _t->onSwitchToModifyPatient(); break;
        case 13: _t->onSwitchToDelPatient(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWideget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWideget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11MainWidegetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainWideget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
