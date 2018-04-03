#include <pcl/io/openni_grabber.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>

class SimpleOpenNIViewer
{
public:
    //SimpleOpenNIViewer () : viewer ("PCL OpenNI Viewer") {}
    SimpleOpenNIViewer () : viewer(new pcl::visualization::PCLVisualizer("Point Cloud")) {
    	 viewer->setCameraPosition(0, 0, -2, 0, -1, 0, 0); 
    }
    void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr &cloud)
    {
        if (!viewer->wasStopped()) {
            viewer->addPointCloud(cloud);
            viewer->spinOnce();
            viewer->removePointCloud();
        }
    }

    void run ()
    {
        pcl::Grabber* interface = new pcl::OpenNIGrabber();

        boost::function<void (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&)> f =
                boost::bind (&SimpleOpenNIViewer::cloud_cb_, this, _1);

        interface->registerCallback (f);

        interface->start ();

        while (!viewer->wasStopped())
        {
            //boost::this_thread::sleep (boost::posix_time::seconds (1));
            //viewer->spinOnce();
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
