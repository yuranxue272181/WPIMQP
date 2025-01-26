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
    "setExposureTimeValue",
    "setGainValue",
    "setDynamicRangeValue",
    "setSTNRValue",
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
    "setFrameRate",
    "grabBtnChecked"
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
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  194,    2, 0x08,    1 /* Private */,
       3,    0,  195,    2, 0x08,    2 /* Private */,
       4,    0,  196,    2, 0x08,    3 /* Private */,
       5,    0,  197,    2, 0x08,    4 /* Private */,
       6,    0,  198,    2, 0x08,    5 /* Private */,
       7,    0,  199,    2, 0x08,    6 /* Private */,
       8,    1,  200,    2, 0x08,    7 /* Private */,
      10,    1,  203,    2, 0x08,    9 /* Private */,
      11,    1,  206,    2, 0x08,   11 /* Private */,
      12,    1,  209,    2, 0x08,   13 /* Private */,
      13,    1,  212,    2, 0x08,   15 /* Private */,
      14,    1,  215,    2, 0x08,   17 /* Private */,
      15,    0,  218,    2, 0x08,   19 /* Private */,
      16,    1,  219,    2, 0x08,   20 /* Private */,
      17,    1,  222,    2, 0x08,   22 /* Private */,
      18,    1,  225,    2, 0x08,   24 /* Private */,
      19,    1,  228,    2, 0x08,   26 /* Private */,
      20,    0,  231,    2, 0x08,   28 /* Private */,
      21,    2,  232,    2, 0x08,   29 /* Private */,
      24,    3,  237,    2, 0x08,   32 /* Private */,
      29,    0,  244,    2, 0x08,   36 /* Private */,
      30,    0,  245,    2, 0x08,   37 /* Private */,
      31,    0,  246,    2, 0x08,   38 /* Private */,
      32,    0,  247,    2, 0x08,   39 /* Private */,
      33,    0,  248,    2, 0x08,   40 /* Private */,
      34,    0,  249,    2, 0x08,   41 /* Private */,
      35,    0,  250,    2, 0x08,   42 /* Private */,
      36,    1,  251,    2, 0x08,   43 /* Private */,
      37,    1,  254,    2, 0x08,   45 /* Private */,
      38,    0,  257,    2, 0x08,   47 /* Private */,

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
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF,   22,   23,
    QMetaType::Void, 0x80000000 | 25, QMetaType::Int, QMetaType::Int,   26,   27,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

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
        // method 'setExposureTimeValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setGainValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setDynamicRangeValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSTNRValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
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
        // method 'setFrameRate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'grabBtnChecked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
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
        case 13: _t->setExposureTimeValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->setGainValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->setDynamicRangeValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->setSTNRValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->setTrackingEnabled(); break;
        case 18: _t->onSelectionCompleted((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2]))); break;
        case 19: _t->updateAnalysis((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<QList<int>>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 20: _t->minCheck(); break;
        case 21: _t->maxCheck(); break;
        case 22: _t->avegCheck(); break;
        case 23: _t->pixelCheck(); break;
        case 24: _t->rowCheck(); break;
        case 25: _t->columnCheck(); break;
        case 26: _t->resetTotal(); break;
        case 27: _t->updateQueueSize((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->setFrameRate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->grabBtnChecked(); break;
        default: ;
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
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 30;
    }
    return _id;
}
QT_WARNING_POP
