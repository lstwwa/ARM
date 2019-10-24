/****************************************************************************
** Meta object code from reading C++ file 'gamewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gamewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Gamewidget_t {
    QByteArrayData data[17];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gamewidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gamewidget_t qt_meta_stringdata_Gamewidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Gamewidget"
QT_MOC_LITERAL(1, 11, 9), // "M_timeout"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "M_startPush1"
QT_MOC_LITERAL(4, 35, 12), // "M_startPush2"
QT_MOC_LITERAL(5, 48, 12), // "M_startPush3"
QT_MOC_LITERAL(6, 61, 12), // "M_startPush4"
QT_MOC_LITERAL(7, 74, 12), // "M_startPush5"
QT_MOC_LITERAL(8, 87, 13), // "M_setDiretion"
QT_MOC_LITERAL(9, 101, 5), // "index"
QT_MOC_LITERAL(10, 107, 10), // "M_exitPush"
QT_MOC_LITERAL(11, 118, 12), // "M_pausePush1"
QT_MOC_LITERAL(12, 131, 12), // "M_pausePush2"
QT_MOC_LITERAL(13, 144, 12), // "M_pausePush3"
QT_MOC_LITERAL(14, 157, 12), // "M_pausePush4"
QT_MOC_LITERAL(15, 170, 12), // "M_pausePush5"
QT_MOC_LITERAL(16, 183, 15) // "M_CheckGameOver"

    },
    "Gamewidget\0M_timeout\0\0M_startPush1\0"
    "M_startPush2\0M_startPush3\0M_startPush4\0"
    "M_startPush5\0M_setDiretion\0index\0"
    "M_exitPush\0M_pausePush1\0M_pausePush2\0"
    "M_pausePush3\0M_pausePush4\0M_pausePush5\0"
    "M_CheckGameOver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gamewidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    1,   90,    2, 0x0a /* Public */,
      10,    0,   93,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    0,   96,    2, 0x0a /* Public */,
      14,    0,   97,    2, 0x0a /* Public */,
      15,    0,   98,    2, 0x0a /* Public */,
      16,    0,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Gamewidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Gamewidget *_t = static_cast<Gamewidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->M_timeout(); break;
        case 1: _t->M_startPush1(); break;
        case 2: _t->M_startPush2(); break;
        case 3: _t->M_startPush3(); break;
        case 4: _t->M_startPush4(); break;
        case 5: _t->M_startPush5(); break;
        case 6: _t->M_setDiretion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->M_exitPush(); break;
        case 8: _t->M_pausePush1(); break;
        case 9: _t->M_pausePush2(); break;
        case 10: _t->M_pausePush3(); break;
        case 11: _t->M_pausePush4(); break;
        case 12: _t->M_pausePush5(); break;
        case 13: _t->M_CheckGameOver(); break;
        default: ;
        }
    }
}

const QMetaObject Gamewidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Gamewidget.data,
      qt_meta_data_Gamewidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Gamewidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gamewidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Gamewidget.stringdata0))
        return static_cast<void*>(const_cast< Gamewidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Gamewidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
