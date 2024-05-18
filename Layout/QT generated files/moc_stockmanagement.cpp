/****************************************************************************
** Meta object code from reading C++ file 'stockmanagement.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stockmanagement.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockmanagement.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSstockManagementENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSstockManagementENDCLASS = QtMocHelpers::stringData(
    "stockManagement",
    "Send_Signal_DB",
    "",
    "value",
    "on_removeProduct_clicked",
    "on_addProduct_clicked",
    "on_goback_clicked",
    "on_timer_timeout",
    "on_add_product",
    "on_remove_product",
    "onPinInputDialogClosed",
    "result",
    "hideEvent",
    "QHideEvent*",
    "event"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSstockManagementENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[16];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[25];
    char stringdata5[22];
    char stringdata6[18];
    char stringdata7[17];
    char stringdata8[15];
    char stringdata9[18];
    char stringdata10[23];
    char stringdata11[7];
    char stringdata12[10];
    char stringdata13[12];
    char stringdata14[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSstockManagementENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSstockManagementENDCLASS_t qt_meta_stringdata_CLASSstockManagementENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "stockManagement"
        QT_MOC_LITERAL(16, 14),  // "Send_Signal_DB"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 5),  // "value"
        QT_MOC_LITERAL(38, 24),  // "on_removeProduct_clicked"
        QT_MOC_LITERAL(63, 21),  // "on_addProduct_clicked"
        QT_MOC_LITERAL(85, 17),  // "on_goback_clicked"
        QT_MOC_LITERAL(103, 16),  // "on_timer_timeout"
        QT_MOC_LITERAL(120, 14),  // "on_add_product"
        QT_MOC_LITERAL(135, 17),  // "on_remove_product"
        QT_MOC_LITERAL(153, 22),  // "onPinInputDialogClosed"
        QT_MOC_LITERAL(176, 6),  // "result"
        QT_MOC_LITERAL(183, 9),  // "hideEvent"
        QT_MOC_LITERAL(193, 11),  // "QHideEvent*"
        QT_MOC_LITERAL(205, 5)   // "event"
    },
    "stockManagement",
    "Send_Signal_DB",
    "",
    "value",
    "on_removeProduct_clicked",
    "on_addProduct_clicked",
    "on_goback_clicked",
    "on_timer_timeout",
    "on_add_product",
    "on_remove_product",
    "onPinInputDialogClosed",
    "result",
    "hideEvent",
    "QHideEvent*",
    "event"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSstockManagementENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   71,    2, 0x08,    3 /* Private */,
       5,    0,   72,    2, 0x08,    4 /* Private */,
       6,    0,   73,    2, 0x08,    5 /* Private */,
       7,    0,   74,    2, 0x08,    6 /* Private */,
       8,    1,   75,    2, 0x08,    7 /* Private */,
       9,    1,   78,    2, 0x08,    9 /* Private */,
      10,    1,   81,    2, 0x08,   11 /* Private */,
      12,    1,   84,    2, 0x08,   13 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

Q_CONSTINIT const QMetaObject stockManagement::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSstockManagementENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSstockManagementENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSstockManagementENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<stockManagement, std::true_type>,
        // method 'Send_Signal_DB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_removeProduct_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addProduct_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_goback_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_timer_timeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_add_product'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_remove_product'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onPinInputDialogClosed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'hideEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHideEvent *, std::false_type>
    >,
    nullptr
} };

void stockManagement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<stockManagement *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Send_Signal_DB((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_removeProduct_clicked(); break;
        case 2: _t->on_addProduct_clicked(); break;
        case 3: _t->on_goback_clicked(); break;
        case 4: _t->on_timer_timeout(); break;
        case 5: _t->on_add_product((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_remove_product((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->onPinInputDialogClosed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->hideEvent((*reinterpret_cast< std::add_pointer_t<QHideEvent*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (stockManagement::*)(int );
            if (_t _q_method = &stockManagement::Send_Signal_DB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *stockManagement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *stockManagement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSstockManagementENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int stockManagement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void stockManagement::Send_Signal_DB(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
