cmake_minimum_required(VERSION 3.13)

project( new_backend )

find_package( OpenCV HINTS "/usr/local/Cellar/opencv@2/2.4.13.7_2")
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable( project_cml
        src/Parser.cpp
        src/DataCost.cpp
        src/Util.cpp
        src/DigitalMontage.cpp
        src/Graph.cpp
        src/LinkedBlockList.cpp
        src/ConjGrad.cpp
        src/MaxFlow.cpp
        src/GCoptimization.cpp)
target_link_libraries( project_cml ${OpenCV_LIBS} Eigen3::Eigen)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread" )