/****************************************************************************
** Meta object code from reading C++ file 'glvideowidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
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
#error "This file was generated using the moc from 6.8.0. It"
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
<<<<<<< HEAD
    "GLVideoWidget"
=======
    "GLVideoWidget",
    "videoFinished",
    ""
>>>>>>> usb
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
<<<<<<< HEAD
       0,    0, // methods
=======
       1,   14, // methods
>>>>>>> usb
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
<<<<<<< HEAD
       0,       // signalCount
=======
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,
>>>>>>> usb

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
<<<<<<< HEAD
        QtPrivate::TypeAndForceComplete<GLVideoWidget, std::true_type>
=======
        QtPrivate::TypeAndForceComplete<GLVideoWidget, std::true_type>,
        // method 'videoFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
>>>>>>> usb
    >,
    nullptr
} };

void GLVideoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
<<<<<<< HEAD
    (void)_o;
    (void)_id;
    (void)_c;
=======
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GLVideoWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->videoFinished(); break;
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
>>>>>>> usb
    (void)_a;
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
<<<<<<< HEAD
    return _id;
}
=======
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GLVideoWidget::videoFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
>>>>>>> usb
QT_WARNING_POP
