/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun 10. Jun 23:31:27 2012
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
      28,   14, // methods
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
     327,  323,   11,   11, 0x08,
     352,   11,   11,   11, 0x08,
     366,   11,   11,   11, 0x08,
     385,   11,   11,   11, 0x08,
     405,   11,   11,   11, 0x08,
     422,   11,   11,   11, 0x08,
     433,   11,   11,   11, 0x08,
     449,   11,   11,   11, 0x08,
     466,   11,   11,   11, 0x08,
     479,   11,   11,   11, 0x08,
     497,   11,   11,   11, 0x08,
     516,   11,   11,   11, 0x08,
     537,   11,   11,   11, 0x08,
     555,   11,   11,   11, 0x08,
     578,   11,   11,   11, 0x08,
     602,   11,   11,   11, 0x08,
     616,   11,   11,   11, 0x08,
     635,   11,   11,   11, 0x08,

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
    "openMedia(QString,int)\0str\0"
    "receiveContents(QString)\0newQuestion()\0"
    "modifierQuestion()\0supprimerQuestion()\0"
    "newCommentaire()\0newMedia()\0modifierMedia()\0"
    "supprimerMedia()\0newReponse()\0"
    "modifierReponse()\0supprimerReponse()\0"
    "newComMediaReponse()\0newMediaReponse()\0"
    "modifierMediaReponse()\0supprimerMediaReponse()\0"
    "newResultat()\0modifierResultat()\0"
    "supprimerResultat()\0"
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
        case 10: _t->receiveContents((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->newQuestion(); break;
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
        case 25: _t->newResultat(); break;
        case 26: _t->modifierResultat(); break;
        case 27: _t->supprimerResultat(); break;
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
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
