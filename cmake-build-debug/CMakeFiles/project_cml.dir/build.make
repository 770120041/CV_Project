# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zcy/cs543/proj/new_backend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zcy/cs543/proj/new_backend/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project_cml.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project_cml.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project_cml.dir/flags.make

CMakeFiles/project_cml.dir/src/Parser.cpp.o: CMakeFiles/project_cml.dir/flags.make
CMakeFiles/project_cml.dir/src/Parser.cpp.o: ../src/Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zcy/cs543/proj/new_backend/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project_cml.dir/src/Parser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_cml.dir/src/Parser.cpp.o -c /Users/zcy/cs543/proj/new_backend/src/Parser.cpp

CMakeFiles/project_cml.dir/src/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_cml.dir/src/Parser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zcy/cs543/proj/new_backend/src/Parser.cpp > CMakeFiles/project_cml.dir/src/Parser.cpp.i

CMakeFiles/project_cml.dir/src/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_cml.dir/src/Parser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zcy/cs543/proj/new_backend/src/Parser.cpp -o CMakeFiles/project_cml.dir/src/Parser.cpp.s

CMakeFiles/project_cml.dir/src/DataCost.cpp.o: CMakeFiles/project_cml.dir/flags.make
CMakeFiles/project_cml.dir/src/DataCost.cpp.o: ../src/DataCost.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zcy/cs543/proj/new_backend/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project_cml.dir/src/DataCost.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_cml.dir/src/DataCost.cpp.o -c /Users/zcy/cs543/proj/new_backend/src/DataCost.cpp

CMakeFiles/project_cml.dir/src/DataCost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_cml.dir/src/DataCost.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zcy/cs543/proj/new_backend/src/DataCost.cpp > CMakeFiles/project_cml.dir/src/DataCost.cpp.i

CMakeFiles/project_cml.dir/src/DataCost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_cml.dir/src/DataCost.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zcy/cs543/proj/new_backend/src/DataCost.cpp -o CMakeFiles/project_cml.dir/src/DataCost.cpp.s

CMakeFiles/project_cml.dir/src/Util.cpp.o: CMakeFiles/project_cml.dir/flags.make
CMakeFiles/project_cml.dir/src/Util.cpp.o: ../src/Util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zcy/cs543/proj/new_backend/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project_cml.dir/src/Util.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_cml.dir/src/Util.cpp.o -c /Users/zcy/cs543/proj/new_backend/src/Util.cpp

CMakeFiles/project_cml.dir/src/Util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_cml.dir/src/Util.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zcy/cs543/proj/new_backend/src/Util.cpp > CMakeFiles/project_cml.dir/src/Util.cpp.i

CMakeFiles/project_cml.dir/src/Util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_cml.dir/src/Util.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zcy/cs543/proj/new_backend/src/Util.cpp -o CMakeFiles/project_cml.dir/src/Util.cpp.s

CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.o: CMakeFiles/project_cml.dir/flags.make
CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.o: ../src/DigitalMontage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zcy/cs543/proj/new_backend/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.o -c /Users/zcy/cs543/proj/new_backend/src/DigitalMontage.cpp

CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zcy/cs543/proj/new_backend/src/DigitalMontage.cpp > CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.i

CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zcy/cs543/proj/new_backend/src/DigitalMontage.cpp -o CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.s

CMakeFiles/project_cml.dir/src/Graph.cpp.o: CMakeFiles/project_cml.dir/flags.make
CMakeFiles/project_cml.dir/src/Graph.cpp.o: ../src/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zcy/cs543/proj/new_backend/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project_cml.dir/src/Graph.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_cml.dir/src/Graph.cpp.o -c /Users/zcy/cs543/proj/new_backend/src/Graph.cpp

CMakeFiles/project_cml.dir/src/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_cml.dir/src/Graph.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zcy/cs543/proj/new_backend/src/Graph.cpp > CMakeFiles/project_cml.dir/src/Graph.cpp.i

CMakeFiles/project_cml.dir/src/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_cml.dir/src/Graph.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zcy/cs543/proj/new_backend/src/Graph.cpp -o CMakeFiles/project_cml.dir/src/Graph.cpp.s

CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.o: CMakeFiles/project_cml.dir/flags.make
CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.o: ../src/LinkedBlockList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zcy/cs543/proj/new_backend/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.o -c /Users/zcy/cs543/proj/new_backend/src/LinkedBlockList.cpp

CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zcy/cs543/proj/new_backend/src/LinkedBlockList.cpp > CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.i

CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zcy/cs543/proj/new_backend/src/LinkedBlockList.cpp -o CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.s

CMakeFiles/project_cml.dir/src/ConjGrad.cpp.o: CMakeFiles/project_cml.dir/flags.make
CMakeFiles/project_cml.dir/src/ConjGrad.cpp.o: ../src/ConjGrad.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zcy/cs543/proj/new_backend/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/project_cml.dir/src/ConjGrad.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_cml.dir/src/ConjGrad.cpp.o -c /Users/zcy/cs543/proj/new_backend/src/ConjGrad.cpp

CMakeFiles/project_cml.dir/src/ConjGrad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_cml.dir/src/ConjGrad.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zcy/cs543/proj/new_backend/src/ConjGrad.cpp > CMakeFiles/project_cml.dir/src/ConjGrad.cpp.i

CMakeFiles/project_cml.dir/src/ConjGrad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_cml.dir/src/ConjGrad.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zcy/cs543/proj/new_backend/src/ConjGrad.cpp -o CMakeFiles/project_cml.dir/src/ConjGrad.cpp.s

CMakeFiles/project_cml.dir/src/MaxFlow.cpp.o: CMakeFiles/project_cml.dir/flags.make
CMakeFiles/project_cml.dir/src/MaxFlow.cpp.o: ../src/MaxFlow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zcy/cs543/proj/new_backend/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/project_cml.dir/src/MaxFlow.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_cml.dir/src/MaxFlow.cpp.o -c /Users/zcy/cs543/proj/new_backend/src/MaxFlow.cpp

CMakeFiles/project_cml.dir/src/MaxFlow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_cml.dir/src/MaxFlow.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zcy/cs543/proj/new_backend/src/MaxFlow.cpp > CMakeFiles/project_cml.dir/src/MaxFlow.cpp.i

CMakeFiles/project_cml.dir/src/MaxFlow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_cml.dir/src/MaxFlow.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zcy/cs543/proj/new_backend/src/MaxFlow.cpp -o CMakeFiles/project_cml.dir/src/MaxFlow.cpp.s

CMakeFiles/project_cml.dir/src/GCoptimization.cpp.o: CMakeFiles/project_cml.dir/flags.make
CMakeFiles/project_cml.dir/src/GCoptimization.cpp.o: ../src/GCoptimization.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zcy/cs543/proj/new_backend/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/project_cml.dir/src/GCoptimization.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_cml.dir/src/GCoptimization.cpp.o -c /Users/zcy/cs543/proj/new_backend/src/GCoptimization.cpp

CMakeFiles/project_cml.dir/src/GCoptimization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_cml.dir/src/GCoptimization.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zcy/cs543/proj/new_backend/src/GCoptimization.cpp > CMakeFiles/project_cml.dir/src/GCoptimization.cpp.i

CMakeFiles/project_cml.dir/src/GCoptimization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_cml.dir/src/GCoptimization.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zcy/cs543/proj/new_backend/src/GCoptimization.cpp -o CMakeFiles/project_cml.dir/src/GCoptimization.cpp.s

# Object files for target project_cml
project_cml_OBJECTS = \
"CMakeFiles/project_cml.dir/src/Parser.cpp.o" \
"CMakeFiles/project_cml.dir/src/DataCost.cpp.o" \
"CMakeFiles/project_cml.dir/src/Util.cpp.o" \
"CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.o" \
"CMakeFiles/project_cml.dir/src/Graph.cpp.o" \
"CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.o" \
"CMakeFiles/project_cml.dir/src/ConjGrad.cpp.o" \
"CMakeFiles/project_cml.dir/src/MaxFlow.cpp.o" \
"CMakeFiles/project_cml.dir/src/GCoptimization.cpp.o"

# External object files for target project_cml
project_cml_EXTERNAL_OBJECTS =

project_cml: CMakeFiles/project_cml.dir/src/Parser.cpp.o
project_cml: CMakeFiles/project_cml.dir/src/DataCost.cpp.o
project_cml: CMakeFiles/project_cml.dir/src/Util.cpp.o
project_cml: CMakeFiles/project_cml.dir/src/DigitalMontage.cpp.o
project_cml: CMakeFiles/project_cml.dir/src/Graph.cpp.o
project_cml: CMakeFiles/project_cml.dir/src/LinkedBlockList.cpp.o
project_cml: CMakeFiles/project_cml.dir/src/ConjGrad.cpp.o
project_cml: CMakeFiles/project_cml.dir/src/MaxFlow.cpp.o
project_cml: CMakeFiles/project_cml.dir/src/GCoptimization.cpp.o
project_cml: CMakeFiles/project_cml.dir/build.make
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_videostab.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_ts.a
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_superres.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_stitching.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_contrib.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_nonfree.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_ocl.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_gpu.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_photo.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_objdetect.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_legacy.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_video.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_ml.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_calib3d.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_features2d.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_highgui.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_imgproc.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_flann.2.4.13.dylib
project_cml: /usr/local/Cellar/opencv@2/2.4.13.7_2/lib/libopencv_core.2.4.13.dylib
project_cml: CMakeFiles/project_cml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zcy/cs543/proj/new_backend/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable project_cml"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project_cml.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project_cml.dir/build: project_cml

.PHONY : CMakeFiles/project_cml.dir/build

CMakeFiles/project_cml.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project_cml.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project_cml.dir/clean

CMakeFiles/project_cml.dir/depend:
	cd /Users/zcy/cs543/proj/new_backend/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zcy/cs543/proj/new_backend /Users/zcy/cs543/proj/new_backend /Users/zcy/cs543/proj/new_backend/cmake-build-debug /Users/zcy/cs543/proj/new_backend/cmake-build-debug /Users/zcy/cs543/proj/new_backend/cmake-build-debug/CMakeFiles/project_cml.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project_cml.dir/depend

