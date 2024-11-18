/****************************************************************************
** Meta object code from reading C++ file 'glvideowidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../glvideowidget.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glvideowidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGLVideoWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGLVideoWidgetENDCLASS = QtMocHelpers::stringData(
    "GLVideoWidget",
    "videoFinished",
    "",
    "selectionCompleted",
    "start",
    "end",
    "updateGrayValues",
    "QList<int>&",
    "grayValues",
    "setBrightness",
    "value",
    "setContrast",
    "setSharpness",
    "setHEValue",
    "setNoiseReduction",
    "setGamma",
    "onTimerTimeout",
    "saveRecordingData"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGLVideoWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    2,   81,    2, 0x06,    2 /* Public */,
       6,    1,   86,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   89,    2, 0x0a,    7 /* Public */,
      11,    1,   92,    2, 0x0a,    9 /* Public */,
      12,    1,   95,    2, 0x0a,   11 /* Public */,
      13,    1,   98,    2, 0x0a,   13 /* Public */,
      14,    1,  101,    2, 0x0a,   15 /* Public */,
      15,    1,  104,    2, 0x0a,   17 /* Public */,
      16,    0,  107,    2, 0x08,   19 /* Private */,
      17,    0,  108,    2, 0x08,   20 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,   10,
    QMetaType::Void, QMetaType::Float,   10,
    QMetaType::Void, QMetaType::Float,   10,
    QMetaType::Void, QMetaType::Float,   10,
    QMetaType::Void, QMetaType::Float,   10,
    QMetaType::Void, QMetaType::Float,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GLVideoWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGLVideoWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGLVideoWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGLVideoWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GLVideoWidget, std::true_type>,
        // method 'videoFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectionCompleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPointF &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPointF &, std::false_type>,
        // method 'updateGrayValues'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<int> &, std::false_type>,
        // method 'setBrightness'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'setContrast'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'setSharpness'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'setHEValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'setNoiseReduction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'setGamma'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'onTimerTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveRecordingData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GLVideoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GLVideoWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->videoFinished(); break;
        case 1: _t->selectionCompleted((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2]))); break;
        case 2: _t->updateGrayValues((*reinterpret_cast< std::add_pointer_t<QList<int>&>>(_a[1]))); break;
        case 3: _t->setBrightness((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 4: _t->setContrast((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 5: _t->setSharpness((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 6: _t->setHEValue((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 7: _t->setNoiseReduction((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 8: _t->setGamma((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 9: _t->onTimerTimeout(); break;
        case 10: _t->saveRecordingData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GLVideoWidget::*)();
            if (_t _q_method = &GLVideoWidget::videoFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GLVideoWidget::*)(const QPointF & , const QPointF & );
            if (_t _q_method = &GLVideoWidget::selectionCompleted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GLVideoWidget::*)(QVector<int> & );
            if (_t _q_method = &GLVideoWidget::updateGrayValues; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *GLVideoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLVideoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGLVideoWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int GLVideoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void GLVideoWidget::videoFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GLVideoWidget::selectionCompleted(const QPointF & _t1, const QPointF & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GLVideoWidget::updateGrayValues(QVector<int> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
