cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

project      (pcl-visualizer)
find_package (Qt4 REQUIRED)
find_package (VTK REQUIRED)
find_package (PCL 1.8 REQUIRED)

include_directories (${PCL_INCLUDE_DIRS})
link_directories    (${PCL_LIBRARY_DIRS})
add_definitions     (${PCL_DEFINITIONS})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set  (project_SOURCES main.cpp pclviewer.cpp kdtree.cpp greedy_triangulation.cpp smoothSurface.h smoothSurface.cpp pretreatment.cpp  calthread.cpp
        select_cloud.h fill_hole.cpp rgb.cpp)
set  (project_HEADERS pclviewer.h kdtree.h greedy_triangulation.h pretreatment.h changeformat.h calthread.h fill_hole.h rgb.h)
set  (project_FORMS   pclviewer.ui)
set  (VTK_LIBRARIES   vtkRendering vtkGraphics vtkHybrid QVTK)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

QT4_ADD_RESOURCES(project_SOURCES icon.qrc)
QT4_WRAP_CPP (project_HEADERS_MOC   ${project_HEADERS})
QT4_WRAP_UI  (project_FORMS_HEADERS ${project_FORMS})

INCLUDE         (${QT_USE_FILE})
ADD_DEFINITIONS (${QT_DEFINITIONS})

ADD_EXECUTABLE  (pcl_visualizer ${project_SOURCES}
                                ${project_FORMS_HEADERS}
                                ${project_HEADERS_MOC})

TARGET_LINK_LIBRARIES (pcl_visualizer ${QT_LIBRARIES} ${PCL_LIBRARIES} ${VTK_LIBRARIES})

