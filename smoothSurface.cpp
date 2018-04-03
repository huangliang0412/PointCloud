//
// Created by huangliang on 16-11-25.
//
#include "smoothSurface.h"
#include <pcl/PolygonMesh.h>
#include <pcl/surface/vtk_smoothing/vtk_mesh_subdivision.h>

using namespace pcl;
PolygonMesh::Ptr smoothSurface(PolygonMesh::Ptr mesh)
{
    MeshSubdivisionVTK processPointCloud;
    processPointCloud.setFilterType(MeshSubdivisionVTK::LOOP);
    // processPointCloud.setFilterType();
    processPointCloud.setInputMesh(mesh);
    PolygonMesh::Ptr newMesh(new PolygonMesh);
    processPointCloud.process(*newMesh);
    std::cout << "--------" <<std::endl;
    std::cout << processPointCloud.getFilterType() << std::endl;
    //MeshSubdivisionVTKFilterType = LOOP;
    std::cout << pcl::MeshSubdivisionVTK::LOOP<< std::endl;
    return newMesh;
}
