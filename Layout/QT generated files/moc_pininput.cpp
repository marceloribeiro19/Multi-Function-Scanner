/****************************************************************************
** Meta object code from reading C++ file 'pininput.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pininput.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pininput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSpininputENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSpininputENDCLASS = QtMocHelpers::stringData(
    "pininput",
    "Send_Signal_DB",
    "",
    "value",
    "NumPress",
    "Test",
    "verifyPin",
    "clearPin",
    "resetAttempts",
    "on_hidePassword_clicked",
    "on_enter_clicked",
    "on_goback_clicked",
    "on_confirm_clicked",
    "on_timer_timeout"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSpininputENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[9];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[9];
    char stringdata5[5];
    char stringdata6[10];
    char stringdata7[9];
    char stringdata8[14];
    char stringdata9[24];
    char stringdata10[17];
    char stringdata11[18];
    char stringdata12[19];
    char stringdata13[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSpininputENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSpininputENDCLASS_t qt_meta_stringdata_CLASSpininputENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "pininput"
        QT_MOC_LITERAL(9, 14),  // "Send_Signal_DB"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 5),  // "value"
        QT_MOC_LITERAL(31, 8),  // "NumPress"
        QT_MOC_LITERAL(40, 4),  // "Test"
        QT_MOC_LITERAL(45, 9),  // "verifyPin"
        QT_MOC_LITERAL(55, 8),  // "clearPin"
        QT_MOC_LITERAL(64, 13),  // "resetAttempts"
        QT_MOC_LITERAL(78, 23),  // "on_hidePassword_clicked"
        QT_MOC_LITERAL(102, 16),  // "on_enter_clicked"
        QT_MOC_LITERAL(119, 17),  // "on_goback_clicked"
        QT_MOC_LITERAL(137, 18),  // "on_confirm_clicked"
        QT_MOC_LITERAL(156, 16)   // "on_timer_timeout"
    },
    "pininput",
    "Send_Signal_DB",
    "",
    "value",
    "NumPress",
    "Test",
    "verifyPin",
    "clearPin",
    "resetAttempts",
    "on_hidePassword_clicked",
    "on_enter_clicked",
    "on_goback_clicked",
    "on_confirm_clicked",
    "on_timer_timeout"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSpininputENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   83,    2, 0x08,    3 /* Private */,
       5,    0,   84,    2, 0x08,    4 /* Private */,
       6,    0,   85,    2, 0x08,    5 /* Private */,
       7,    0,   86,    2, 0x08,    6 /* Private */,
       8,    0,   87,    2, 0x08,    7 /* Private */,
       9,    0,   88,    2, 0x08,    8 /* Private */,
      10,    0,   89,    2, 0x08,    9 /* Private */,
      11,    0,   90,    2, 0x08,   10 /* Private */,
      12,    0,   91,    2, 0x08,   11 /* Private */,
      13,    0,   92,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject pininput::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSpininputENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSpininputENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSpininputENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<pininput, std::true_type>,
        // method 'Send_Signal_DB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'NumPress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Test'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'verifyPin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearPin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetAttempts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_hidePassword_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_enter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_goback_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_confirm_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_timer_timeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void pininput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pininput *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Send_Signal_DB((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->NumPress(); break;
        case 2: _t->Test(); break;
        case 3: _t->verifyPin(); break;
        case 4: _t->clearPin(); break;
        case 5: _t->resetAttempts(); break;
        case 6: _t->on_hidePassword_clicked(); break;
        case 7: _t->on_enter_clicked(); break;
        case 8: _t->on_goback_clicked(); break;
        case 9: _t->on_confirm_clicked(); break;
        case 10: _t->on_timer_timeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (pininput::*)(int );
            if (_t _q_method = &pininput::Send_Signal_DB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *pininput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pininput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSpininputENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int pininput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void pininput::Send_Signal_DB(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
