/****************************************************************************
** Meta object code from reading C++ file 'note.h'
**
** Created: Wed Nov 26 16:16:45 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "note.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'note.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Note[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      11,    6,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Note[] = {
    "Note\0\0text\0setContent(QString)\0"
};

const QMetaObject Note::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Note,
      qt_meta_data_Note, 0 }
};

const QMetaObject *Note::metaObject() const
{
    return &staticMetaObject;
}

void *Note::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Note))
        return static_cast<void*>(const_cast< Note*>(this));
    return QObject::qt_metacast(_clname);
}

int Note::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setContent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
