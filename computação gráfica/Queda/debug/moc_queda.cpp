/****************************************************************************
** Meta object code from reading C++ file 'queda.h'
**
** Created: Mon Jul 6 22:39:41 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../queda.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'queda.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Queda[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      17,    6,    6,    6, 0x08,
      27,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Queda[] = {
    "Queda\0\0getInfs()\0setInfs()\0parar()\0"
};

const QMetaObject Queda::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Queda,
      qt_meta_data_Queda, 0 }
};

const QMetaObject *Queda::metaObject() const
{
    return &staticMetaObject;
}

void *Queda::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Queda))
        return static_cast<void*>(const_cast< Queda*>(this));
    return QWidget::qt_metacast(_clname);
}

int Queda::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: getInfs(); break;
        case 1: setInfs(); break;
        case 2: parar(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
