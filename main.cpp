#include "pclviewer.h"
#include <QApplication>

#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/io/openni_grabber.h>
#include <iostream>

//pcl::visualization::PCLVisualizer::Ptr viewer;
PointCloudT::Ptr cloud, simplifycloud;
pcl::PolygonMesh::Ptr mesh, smoothMesh;

/*openni interface*/
pcl::Grabber *interface;
/*
void pp_callback(const pcl::visualization::PointPickingEvent& event, void* args)
{
    //struct callback_args* data = (struct callback_args *)args;
    if (event.getPointIndex() == -1) {
        viewer->removePointCloud("clicked_points");
        return;
    }
    PointT current_point;
    PointCloudT::Ptr clicked_point(new PointCloudT);
    event.getPoint(current_point.x, current_point.y, current_point.z);
    clicked_point->points.push_back(current_point);
    // Draw clicked points in red:
    pcl::visualization::PointCloudColorHandlerCustom<PointT> red(clicked_point, 255, 0, 0);
    viewer->removePointCloud("clicked_points");
    viewer->addPointCloud(clicked_point, red, "clicked_points");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "clicked_points");
    std::cout << current_point.x << " " << current_point.y << " " << current_point.z << std::endl;
}
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*data initial*/
    mesh.reset(new pcl::PolygonMesh);
    smoothMesh.reset(new pcl::PolygonMesh);
    //viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
    //viewer->registerPointPickingCallback(pp_callback, NULL);
    cloud.reset(new PointCloudT);
    simplifycloud.reset(new PointCloudT);

    PCLViewer w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
