/****************************************************************************
** Meta object code from reading C++ file 'newresultatwindow.h'
**
** Created: Sun 10. Jun 23:18:07 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../newresultatwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newresultatwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewResultatWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      35,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewResultatWindow[] = {
    "NewResultatWindow\0\0clic_accepted()\0"
    "clic_rejected()\0"
};

void NewResultatWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewResultatWindow *_t = static_cast<NewResultatWindow *>(_o);
        switch (_id) {
        case 0: _t->clic_accepted(); break;
        case 1: _t->clic_rejected(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData NewResultatWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewResultatWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewResultatWindow,
      qt_meta_data_NewResultatWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewResultatWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewResultatWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewResultatWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewResultatWindow))
        return static_cast<void*>(const_cast< NewResultatWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewResultatWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
