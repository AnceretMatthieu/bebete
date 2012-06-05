/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue 5. Jun 12:35:59 2012
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
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
     100,   11,   11,   11, 0x08,
     122,  116,   11,   11, 0x08,
     158,  116,   11,   11, 0x08,
     200,  116,   11,   11, 0x08,
     243,  234,   11,   11, 0x08,
     262,  234,   11,   11, 0x08,
     300,  281,   11,   11, 0x08,
     323,   11,   11,   11, 0x08,
     341,   11,   11,   11, 0x08,
     360,   11,   11,   11, 0x08,
     379,   11,   11,   11, 0x08,
     399,   11,   11,   11, 0x08,
     416,   11,   11,   11, 0x08,
     427,   11,   11,   11, 0x08,
     443,   11,   11,   11, 0x08,
     460,   11,   11,   11, 0x08,
     473,   11,   11,   11, 0x08,
     491,   11,   11,   11, 0x08,
     510,   11,   11,   11, 0x08,
     531,   11,   11,   11, 0x08,
     549,   11,   11,   11, 0x08,
     572,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0actionQuitter_triggered()\0"
    "actionExporter_XML_triggered()\0"
    "actionImporter_XML_triggered()\0"
    "actionApropos()\0index\0"
    "clickTreeViewQuestions(QModelIndex)\0"
    "clickTreeViewMediasQuestions(QModelIndex)\0"
    "clickTreeViewReponse(QModelIndex)\0"
    "fileName\0playAudio(QString)\0"
    "playVideo(QString)\0fileName,typeMedia\0"
    "openMedia(QString,int)\0newQuestionFils()\0"
    "newQuestionFrere()\0modifierQuestion()\0"
    "supprimerQuestion()\0newCommentaire()\0"
    "newMedia()\0modifierMedia()\0supprimerMedia()\0"
    "newReponse()\0modifierReponse()\0"
    "supprimerReponse()\0newComMediaReponse()\0"
    "newMediaReponse()\0modifierMediaReponse()\0"
    "supprimerMediaReponse()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->actionQuitter_triggered(); break;
        case 1: _t->actionExporter_XML_triggered(); break;
        case 2: _t->actionImporter_XML_triggered(); break;
        case 3: _t->actionApropos(); break;
        case 4: _t->clickTreeViewQuestions((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->clickTreeViewMediasQuestions((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->clickTreeViewReponse((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->playAudio((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->playVideo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->openMedia((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->newQuestionFils(); break;
        case 11: _t->newQuestionFrere(); break;
        case 12: _t->modifierQuestion(); break;
        case 13: _t->supprimerQuestion(); break;
        case 14: _t->newCommentaire(); break;
        case 15: _t->newMedia(); break;
        case 16: _t->modifierMedia(); break;
        case 17: _t->supprimerMedia(); break;
        case 18: _t->newReponse(); break;
        case 19: _t->modifierReponse(); break;
        case 20: _t->supprimerReponse(); break;
        case 21: _t->newComMediaReponse(); break;
        case 22: _t->newMediaReponse(); break;
        case 23: _t->modifierMediaReponse(); break;
        case 24: _t->supprimerMediaReponse(); break;
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
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
