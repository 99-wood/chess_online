/****************************************************************************
** Meta object code from reading C++ file 'zi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../chess-online/zi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Zi_t {
    QByteArrayData data[13];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Zi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Zi_t qt_meta_stringdata_Zi = {
    {
QT_MOC_LITERAL(0, 0, 2), // "Zi"
QT_MOC_LITERAL(1, 3, 8), // "Selected"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 3), // "Zi*"
QT_MOC_LITERAL(4, 17, 2), // "id"
QT_MOC_LITERAL(5, 20, 10), // "UnSelected"
QT_MOC_LITERAL(6, 31, 3), // "Die"
QT_MOC_LITERAL(7, 35, 4), // "Move"
QT_MOC_LITERAL(8, 40, 1), // "x"
QT_MOC_LITERAL(9, 42, 1), // "y"
QT_MOC_LITERAL(10, 44, 6), // "BeDead"
QT_MOC_LITERAL(11, 51, 7), // "BeAlive"
QT_MOC_LITERAL(12, 59, 14) // "CancelSelected"

    },
    "Zi\0Selected\0\0Zi*\0id\0UnSelected\0Die\0"
    "Move\0x\0y\0BeDead\0BeAlive\0CancelSelected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Zi[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   58,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,
      11,    0,   64,    2, 0x0a /* Public */,
      12,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Zi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Zi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Selected((*reinterpret_cast< Zi*(*)>(_a[1]))); break;
        case 1: _t->UnSelected((*reinterpret_cast< Zi*(*)>(_a[1]))); break;
        case 2: _t->Die((*reinterpret_cast< Zi*(*)>(_a[1]))); break;
        case 3: _t->Move((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 4: _t->BeDead(); break;
        case 5: _t->BeAlive(); break;
        case 6: _t->CancelSelected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Zi* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Zi* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Zi* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Zi::*)(Zi * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Zi::Selected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Zi::*)(Zi * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Zi::UnSelected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Zi::*)(Zi * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Zi::Die)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Zi::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Zi.data,
    qt_meta_data_Zi,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Zi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Zi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Zi.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Zi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Zi::Selected(Zi * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Zi::UnSelected(Zi * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Zi::Die(Zi * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
