#ifndef FILLHOLE_H_
#define FILLHOLE_H_

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


#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/vtk_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/visualization/pcl_visualizer.h>

//vtkSmartPointer<vtkRenderer> fillhole_triangle (pcl::PolygonMesh::Ptr triangles);
void fillhole_triangle (pcl::PolygonMesh::Ptr triangles, vtkSmartPointer<vtkRenderer>& renderer);

#endif
