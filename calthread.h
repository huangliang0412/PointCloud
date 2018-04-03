//
// Created by huangliang on 17-12-13.
//
//#pragma once
#ifndef PCL_VISUALIZER_CALTHREAD_H
#define PCL_VISUALIZER_CALTHREAD_H
//#include "pclviewer.h"

#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/openni_grabber.h>

#include <QThread>

#include <string.h>

//extern pcl::visualization::PCLVisualizer::Ptr viewer;
extern pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, simplifycloud;
extern pcl::PolygonMesh::Ptr mesh, smoothMesh;

extern pcl::Grabber *interface;

class CalStaticThread : public QThread {
    Q_OBJECT

public:
    CalStaticThread();
    void run();
    
    //enum cal_flag {INPUT, SIMPLY, CONSTRUCT, SURFACE, CLEAR};
    int cal_flag;

public slots:
    void receivers(char*);
    void recv_mls_signal(double);
    void recv_downSample_signal(double);
    void recv_reconstruct(double, double);

signals:
    void finishLoadFile(bool flag);
    void finish_mls(bool);
    void finish_downSample(bool);
    void finish_reconstruct(bool);

private:
    char cloudfilepath[150];     //save file path
    double mls_radius;
    double downsample_leaf_size;
    double max_p2p_length, reconstruct_searchradius;
};

class DynamicThread : public QThread {
    Q_OBJECT

public:
    DynamicThread();
    ~DynamicThread();
    void run();

};

#endif //PCL_VISUALIZER_CALTHREAD_H
