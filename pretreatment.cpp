#include "pretreatment.h"
using namespace pcl;

//PreTreatment::PreTreatment() {

//}

void PreTreatment::mls(PointCloud<PointXYZ>::Ptr& cloud, float mls_search_radius) {
    //create a kd-tree
    search::KdTree<PointXYZ>::Ptr tree(new search::KdTree<PointXYZ>);

    PointCloud<PointXYZ> mls_points;
    MovingLeastSquares<PointXYZ, PointXYZ> mls;
    mls.setInputCloud(cloud);
    //mls.setPolynomialFit(true);
    mls.setSearchMethod(tree);
    //mls.setSearchRadius(5);
    mls.setSearchRadius(mls_search_radius);
    //mls.setUpsamplingMethod(pcl::MovingLeastSquares::UpsamplingMethod::VOXEL_GRID_DILATION);
    //std::cout << "method " << mls.VOXEL_GRID_DILATION << std::endl;

    //mls.setUpsamplingMethod(mls.VOXEL_GRID_DILATION);
    /*************************************/
    //mls.setUpsamplingMethod(mls.SAMPLE_LOCAL_PLANE);
    //mls.setUpsamplingRadius(1.2);
    //mls.setUpsamplingStepSize(0.4);
    /*
    mls.setUpsamplingMethod(mls.RANDOM_UNIFORM_DENSITY);
   // pcl::MovingLeastSquares::UpsamplingMethod::VOXEL_GRID_DILATION;
   // pcl::MovingLeastSquares::MLSVoxelGrid;
    //pcl::MovingLeastSquares::VOXEL_GRID_DILATION
    mls.setUpsamplingRadius(10);
    mls.setUpsamplingStepSize(10);
    mls.setDilationIterations(1000);
    mls.setDilationVoxelSize(0.005);
    */
    //mls.setComputeNormals(false);
    //mls.setUpsamplingMethod(mls.VOXEL_GRID_DILATION);
    //mls.setDilationVoxelSize(1);
    //mls.setDilationIterations(2);

    mls.process(mls_points);
    cloud->clear();
    *cloud = mls_points;
    //io::savePCDFile("mls.pcd", mls_points);
}

void PreTreatment::downSamping(PointCloud<PointXYZ>::Ptr &cloud, float downSamping_K) {
    PointCloud<PointXYZ>::Ptr filter_cloud(new PointCloud<PointXYZ>);
    VoxelGrid<PointXYZ> sor;
    sor.setInputCloud(cloud);
    //sor.setLeafSize(2.5f, 2.5f, 2.5f);
    sor.setLeafSize(downSamping_K, downSamping_K, downSamping_K);
    sor.filter(*filter_cloud);
    cloud->clear();
    cloud = filter_cloud;
}
