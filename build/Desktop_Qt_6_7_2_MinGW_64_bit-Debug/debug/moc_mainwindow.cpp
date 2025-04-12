/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "renderVideo",
    "",
    "pauseVideo",
    "onVideoFinished",
    "zoomIn",
    "zoomOut",
    "recordingStatu",
    "setBrightness",
    "value",
    "setContrast",
    "setSharpness",
    "setHEValue",
    "setNRValue",
    "setGammaValue",
    "reset",
    "setTrackingEnabled",
    "onSelectionCompleted",
    "start",
    "end",
    "updateAnalysis",
    "std::shared_ptr<QList<int>>",
    "grayValues",
    "selectedWidth",
    "selectedHeight",
    "minCheck",
    "maxCheck",
    "avegCheck",
    "pixelCheck",
    "rowCheck",
    "columnCheck",
    "resetTotal",
    "updateQueueSize",
    "grabBtnChecked",
    "on_aboutUsButton_clicked",
    "setButtonIconColor",
    "QToolButton*",
    "button",
    "iconPath",
    "color"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  176,    2, 0x08,    1 /* Private */,
       3,    0,  177,    2, 0x08,    2 /* Private */,
       4,    0,  178,    2, 0x08,    3 /* Private */,
       5,    0,  179,    2, 0x08,    4 /* Private */,
       6,    0,  180,    2, 0x08,    5 /* Private */,
       7,    0,  181,    2, 0x08,    6 /* Private */,
       8,    1,  182,    2, 0x08,    7 /* Private */,
      10,    1,  185,    2, 0x08,    9 /* Private */,
      11,    1,  188,    2, 0x08,   11 /* Private */,
      12,    1,  191,    2, 0x08,   13 /* Private */,
      13,    1,  194,    2, 0x08,   15 /* Private */,
      14,    1,  197,    2, 0x08,   17 /* Private */,
      15,    0,  200,    2, 0x08,   19 /* Private */,
      16,    0,  201,    2, 0x08,   20 /* Private */,
      17,    2,  202,    2, 0x08,   21 /* Private */,
      20,    3,  207,    2, 0x08,   24 /* Private */,
      25,    0,  214,    2, 0x08,   28 /* Private */,
      26,    0,  215,    2, 0x08,   29 /* Private */,
      27,    0,  216,    2, 0x08,   30 /* Private */,
      28,    0,  217,    2, 0x08,   31 /* Private */,
      29,    0,  218,    2, 0x08,   32 /* Private */,
      30,    0,  219,    2, 0x08,   33 /* Private */,
      31,    0,  220,    2, 0x08,   34 /* Private */,
      32,    1,  221,    2, 0x08,   35 /* Private */,
      33,    0,  224,    2, 0x08,   37 /* Private */,
      34,    0,  225,    2, 0x08,   38 /* Private */,
      35,    3,  226,    2, 0x08,   39 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF,   18,   19,
    QMetaType::Void, 0x80000000 | 21, QMetaType::Int, QMetaType::Int,   22,   23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 36, QMetaType::QString, QMetaType::QColor,   37,   38,   39,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'renderVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pauseVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onVideoFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'zoomIn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'zoomOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'recordingStatu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setBrightness'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setContrast'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSharpness'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setHEValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setNRValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setGammaValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'reset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setTrackingEnabled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSelectionCompleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPointF &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPointF &, std::false_type>,
        // method 'updateAnalysis'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<QVector<int>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'minCheck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'maxCheck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'avegCheck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pixelCheck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rowCheck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'columnCheck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetTotal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateQueueSize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'grabBtnChecked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_aboutUsButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setButtonIconColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QToolButton *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->renderVideo(); break;
        case 1: _t->pauseVideo(); break;
        case 2: _t->onVideoFinished(); break;
        case 3: _t->zoomIn(); break;
        case 4: _t->zoomOut(); break;
        case 5: _t->recordingStatu(); break;
        case 6: _t->setBrightness((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->setContrast((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->setSharpness((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->setHEValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->setNRValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->setGammaValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->reset(); break;
        case 13: _t->setTrackingEnabled(); break;
        case 14: _t->onSelectionCompleted((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2]))); break;
        case 15: _t->updateAnalysis((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<QList<int>>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 16: _t->minCheck(); break;
        case 17: _t->maxCheck(); break;
        case 18: _t->avegCheck(); break;
        case 19: _t->pixelCheck(); break;
        case 20: _t->rowCheck(); break;
        case 21: _t->columnCheck(); break;
        case 22: _t->resetTotal(); break;
        case 23: _t->updateQueueSize((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->grabBtnChecked(); break;
        case 25: _t->on_aboutUsButton_clicked(); break;
        case 26: _t->setButtonIconColor((*reinterpret_cast< std::add_pointer_t<QToolButton*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QToolButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}
QT_WARNING_POP
