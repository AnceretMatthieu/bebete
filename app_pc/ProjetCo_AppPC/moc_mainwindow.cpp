/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed May 16 10:03:05 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      41,   11,   11,   11, 0x08,
      75,   11,   11,   11, 0x08,
     109,   11,   11,   11, 0x08,
     134,  128,   11,   11, 0x08,
     173,   11,   11,   11, 0x08,
     206,   11,   11,   11, 0x08,
     220,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionQuitter_triggered()\0"
    "on_actionExporter_XML_triggered()\0"
    "on_actionImporter_XML_triggered()\0"
    "on_actionApropos()\0index\0"
    "on_clickTreeViewQuestions(QModelIndex)\0"
    "treeQuestionsContextMenu(QPoint)\0"
    "newQuestion()\0modifierQuestion()\0"
    "supprimerQuestion()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionQuitter_triggered(); break;
        case 1: on_actionExporter_XML_triggered(); break;
        case 2: on_actionImporter_XML_triggered(); break;
        case 3: on_actionApropos(); break;
        case 4: on_clickTreeViewQuestions((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: treeQuestionsContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 6: newQuestion(); break;
        case 7: modifierQuestion(); break;
        case 8: supprimerQuestion(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
