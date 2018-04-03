#include "greedy_triangulation.h"
#include <iostream>
#include <pcl/io/vtk_io.h>
#include <pcl/surface/processing.h>
#include <pcl/surface/vtk_smoothing/vtk_mesh_subdivision.h>
#include <pcl/surface/vtk_smoothing/vtk.h>

using namespace pcl;

/*calculate every points of cloudpoint normal vector*/

PointCloud<PointNormal>::Ptr calculate_normal(PointCloud<PointXYZ>::Ptr &cloud)
{
    NormalEstimation<PointXYZ, Normal> ne;
    PointCloud<Normal>::Ptr normals(new PointCloud<Normal>);
    search::KdTree<PointXYZ>::Ptr tree(new search::KdTree<PointXYZ>);

    tree->setInputCloud(cloud);
    ne.setInputCloud(cloud);
    ne.setSearchMethod(tree);
    ne.setKSearch(20);
    ne.compute(*normals);       //calculate normal vector

    PointCloud<PointNormal>::Ptr cloud_with_normals(new PointCloud<PointNormal>);
    //combine normal vectors with points
    concatenateFields(*cloud, *normals, *cloud_with_normals);
    return cloud_with_normals;


}

/*
PointCloud<PointNormal>::Ptr calculate_normal(PointCloud<PointXYZ>::Ptr &cloud)
{
    PointCloud<PointNormal>::Ptr mlsNormal;
    search::KdTree<PointXYZ>::Ptr tree(new search::KdTree<PointXYZ>);
    MovingLeastSquares<PointXYZ, PointNormal> mls;
    std::cout << "11111"<<std::endl;
    mls.setUpsamplingMethod();
    mls.setComputeNormals(true);
    mls.setInputCloud(cloud);
    mls.setSearchMethod(tree);

    std::cout << "2222"<<std::endl;
    mls.setSearchRadius(0.03);
    mls.process(*mlsNormal);
    std::cout << "333" << std::endl;

    return mlsNormal;
}
*/

PolygonMesh reconstruct_mesh(pcl::PointCloud<pcl::PointNormal>::Ptr cloud_normals,
                             double maxp2plength, double searchradius)
{
    search::KdTree<PointNormal>::Ptr tree2(new search::KdTree<PointNormal>);

    tree2->setInputCloud(cloud_normals);

    //use greedy triangulation algrithom reconstruct
    GreedyProjectionTriangulation<PointNormal> gp3;

    //build polygonmesh
    PolygonMesh triangles;

    //set the maximum distance between connected points (maximum edge length)
    //gp3.setSearchRadius(4);  //0.025
    gp3.setSearchRadius(searchradius);  //0.025

    //Set typical value for the parameters
    //gp3.setMu(2.5);
    gp3.setMu(maxp2plength);
    gp3.setMaximumNearestNeighbors(100);
    gp3.setMaximumSurfaceAngle(M_PI/4);   //45 degrees
    gp3.setMinimumAngle(M_PI/9);         //10 degrees
    gp3.setMaximumAngle(2*M_PI/3);        //120 degrees
    gp3.setNormalConsistency(false);

    /* Get result */
    gp3.setInputCloud (cloud_normals);
    gp3.setSearchMethod(tree2);
	gp3.reconstruct(triangles);
    pcl::io::saveVTKFile("mymesh.vtk", triangles);
    return triangles;
}

PolygonMesh reconstruct_mesh1(pcl::PointCloud<pcl::PointNormal>::Ptr cloud_normals,
                              double maxp2plength, double searchradius) {
    /*
    pcl::Poisson<pcl::PointNormal> poisson_reconstruct;
    pcl::PolygonMesh mesh;
    poisson_reconstruct.reconstruct(mesh);
    return mesh;
    */
    search::KdTree<PointNormal>::Ptr tree2(new search::KdTree<PointNormal>);
    tree2->setInputCloud(cloud_normals);

    Poisson<PointNormal> poisson_reconstruct;
    poisson_reconstruct.setConfidence(false);
    poisson_reconstruct.setDegree(2);
    poisson_reconstruct.setDepth(9);
    poisson_reconstruct.setIsoDivide(8);
    poisson_reconstruct.setManifold(false);
    poisson_reconstruct.setSolverDivide(8);
    poisson_reconstruct.setSamplesPerNode(3.0);
    poisson_reconstruct.setScale(1.25);
    poisson_reconstruct.setSearchMethod(tree2);
    poisson_reconstruct.setInputCloud(cloud_normals);
    PolygonMesh mesh;
    poisson_reconstruct.reconstruct(mesh);
    return mesh;
}

PolygonMesh rebuild(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud, double maxp2plength, double searchradius)
{
    PointCloud<PointNormal>::Ptr ne;
    ne = calculate_normal(cloud);
    PolygonMesh::Ptr mesh(new PolygonMesh);
    *mesh = reconstruct_mesh(ne, maxp2plength, searchradius);
    std::cout<<"construct"<<std::endl;


    return *mesh;
}

