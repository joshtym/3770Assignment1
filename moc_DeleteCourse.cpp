/****************************************************************************
** Meta object code from reading C++ file 'DeleteCourse.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DeleteCourse.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DeleteCourse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DeleteCourse[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DeleteCourse[] = {
    "DeleteCourse\0\0deleteSend(QString)\0"
    "deleteClicked()\0"
};

void DeleteCourse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DeleteCourse *_t = static_cast<DeleteCourse *>(_o);
        switch (_id) {
        case 0: _t->deleteSend((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->deleteClicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DeleteCourse::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DeleteCourse::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DeleteCourse,
      qt_meta_data_DeleteCourse, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeleteCourse::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeleteCourse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeleteCourse::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeleteCourse))
        return static_cast<void*>(const_cast< DeleteCourse*>(this));
    return QDialog::qt_metacast(_clname);
}

int DeleteCourse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DeleteCourse::deleteSend(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
