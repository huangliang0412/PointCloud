#ifndef PRETREATMENT_H
#define PRETREATMENT_H

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/kdtree/flann.h>
#include <pcl/surface/mls.h>

//class PreTreatment {
//public:
    pcl::PointCloud<pcl::PointXYZ>::Ptr mls(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& cloud, float mls_search_radius);
    pcl::PointCloud<pcl::PointXYZ>::Ptr downSamping(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& cloud, float downSamping_K);
/*
private:
    float mls_search_radius;
    float downSamping_K;
*/
//};

#endif // PRETREATMENT_H
