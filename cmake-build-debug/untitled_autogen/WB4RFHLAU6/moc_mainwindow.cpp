/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../View/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "addCategorySignal",
    "",
    "deleteButtonClickedSignal",
    "Category*",
    "addTaskButtonClickedSignal",
    "deleteTaskButtonClickedSignal",
    "Goal*",
    "plusTaskButtonSignal",
    "minusTaskButtonSignal",
    "onAddCategoryButton_clicked",
    "onPrintButton_clicked",
    "onDeleteButtonClicked",
    "onAddTaskButtonClicked",
    "onDeleteTaskButtonClicked",
    "onPlusTaskButtonClicked",
    "onMinusTaskButtonClicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x06,    1 /* Public */,
       3,    1,   93,    2, 0x06,    2 /* Public */,
       5,    1,   96,    2, 0x06,    4 /* Public */,
       6,    2,   99,    2, 0x06,    6 /* Public */,
       8,    2,  104,    2, 0x06,    9 /* Public */,
       9,    2,  109,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  114,    2, 0x0a,   15 /* Public */,
      11,    0,  115,    2, 0x0a,   16 /* Public */,
      12,    1,  116,    2, 0x0a,   17 /* Public */,
      13,    1,  119,    2, 0x0a,   19 /* Public */,
      14,    2,  122,    2, 0x0a,   21 /* Public */,
      15,    2,  127,    2, 0x0a,   24 /* Public */,
      16,    2,  132,    2, 0x0a,   27 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    2,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'addCategorySignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteButtonClickedSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Category *, std::false_type>,
        // method 'addTaskButtonClickedSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Category *, std::false_type>,
        // method 'deleteTaskButtonClickedSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Category *, std::false_type>,
        QtPrivate::TypeAndForceComplete<Goal *, std::false_type>,
        // method 'plusTaskButtonSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Category *, std::false_type>,
        QtPrivate::TypeAndForceComplete<Goal *, std::false_type>,
        // method 'minusTaskButtonSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Category *, std::false_type>,
        QtPrivate::TypeAndForceComplete<Goal *, std::false_type>,
        // method 'onAddCategoryButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPrintButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Category *, std::false_type>,
        // method 'onAddTaskButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Category *, std::false_type>,
        // method 'onDeleteTaskButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Category *, std::false_type>,
        QtPrivate::TypeAndForceComplete<Goal *, std::false_type>,
        // method 'onPlusTaskButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Category *, std::false_type>,
        QtPrivate::TypeAndForceComplete<Goal *, std::false_type>,
        // method 'onMinusTaskButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Category *, std::false_type>,
        QtPrivate::TypeAndForceComplete<Goal *, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->addCategorySignal(); break;
        case 1: _t->deleteButtonClickedSignal((*reinterpret_cast< std::add_pointer_t<Category*>>(_a[1]))); break;
        case 2: _t->addTaskButtonClickedSignal((*reinterpret_cast< std::add_pointer_t<Category*>>(_a[1]))); break;
        case 3: _t->deleteTaskButtonClickedSignal((*reinterpret_cast< std::add_pointer_t<Category*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Goal*>>(_a[2]))); break;
        case 4: _t->plusTaskButtonSignal((*reinterpret_cast< std::add_pointer_t<Category*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Goal*>>(_a[2]))); break;
        case 5: _t->minusTaskButtonSignal((*reinterpret_cast< std::add_pointer_t<Category*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Goal*>>(_a[2]))); break;
        case 6: _t->onAddCategoryButton_clicked(); break;
        case 7: _t->onPrintButton_clicked(); break;
        case 8: _t->onDeleteButtonClicked((*reinterpret_cast< std::add_pointer_t<Category*>>(_a[1]))); break;
        case 9: _t->onAddTaskButtonClicked((*reinterpret_cast< std::add_pointer_t<Category*>>(_a[1]))); break;
        case 10: _t->onDeleteTaskButtonClicked((*reinterpret_cast< std::add_pointer_t<Category*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Goal*>>(_a[2]))); break;
        case 11: _t->onPlusTaskButtonClicked((*reinterpret_cast< std::add_pointer_t<Category*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Goal*>>(_a[2]))); break;
        case 12: _t->onMinusTaskButtonClicked((*reinterpret_cast< std::add_pointer_t<Category*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Goal*>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Category* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Category* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Category* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Goal* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Category* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Goal* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Category* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Goal* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Category* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Category* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Category* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Goal* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Category* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Goal* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Category* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Goal* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (MainWindow::*)();
            if (_q_method_type _q_method = &MainWindow::addCategorySignal; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (MainWindow::*)(Category * );
            if (_q_method_type _q_method = &MainWindow::deleteButtonClickedSignal; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (MainWindow::*)(Category * );
            if (_q_method_type _q_method = &MainWindow::addTaskButtonClickedSignal; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (MainWindow::*)(Category * , Goal * );
            if (_q_method_type _q_method = &MainWindow::deleteTaskButtonClickedSignal; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (MainWindow::*)(Category * , Goal * );
            if (_q_method_type _q_method = &MainWindow::plusTaskButtonSignal; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (MainWindow::*)(Category * , Goal * );
            if (_q_method_type _q_method = &MainWindow::minusTaskButtonSignal; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
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
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Observer"))
        return static_cast< Observer*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::addCategorySignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::deleteButtonClickedSignal(Category * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::addTaskButtonClickedSignal(Category * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::deleteTaskButtonClickedSignal(Category * _t1, Goal * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::plusTaskButtonSignal(Category * _t1, Goal * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::minusTaskButtonSignal(Category * _t1, Goal * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
