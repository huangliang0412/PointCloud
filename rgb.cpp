#include "rgb.h"
using namespace std;
void rgbreconstruct (vtkSmartPointer<vtkRenderer>& renderer) {
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr rgbcloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    FILE *fp = fopen("/home/huangliang/resource/xiyiye.txt", "r");
    if(fp == NULL) {
        std::cout << "open file error" << std::endl;
        return;
    }
    vector<vector<float> > arr(284705);
    for(int i = 0; i < 284705; ++i) {
        arr[i].resize(6);
    }
    int j = 0;
    while(!feof(fp)) {
        fscanf(fp, "%f %f %f %f %f %f", &arr[j][0], &arr[j][1], &arr[j][2], &arr[j][3], &arr[j][4], &arr[j][5]);
        ++j;
    }
   // for(int i = 0; i < arr.size(); ++i) {
        //for(int t = 0; t < 6; ++t)
    //        std::cout << arr[i][t] << " ";
    //}
    rgbcloud->resize(284705);
    cloud->resize(284705);
    for(int i = 0; i < 284705; ++i) {
        rgbcloud->points[i].x = arr[i][0];
        rgbcloud->points[i].y = arr[i][1];
        rgbcloud->points[i].z = arr[i][2];
        rgbcloud->points[i].b = arr[i][3];
        rgbcloud->points[i].g = arr[i][4];
        rgbcloud->points[i].r = arr[i][5];

        cloud->points[i].x = arr[i][0];
        cloud->points[i].y = arr[i][1];
        cloud->points[i].z = arr[i][2];
    }


    pcl::NormalEstimation <pcl::PointXYZ, pcl::Normal> n;//创建法向估计对象
    pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud <pcl::Normal>);//创建法向数据指针
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree <pcl::PointXYZ>);//创建kdtree用于法向计算时近邻搜索
    tree->setInputCloud(cloud);//为kdtree输入点云
    n.setInputCloud(cloud);//为法向估计对象输入点云
    n.setSearchMethod(tree);//设置法向估计时采用的搜索方式为kdtree
    n.setKSearch(20);//设置法向估计时,k近邻搜索的点数
    n.compute(*normals);  //进行法向估计

    std::cerr << "法线计算   完成" << std::endl;

    // 创建同时包含点和法向的数据结构的指针
    pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals(new pcl::PointCloud <pcl::PointNormal>);
    //将已获得的点数据和法向数据拼接
    pcl::concatenateFields(*cloud, *normals, *cloud_with_normals);

    // 创建另一个kdtree用于重建
    pcl::search::KdTree<pcl::PointNormal>::Ptr tree2(new pcl::search::KdTree <pcl::PointNormal>);
    //为kdtree输入点云数据,该点云数据类型为点和法向
    tree2->setInputCloud(cloud_with_normals);

    // 创建贪婪三角形投影重建对象
    pcl::GreedyProjectionTriangulation <pcl::PointNormal> gp3;
    //创建多边形网格对象,用来存储重建结果
    pcl::PolygonMesh triangles;

    //设置参数
    gp3.setSearchRadius(2.5);  // 设置连接点之间的最大距离（最大边长）用于确定k近邻的球半径（默认为0）
    gp3.setMu(4);  // 设置最近邻距离的乘子，已得到每个点的最终搜索半径（默认为0）
    gp3.setMaximumNearestNeighbors(50);  //设置搜索的最近邻点的最大数量
    gp3.setMaximumSurfaceAngle(M_PI / 2); // 45 degrees 最大平面角
    gp3.setMinimumAngle(M_PI / 18); // 10 degrees 每个三角的最大角度
    gp3.setMaximumAngle(2 * M_PI / 3); // 120 degrees
    gp3.setNormalConsistency(false);  //若法向量一致，设为true

    // 设置点云数据和搜索方式
    gp3.setInputCloud(cloud_with_normals);
    gp3.setSearchMethod(tree2);

    //开始重建
    gp3.reconstruct(triangles);

    std::cerr << "重建   完成" << std::endl;

    //将重建结果保存到硬盘文件中,重建结果以VTK格式存储
    pcl::io::saveVTKFile("mymesh.vtk", triangles);

    std::cout << cloud->size() << std::endl;
    std::cout << triangles.polygons.size() << std::endl;
    std::cout << triangles.cloud.data.size() << "size: " << std::endl;
    //pcl::fromPCLPointCloud2()
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1 (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(triangles.cloud, *cloud1);

    std::cout << cloud1->size() << std::endl;

    vtkSmartPointer<vtkPoints> points =
            vtkSmartPointer<vtkPoints>::New();
    cout << cloud->at(0) << endl;
    cout << cloud->at(0).x << endl;
    cout << triangles.polygons.at(0) << endl;
    for (int i = 0; i < cloud->size(); ++i) {
        points->InsertNextPoint(cloud->at(i).x, cloud->at(i).y, cloud->at(i).z);
    }

    std::set<int> record_index;

    vtkSmartPointer<vtkCellArray> cells =
            vtkSmartPointer<vtkCellArray>::New();

    for (int i = 0; i < triangles.polygons.size(); ++i) {
        vtkSmartPointer<vtkTriangle> sanjiao =
                vtkSmartPointer<vtkTriangle>::New();
        int id1, id2, id3;
        id1 = triangles.polygons.at(i).vertices[0];
        id2 = triangles.polygons.at(i).vertices[1];
        id3 = triangles.polygons.at(i).vertices[2];

        record_index.insert(id1);
        record_index.insert(id2);
        record_index.insert(id3);

        sanjiao->GetPointIds()->SetId(0, id1);
        sanjiao->GetPointIds()->SetId(1, id2);
        sanjiao->GetPointIds()->SetId(2, id3);
        cells->InsertNextCell(sanjiao);

    }
    std::cout << "record_index " << record_index.size() << std::endl;

    for(int j = 0; j < cloud->size(); ++j) {
        if(record_index.find(j) == record_index.end()){
            //points->InsertPoint(j, 0, 0, 0);
            // points->SetPoint(j, 0, 0, 0);
        }
    }
    //points->

    vtkSmartPointer<vtkPolyData> polydata =
            vtkSmartPointer<vtkPolyData>::New();
    polydata->SetPoints(points);
    polydata->SetPolys(cells);



    unsigned char red[3] = {255, 0, 0};
    unsigned char green[3] = {0, 255, 0};
    unsigned char blue[3] = {0, 0, 255};

    vtkSmartPointer<vtkUnsignedCharArray> pointColors =
            vtkSmartPointer<vtkUnsignedCharArray>::New();
    pointColors->SetNumberOfComponents(3);
    for (int i = 0; i < cloud->size(); ++i) {
        unsigned char pcolor[3];
        pcolor[0] = arr[i][5];
        pcolor[1] = arr[i][4];
        pcolor[2] = arr[i][3];

        pointColors->InsertTupleValue(i, pcolor);
        /*
        if (i % 3 == 0)
            pointColors->InsertTupleValue(i, red);
        if (i % 3 == 1)
            pointColors->InsertTupleValue(i, green);
        if (i % 3 == 2)
            pointColors->InsertTupleValue(i, blue);
            */
    }
    polydata->GetPointData()->SetScalars(pointColors);

    vtkSmartPointer<vtkPolyDataMapper> mapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
    //mapper->SetInput(subdivisionFilter->GetOutput());
    mapper->SetInput(polydata);

    //mapper->SetInput(polydata);
    //mapper->SetInput(smoothFilter->GetOutput());

    vtkSmartPointer<vtkActor> actor =
            vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

   // vtkSmartPointer<vtkRenderer> renderer =
         //   vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);
    renderer->SetBackground(0.1, 0.1, 0.3);

    /*
    vtkSmartPointer<vtkRenderWindow> renderWindow =
            vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    renderWindow->SetSize(640, 480);
    //renderWindow->Render();


    vtkSmartPointer<vtkRenderWindowInteractor> iter =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    iter->SetRenderWindow(renderWindow);

   renderWindow->Render();
    iter->Start();

  //  return 0;
  */
    /*
    pcl::visualization::PCLVisualizer::Ptr viewer(new pcl::visualization::PCLVisualizer);
    viewer->addPointCloud(rgbcloud);
    pcl::io::savePCDFile("/home/huangliang/xiyiye.pcd", *cloud);
    while(!viewer->wasStopped()) {
        viewer->spinOnce();
    }
     */
}
