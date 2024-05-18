/****************************************************************************
** Meta object code from reading C++ file 'registersale.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "registersale.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registersale.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSregistersaleENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSregistersaleENDCLASS = QtMocHelpers::stringData(
    "registersale",
    "Send_Signal_DB",
    "",
    "value",
    "on_goback_clicked",
    "on_registerSale_clicked",
    "Update_Table",
    "on_scan_clicked",
    "on_timer_timeout"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSregistersaleENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[13];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[18];
    char stringdata5[24];
    char stringdata6[13];
    char stringdata7[16];
    char stringdata8[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSregistersaleENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSregistersaleENDCLASS_t qt_meta_stringdata_CLASSregistersaleENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "registersale"
        QT_MOC_LITERAL(13, 14),  // "Send_Signal_DB"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 5),  // "value"
        QT_MOC_LITERAL(35, 17),  // "on_goback_clicked"
        QT_MOC_LITERAL(53, 23),  // "on_registerSale_clicked"
        QT_MOC_LITERAL(77, 12),  // "Update_Table"
        QT_MOC_LITERAL(90, 15),  // "on_scan_clicked"
        QT_MOC_LITERAL(106, 16)   // "on_timer_timeout"
    },
    "registersale",
    "Send_Signal_DB",
    "",
    "value",
    "on_goback_clicked",
    "on_registerSale_clicked",
    "Update_Table",
    "on_scan_clicked",
    "on_timer_timeout"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSregistersaleENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   53,    2, 0x08,    3 /* Private */,
       5,    0,   54,    2, 0x08,    4 /* Private */,
       6,    0,   55,    2, 0x08,    5 /* Private */,
       7,    0,   56,    2, 0x08,    6 /* Private */,
       8,    0,   57,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject registersale::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSregistersaleENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSregistersaleENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSregistersaleENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<registersale, std::true_type>,
        // method 'Send_Signal_DB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_goback_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_registerSale_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Update_Table'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_scan_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_timer_timeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void registersale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<registersale *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Send_Signal_DB((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_goback_clicked(); break;
        case 2: _t->on_registerSale_clicked(); break;
        case 3: _t->Update_Table(); break;
        case 4: _t->on_scan_clicked(); break;
        case 5: _t->on_timer_timeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (registersale::*)(int );
            if (_t _q_method = &registersale::Send_Signal_DB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *registersale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *registersale::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSregistersaleENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int registersale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void registersale::Send_Signal_DB(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
