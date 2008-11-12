/****************************************************************************
** Meta object code from reading C++ file 'stickerwindow.h'
**
** Created: Thu Oct 30 15:12:14 2008
**      by: The Qt Meta Object Compiler version 60 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stickerwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stickerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 60
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_stickerWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_stickerWindow[] = {
    "stickerWindow\0"
};

const QMetaObject stickerWindow::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_stickerWindow,
      qt_meta_data_stickerWindow, 0 }
};

const QMetaObject *stickerWindow::metaObject() const
{
    return &staticMetaObject;
}

void *stickerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_stickerWindow))
        return static_cast<void*>(const_cast< stickerWindow*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int stickerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
