# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/huangliang/PointCloudThread/RGBPointCloud

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huangliang/PointCloudThread/RGBPointCloud/build

# Include any dependencies generated for this target.
include CMakeFiles/openni_rgbpointcloud.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/openni_rgbpointcloud.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/openni_rgbpointcloud.dir/flags.make

CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o: CMakeFiles/openni_rgbpointcloud.dir/flags.make
CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o: ../rgbpointcloud.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huangliang/PointCloudThread/RGBPointCloud/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o -c /home/huangliang/PointCloudThread/RGBPointCloud/rgbpointcloud.cpp

CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huangliang/PointCloudThread/RGBPointCloud/rgbpointcloud.cpp > CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.i

CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huangliang/PointCloudThread/RGBPointCloud/rgbpointcloud.cpp -o CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.s

CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o.requires:
.PHONY : CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o.requires

CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o.provides: CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o.requires
	$(MAKE) -f CMakeFiles/openni_rgbpointcloud.dir/build.make CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o.provides.build
.PHONY : CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o.provides

CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o.provides.build: CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o

# Object files for target openni_rgbpointcloud
openni_rgbpointcloud_OBJECTS = \
"CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o"

# External object files for target openni_rgbpointcloud
openni_rgbpointcloud_EXTERNAL_OBJECTS =

openni_rgbpointcloud: CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o
openni_rgbpointcloud: CMakeFiles/openni_rgbpointcloud.dir/build.make
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_system.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_thread.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libpthread.so
openni_rgbpointcloud: /usr/local/lib/libpcl_common.so
openni_rgbpointcloud: /usr/local/lib/libflann_cpp.so
openni_rgbpointcloud: /usr/local/lib/libpcl_kdtree.so
openni_rgbpointcloud: /usr/local/lib/libpcl_octree.so
openni_rgbpointcloud: /usr/local/lib/libpcl_search.so
openni_rgbpointcloud: /usr/local/lib/libpcl_sample_consensus.so
openni_rgbpointcloud: /usr/local/lib/libpcl_filters.so
openni_rgbpointcloud: /usr/local/lib/libpcl_features.so
openni_rgbpointcloud: /usr/lib/libOpenNI.so
openni_rgbpointcloud: /usr/lib/libOpenNI2.so
openni_rgbpointcloud: /usr/local/lib/libpcl_io.so
openni_rgbpointcloud: /usr/local/lib/libpcl_visualization.so
openni_rgbpointcloud: /usr/local/lib/libpcl_ml.so
openni_rgbpointcloud: /usr/local/lib/libpcl_segmentation.so
openni_rgbpointcloud: /usr/local/lib/libpcl_people.so
openni_rgbpointcloud: /usr/local/lib/libpcl_tracking.so
openni_rgbpointcloud: /usr/local/lib/libpcl_keypoints.so
openni_rgbpointcloud: /usr/local/lib/libpcl_outofcore.so
openni_rgbpointcloud: /usr/local/lib/libpcl_stereo.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libqhull.so
openni_rgbpointcloud: /usr/local/lib/libpcl_surface.so
openni_rgbpointcloud: /usr/local/lib/libpcl_registration.so
openni_rgbpointcloud: /usr/local/lib/libpcl_recognition.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_system.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_thread.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libpthread.so
openni_rgbpointcloud: /usr/lib/x86_64-linux-gnu/libqhull.so
openni_rgbpointcloud: /usr/lib/libOpenNI.so
openni_rgbpointcloud: /usr/lib/libOpenNI2.so
openni_rgbpointcloud: /usr/local/lib/libflann_cpp.so
openni_rgbpointcloud: /usr/lib/libvtkGenericFiltering.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkGeovis.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkCharts.so.5.8.0
openni_rgbpointcloud: /usr/local/lib/libpcl_common.so
openni_rgbpointcloud: /usr/local/lib/libpcl_kdtree.so
openni_rgbpointcloud: /usr/local/lib/libpcl_octree.so
openni_rgbpointcloud: /usr/local/lib/libpcl_search.so
openni_rgbpointcloud: /usr/local/lib/libpcl_sample_consensus.so
openni_rgbpointcloud: /usr/local/lib/libpcl_filters.so
openni_rgbpointcloud: /usr/local/lib/libpcl_features.so
openni_rgbpointcloud: /usr/local/lib/libpcl_io.so
openni_rgbpointcloud: /usr/local/lib/libpcl_visualization.so
openni_rgbpointcloud: /usr/local/lib/libpcl_ml.so
openni_rgbpointcloud: /usr/local/lib/libpcl_segmentation.so
openni_rgbpointcloud: /usr/local/lib/libpcl_people.so
openni_rgbpointcloud: /usr/local/lib/libpcl_tracking.so
openni_rgbpointcloud: /usr/local/lib/libpcl_keypoints.so
openni_rgbpointcloud: /usr/local/lib/libpcl_outofcore.so
openni_rgbpointcloud: /usr/local/lib/libpcl_stereo.so
openni_rgbpointcloud: /usr/local/lib/libpcl_surface.so
openni_rgbpointcloud: /usr/local/lib/libpcl_registration.so
openni_rgbpointcloud: /usr/local/lib/libpcl_recognition.so
openni_rgbpointcloud: /usr/lib/libvtkViews.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkInfovis.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkWidgets.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkVolumeRendering.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkHybrid.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkParallel.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkRendering.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkImaging.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkGraphics.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkIO.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkFiltering.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtkCommon.so.5.8.0
openni_rgbpointcloud: /usr/lib/libvtksys.so.5.8.0
openni_rgbpointcloud: CMakeFiles/openni_rgbpointcloud.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable openni_rgbpointcloud"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openni_rgbpointcloud.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/openni_rgbpointcloud.dir/build: openni_rgbpointcloud
.PHONY : CMakeFiles/openni_rgbpointcloud.dir/build

CMakeFiles/openni_rgbpointcloud.dir/requires: CMakeFiles/openni_rgbpointcloud.dir/rgbpointcloud.cpp.o.requires
.PHONY : CMakeFiles/openni_rgbpointcloud.dir/requires

CMakeFiles/openni_rgbpointcloud.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/openni_rgbpointcloud.dir/cmake_clean.cmake
.PHONY : CMakeFiles/openni_rgbpointcloud.dir/clean

CMakeFiles/openni_rgbpointcloud.dir/depend:
	cd /home/huangliang/PointCloudThread/RGBPointCloud/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangliang/PointCloudThread/RGBPointCloud /home/huangliang/PointCloudThread/RGBPointCloud /home/huangliang/PointCloudThread/RGBPointCloud/build /home/huangliang/PointCloudThread/RGBPointCloud/build /home/huangliang/PointCloudThread/RGBPointCloud/build/CMakeFiles/openni_rgbpointcloud.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/openni_rgbpointcloud.dir/depend

