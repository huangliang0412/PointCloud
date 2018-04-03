#include "pretreatment.h"
using namespace pcl;

//PreTreatment::PreTreatment() {

//}

PointCloud<PointXYZ>::Ptr mls(const PointCloud<PointXYZ>::ConstPtr& cloud, float mls_search_radius) {
    //void mls(const PointCloud<PointXYZ>::ConstPtr& cloud, float mls_search_radius) {
    //create a kd-tree
    search::KdTree<PointXYZ>::Ptr tree(new search::KdTree<PointXYZ>);

    PointCloud<PointXYZ>::Ptr mls_points(new PointCloud<PointXYZ>);
    MovingLeastSquares<PointXYZ, PointXYZ> mls;
    mls.setInputCloud(cloud);
    mls.setComputeNormals(true);
    mls.setPolynomialFit(true);
    mls.setSearchMethod(tree);
    //mls.setSearchRadius(5);
    mls.setSearchRadius(mls_search_radius);
    //mls.setSearchRadius(mls_);

    //mls.setComputeNormals(false);
    //mls.setUpsamplingMethod(mls.VOXEL_GRID_DILATION);
    //mls.setDilationVoxelSize(1);
    //mls.setDilationIterations(2);
    std::cout << "---------" << std::endl;
    mls.process(*mls_points);
    //cloud->clear();
    //std::cout <<"dfffdff"<< std::endl;

    return mls_points;
    //*cloud = mls_points;
    //io::savePCDFile("mls.pcd", mls_points);
}

PointCloud<PointXYZ>::Ptr downSamping(const PointCloud<PointXYZ>::ConstPtr &cloud, float downSamping_K) {
    PointCloud<PointXYZ>::Ptr filter_cloud(new PointCloud<PointXYZ>);
    VoxelGrid<PointXYZ> sor;
    sor.setInputCloud(cloud);
    //sor.setLeafSize(df, 2.5f, 2.5f);
    sor.setLeafSize(downSamping_K, downSamping_K, downSamping_K);
    sor.filter(*filter_cloud);
    //cloud->clear();
    //cloud = filter_cloud;
    return filter_cloud;
}
