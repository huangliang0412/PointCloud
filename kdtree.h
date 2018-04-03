#ifndef KDTREE_H
#define KDTREE_H

#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <vector>

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

PointCloudT::Ptr KdTree(PointCloudT::Ptr &original_cloud, int K);

#endif // KDTREE_H
