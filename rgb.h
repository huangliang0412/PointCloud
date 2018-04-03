#ifndef RGB_H_
#define RGB_H_

#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>

#include <vector>
#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/vtk_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread/thread.hpp>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include <vtkConeSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyDataMapper.h>

#include <vtkPolygon.h>
#include <vtkTriangle.h>
#include <vtkCellArray.h>

#include <vtkPointData.h>
#include <vtkPolygon.h>

#include <vtkFeatureEdges.h>
#include <vtkFillHolesFilter.h>
#include <vtkPolyDataNormals.h>

#include <vtkSmoothPolyDataFilter.h>

#include <vtkLoopSubdivisionFilter.h>

#include <set>
//using namespace std;

void rgbreconstruct (vtkSmartPointer<vtkRenderer>& renderer);

#endif
