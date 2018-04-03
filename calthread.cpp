//
// Created by huangliang on 17-12-13.
//

#include "calthread.h"
#include "pretreatment.h"
#include "greedy_triangulation.h"


CalStaticThread::CalStaticThread() : cal_flag(0),
    mls_radius(1.0), downsample_leaf_size(1.0) {
    max_p2p_length = 1.0;
    reconstruct_searchradius = 1.0;
}

void CalStaticThread::run()
{
    if(cal_flag == 1) {
        pcl::io::loadPCDFile(cloudfilepath, *cloud);
        pcl::io::loadPCDFile(cloudfilepath, *simplifycloud);
        std::cout << "load file" << std::endl;
        emit finishLoadFile(true);
        return;
    }

    else if(cal_flag == 2) {
        // point cloud mls process
        PreTreatment process;
        process.mls(simplifycloud, mls_radius);
        //process.downSamping(simplifycloud, downsample_leaf_size);
        std::cout << "mls mls" << std::endl;
        emit finish_mls(true);
        return;
        }
    else if(cal_flag == 3) {
        // point cloud downsample process
        PreTreatment process1;
        process1.downSamping(simplifycloud, downsample_leaf_size);
        std::cout << "down sample" << std::endl;
        emit finish_downSample(true);
        return;
    }

    else if(cal_flag == 4) {
        *mesh = rebuild(simplifycloud, max_p2p_length, reconstruct_searchradius);
        std::cout << "())))" << std::endl;
        emit finish_reconstruct(true);
        return;
    }
}

void CalStaticThread::receivers(char *getcloudfilepath)
{
   // pcl::io::loadPCDFile(getcloudfilepath, *cloud);
    //simplifycloud = cloud;
   // pcl::io::loadPCDFile(getcloudfilepath, *simplifycloud);
    //cal_flag = INPUT;
    strcpy(cloudfilepath, getcloudfilepath);
    cal_flag = 1;
}

void CalStaticThread::recv_mls_signal(double radius)
{
    cal_flag = 2;
    mls_radius = radius;
    std::cout << radius << std::endl;

}

void CalStaticThread::recv_downSample_signal(double leafsize)
{
    cal_flag = 3;
    downsample_leaf_size = leafsize;
    std::cout << leafsize << std::endl;
}

void CalStaticThread::recv_reconstruct(double maxp2plength, double searchradius)
{
    cal_flag = 4;
    max_p2p_length = maxp2plength;
    reconstruct_searchradius = searchradius;
}



DynamicThread::DynamicThread()
{

}

DynamicThread::~DynamicThread() {
}

void DynamicThread::run()
{

    /*
    interface = new pcl::OpenNIGrabber();
    boost::function<void(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr&)> show_cloud =
            boost::bind(&PCLViewer::showCloudKinectStream, this, _1);
    interface->registerCallback(show_cloud);
    */
    interface->start();
    std::cout << pthread_self() << "^^^^^^^\n";
    while(true) {
        std::cout << pthread_self() << "%%%%%%%\n";
        //usleep(100000);
        boost::this_thread::sleep (boost::posix_time::seconds (1));
    }

}


