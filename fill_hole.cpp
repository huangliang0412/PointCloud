#include "fill_hole.h"
#include <iostream>

void fillhole_triangle(pcl::PolygonMesh::Ptr triangles, vtkSmartPointer<vtkRenderer>& renderer) {

    std::cout << triangles->polygons.size() << std::endl;
    std::cout << triangles->cloud.data.size() << "size: " << std::endl;
    //pcl::fromPCLPointCloud2()
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(triangles->cloud, *cloud);

    std::cout << cloud->size() << std::endl;

    vtkSmartPointer<vtkPoints> points =
            vtkSmartPointer<vtkPoints>::New();
    cout << cloud->at(0) << endl;
    cout << cloud->at(0).x << endl;
    cout << triangles->polygons.at(0) << endl;
    for (int i = 0; i < cloud->size(); ++i) {
        points->InsertNextPoint(cloud->at(i).x, cloud->at(i).y, cloud->at(i).z);
    }

    //std::unordered_set<int> record_index;

    vtkSmartPointer<vtkCellArray> cells =
            vtkSmartPointer<vtkCellArray>::New();

    for (int i = 0; i < triangles->polygons.size(); ++i) {
        vtkSmartPointer<vtkTriangle> sanjiao =
                vtkSmartPointer<vtkTriangle>::New();
        int id1, id2, id3;
        id1 = triangles->polygons.at(i).vertices[0];
        id2 = triangles->polygons.at(i).vertices[1];
        id3 = triangles->polygons.at(i).vertices[2];


        sanjiao->GetPointIds()->SetId(0, id1);
        sanjiao->GetPointIds()->SetId(1, id2);
        sanjiao->GetPointIds()->SetId(2, id3);
        cells->InsertNextCell(sanjiao);

    }


    vtkSmartPointer<vtkPolyData> polydata =
            vtkSmartPointer<vtkPolyData>::New();
    polydata->SetPoints(points);
    polydata->SetPolys(cells);


    /*
    unsigned char red[3] = {255, 0, 0};
    unsigned char green[3] = {0, 255, 0};
    unsigned char blue[3] = {0, 0, 255};

    vtkSmartPointer<vtkUnsignedCharArray> pointColors =
            vtkSmartPointer<vtkUnsignedCharArray>::New();
    pointColors->SetNumberOfComponents(3);
    for (int i = 0; i < cloud->size(); ++i) {
        if (i % 3 == 0)
            pointColors->InsertTupleValue(i, red);
        if (i % 3 == 1)
            pointColors->InsertTupleValue(i, green);
        if (i % 3 == 2)
            pointColors->InsertTupleValue(i, blue);
    }
    //polydata->GetPointData()->SetScalars(pointColors);
    */
    /*****************************/

    vtkSmartPointer<vtkFeatureEdges> featureEdges =
            vtkSmartPointer<vtkFeatureEdges>::New();
    featureEdges->SetInput(polydata);
    featureEdges->BoundaryEdgesOn();
    featureEdges->FeatureEdgesOff();
    featureEdges->ManifoldEdgesOff();
    featureEdges->NonManifoldEdgesOff();
    featureEdges->Update();

    int numberOfOpenEdges = featureEdges->GetOutput()->GetNumberOfCells();
    if(numberOfOpenEdges)
    {
        std::cout<<"the number of boudary " << numberOfOpenEdges <<std::endl;
    }
    else
    {
        std::cout<< "there is no boundary" <<std::endl;
        //return EXIT_SUCCESS;
    }


    vtkSmartPointer<vtkFillHolesFilter> fillHolesFilter =
            vtkSmartPointer<vtkFillHolesFilter>::New();
    fillHolesFilter->SetInput(polydata);
    //fillHolesFilter->S
    fillHolesFilter->SetHoleSize(50);
    fillHolesFilter->Update();

    //fillHolesFilter->
    /*
    vtkSmartPointer<vtkPolyDataNormals> normals_fill =
            vtkSmartPointer<vtkPolyDataNormals>::New();
    normals_fill->SetInputConnection(fillHolesFilter->GetOutputPort());
    normals_fill->ConsistencyOn();
    normals_fill->SplittingOff();
    normals_fill->Update();
    */
    /*
    vtkSmartPointer<vtkSmoothPolyDataFilter> smoothFilter =
            vtkSmartPointer<vtkSmoothPolyDataFilter>::New();
    smoothFilter->SetInput(normals_fill->GetOutput());
    smoothFilter->SetNumberOfIterations(200);
    smoothFilter->Update();
    */


    vtkSmartPointer<vtkLoopSubdivisionFilter> subdivisionFilter =
            vtkSmartPointer<vtkLoopSubdivisionFilter>::New();
    //subdivisionFilter->SetNumberOfSubdivisions(3);
    //subdivisionFilter->SetInput(fillHolesFilter->GetOutput());
    //subdivisionFilter->Update();
    //subdivisionFilter->GetOutput()->GetPointData().


    vtkSmartPointer<vtkPolyDataMapper> mapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInput(fillHolesFilter->GetOutput());

    //mapper->SetInput(polydata);
    //mapper->SetInput(smoothFilter->GetOutput());

    vtkSmartPointer<vtkActor> actor =
            vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    //vtkSmartPointer<vtkRenderer> renderer =
        //    vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);
 //   renderer->SetBackground(0.1, 0.1, 0.3);

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
    */
   // return renderer;

}
