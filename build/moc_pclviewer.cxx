/****************************************************************************
** Meta object code from reading C++ file 'pclviewer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pclviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pclviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PCLViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      33,   10,   10,   10, 0x05,
      57,   10,   10,   10, 0x05,
      90,   88,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     122,   10,   10,   10, 0x0a,
     143,   10,   10,   10, 0x0a,
     168,   10,   10,   10, 0x0a,
     186,   10,   10,   10, 0x0a,
     207,   10,   10,   10, 0x0a,
     222,   10,   10,   10, 0x0a,
     237,   10,   10,   10, 0x0a,
     257,   10,   10,   10, 0x0a,
     271,   10,   10,   10, 0x0a,
     288,   10,   10,   10, 0x0a,
     308,   10,   10,   10, 0x0a,
     326,   10,   10,   10, 0x0a,
     336,   10,   10,   10, 0x0a,
     355,   10,   10,   10, 0x0a,
     370,   10,   10,   10, 0x0a,
     396,  390,   10,   10, 0x0a,
     460,   10,   10,   10, 0x0a,
     484,   10,   10,   10, 0x0a,
     511,   10,   10,   10, 0x0a,
     539,   10,   10,   10, 0x0a,
     557,   10,   10,   10, 0x0a,
     582,   10,   10,   10, 0x0a,
     609,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PCLViewer[] = {
    "PCLViewer\0\0trans_filepath(char*)\0"
    "emit_mls_signal(double)\0"
    "emit_downSample_signal(double)\0,\0"
    "emit_reconstruct(double,double)\0"
    "SimplifyPointcloud()\0ReconstructPolygonmesh()\0"
    "ResetPointcloud()\0CurvesurfaceReform()\0"
    "openFileSlot()\0saveFileSlot()\0"
    "displayPointCloud()\0dispalyMesh()\0"
    "clearCloudSlot()\0filterSurfaceSlot()\0"
    "selectCloudSlot()\0mlsSlot()\0"
    "downSamplingSlot()\0fillHoleSlot()\0"
    "computeNormalSlot()\0cloud\0"
    "showCloudKinectStream(pcl::PointCloud<pcl::PointXYZ>::ConstPtr)\0"
    "displayPointXYZ_Cloud()\0"
    "displayPointXYZRGB_Cloud()\0"
    "displayPointCloudRealTime()\0"
    "show_coordinate()\0show_operateDockWidget()\0"
    "show_configureDockWidget()\0"
    "set_background_color()\0"
};

void PCLViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PCLViewer *_t = static_cast<PCLViewer *>(_o);
        switch (_id) {
        case 0: _t->trans_filepath((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->emit_mls_signal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->emit_downSample_signal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->emit_reconstruct((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->SimplifyPointcloud(); break;
        case 5: _t->ReconstructPolygonmesh(); break;
        case 6: _t->ResetPointcloud(); break;
        case 7: _t->CurvesurfaceReform(); break;
        case 8: _t->openFileSlot(); break;
        case 9: _t->saveFileSlot(); break;
        case 10: _t->displayPointCloud(); break;
        case 11: _t->dispalyMesh(); break;
        case 12: _t->clearCloudSlot(); break;
        case 13: _t->filterSurfaceSlot(); break;
        case 14: _t->selectCloudSlot(); break;
        case 15: _t->mlsSlot(); break;
        case 16: _t->downSamplingSlot(); break;
        case 17: _t->fillHoleSlot(); break;
        case 18: _t->computeNormalSlot(); break;
        case 19: _t->showCloudKinectStream((*reinterpret_cast< const pcl::PointCloud<pcl::PointXYZ>::ConstPtr(*)>(_a[1]))); break;
        case 20: _t->displayPointXYZ_Cloud(); break;
        case 21: _t->displayPointXYZRGB_Cloud(); break;
        case 22: _t->displayPointCloudRealTime(); break;
        case 23: _t->show_coordinate(); break;
        case 24: _t->show_operateDockWidget(); break;
        case 25: _t->show_configureDockWidget(); break;
        case 26: _t->set_background_color(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PCLViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PCLViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PCLViewer,
      qt_meta_data_PCLViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PCLViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PCLViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PCLViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PCLViewer))
        return static_cast<void*>(const_cast< PCLViewer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PCLViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void PCLViewer::trans_filepath(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PCLViewer::emit_mls_signal(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PCLViewer::emit_downSample_signal(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PCLViewer::emit_reconstruct(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
static const uint qt_meta_data_MlsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_MlsDialog[] = {
    "MlsDialog\0"
};

void MlsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MlsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MlsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MlsDialog,
      qt_meta_data_MlsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MlsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MlsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MlsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MlsDialog))
        return static_cast<void*>(const_cast< MlsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MlsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_DownSampingDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_DownSampingDialog[] = {
    "DownSampingDialog\0"
};

void DownSampingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DownSampingDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DownSampingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DownSampingDialog,
      qt_meta_data_DownSampingDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DownSampingDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DownSampingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DownSampingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownSampingDialog))
        return static_cast<void*>(const_cast< DownSampingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int DownSampingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_Triangulation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Triangulation[] = {
    "Triangulation\0"
};

void Triangulation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Triangulation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Triangulation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Triangulation,
      qt_meta_data_Triangulation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Triangulation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Triangulation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Triangulation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Triangulation))
        return static_cast<void*>(const_cast< Triangulation*>(this));
    return QDialog::qt_metacast(_clname);
}

int Triangulation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_OpenContrlKinect[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_OpenContrlKinect[] = {
    "OpenContrlKinect\0"
};

void OpenContrlKinect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OpenContrlKinect::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OpenContrlKinect::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_OpenContrlKinect,
      qt_meta_data_OpenContrlKinect, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OpenContrlKinect::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OpenContrlKinect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OpenContrlKinect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OpenContrlKinect))
        return static_cast<void*>(const_cast< OpenContrlKinect*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int OpenContrlKinect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_CloudRangeDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_CloudRangeDialog[] = {
    "CloudRangeDialog\0"
};

void CloudRangeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CloudRangeDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CloudRangeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CloudRangeDialog,
      qt_meta_data_CloudRangeDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CloudRangeDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CloudRangeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CloudRangeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CloudRangeDialog))
        return static_cast<void*>(const_cast< CloudRangeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CloudRangeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_RealTimeDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_RealTimeDialog[] = {
    "RealTimeDialog\0"
};

void RealTimeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData RealTimeDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RealTimeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RealTimeDialog,
      qt_meta_data_RealTimeDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RealTimeDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RealTimeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RealTimeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RealTimeDialog))
        return static_cast<void*>(const_cast< RealTimeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RealTimeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
