/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Project_Optimization_GUI/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[46];
    char stringdata0[420];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 19), // "on_delete_1_clicked"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 19), // "on_delete_2_clicked"
QT_MOC_LITERAL(52, 19), // "on_delete_3_clicked"
QT_MOC_LITERAL(72, 19), // "on_delete_4_clicked"
QT_MOC_LITERAL(92, 19), // "on_delete_5_clicked"
QT_MOC_LITERAL(112, 21), // "on_select_all_clicked"
QT_MOC_LITERAL(134, 17), // "on_disk_1_clicked"
QT_MOC_LITERAL(152, 17), // "on_disk_3_clicked"
QT_MOC_LITERAL(170, 27), // "on_disk_2_combo_highlighted"
QT_MOC_LITERAL(198, 5), // "index"
QT_MOC_LITERAL(204, 24), // "on_dashboard_btn_pressed"
QT_MOC_LITERAL(229, 24), // "on_processes_btn_pressed"
QT_MOC_LITERAL(254, 26), // "on_delete_selected_clicked"
QT_MOC_LITERAL(281, 17), // "on_defrag_clicked"
QT_MOC_LITERAL(299, 29), // "on_disk_2_combo_textActivated"
QT_MOC_LITERAL(329, 4), // "arg1"
QT_MOC_LITERAL(334, 28), // "on_process_table_cellClicked"
QT_MOC_LITERAL(363, 3), // "row"
QT_MOC_LITERAL(367, 6), // "column"
QT_MOC_LITERAL(374, 22), // "on_end_process_clicked"
QT_MOC_LITERAL(397, 22) // "on_refresh_btn_clicked"

    },
    "MainWindow\0on_delete_1_clicked\0\0"
    "on_delete_2_clicked\0on_delete_3_clicked\0"
    "on_delete_4_clicked\0on_delete_5_clicked\0"
    "on_select_all_clicked\0on_disk_1_clicked\0"
    "on_disk_3_clicked\0on_disk_2_combo_highlighted\0"
    "index\0on_dashboard_btn_pressed\0"
    "on_processes_btn_pressed\0"
    "on_delete_selected_clicked\0on_defrag_clicked\0"
    "on_disk_2_combo_textActivated\0arg1\0"
    "on_process_table_cellClicked\0row\0"
    "column\0on_end_process_clicked\0"
    "on_refresh_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x08,    1 /* Private */,
       3,    0,  117,    2, 0x08,    2 /* Private */,
       4,    0,  118,    2, 0x08,    3 /* Private */,
       5,    0,  119,    2, 0x08,    4 /* Private */,
       6,    0,  120,    2, 0x08,    5 /* Private */,
       7,    0,  121,    2, 0x08,    6 /* Private */,
       8,    0,  122,    2, 0x08,    7 /* Private */,
       9,    0,  123,    2, 0x08,    8 /* Private */,
      10,    1,  124,    2, 0x08,    9 /* Private */,
      12,    0,  127,    2, 0x08,   11 /* Private */,
      13,    0,  128,    2, 0x08,   12 /* Private */,
      14,    0,  129,    2, 0x08,   13 /* Private */,
      15,    0,  130,    2, 0x08,   14 /* Private */,
      16,    1,  131,    2, 0x08,   15 /* Private */,
      18,    2,  134,    2, 0x08,   17 /* Private */,
      21,    0,  139,    2, 0x08,   20 /* Private */,
      22,    0,  140,    2, 0x08,   21 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_delete_1_clicked(); break;
        case 1: _t->on_delete_2_clicked(); break;
        case 2: _t->on_delete_3_clicked(); break;
        case 3: _t->on_delete_4_clicked(); break;
        case 4: _t->on_delete_5_clicked(); break;
        case 5: _t->on_select_all_clicked(); break;
        case 6: _t->on_disk_1_clicked(); break;
        case 7: _t->on_disk_3_clicked(); break;
        case 8: _t->on_disk_2_combo_highlighted((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_dashboard_btn_pressed(); break;
        case 10: _t->on_processes_btn_pressed(); break;
        case 11: _t->on_delete_selected_clicked(); break;
        case 12: _t->on_defrag_clicked(); break;
        case 13: _t->on_disk_2_combo_textActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->on_process_table_cellClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 15: _t->on_end_process_clicked(); break;
        case 16: _t->on_refresh_btn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
