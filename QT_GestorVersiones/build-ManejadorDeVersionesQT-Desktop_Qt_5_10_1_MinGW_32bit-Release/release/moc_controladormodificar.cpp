/****************************************************************************
** Meta object code from reading C++ file 'controladormodificar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ManejadorDeVersionesQT/controladormodificar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controladormodificar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ControladorModificar_t {
    QByteArrayData data[9];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControladorModificar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControladorModificar_t qt_meta_stringdata_ControladorModificar = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ControladorModificar"
QT_MOC_LITERAL(1, 21, 22), // "on_BotonCerrar_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 25), // "on_botonHistorial_clicked"
QT_MOC_LITERAL(4, 71, 7), // "checked"
QT_MOC_LITERAL(5, 79, 26), // "on_botonVisualizar_clicked"
QT_MOC_LITERAL(6, 106, 26), // "on_botonDiferencia_clicked"
QT_MOC_LITERAL(7, 133, 23), // "on_botonGuardar_clicked"
QT_MOC_LITERAL(8, 157, 25) // "on_botonModificar_clicked"

    },
    "ControladorModificar\0on_BotonCerrar_clicked\0"
    "\0on_botonHistorial_clicked\0checked\0"
    "on_botonVisualizar_clicked\0"
    "on_botonDiferencia_clicked\0"
    "on_botonGuardar_clicked\0"
    "on_botonModificar_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControladorModificar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       3,    1,   66,    2, 0x08 /* Private */,
       5,    0,   69,    2, 0x08 /* Private */,
       5,    1,   70,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       6,    1,   74,    2, 0x08 /* Private */,
       7,    0,   77,    2, 0x08 /* Private */,
       8,    0,   78,    2, 0x08 /* Private */,
       7,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

       0        // eod
};

void ControladorModificar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControladorModificar *_t = static_cast<ControladorModificar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_BotonCerrar_clicked(); break;
        case 1: _t->on_botonHistorial_clicked(); break;
        case 2: _t->on_botonHistorial_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_botonVisualizar_clicked(); break;
        case 4: _t->on_botonVisualizar_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_botonDiferencia_clicked(); break;
        case 6: _t->on_botonDiferencia_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_botonGuardar_clicked(); break;
        case 8: _t->on_botonModificar_clicked(); break;
        case 9: _t->on_botonGuardar_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ControladorModificar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ControladorModificar.data,
      qt_meta_data_ControladorModificar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ControladorModificar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControladorModificar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ControladorModificar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ControladorModificar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
