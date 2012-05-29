/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
<<<<<<< HEAD
** Created: Tue 29. May 09:17:47 2012
=======
** Created: Tue 29. May 10:15:42 2012
>>>>>>> 84d0423
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
      22,   14, // methods
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
     218,  128,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,
     288,   11,   11,   11, 0x08,
     329,  320,   11,   11, 0x08,
     348,  320,   11,   11, 0x08,
     386,  367,   11,   11, 0x08,
     409,   11,   11,   11, 0x08,
     427,   11,   11,   11, 0x08,
     446,   11,   11,   11, 0x08,
     465,   11,   11,   11, 0x08,
     485,   11,   11,   11, 0x08,
     498,   11,   11,   11, 0x08,
     516,   11,   11,   11, 0x08,
     535,   11,   11,   11, 0x08,
     546,   11,   11,   11, 0x08,
     562,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionQuitter_triggered()\0"
    "on_actionExporter_XML_triggered()\0"
    "on_actionImporter_XML_triggered()\0"
    "on_actionApropos()\0index\0"
    "on_clickTreeViewQuestions(QModelIndex)\0"
    "on_clickTreeViewMediasQuestions(QModelIndex)\0"
    "on_clickTreeViewReponse(QModelIndex)\0"
    "treeQuestionsContextMenu(QPoint)\0"
    "treeReponsesContextMenu(QPoint)\0"
    "fileName\0playAudio(QString)\0"
    "playVideo(QString)\0fileName,typeMedia\0"
    "openMedia(QString,int)\0newQuestionFils()\0"
    "newQuestionFrere()\0modifierQuestion()\0"
    "supprimerQuestion()\0newReponse()\0"
    "modifierReponse()\0supprimerReponse()\0"
    "newMedia()\0modifierMedia()\0supprimerMedia()\0"
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
        case 6: _t->on_clickTreeViewReponse((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->treeQuestionsContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->treeReponsesContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 9: _t->playAudio((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->playVideo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->openMedia((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->newQuestionFils(); break;
        case 13: _t->newQuestionFrere(); break;
        case 14: _t->modifierQuestion(); break;
        case 15: _t->supprimerQuestion(); break;
        case 16: _t->newReponse(); break;
        case 17: _t->modifierReponse(); break;
        case 18: _t->supprimerReponse(); break;
        case 19: _t->newMedia(); break;
        case 20: _t->modifierMedia(); break;
        case 21: _t->supprimerMedia(); break;
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
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
