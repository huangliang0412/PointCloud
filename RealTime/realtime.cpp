#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/visualization/cloud_viewer.h>

#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/conditional_removal.h>

#include <pcl/visualization/pcl_visualizer.h>

#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>

#include "pretreatment.h"



int i = 0;
class SimpleOpenNIViewer
{
public:
    SimpleOpenNIViewer () : viewer(new pcl::visualization::PCLVisualizer("3D")) 
	{
		viewer->setCameraPosition(0, 0, -2, -1, 0, 0);
	}

    void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud)
    {

        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
        //pcl::io::loadPCDFile("/home/huangliang/finish.pcd", *cloud);
        pcl::ConditionAnd<pcl::PointXYZ>::Ptr range_cond (new pcl::ConditionAnd<pcl::PointXYZ> ());
        range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr (new pcl::FieldComparison<pcl::PointXYZ> ("z", pcl::ComparisonOps::GT, 0.0)));
        range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr (new pcl::FieldComparison<pcl::PointXYZ> ("z", pcl::ComparisonOps::LT, 0.8)));
// build the filter
        pcl::ConditionalRemoval<pcl::PointXYZ> condrem;
        condrem.setCondition (range_cond);
        if(cloud->size() == 0)
            return;
        condrem.setInputCloud (cloud);
        condrem.setKeepOrganized(true);
// apply filter
        condrem.filter (*cloud_filtered);

        std::vector<int> mapping;
        pcl::removeNaNFromPointCloud(*cloud_filtered, *cloud_filtered, mapping);

        std::cout << cloud_filtered->size() << std::endl;

        pcl::PointCloud<pcl::PointXYZ>::Ptr smooth_cloud(new pcl::PointCloud<pcl::PointXYZ>);
        std::cout << "mlsmksmls" << std::endl;
        smooth_cloud = mls(cloud_filtered, 0.01);
        std::cout << "finishsd" << std::endl;
        ++i;
        std::cout << i << std::endl;
        if(i == 100) {
            pcl::io::savePCDFile("test_pcd.pcd", *cloud_filtered);
            std::cout << "complete" << std::endl;
            //sleep(1);
            //exit(0);
        }

        pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;
        pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
        pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
        tree->setInputCloud (smooth_cloud);
        n.setInputCloud (smooth_cloud);
        n.setSearchMethod (tree);
        n.setKSearch (20);
        n.compute (*normals);
        //* normals should not contain the point normals + surface curvatures

        // Concatenate the XYZ and normal fields*
        pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
        pcl::concatenateFields (*smooth_cloud, *normals, *cloud_with_normals);
        //* cloud_with_normals = cloud + normals

        // Create search tree*
        pcl::search::KdTree<pcl::PointNormal>::Ptr tree2 (new pcl::search::KdTree<pcl::PointNormal>);
        tree2->setInputCloud (cloud_with_normals);

        // Initialize objects
        pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
        pcl::PolygonMesh triangles;

        // Set the maximum distance between connected points (maximum edge length)
        gp3.setSearchRadius (4);

        // Set typical values for the parameters
        gp3.setMu (3);
        gp3.setMaximumNearestNeighbors (20);
        gp3.setMaximumSurfaceAngle(M_PI/4); // 45 degrees
        gp3.setMinimumAngle(M_PI/18); // 10 degrees
        gp3.setMaximumAngle(2*M_PI/3); // 120 degrees
        gp3.setNormalConsistency(false);

        // Get result
        gp3.setInputCloud (cloud_with_normals);
        gp3.setSearchMethod (tree2);
        gp3.reconstruct (triangles);


        viewer->addPolygonMesh(triangles, "chongjain");
        viewer->setRepresentationToSurfaceForAllActors();
        //viewer->initCameraParameters();
 	viewer->setCameraPosition(0, 0, -2, 0, -1, 0, 0); 
        viewer->spinOnce();
        viewer->removePolygonMesh("chongjain");

       // if (!viewer.wasStopped())
          //  viewer.showCloud (smooth_cloud);
        //pcl::io::savePCDFile("hello.pcd", *cloud);
    }

    void run ()
    {
        pcl::Grabber* interface = new pcl::OpenNIGrabber();

        boost::function<void (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr&)> f =
                boost::bind (&SimpleOpenNIViewer::cloud_cb_, this, _1);

        interface->registerCallback (f);

        interface->start ();

        while (!viewer->wasStopped())
        {
            boost::this_thread::sleep (boost::posix_time::seconds (1));
        }

        interface->stop ();
    }

    //pcl::visualization::CloudViewer viewer;
    pcl::visualization::PCLVisualizer::Ptr viewer;
};

int main ()
{
    SimpleOpenNIViewer v;
    v.run ();
    return 0;
}
