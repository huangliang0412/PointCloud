#ifndef GREEDY_TRIANGULATION_H
#define GREEDY_TRIANGULATION_H

#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/surface/poisson.h>
#include <pcl/visualization/pcl_visualizer.h>

#include <pcl/surface/mls.h>
//calculate each point of this cloudpoints normal vector
pcl::PointCloud<pcl::PointNormal>::Ptr calculate_normal(pcl::PointCloud<pcl::PointXYZ>::Ptr &);

//mesh reconstruct algorithm
pcl::PolygonMesh reconstruct_mesh(pcl::PointCloud<pcl::PointNormal>::Ptr, double, double);
pcl::PolygonMesh reconstruct_mesh1(pcl::PointCloud<pcl::PointNormal>::Ptr, double, double);

pcl::PolygonMesh rebuild(pcl::PointCloud<pcl::PointXYZ>::Ptr &, double, double);
#endif // GREEDY_TRIANGULATION_H
