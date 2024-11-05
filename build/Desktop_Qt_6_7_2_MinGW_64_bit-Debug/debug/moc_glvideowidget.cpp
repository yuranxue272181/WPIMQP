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
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   69,    2, 0x0a,    2 /* Public */,
       5,    1,   72,    2, 0x0a,    4 /* Public */,
       6,    1,   75,    2, 0x0a,    6 /* Public */,
       7,    1,   78,    2, 0x0a,    8 /* Public */,
       8,    1,   81,    2, 0x0a,   10 /* Public */,
       9,    1,   84,    2, 0x0a,   12 /* Public */,
      10,    0,   87,    2, 0x08,   14 /* Private */,
      11,    0,   88,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Float,    4,
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
        case 1: _t->setBrightness((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 2: _t->setContrast((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 3: _t->setSharpness((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 4: _t->setHEValue((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 5: _t->setNoiseReduction((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 6: _t->setGamma((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 7: _t->onTimerTimeout(); break;
        case 8: _t->saveRecordingData(); break;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GLVideoWidget::videoFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
