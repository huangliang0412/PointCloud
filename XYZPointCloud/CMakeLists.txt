cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(openni_xyzpointcloud)

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (openni_xyzpointcloud xyzpointcloud.cpp)
target_link_libraries (openni_xyzpointcloud ${PCL_LIBRARIES})
