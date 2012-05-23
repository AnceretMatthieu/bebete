/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed 23. May 13:56:38 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
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
     173,  128,   11,   11, 0x08,
     218,   11,   11,   11, 0x08,
     251,   11,   11,   11, 0x08,
     283,   11,   11,   11, 0x08,
     301,   11,   11,   11, 0x08,
     320,   11,   11,   11, 0x08,
     339,   11,   11,   11, 0x08,
     359,   11,   11,   11, 0x08,
     372,   11,   11,   11, 0x08,
     390,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionQuitter_triggered()\0"
    "on_actionExporter_XML_triggered()\0"
    "on_actionImporter_XML_triggered()\0"
    "on_actionApropos()\0index\0"
    "on_clickTreeViewQuestions(QModelIndex)\0"
    "on_clickTreeViewMediasQuestions(QModelIndex)\0"
    "treeQuestionsContextMenu(QPoint)\0"
    "treeReponsesContextMenu(QPoint)\0"
    "newQuestionFils()\0newQuestionFrere()\0"
    "modifierQuestion()\0supprimerQuestion()\0"
    "newReponse()\0modifierReponse()\0"
    "supprimerReponse()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionQuitter_triggered(); break;
        case 1: _t->on_actionExporter_XML_triggered(); break;
        case 2: _t->on_actionImporter_XML_triggered(); break;
        case 3: _t->on_actionApropos(); break;
        case 4: _t->on_clickTreeViewQuestions((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_clickTreeViewMediasQuestions((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->treeQuestionsContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->treeReponsesContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->newQuestionFils(); break;
        case 9: _t->newQuestionFrere(); break;
        case 10: _t->modifierQuestion(); break;
        case 11: _t->supprimerQuestion(); break;
        case 12: _t->newReponse(); break;
        case 13: _t->modifierReponse(); break;
        case 14: _t->supprimerReponse(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
