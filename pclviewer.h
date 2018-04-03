#ifndef PCLVIEWER_H
#define PCLVIEWER_H
// Qt Library
#include <QMainWindow>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/PolygonMesh.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>

#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/conditional_removal.h>
// visualization Toolkit
#include <vtkRenderWindow.h>

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <qdebug.h>
#include <QTime>
#include <QString>

#include <iostream>

/* openni head file*/
#include <pcl/io/openni_grabber.h>
#include <QDockWidget>

//#include "smoothSurface.h"

#include "calthread.h"
#include "fill_hole.h"
#include "rgb.h"
//#include "select_cloud.h"

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

extern PointCloudT::Ptr cloud, simplifycloud;
extern pcl::PolygonMesh::Ptr mesh, smoothMesh;

extern pcl::Grabber *interface;
//typedef pcl::PointXYZ PointT;
//typedef pcl::PointCloud<PointT> PointCloudT;

namespace Ui {
class PCLViewer;
}

class MyDialog1 : public QDialog {
    //Q_OBJECT

public:
    explicit MyDialog1(QWidget *parent = 0){}
    ~MyDialog1() {}
};

class MlsDialog;

class DownSampingDialog;
class OpenContrlKinect;

class CloudRangeDialog;

class RealTimeDialog;

class PCLViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit PCLViewer(QWidget *parent = 0);

    ~PCLViewer();

    static void pp_callback(const pcl::visualization::PointPickingEvent& event, void* args);
    static void keyboardevent_callback(const pcl::visualization::KeyboardEvent& event, void* args);
    //int vivi;

signals:
    void trans_filepath(char*);
    void emit_mls_signal(double);
    void emit_downSample_signal(double);
    void emit_reconstruct(double, double);

public slots:
    void SimplifyPointcloud();   //simplify pointcloud
    void ReconstructPolygonmesh();

    void ResetPointcloud();      //reset
    void CurvesurfaceReform();     //qumian chongjian

    void openFileSlot();
    void saveFileSlot();

    void displayPointCloud();
    void dispalyMesh();

    void clearCloudSlot();          //clear the cloud data from the vtk

    void filterSurfaceSlot();       // let surface get more smoother
    void selectCloudSlot();
    void mlsSlot();
    void downSamplingSlot();

    void fillHoleSlot();
    void computeNormalSlot();

    /* openni function*/
    //void openKinect();
    void showCloudKinectStream(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud);
    //void recv_stream();
    void displayPointXYZ_Cloud();
    void displayPointXYZRGB_Cloud();
    void displayPointCloudRealTime();

    /*  pclvisulaizer configure */
    void show_coordinate();
    void show_operateDockWidget();
    void show_configureDockWidget();

    void set_background_color();
   // void set_normal_len();
    //void set_normal_point_number();

protected:
    //boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    //pcl::visualization::PCLVisualizer::Ptr viewer;
    //PointCloudT::Ptr cloud, simplifycloud;
    //pcl::PolygonMesh::Ptr mesh, smoothMesh;

    /*openni interface*/
    //pcl::Grabber *interface;

    CalStaticThread *static_thread;
    DynamicThread *dynamic_thread;

    /* pclvisualizer configure flag */
    bool coordinate_isexit;
    bool operateDockWidget_isexit;
    bool configureDockWidget_isexit;
    bool normal_isexit;



private:

    Ui::PCLViewer *ui;

    pcl::visualization::PCLVisualizer::Ptr viewer;

    QTime time;

    QString time_info;

    vtkSmartPointer<vtkRenderer> renderer;
    //OpenContrlKinect *contrl_kinectWindow;
};

class MlsDialog : public QDialog {
    Q_OBJECT

public:
    explicit MlsDialog(QWidget *parent = 0);
    ~MlsDialog();
    void inline getStr(double& mls_search_radius) {
        str = line_1->text();
        mls_search_radius = str.toDouble();
       // std::cout << mls_search_radius << std::endl;
        //qDebug() << str;
    }

public slots:
    //void accept();
    //void reject();


private:
    QString str;
    QLabel *label_1;
    QLineEdit *line_1;
    QDialogButtonBox *buttonbox;
};

class DownSampingDialog : public QDialog {
    Q_OBJECT

public:
    explicit DownSampingDialog(QWidget *parent = 0);
    ~DownSampingDialog();
    void inline getStr(double & leaf_size) {
        str = line_1->text();
        leaf_size = str.toDouble();
        //qDebug() << str;
    }

public slots:
    //void accept();
    //void reject();


private:
    QString str;
    QLabel *label_1;
    QLineEdit *line_1;
    QDialogButtonBox *buttonbox;
};

class Triangulation : public QDialog {
    Q_OBJECT

public:
    explicit Triangulation(QWidget *parent = 0);
    ~Triangulation();
    void inline getData(double *maxp2plength, double *searchradius) {
        *maxp2plength = line_1->text().toDouble();
        *searchradius = line_2->text().toDouble();
    }

public slots:

private:
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *line_1;
    QLineEdit *line_2;
    QLineEdit *line_3;
    QLineEdit *line_4;
};


class OpenContrlKinect : public QDockWidget {
    Q_OBJECT
public:
    explicit OpenContrlKinect(QWidget *parent = 0);
    ~OpenContrlKinect() {}

private:
    QPushButton *start;
    QPushButton *end;

};


class CloudRangeDialog : public QDialog {
    Q_OBJECT

public:
    explicit CloudRangeDialog(QWidget *parent = 0);
    ~CloudRangeDialog();

    void getData(float *x_low, float *x_high, float *y_low, float *y_high, float *z_low, float *z_high);
        /*
        *x_low = X1->text().toFloat();
        *x_high = X2->text().toFloat();
        *y_low = Y1->text().toFloat();
        *y_high = Y2->text().toFloat();
        *z_low = Z1->text().toFloat();
        *z_high = Z2->text().toFloat();
        */
   // }

private:
    //QLabel label_x1, label_x2;
    //QLabel label_y1, label_y2;
    //QLabel label_z1, label_z2;

    QLineEdit *X1, *X2, *Y1, *Y2, *Z1, *Z2;

    //QDialogButtonBox buttonbox;
};

class RealTimeDialog : public QDialog {
    Q_OBJECT

public:
    explicit RealTimeDialog(QWidget *parent = 0);
    ~RealTimeDialog();
};

#endif // PCLVIEWER_H
