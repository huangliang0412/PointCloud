#include "pclviewer.h"
#include "kdtree.h"
#include "greedy_triangulation.h"
#include "smoothSurface.h"
#include "ui_pclviewer.h"
#include "changeformat.h"

#include "pretreatment.h"
#include <QMainWindow>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>

#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QIODevice>
#include <QDockWidget>
#include <QInputDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <qdebug.h>
#include <QFont>

#include <iostream>
#include <string>

#include <math.h>
#include <unistd.h>
#include <sys/wait.h>

PCLViewer::PCLViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PCLViewer)
{
    //ui->setWindowState(Qt::WindowMaximized);
   //QLabel *point_lable = new QLable(tr("The Number of Points"));
    renderer = vtkSmartPointer<vtkRenderer>::New();

    ui->setupUi(this);
    this->setWindowTitle("PointCloud Viewer");
    ui->subwindow->setWindowState(Qt::WindowMaximized);
    ui->subwindow->setWindowIcon(QIcon(":/image/view_raster.png"));

    /* initial viewer */
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
    viewer->registerPointPickingCallback(pp_callback, this);

    viewer->registerKeyboardCallback(keyboardevent_callback, this);

    /* set coordinate */
   // viewer->addCoordinateSystem(1.0);
    coordinate_isexit = false;
    connect(ui->CoordinateAction, SIGNAL(triggered(bool)), this, SLOT(show_coordinate()));

    /* initial operatorDockwidget flag */
    operateDockWidget_isexit = true;
    connect(ui->HideAction, SIGNAL(triggered(bool)), this, SLOT(show_operateDockWidget()));

    //current the normal is not exit
    normal_isexit = false;

    QFont font("Microsoft YaHei", 16, 75);
    ui->label_2->setFont(font);

    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
    //ui->progressBar->set
    ui->progressBar->setAlignment(Qt::AlignRight);
    ui->progressBar->setMaximumHeight(15);
    ui->progressBar->setMaximumWidth(600);
    ui->progressBar->setVisible(false);

    //initial process that process static
    static_thread = new CalStaticThread;
    dynamic_thread = new DynamicThread;

    //initialize vtk
    viewer->setBackgroundColor(0.1, 0.1, 0.3);
    //viewer->addCoordinateSystem(1.0);
    //viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_FONT_SIZE, 1);
    ui->qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setupInteractor(ui->qvtkWidget->GetInteractor(), ui->qvtkWidget->GetRenderWindow());
    ui->qvtkWidget->update();

    // add pointcloud

    //char* fileName = "/home/huangliang/rabbit.pcd";
    //pcl::io::loadPCDFile(fileName, *cloud);
    //simplifycloud = cloud;
    //simplify_old_cloud = cloud;
    /*
    viewer->addPointCloud(cloud, "cloud");
    viewer->resetCamera();
    ui->qvtkWidget->update();
    */
    //connect(ui->KtreeSlider, SIGNAL(sliderMoved(int)), this, SLOT(SimplifyPointcloud()));
   // contrl_kinectWindow = new OpenContrlKinect;
    //addDockWidget(Qt::LeftDockWidgetArea, contrl_kinectWindow);
    //showDock(contrl_kinectWindow);

    ui->ShowDockWidget->setMinimumWidth(250);
    ui->ShowDockWidget->setMinimumHeight(400);

    ui->PointsNumber->setMinimumHeight(60);
    ui->PointsNumber->setNumDigits(8);
    ui->lcdNumber->setMinimumHeight(50);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignHCenter);

    /* Set configure dockwidget */
    ui->ConfigurDockWidget->setMinimumWidth(300);
    ui->ConfigurDockWidget->setMaximumWidth(400);
    ui->ConfigurDockWidget->setVisible(false);
    configureDockWidget_isexit = false;
    connect(ui->Slider_Backgroud_R, SIGNAL(valueChanged(int)), this, SLOT(set_background_color()));
    connect(ui->Slider_Background_G, SIGNAL(valueChanged(int)), this, SLOT(set_background_color()));
    connect(ui->Slide_Background_B, SIGNAL(valueChanged(int)), this, SLOT(set_background_color()));




    QFont font_text("Microsoft YaHei", 14, 75);
    ui->textBrowser->setMinimumHeight(300);
    ui->textBrowser->setFont(font);
    connect(ui->KtreeSlider, SIGNAL(valueChanged(int)), this, SLOT(SimplifyPointcloud()));


    connect(ui->MLSButton, SIGNAL(clicked(bool)), this, SLOT(mlsSlot()));
    connect(ui->MlsAction, SIGNAL(triggered(bool)), this, SLOT(mlsSlot()));

    connect(ui->DownSampingButton, SIGNAL(clicked(bool)), this, SLOT(downSamplingSlot()));
    connect(ui->SimplyAction, SIGNAL(triggered(bool)), this, SLOT(downSamplingSlot()));

    connect(ui->SelectAction, SIGNAL(triggered(bool)), this, SLOT(selectCloudSlot()));

    connect(ui->ReconstructButton, SIGNAL(clicked(bool)), this, SLOT(ReconstructPolygonmesh()));
    connect(ui->ReconstructAction, SIGNAL(triggered(bool)), this, SLOT(ReconstructPolygonmesh()));

    connect(ui->ResetButton, SIGNAL(clicked(bool)), this, SLOT(ResetPointcloud()));
    connect(ui->ResetAction, SIGNAL(triggered(bool)), this, SLOT(ResetPointcloud()));

    connect(ui->BuildButton, SIGNAL(clicked(bool)),this, SLOT(CurvesurfaceReform()));
    connect(ui->SurfaceAction, SIGNAL(triggered(bool)), this, SLOT(CurvesurfaceReform()));

    connect(ui->ClearButton, SIGNAL(clicked(bool)), this, SLOT(clearCloudSlot()));
    connect(ui->CleraAction, SIGNAL(triggered(bool)), this, SLOT(clearCloudSlot()));

    connect(ui->OpenAction, SIGNAL(triggered(bool)), this, SLOT(openFileSlot()));
    connect(ui->SaveAction, SIGNAL(triggered(bool)), this, SLOT(saveFileSlot()));

    connect(this, SIGNAL(trans_filepath(char*)), static_thread, SLOT(receivers(char*)));
    connect(static_thread, SIGNAL(finishLoadFile(bool)), this, SLOT(displayPointCloud()));

    connect(this, SIGNAL(emit_mls_signal(double)), static_thread, SLOT(recv_mls_signal(double)));
    connect(static_thread, SIGNAL(finish_mls(bool)), this, SLOT(displayPointCloud()));

    connect(this, SIGNAL(emit_downSample_signal(double)), static_thread, SLOT(recv_downSample_signal(double)));
    connect(static_thread, SIGNAL(finish_downSample(bool)), this, SLOT(displayPointCloud()));

    connect(this, SIGNAL(emit_reconstruct(double,double)), static_thread, SLOT(recv_reconstruct(double,double)));
    connect(static_thread, SIGNAL(finish_reconstruct(bool)), this, SLOT(dispalyMesh()));



    connect(ui->FilterButton, SIGNAL(clicked(bool)), this, SLOT(filterSurfaceSlot()));

    connect(ui->FillholeAction, SIGNAL(triggered(bool)), this, SLOT(fillHoleSlot()));

    //connect(ui->KinectAction, SIGNAL(triggered(bool)), this, SLOT(openKinect()));
    connect(ui->RGBCloudAction, SIGNAL(triggered(bool)), this, SLOT(displayPointXYZRGB_Cloud()));
    connect(ui->XYZCloudAction, SIGNAL(triggered(bool)), this, SLOT(displayPointXYZ_Cloud()));
    connect(ui->ReconstructRealTimeAction, SIGNAL(triggered(bool)), this, SLOT(displayPointCloudRealTime()));

    /*show normal */
    connect(ui->NormalAction, SIGNAL(triggered(bool)), this, SLOT(computeNormalSlot()));

    /*show configure dockwidget*/
    //connect()
    connect(ui->BackgroudAction, SIGNAL(triggered(bool)), this, SLOT(show_configureDockWidget()));
    connect(ui->VerticesAction, SIGNAL(triggered(bool)), this, SLOT(show_configureDockWidget()));
    connect(ui->ConfigurationAction, SIGNAL(triggered(bool)), this, SLOT(show_configureDockWidget()));
    //connect(dynamic_thread, SIGNAL(finish_loadStream(bool)), this, SLOT(recv_stream()));


    //ui->ShowDockWidget->setVisible(false);
    //ui->OperateDockWidget->setVisible(false);

    //viewer->initCameraParameters();
    //viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 0.2, 0.3, 0.3);
    //viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 0.2, 0.3, 0.3);

}

PCLViewer::~PCLViewer()
{
    delete ui;
}



void PCLViewer::pp_callback(const pcl::visualization::PointPickingEvent &event, void *args)
{
    PCLViewer *pcl_viewer = (PCLViewer*)args;

    if (event.getPointIndex() == -1) {
        pcl_viewer->viewer->removePointCloud("clicked_points");
        return;
    }

    PointT current_point;
    PointCloudT::Ptr clicked_point(new PointCloudT);
    event.getPoint(current_point.x, current_point.y, current_point.z);
    //data->clicked_points_3d->points.push_back(current_point);
    clicked_point->points.push_back(current_point);
    // Draw clicked points in red:
    pcl::visualization::PointCloudColorHandlerCustom<PointT> red(clicked_point, 255, 0, 0);
    //data->viewerPtr->removePointCloud("clicked_points");
    //data->viewerPtr->addPointCloud(data->clicked_points_3d, red, "clicked_points");
    pcl_viewer->viewer->removePointCloud("clicked_points");
    pcl_viewer->viewer->addPointCloud(clicked_point, red, "clicked_points");
    pcl_viewer->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "clicked_points");
    //data->viewerPtr->removePointCloud("clicked_points");
    //std::cout << current_point.x << " " << current_point.y << " " << current_point.z << std::endl;


    QString info;
    info.sprintf("X:  %f\nY:  %f\nZ:  %f\n", current_point.x, current_point.y, current_point.z);
    //time_info += info;
    pcl_viewer->ui->textBrowser->append(info);
    //time_info.clear();
}

void PCLViewer::keyboardevent_callback(const pcl::visualization::KeyboardEvent &event, void *args)
{
    PCLViewer *pcl_viewer = (PCLViewer*)args;

    if(event.getKeySym() == "r" && event.keyDown()) {
        pcl_viewer->viewer->removePointCloud("clicked_points");
    }
}


void PCLViewer::SimplifyPointcloud()
{

   //PointCloudT::Ptr simplifyCloud;
   simplifycloud = KdTree(cloud, ui->KtreeSlider->value());
   viewer->removePointCloud();
   viewer->addPointCloud(simplifycloud);
   //simplify_old_cloud = simplify_new_cloud;
   viewer->resetCamera();
   ui->qvtkWidget->update();
   ui->lcdNumber->display(ui->KtreeSlider->value());
   int number = simplifycloud->size();
   //std::cout << number << std::endl;
   ui->PointsNumber->display(number);

   //std::cout<<ui->KtreeSlider->value()<<std::endl;
}

void PCLViewer::mlsSlot() {
    //QInputDialog *mlsDialog = new QInputDialog;
    if(!simplifycloud->size()) {
        QMessageBox::information(this, "Error Message",
                                 "This Is a Empty Point Cloud, Please Input Point Cloud");
        return;
    }
    MlsDialog *mlsDialog = new MlsDialog;
    mlsDialog->setGeometry(1600, 100, 250, 50);
    mlsDialog->setWindowTitle(tr("SET MLS"));
    if(mlsDialog->exec() == QDialog::Accepted)
    {
        double mls_search_radius;

        mlsDialog->getStr(mls_search_radius);
        delete mlsDialog;

        time.restart();
        time_info += "PointCloud filter takes ";

        ui->progressBar->setVisible(true);
        static_thread->start();
        emit emit_mls_signal(mls_search_radius);
    } else {
        delete mlsDialog;
    }
    /*
    PreTreatment prement;
    prement.mls(simplifycloud, mls_search_radius);
    viewer->removePointCloud();
    viewer->addPointCloud(simplifycloud);

    //PreTreatment::mls(cloud);
    viewer->resetCamera();
    ui->qvtkWidget->update();
    int number = simplifycloud->size();
    ui->PointsNumber->display(number);
    */
}

void PCLViewer::downSamplingSlot() {

    if(!simplifycloud->size()) {
        QMessageBox::information(this, "Error Message",
                                 "This Is a Empty Point Cloud, Please Input Point Cloud");
        return;
    }

    DownSampingDialog *downDialog = new DownSampingDialog;
    downDialog->setGeometry(1600, 100, 250, 50);
    downDialog->setWindowTitle(tr("SET DownSamping"));

    if(downDialog->exec() == QDialog::Accepted){
        double leaf_size;


        downDialog->getStr(leaf_size);
        delete downDialog;

        time_info += "Point Cloud simplify takes ";
        time.restart();

        ui->progressBar->setVisible(true);
        static_thread->start();
        emit emit_downSample_signal(leaf_size);
    } else {
        delete downDialog;
    }
    /*
    PreTreatment prement;
    prement.downSamping(simplifycloud, leaf_size);
    viewer->removePointCloud();
    viewer->addPointCloud(simplifycloud);
    viewer->resetCamera();
    ui->qvtkWidget->update();
   // ui->PointsNumber->display(simplifycloud->size());


   // PreTreatment::downSamping(cloud);
   // viewer->resetCamera();
    //ui->qvtkWidget->update();

    int  number = simplifycloud->size();
   //std::cout << number << std::endl;
  //int pnum = 100;
   ui->PointsNumber->display(number);
   */

}

void PCLViewer::fillHoleSlot()
{
   /* fill hole */

    viewer->removePolygonMesh("chongjian");
    ui->qvtkWidget->update();
    //vtkSmartPointer<vtkRenderer> renderer = fillhole_triangle(mesh);
   // vtkSmartPointer<vtkRenderer> renderer =
     //       vtkSmartPointer<vtkRenderer>::New();
    fillhole_triangle(mesh, renderer);
    //rgbreconstruct(renderer);
    //std::cout << "whalt" << std::endl;
    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
    //std::cout << "00000" << std::endl;
    ui->qvtkWidget->GetRenderWindow()->Render();
    //ui->qvtkWidget->GetRenderWindow()->
    //ui->qvtkWidget->update();

   // hello();
}

void PCLViewer::computeNormalSlot()
{
    if(!simplifycloud->size()) {
        QMessageBox::information(this, "Error Message",
                                 "This Is a Empty Point Cloud, Please Input Point Cloud");
        return;
    }

    if(!normal_isexit) {

        pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
        cloud_with_normals = calculate_normal(simplifycloud);

        //calculate normal per ten points

        int normal_len = ui->NormallenSlider->value();
        int normal_point_number = ui->NormalPointNumber->value();
        viewer->addPointCloudNormals<pcl::PointNormal>(cloud_with_normals, normal_point_number, normal_len, "normals");
        viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 1, 0, 0, "normals");
        viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 1, "normals");
        //viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VI)
        //viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 1, 0, 0, "normals");
        //viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 6);
        normal_isexit = true;
        ui->qvtkWidget->update();
    } else {
        viewer->removePointCloud("normals");
        ui->qvtkWidget->update();
        normal_isexit = false;
    }

}


void PCLViewer::ReconstructPolygonmesh()
{
    if(!simplifycloud->size()) {
        QMessageBox::information(this, "Error Message",
                                 "This Is a Empty Point Cloud, Please Input Point Cloud");
        return;
    }

    Triangulation *triang = new Triangulation;
    triang->setGeometry(1600, 100, 250, 250);
    triang->setWindowTitle(tr("ReconstructPolygonmesh"));

    if(triang->exec() == QDialog::Accepted) {
        double maxp2plength;
        double searchradius;


        triang->getData(&maxp2plength, &searchradius);
        delete triang;
    /*
    *mesh = rebuild(simplifycloud, maxp2plength, searchradius);
    viewer->removePointCloud();
    viewer->addPolygonMesh(*mesh, "chongjian");
    viewer->setRepresentationToWireframeForAllActors();
    viewer->resetCamera();
    ui->qvtkWidget->update();
    */
        time_info += "Point Cloud reconstruct takes ";
        time.restart();

        ui->progressBar->setVisible(true);
        static_thread->start();
        emit emit_reconstruct(maxp2plength, searchradius);
    } else{
        delete triang;
    }
}

void PCLViewer::filterSurfaceSlot()
{
    /*
    smoothMesh = smoothSurface(mesh);
    viewer->removePolygonMesh("chongjian");
    viewer->addPolygonMesh(*smoothMesh, "SmoothMesh");
    viewer->resetCamera();
    ui->qvtkWidget->update();
    */
}

void PCLViewer::selectCloudSlot()
{
    if(!simplifycloud->size()) {
        QMessageBox::information(this, "Error Message",
                                 "This Is a Empty Point Cloud, Please Input Point Cloud");
        return;
    }

    //CloudRangeDialog *cloudrange = new CloudRangeDialog;
    //cloudrange->exec();
    CloudRangeDialog *select_range = new CloudRangeDialog;
    select_range->setWindowTitle("Cloud Range");

    if(select_range->exec() == QDialog::Accepted) {

        float x_low, x_high, y_low, y_high, z_low, z_high;
        select_range->getData(&x_low, &x_high, &y_low, &y_high, &z_low, &z_high);



        pcl::ConditionAnd<pcl::PointXYZ>::Ptr range_cond (new pcl::ConditionAnd<pcl::PointXYZ> ());
        if(x_low != 9999) {
            range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr
                                       (new pcl::FieldComparison<pcl::PointXYZ> ("x", pcl::ComparisonOps::GT, x_low)));
            range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr
                                       (new pcl::FieldComparison<pcl::PointXYZ> ("x", pcl::ComparisonOps::LT, x_high)));
        }

        if(y_low != 9999) {
            range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr
                                       (new pcl::FieldComparison<pcl::PointXYZ> ("y", pcl::ComparisonOps::GT, y_low)));
            range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr
                                       (new pcl::FieldComparison<pcl::PointXYZ> ("y", pcl::ComparisonOps::LT, y_high)));
        }

        if(z_low != 9999) {
            range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr
                                       (new pcl::FieldComparison<pcl::PointXYZ> ("z", pcl::ComparisonOps::GT, z_low)));
            range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr
                                       (new pcl::FieldComparison<pcl::PointXYZ> ("z", pcl::ComparisonOps::LT, z_high)));
        }
        // build the filter
        pcl::ConditionalRemoval<pcl::PointXYZ> condrem;
        condrem.setCondition (range_cond);
        if(cloud->size() == 0)
            return;
        condrem.setInputCloud (simplifycloud);
        condrem.setKeepOrganized(true);
        // apply filter
        condrem.filter (*simplifycloud);
        viewer->removePointCloud("cloud");
        viewer->addPointCloud(simplifycloud, "cloud");
        ui->qvtkWidget->update();
    }
    delete select_range;
}


void PCLViewer::ResetPointcloud()
{
    ui->qvtkWidget->GetRenderWindow()->RemoveRenderer(renderer);

    //viewer->removePolygonMesh("SmoothMesh");
    viewer->removePointCloud("normals");
    if(viewer->removePolygonMesh("chongjian"));
        viewer->removePointCloud("cloud");
    std::cout<<"qingkong"<<std::endl;
    //smoothMesh.reset(new pcl::PolygonMesh);
    mesh.reset(new pcl::PolygonMesh);
    //mesh.reset();
    //viewer->addPointCloud(cloud);
    simplifycloud.reset(new PointCloudT);



    //memcpy()
    pcl::copyPointCloud(*cloud, *simplifycloud);
    viewer->addPointCloud(simplifycloud);
    viewer->resetCamera();
    int points_number = simplifycloud->size();
    ui->PointsNumber->display(points_number);
    ui->qvtkWidget->update();
    ui->KtreeSlider->setValue(0);
    ui->lcdNumber->display(ui->KtreeSlider->value());
    //ui->PointsNumber->display(simplifycloud->size());
}

/*jiang duobianxing wangge yong mian de xingshi xian
 * shi chu lai
 */
void PCLViewer::CurvesurfaceReform()
{
   // viewer->removePolygonMesh("chongjian");
    // dispaly surface
    viewer->setRepresentationToSurfaceForAllActors();
    ui->qvtkWidget->update();
    std::cout<<"qumianchongjian"<<std::endl;

}

void PCLViewer::openFileSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());
    if (fileName.isEmpty())
    {
        QMessageBox::information(this, "Error Message", "Please select file");
        return;
    }
    std::cout << fileName.toStdString() <<std::endl;

    std::string fileAbsolutPath = fileName.toStdString();     //put Qstring convert to string
    char* inputfile = (char*) fileAbsolutPath.data();      //put string convert to char*
    char cloudFileName[120];
    reverseFormatFile(inputfile, cloudFileName);

    time_info += "Point Cloud load takes ";        //record load file take how much time;
    time.restart();

    ui->progressBar->setVisible(true);
    static_thread->start();
    static_thread->cal_flag = 5;
    // load pointcloud
    /*
    pcl::io::loadPCDFile(cloudFileName, *cloud);
    //simplifycloud = cloud;
    pcl::io::loadPCDFile(cloudFileName, *simplifycloud);
    */

    emit trans_filepath(cloudFileName);
}

void PCLViewer::saveFileSlot()
{
    if(!simplifycloud->size()) {
        QMessageBox::information(this, "Error Message",
                                 "This Is a Empty Point Cloud can't Save");
        return;
    }

   QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QDir::currentPath());
   if(fileName.isNull()) {
       return;
   }
   const char* savefile = fileName.toStdString().data();
   pcl::io::savePCDFile(savefile, *simplifycloud);
}

void PCLViewer::displayPointCloud()
{
    ui->progressBar->setVisible(false);
    if(cloud->points.size() > 0) {
        viewer->removePointCloud();
        ui->qvtkWidget->update();
    }
    //viewer->removePointCloud();
    viewer->addPointCloud(simplifycloud);
    //viewer->addCoordinateSystem(1.0);
    //pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal);
    //pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals(new pcl::PointCloud<pcl::PointNormal>);
    //cloud_with_normals = calculate_normal(simplifycloud);
    //viewer->addPointCloudNormals(cloud_with_normals, 10, 0.02, "normal");

    //viewer->addPointCloudNormals<pcl::PointXYZ, pcl::Normal>(simplifycloud, normals, 10, 0.05, "normals");
    //viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_FONT_SIZE, 3);
    cout << simplifycloud->size() << endl;
    viewer->resetCamera();
    ui->qvtkWidget->update();

    int number = simplifycloud->size();
    ui->PointsNumber->display(number);
    int ms_time = time.elapsed();
    //std::cout << mintue << "ms\n";
    //qDebug() << time.elapsed() << "ms";
   // ui->progressBar->setVisible(true);
    QString info;
    info.sprintf("%d ms\n", ms_time);
    time_info += info;
    ui->textBrowser->append(time_info);
    time_info.clear();


}

void PCLViewer::dispalyMesh()
{
    viewer->removePointCloud();
    viewer->addPolygonMesh(*mesh, "chongjian");
    ui->progressBar->setVisible(false);
    viewer->setRepresentationToWireframeForAllActors();    //display triangular mesh
    viewer->resetCamera();
    ui->qvtkWidget->update();

    int ms_time = time.elapsed();
    QString info;
    info.sprintf("%d ms\n", ms_time);
    time_info += info;
    ui->textBrowser->append(time_info);
    time_info.clear();
}

void PCLViewer::clearCloudSlot()
{
    viewer->removePointCloud("normals");

    if(!viewer->removePolygonMesh("chongjian"))
        viewer->removePointCloud("cloud");

    mesh.reset(new pcl::PolygonMesh);
    simplifycloud.reset(new PointCloudT);
    cloud.reset(new PointCloudT);
    //viewer->removeCoordinateSystem();
    viewer->resetCamera();
    ui->qvtkWidget->update();

    ui->PointsNumber->display(0);


   // std::cout<<viewer->removeAllShapes() << "sfsf" << std::end;;
    /*
    std::cout << viewer->removePolygonMesh("chongjian") << "dddd" << std::endl;
    viewer->resetCamera();
    ui->qvtkWidget->update();
    /*
    if(cloud->points.size() > 0)      //
    {
        //cloud.reset(new PointCloudT);        // reset pointcloud
        //viewer->addPointCloud(cloud, "cloud");
        viewer->removePointCloud();
        viewer->resetCamera();
        ui->qvtkWidget->update();
    }
    */
}
/*
void PCLViewer::openKinect() {
    std::cout << "open kinect" << std::endl;
    if(cloud->size() > 0){
        viewer->removePointCloud();
        ui->qvtkWidget->update();
    }

    //viewer->initCameraParameters();
    //viewer->

    interface = new pcl::OpenNIGrabber();
    boost::function<void(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr&)> show_cloud =
            boost::bind(&PCLViewer::showCloudKinectStream, this, _1);
    interface->registerCallback(show_cloud);
    //interface->start();
    //OpenContrlKinect *contrl_widget = new OpenContrlKinect;
    //contrl_widget->exec();
    dynamic_thread->start();

}
*/
void PCLViewer::showCloudKinectStream(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud) {

    /*
    std::cout << pthread_self() << "11111111" << std::endl;
    ui->qvtkWidget->update();
    usleep(1000000);
    viewer->removePointCloud();
    */
        viewer->removePointCloud();

        viewer->addPointCloud(cloud);
        std::cout << "dispaly" << std::endl;
        ui->qvtkWidget->update();
        boost::this_thread::sleep (boost::posix_time::seconds (1));

}

void PCLViewer::displayPointXYZ_Cloud()
{
    std::cout << "displayPointXYZ_Cloud" << std::endl;
    char *argvec[] = {NULL};
    char *envvec[2] = {"DISPLAY=:0.0", NULL};
    pid_t xyzpointcloud;
    xyzpointcloud = fork();
    if(xyzpointcloud == 0) {
        execve("../XYZPointCloud/openni_xyzpointcloud", argvec, envvec);
        //std::cout << execve("./openni_xyzpointcloud", argvec, envvec) << std::endl;
    }
    else if(xyzpointcloud < 0) {
        printf("creat child progress error\n");
        return;
    }
    else {
        wait(NULL);
    }

}

void PCLViewer::displayPointXYZRGB_Cloud()
{

    std::cout << "displayPointXYZRGB_Cloud" << std::endl;
    char *argvec[] = {NULL};
    char *envvec[2] = {"DISPLAY=:0.0", NULL};
    pid_t rgbpointcloud;
    rgbpointcloud = fork();
    if(rgbpointcloud == 0) {
        execve("../RGBPointCloud/openni_rgbpointcloud", argvec, envvec);
    }
    else if(rgbpointcloud < 0) {
        printf("creat child progress error\n");
        return;
    }
    else {
        wait(NULL);
    }
}

void PCLViewer::displayPointCloudRealTime()
{
    std::cout << "displayPointCloudRealTime" << std::endl;
    RealTimeDialog *realtime = new RealTimeDialog;
    realtime->exec();

    char *argvec[] = {NULL};
    char *envvec[2] = {"DISPLAY=:0.0", NULL};
    pid_t realtime_pid;
    realtime_pid = fork();
    if(realtime_pid == 0) {
        execve("../RealTime/openni_realtime", argvec, envvec);
    }
    else if(realtime_pid < 0) {
        printf("creat child progress error\n");
        return;
    }
    else {
        wait(NULL);
    }

}

void PCLViewer::show_coordinate()
{
    if(coordinate_isexit){
        viewer->removeCoordinateSystem();
        coordinate_isexit = false;
        ui->qvtkWidget->update();
        //std::cout << "yichu" << std::endl;
    } else{
        viewer->addCoordinateSystem(20.0);
        coordinate_isexit = true;
        ui->qvtkWidget->update();
    }

}

void PCLViewer::show_operateDockWidget()
{
    if(operateDockWidget_isexit){
        ui->ShowDockWidget->setVisible(false);
        ui->OperateDockWidget->setVisible(false);
        operateDockWidget_isexit = false;
    } else {
        ui->ShowDockWidget->setVisible(true);
        ui->OperateDockWidget->setVisible(true);
        operateDockWidget_isexit = true;
    }

}

void PCLViewer::show_configureDockWidget()
{
    if(configureDockWidget_isexit) {
        ui->ConfigurDockWidget->setVisible(false);
        configureDockWidget_isexit = false;
    } else {
        ui->ConfigurDockWidget->setVisible(true);
        configureDockWidget_isexit = true;
    }

}

void PCLViewer::set_background_color()
{
    double red = ui->Slider_Backgroud_R->value() / 255.0;
    double green = ui->Slider_Background_G->value() / 255.0;
    double blue = ui->Slide_Background_B->value() / 255.0;
    viewer->setBackgroundColor(red, green, blue);
    ui->qvtkWidget->update();
}





/***********************MlsDialog****************************/

MlsDialog::MlsDialog(QWidget *parent) :
    QDialog(parent) {
    label_1 = new QLabel(tr("search radius"));
    line_1 = new QLineEdit;
    line_1->setAlignment(Qt::AlignRight);
    line_1->setText("5.00");
    buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    QHBoxLayout *box = new QHBoxLayout;
    box->addWidget(label_1);
    box->addWidget(line_1);
    QVBoxLayout *box_1 = new QVBoxLayout;
    box_1->addLayout(box);
    box_1->addWidget(buttonbox);
    setLayout(box_1);
    connect(buttonbox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonbox, SIGNAL(rejected()), this, SLOT(reject()));
}

MlsDialog::~MlsDialog() {}

/***********************DownSampingDialog************************/

DownSampingDialog::DownSampingDialog(QWidget *parent) :
    QDialog(parent) {
    label_1 = new QLabel(tr("LeafSize"));
    line_1 = new QLineEdit;
    line_1->setAlignment(Qt::AlignRight);
    line_1->setText("1.50");
    buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    QHBoxLayout *box = new QHBoxLayout;
    box->addWidget(label_1);
    box->addWidget(line_1);
    QVBoxLayout *box_1 = new QVBoxLayout;
    box_1->addLayout(box);
    box_1->addWidget(buttonbox);
    setLayout(box_1);
    connect(buttonbox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonbox, SIGNAL(rejected()), this, SLOT(reject()));
}

DownSampingDialog::~DownSampingDialog() {}

/******************************Triangulation**********************/
Triangulation::Triangulation(QWidget *parent) :
    QDialog(parent) {
    label_1 = new QLabel(tr("maxp2plength:"));
    line_1 = new QLineEdit;
    line_1->setAlignment(Qt::AlignRight);
    line_1->setText("2.50");
    label_2 = new QLabel(tr("maxsearchRidius:"));
    line_2 = new QLineEdit;
    line_2->setAlignment(Qt::AlignRight);
    line_2->setText("4.00");

    label_3 = new QLabel(tr("maxAngle:"));
    line_3 = new QLineEdit;
    line_3->setAlignment(Qt::AlignRight);
    line_3->setText("120");

    label_4 = new QLabel(tr("minAngle"));
    line_4 = new QLineEdit;
    line_4->setAlignment(Qt::AlignRight);
    line_4->setText("20");

    QVBoxLayout *box = new QVBoxLayout;
    box->addWidget(label_1);
    box->addWidget(line_1);
    box->addWidget(label_2);
    box->addWidget(line_2);
    box->addWidget(label_3);
    box->addWidget(line_3);
    box->addWidget(label_4);
    box->addWidget(line_4);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(
                QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    box->addWidget(buttonBox);
    setLayout(box);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

Triangulation::~Triangulation() {}
/*
void Triangulation getData(double *maxp2plength, double *searchradius) {

}
*/


/***********control kinect dock widget ****/
OpenContrlKinect::OpenContrlKinect(QWidget *parent) :
    QDockWidget(parent) {
    start = new QPushButton(tr("Start"));
    end = new QPushButton(tr("End"));
    QVBoxLayout *control_box = new QVBoxLayout;
    control_box->addWidget(start);
    control_box->addWidget(end);
}


/************select cloud range dialog ******/

CloudRangeDialog::CloudRangeDialog(QWidget *parent):
    QDialog(parent)
{
    /*
    label_x1.setText("X: ");
    label_y1.setText("Y: ");
    label_z1.setText("Z: ");

    label_x2.setText("--");
    label_y2.setText("--");
    label_z2.setText("--");
    QPushButton p1;
    QHBoxLayout line1;
    line1.addWidget(&label_x1);
    line1.addWidget(&X1);
    line1.addWidget(&label_x2);
    line1.addWidget(&X2);
    //line1.addWidget(&p1);
    QLabel* qq = new QLabel(tr("hhh"));
    line1.addWidget(qq);
    setLayout(&line1);
    */
    X1 = new QLineEdit;
    X2 = new QLineEdit;
    Y1 = new QLineEdit;
    Y2 = new QLineEdit;
    Z1 = new QLineEdit;
    Z2 = new QLineEdit;
    X1->setAlignment(Qt::AlignRight);
    X2->setAlignment(Qt::AlignRight);
    Y1->setAlignment(Qt::AlignRight);
    Y2->setAlignment(Qt::AlignRight);
    Z1->setAlignment(Qt::AlignRight);
    Z2->setAlignment(Qt::AlignRight);


    X1->setText("NAN");
    X2->setText("NAN");
    Y1->setText("NAN");
    Y2->setText("NAN");
    Z1->setText("NAN");
    Z2->setText("NAN");


    QLabel* label_x = new QLabel(tr("X: "));
    QLabel* label_y = new QLabel(tr("Y: "));
    QLabel* label_z = new QLabel(tr("Z: "));

    QLabel* x_x = new QLabel(tr("--"));
    QLabel* y_y = new QLabel(tr("--"));
    QLabel* z_z = new QLabel(tr("--"));

    QHBoxLayout* line1 = new QHBoxLayout;
    QHBoxLayout* line2 = new QHBoxLayout;
    QHBoxLayout* line3 = new QHBoxLayout;

    line1->addWidget(label_x);
    line1->addWidget(X1);
    line1->addWidget(x_x);
    line1->addWidget(X2);

    line2->addWidget(label_y);
    line2->addWidget(Y1);
    line2->addWidget(y_y);
    line2->addWidget(Y2);

    line3->addWidget(label_z);
    line3->addWidget(Z1);
    line3->addWidget(z_z);
    line3->addWidget(Z2);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(
                QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *ll = new QVBoxLayout;


    ll->addLayout(line1);
    ll->addLayout(line2);
    ll->addLayout(line3);
    ll->addWidget(buttonBox);

    setLayout(ll);

}

CloudRangeDialog::~CloudRangeDialog()
{

}

void CloudRangeDialog::getData(float *x_low, float *x_high, float *y_low, float *y_high, float *z_low, float *z_high)
{
    if(X1->text() == "NAN" || X2->text() == "NAN"){
        *x_low = 9999;
        *x_high = 9999;
    } else {
        *x_low = X1->text().toFloat();
        *x_high = X2->text().toFloat();
    }

    if(Y1->text() == "NAN" || Y2->text() == "NAN"){
        *y_low = 9999;
        *y_high = 9999;
    } else {
        *y_low = Y1->text().toFloat();
        *y_high = Y2->text().toFloat();
    }

    if(Z1->text() == "NAN" || Z2->text() == "NAN"){
        *z_low = 9999;
        *z_high = 9999;
    } else {
        *z_low = Z1->text().toFloat();
        *z_high = Z2->text().toFloat();
    }
}

/**********************RealTime Dialog **************/

RealTimeDialog::RealTimeDialog(QWidget *parent)
{
    QVBoxLayout *ll = new QVBoxLayout;
    QDialogButtonBox *buttonBox = new QDialogButtonBox(
                QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    ll->addWidget(buttonBox);

    setLayout(ll);
}

RealTimeDialog::~RealTimeDialog()
{

}
